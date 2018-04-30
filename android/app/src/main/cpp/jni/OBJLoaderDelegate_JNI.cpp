//
//  OBJLoaderDelegate_JNI.cpp
//  ViroRenderer
//
//  Copyright © 2016 Viro Media. All rights reserved.
//


#include <jni.h>
#include <memory>
#include "VROPlatformUtil.h"
#include "OBJLoaderDelegate_JNI.h"
#include "Node_JNI.h"
#include "Geometry_JNI.h"
#include "VROGeometry.h"
#include "VROMaterial.h"
#include "Material_JNI.h"

OBJLoaderDelegate::OBJLoaderDelegate(VRO_OBJECT nodeJavaObject, JNIEnv *env) {
    _javaObject = reinterpret_cast<jclass>(env->NewWeakGlobalRef(nodeJavaObject));
}

OBJLoaderDelegate::~OBJLoaderDelegate() {
    JNIEnv *env = VROPlatformGetJNIEnv();
    env->DeleteWeakGlobalRef(_javaObject);
}

void OBJLoaderDelegate::objLoaded(std::shared_ptr<VRONode> node, bool isFBX, jlong requestId) {
    JNIEnv *env = VROPlatformGetJNIEnv();
    jweak weakObj = env->NewWeakGlobalRef(_javaObject);

    // If the request is antiquated, clear the node
    jlong activeRequestID = VROPlatformCallJavaLongFunction(_javaObject, "getActiveRequestID", "()J");
    if (activeRequestID != requestId) {
        pinfo("Received antiquated Object3D load, discarding");
        node->removeAllChildren();
        return;
    }

    VROPlatformDispatchAsyncApplication([weakObj, node, isFBX] {
        JNIEnv *env = VROPlatformGetJNIEnv();
        VRO_OBJECT localObj = env->NewLocalRef(weakObj);
        if (localObj == NULL) {
            env->DeleteWeakGlobalRef(weakObj);
            return;
        }

        // If the request was for an OBJ, create a persistent ref for the Java Geometry and
        // pass that up as well. This enables Java SDK users to set materials on the Geometry
        long geometryRef = 0;
        if (!isFBX && node->getGeometry()) {
            geometryRef = Geometry::jptr(node->getGeometry());
        }

        // Generate a map of unique jMaterials representing this 3D model.
        std::map<std::string, std::shared_ptr<VROMaterial>> mats;
        generateJMaterials(mats, node);

        // Generate a jObjectArray containing a unique list of jMaterials
        jobjectArray materialArray = env->NewObjectArray(mats.size(),
                                                         env->FindClass("com/viro/core/Material"),
                                                         NULL);
        if (mats.size() > 0) {
            int i = 0;
            for(std::map<std::string, std::shared_ptr<VROMaterial>>::iterator
                        it = mats.begin(); it != mats.end(); ++it) {
                // Create the Material.java and added it to the array
                VRO_OBJECT jMat = Material::createJMaterial(it->second);
                env->SetObjectArrayElement(materialArray, i, jMat);

                // Clean up our local reference to jMaterial after.
                env->DeleteLocalRef(jMat);
                i++;
            }
        }

        // Call the nodeDidFinishCreation callback.
        VRO_REF jGeometryRef = geometryRef;
        VROPlatformCallJavaFunction(localObj,
                                    "nodeDidFinishCreation",
                                    "([Lcom/viro/core/Material;ZJ)V",
                                    materialArray, isFBX, jGeometryRef);

        env->DeleteLocalRef(localObj);
        env->DeleteWeakGlobalRef(weakObj);
    });
}

void OBJLoaderDelegate::generateJMaterials(std::map<std::string, std::shared_ptr<VROMaterial>> &matOut,
                                           std::shared_ptr<VRONode> node) {

    std::shared_ptr<VROGeometry> geom = node->getGeometry();
    if (geom != nullptr){
        for (std::shared_ptr<VROMaterial> mat : geom->getMaterials()) {

            // Skip, if we have already tracked this material.
            std::string materialId = VROStringUtil::toString(mat->getMaterialId());
            if (matOut.find(materialId) != matOut.end()){
                continue;
            }

            // Grab the material name devs to reference by. If no name is provided,
            // generate one from with a combination of geometryName + material ID.
            if (mat->getName().empty()) {
                std::string id = VROStringUtil::toString(mat->getMaterialId());
                std::string geomName = geom->getName();
                std::string matName = geomName + id;
                mat->setName(matName);
            }

            matOut[materialId] = mat;
        }
    }

    for (std::shared_ptr<VRONode> childNode : node->getChildNodes()) {
        generateJMaterials(matOut, childNode);
    }
}

void OBJLoaderDelegate::objFailed(std::string error) {
    JNIEnv *env = VROPlatformGetJNIEnv();
    jweak weakObj = env->NewWeakGlobalRef(_javaObject);

    VROPlatformDispatchAsyncApplication([weakObj, error] {
        JNIEnv *env = VROPlatformGetJNIEnv();

        VRO_OBJECT localObj = env->NewLocalRef(weakObj);
        if (localObj == NULL) {
            env->DeleteWeakGlobalRef(weakObj);
            return;
        }

        VRO_STRING jerror = VRO_NEW_STRING(error.c_str());
        VROPlatformCallJavaFunction(localObj, "nodeDidFailOBJLoad", "(Ljava/lang/String;)V", jerror);

        env->DeleteLocalRef(localObj);
        env->DeleteLocalRef(jerror);
        env->DeleteWeakGlobalRef(weakObj);
    });
}