//
//  Camera_JNI.h
//  ViroRenderer
//
//  Copyright © 2017 Viro Media. All rights reserved.
//

#include "Camera_JNI.h"
#include <iostream>
#include <jni.h>
#include <memory>
#include <VROPlatformUtil.h>
#include "PersistentRef.h"
#include "VRONodeCamera.h"
#include "VROCamera.h"
#include "VROStringUtil.h"
#include "Node_JNI.h"

#define JNI_METHOD(return_type, method_name) \
  JNIEXPORT return_type JNICALL              \
      Java_com_viro_renderer_jni_CameraJni_##method_name

extern "C" {

JNI_METHOD(jlong, nativeCreateCamera)(JNIEnv *env,
                                      jclass clazz) {
    std::shared_ptr<VRONodeCamera> node = std::make_shared<VRONodeCamera>();
    return Camera::jptr(node);
}

JNI_METHOD(void, nativeDestroyCamera)(JNIEnv *env,
                                    jclass clazz,
                                    jlong native_node_ref) {
    VROPlatformDispatchAsyncRenderer([native_node_ref] {
        delete reinterpret_cast<PersistentRef<VRONodeCamera> *>(native_node_ref);
    });
}

JNI_METHOD(void, nativeAddToNode)(JNIEnv *env,
                                  jobject obj,
                                  jlong nativeCamera, jlong nativeNode) {
    VROPlatformDispatchAsyncRenderer([nativeNode, nativeCamera] {
        Node::native(nativeNode)->setCamera(Camera::native(nativeCamera));
    });
}

JNI_METHOD(void, nativeRemoveFromNode)(JNIEnv *env,
                                       jobject obj,
                                       jlong nativeCamera, jlong nativeNode) {
    VROPlatformDispatchAsyncRenderer([nativeNode, nativeCamera] {
        std::shared_ptr<VRONodeCamera> camera = Camera::native(nativeCamera);
        std::shared_ptr<VRONode> node = Node::native(nativeNode);

        if (node->getCamera() == camera) {
            node->setCamera(nullptr);
        }
    });
}

JNI_METHOD(void, nativeSetPosition)(JNIEnv *env,
                                    jobject obj,
                                    jlong nativeCamera, jfloat x, jfloat y, jfloat z) {
    VROPlatformDispatchAsyncRenderer([nativeCamera, x, y, z] {
        Camera::native(nativeCamera)->setPosition(VROVector3f(x, y, z));
    });
}

JNI_METHOD(void, nativeSetRotationType)(JNIEnv *env,
                                              jobject obj,
                                              jlong nativeCamera,
                                              jstring rotationType) {
    // Get the string
    const char *cStrRotationType = env->GetStringUTFChars(rotationType, NULL);
    std::string strRotationType(cStrRotationType);
    VROCameraRotationType type;

    if (VROStringUtil::strcmpinsensitive(strRotationType, "orbit")) {
        type = VROCameraRotationType::Orbit;
    } else {
        // default rotation type is standard.
        type = VROCameraRotationType::Standard;
    }
    env->ReleaseStringUTFChars(rotationType, cStrRotationType);

    VROPlatformDispatchAsyncRenderer([nativeCamera, type] {
        Camera::native(nativeCamera)->setRotationType(type);
    });
}

JNI_METHOD(void, nativeSetOrbitFocalPoint)(JNIEnv *env,
                                           jobject obj,
                                           jlong nativeCamera, jfloat x, jfloat y, jfloat z) {
    VROPlatformDispatchAsyncRenderer([nativeCamera, x, y, z] {
        Camera::native(nativeCamera)->setOrbitFocalPoint(VROVector3f(x, y, z));
    });
}

} // extern "C"