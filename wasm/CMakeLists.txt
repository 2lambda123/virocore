cmake_minimum_required(VERSION 3.4.1)

MESSAGE(STATUS "CMAKE_SOURCE_DIR:         " ${CMAKE_SOURCE_DIR})

SET(VIRO_RENDERER_SRC ../ViroRenderer)
SET(VIRO_CAPI_SRC     ../ViroRenderer/capi)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_EXECUTABLE_SUFFIX ".html")
SET(GCC_COVERAGE_COMPILE_FLAGS "-DWASM_PLATFORM")
ADD_DEFINITIONS(${GCC_COVERAGE_COMPILE_FLAGS})

INCLUDE_DIRECTORIES(${VIRO_RENDERER_SRC}
                    src/cpp
                    libs/freetype/include
                    libs/protobuf/include
                    libs/bullet/include
                    libs/zlib/include
                    libs/jpeg/include)

SET( VIRO_RENDERER_SRC

     # Web Platform
     src/cpp/VROViewScene.cpp
     src/cpp/VROInputControllerWasm.cpp
     src/cpp/VROImageWasm.cpp
     src/cpp/VROTypefaceWasm.cpp
     src/cpp/VROJpegReader.cpp

     # C API
     ${VIRO_CAPI_SRC}/Node_JNI.cpp
     ${VIRO_CAPI_SRC}/Geometry_JNI.cpp
     ${VIRO_CAPI_SRC}/SceneController_JNI.cpp
     ${VIRO_CAPI_SRC}/Camera_JNI.cpp
     ${VIRO_CAPI_SRC}/Box_JNI.cpp
     ${VIRO_CAPI_SRC}/Image_JNI.cpp
     ${VIRO_CAPI_SRC}/Controller_JNI.cpp
     ${VIRO_CAPI_SRC}/Surface_JNI.cpp
     ${VIRO_CAPI_SRC}/Polygon_JNI.cpp
     ${VIRO_CAPI_SRC}/Sphere_JNI.cpp
     ${VIRO_CAPI_SRC}/Material_JNI.cpp
     ${VIRO_CAPI_SRC}/Texture_JNI.cpp
     ${VIRO_CAPI_SRC}/VideoTexture_JNI.cpp
     ${VIRO_CAPI_SRC}/VideoDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/ViroContext_JNI.cpp
     ${VIRO_CAPI_SRC}/EventDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/AnimationChain_JNI.cpp
     ${VIRO_CAPI_SRC}/AnimationGroup_JNI.cpp
     ${VIRO_CAPI_SRC}/ExecutableAnimation_JNI.cpp
     ${VIRO_CAPI_SRC}/LazyMaterial_JNI.cpp
     ${VIRO_CAPI_SRC}/Light_JNI.cpp
     ${VIRO_CAPI_SRC}/AmbientLight_JNI.cpp
     ${VIRO_CAPI_SRC}/SpotLight_JNI.cpp
     ${VIRO_CAPI_SRC}/DirectionalLight_JNI.cpp
     ${VIRO_CAPI_SRC}/OmniLight_JNI.cpp
     ${VIRO_CAPI_SRC}/Sound_JNI.cpp
     ${VIRO_CAPI_SRC}/SoundField_JNI.cpp
     ${VIRO_CAPI_SRC}/SpatialSound_JNI.cpp
     ${VIRO_CAPI_SRC}/SoundDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/Text_JNI.cpp
     ${VIRO_CAPI_SRC}/TextDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/SoundData_JNI.cpp
     ${VIRO_CAPI_SRC}/Object_JNI.cpp
     ${VIRO_CAPI_SRC}/OBJLoaderDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/Polyline_JNI.cpp
     ${VIRO_CAPI_SRC}/PhysicsDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/TransformDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/FixedParticleEmitter_JNI.cpp
     ${VIRO_CAPI_SRC}/ParticleEmitter_JNI.cpp
     ${VIRO_CAPI_SRC}/Portal_JNI.cpp
     ${VIRO_CAPI_SRC}/PortalScene_JNI.cpp
     ${VIRO_CAPI_SRC}/PortalDelegate_JNI.cpp
     ${VIRO_CAPI_SRC}/PhysicsBody_JNI.cpp
     ${VIRO_CAPI_SRC}/AnimationTransaction_JNI.cpp
     ${VIRO_CAPI_SRC}/ViroUtils_JNI.cpp

     # Util
     ${VIRO_RENDERER_SRC}/VROAllocationTracker.cpp
     ${VIRO_RENDERER_SRC}/VROTime.cpp
     ${VIRO_RENDERER_SRC}/VROLog.cpp
     ${VIRO_RENDERER_SRC}/VROByteBuffer.cpp
     ${VIRO_RENDERER_SRC}/VROImageUtil.cpp
     ${VIRO_RENDERER_SRC}/VROData.cpp
     ${VIRO_RENDERER_SRC}/VROGeometryUtil.cpp
     ${VIRO_RENDERER_SRC}/VROTextureUtil.cpp
     ${VIRO_RENDERER_SRC}/VROStringUtil.cpp
     ${VIRO_RENDERER_SRC}/VROPlatformUtil.cpp
     ${VIRO_RENDERER_SRC}/VROModelIOUtil.cpp
     ${VIRO_RENDERER_SRC}/VROOBJLoader.cpp
     ${VIRO_RENDERER_SRC}/VROHDRLoader.cpp
     ${VIRO_RENDERER_SRC}/tiny_obj_loader.cc
     ${VIRO_RENDERER_SRC}/VROThreadRestricted.cpp
     ${VIRO_RENDERER_SRC}/VRORenderUtil.cpp
     ${VIRO_RENDERER_SRC}/VROTaskQueue.cpp
     ${VIRO_RENDERER_SRC}/VROFBXLoader.cpp
     ${VIRO_RENDERER_SRC}/VROGLTFLoader.cpp
     ${VIRO_RENDERER_SRC}/VROCompress.cpp
     ${VIRO_RENDERER_SRC}/VROSparseBitSet.cpp
     ${VIRO_RENDERER_SRC}/Nodes.pb.cc

     # Renderer
     ${VIRO_RENDERER_SRC}/VROScene.cpp
     ${VIRO_RENDERER_SRC}/VROSceneController.cpp
     ${VIRO_RENDERER_SRC}/VROCamera.cpp
     ${VIRO_RENDERER_SRC}/VRONode.cpp
     ${VIRO_RENDERER_SRC}/VROPortal.cpp
     ${VIRO_RENDERER_SRC}/VROPortalFrame.cpp
     ${VIRO_RENDERER_SRC}/VROGeometry.cpp
     ${VIRO_RENDERER_SRC}/VROGeometryElement.cpp
     ${VIRO_RENDERER_SRC}/VROGeometrySource.cpp
     ${VIRO_RENDERER_SRC}/VROMaterial.cpp
     ${VIRO_RENDERER_SRC}/VROMaterialVisual.cpp
     ${VIRO_RENDERER_SRC}/VROTexture.cpp
     ${VIRO_RENDERER_SRC}/VROLight.cpp
     ${VIRO_RENDERER_SRC}/VROBillboardConstraint.cpp
     ${VIRO_RENDERER_SRC}/VROTransformConstraint.cpp
     ${VIRO_RENDERER_SRC}/VRORenderer.cpp
     ${VIRO_RENDERER_SRC}/VROFrameSynchronizerInternal.cpp
     ${VIRO_RENDERER_SRC}/VROPortalTraversalListener.cpp
     ${VIRO_RENDERER_SRC}/VROGeometrySubstrate.cpp
     ${VIRO_RENDERER_SRC}/VROTextureSubstrate.cpp
     ${VIRO_RENDERER_SRC}/VROMaterialSubstrate.cpp
     ${VIRO_RENDERER_SRC}/VRONodeCamera.cpp
     ${VIRO_RENDERER_SRC}/VROInputControllerBase.cpp
     ${VIRO_RENDERER_SRC}/VROFrameScheduler.cpp
     ${VIRO_RENDERER_SRC}/VROChoreographer.cpp
     ${VIRO_RENDERER_SRC}/VROPortalTreeRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VRORenderTargetOpenGL.cpp
     ${VIRO_RENDERER_SRC}/VROImageShaderProgram.cpp
     ${VIRO_RENDERER_SRC}/VROImagePostProcessOpenGL.cpp
     ${VIRO_RENDERER_SRC}/VROParticleEmitter.cpp
     ${VIRO_RENDERER_SRC}/VROParticleUBO.cpp
     ${VIRO_RENDERER_SRC}/VROShadowPreprocess.cpp
     ${VIRO_RENDERER_SRC}/VROShadowMapRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VROShaderFactory.cpp
     ${VIRO_RENDERER_SRC}/VROShaderCapabilities.cpp
     ${VIRO_RENDERER_SRC}/VROTextureReference.cpp
     ${VIRO_RENDERER_SRC}/VROMaterialShaderBinding.cpp
     ${VIRO_RENDERER_SRC}/VROPostProcessEffectFactory.cpp
     ${VIRO_RENDERER_SRC}/VROToneMappingRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VROGaussianBlurRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VROIBLPreprocess.cpp
     ${VIRO_RENDERER_SRC}/VROEquirectangularToCubeRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VROIrradianceRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VROPrefilterRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VROBRDFRenderPass.cpp
     ${VIRO_RENDERER_SRC}/VROFixedParticleEmitter.cpp

     # UI
     ${VIRO_RENDERER_SRC}/VROReticle.cpp
     ${VIRO_RENDERER_SRC}/VROText.cpp
	 ${VIRO_RENDERER_SRC}/VROTextFormatter.cpp
     ${VIRO_RENDERER_SRC}/VROTypeface.cpp
     ${VIRO_RENDERER_SRC}/VROTypefaceCollection.cpp
	 ${VIRO_RENDERER_SRC}/VROVectorizer.cpp
	 ${VIRO_RENDERER_SRC}/VROContour.cpp
     ${VIRO_RENDERER_SRC}/VROFontUtil.cpp
     ${VIRO_RENDERER_SRC}/VROCharmapCoverage.cpp
     ${VIRO_RENDERER_SRC}/VROKnuthPlassFormatter.cpp
     ${VIRO_RENDERER_SRC}/VRODebugHUD.cpp
     ${VIRO_RENDERER_SRC}/VROGlyphOpenGL.cpp
     ${VIRO_RENDERER_SRC}/VROGlyphAtlasOpenGL.cpp

	 # Poly2Tri
	 ${VIRO_RENDERER_SRC}/poly2tri/sweep/advancing_front.cc
	 ${VIRO_RENDERER_SRC}/poly2tri/sweep/cdt.cc
	 ${VIRO_RENDERER_SRC}/poly2tri/sweep/sweep_context.cc
	 ${VIRO_RENDERER_SRC}/poly2tri/sweep/sweep.cc
	 ${VIRO_RENDERER_SRC}/poly2tri/common/shapes.cc

     # Physics
     ${VIRO_RENDERER_SRC}/VROPhysicsWorld.cpp
     ${VIRO_RENDERER_SRC}/VROPhysicsBody.cpp
     ${VIRO_RENDERER_SRC}/VROPhysicsShape.cpp

     # AR
     ${VIRO_RENDERER_SRC}/VROARSceneController.cpp
     ${VIRO_RENDERER_SRC}/VROARScene.cpp
     ${VIRO_RENDERER_SRC}/VROARNode.cpp
     ${VIRO_RENDERER_SRC}/VROARConstraintMatcher.cpp
     ${VIRO_RENDERER_SRC}/VROARDeclarativeSession.cpp
     ${VIRO_RENDERER_SRC}/VROARImperativeSession.cpp
     ${VIRO_RENDERER_SRC}/VROInputControllerAR.cpp
     ${VIRO_RENDERER_SRC}/VROARShadow.cpp

     # Animation
     ${VIRO_RENDERER_SRC}/VROTimingFunction.cpp
     ${VIRO_RENDERER_SRC}/VROTransaction.cpp
     ${VIRO_RENDERER_SRC}/VROAnimatable.cpp
     ${VIRO_RENDERER_SRC}/VROAction.cpp
     ${VIRO_RENDERER_SRC}/VROAnimationChain.cpp
     ${VIRO_RENDERER_SRC}/VROAnimationGroup.cpp
     ${VIRO_RENDERER_SRC}/VROPropertyAnimation.cpp
     ${VIRO_RENDERER_SRC}/VROSkinner.cpp
     ${VIRO_RENDERER_SRC}/VROSkeleton.cpp
     ${VIRO_RENDERER_SRC}/VROBone.cpp
     ${VIRO_RENDERER_SRC}/VROBoneUBO.cpp
     ${VIRO_RENDERER_SRC}/VROSkeletalAnimation.cpp
	 ${VIRO_RENDERER_SRC}/VROLayeredSkeletalAnimation.cpp
     ${VIRO_RENDERER_SRC}/VROKeyframeAnimation.cpp

     # Shapes
     ${VIRO_RENDERER_SRC}/VROBox.cpp
     ${VIRO_RENDERER_SRC}/VROSkybox.cpp
     ${VIRO_RENDERER_SRC}/VROSurface.cpp
     ${VIRO_RENDERER_SRC}/VROTorusKnot.cpp
     ${VIRO_RENDERER_SRC}/VROShapeUtils.cpp
     ${VIRO_RENDERER_SRC}/VROSphere.cpp
     ${VIRO_RENDERER_SRC}/VROPolyline.cpp
     ${VIRO_RENDERER_SRC}/VROPolygon.cpp
     ${VIRO_RENDERER_SRC}/VROVideoSurface.cpp
     ${VIRO_RENDERER_SRC}/VROPencil.cpp

     # OpenGL
     ${VIRO_RENDERER_SRC}/VROGeometrySubstrateOpenGL.cpp
     ${VIRO_RENDERER_SRC}/VROMaterialSubstrateOpenGL.cpp
     ${VIRO_RENDERER_SRC}/VROTextureSubstrateOpenGL.cpp
     ${VIRO_RENDERER_SRC}/VROUniform.cpp
     ${VIRO_RENDERER_SRC}/VROShaderProgram.cpp
     ${VIRO_RENDERER_SRC}/VROShaderModifier.cpp
     ${VIRO_RENDERER_SRC}/VROLightingUBO.cpp

     # Math
     ${VIRO_RENDERER_SRC}/VROLineSegment.cpp
     ${VIRO_RENDERER_SRC}/VROTriangle.cpp
     ${VIRO_RENDERER_SRC}/VROQuaternion.cpp
     ${VIRO_RENDERER_SRC}/VROPlane.cpp
     ${VIRO_RENDERER_SRC}/VROFrustum.cpp
     ${VIRO_RENDERER_SRC}/VROFrustumPlane.cpp
     ${VIRO_RENDERER_SRC}/VROBoundingBox.cpp
     ${VIRO_RENDERER_SRC}/VROFrustumBoxIntersectionMetadata.cpp
     ${VIRO_RENDERER_SRC}/VROMatrix4f.cpp
     ${VIRO_RENDERER_SRC}/VROMath.cpp
     ${VIRO_RENDERER_SRC}/VROProjector.cpp
     ${VIRO_RENDERER_SRC}/VRODualQuaternion.cpp
     ${VIRO_RENDERER_SRC}/VROVector3f.cpp
     ${VIRO_RENDERER_SRC}/VROVector4f.cpp

     # Renderer Test
     ${VIRO_RENDERER_SRC}/VRORendererTestHarness.cpp
     ${VIRO_RENDERER_SRC}/VROTestUtil.cpp
     ${VIRO_RENDERER_SRC}/VROPhysicsTest.cpp
     ${VIRO_RENDERER_SRC}/VROARDraggableNodeTest.cpp
     ${VIRO_RENDERER_SRC}/VROARPlaneTest.cpp
     ${VIRO_RENDERER_SRC}/VROShadowTest.cpp
     ${VIRO_RENDERER_SRC}/VROARShadowTest.cpp
     ${VIRO_RENDERER_SRC}/VROBloomTest.cpp
     ${VIRO_RENDERER_SRC}/VROParticleTest.cpp
     ${VIRO_RENDERER_SRC}/VROFBXTest.cpp
     ${VIRO_RENDERER_SRC}/VROHDRTest.cpp
     ${VIRO_RENDERER_SRC}/VRONormalMapTest.cpp
     ${VIRO_RENDERER_SRC}/VROOBJTest.cpp
     ${VIRO_RENDERER_SRC}/VROPerfTest.cpp
     ${VIRO_RENDERER_SRC}/VROPortalTest.cpp
     ${VIRO_RENDERER_SRC}/VROShadowTest.cpp
     ${VIRO_RENDERER_SRC}/VROStereoscopicTest.cpp
     ${VIRO_RENDERER_SRC}/VROTextTest.cpp
     ${VIRO_RENDERER_SRC}/VROTorusTest.cpp
     ${VIRO_RENDERER_SRC}/VROVideoSphereTest.cpp
     ${VIRO_RENDERER_SRC}/VROBoxTest.cpp
     ${VIRO_RENDERER_SRC}/VROPolylineTest.cpp
     ${VIRO_RENDERER_SRC}/VROPBRDirectTest.cpp
     ${VIRO_RENDERER_SRC}/VROPBRTexturedTest.cpp
     ${VIRO_RENDERER_SRC}/VRODiffuseIrradianceTest.cpp
     ${VIRO_RENDERER_SRC}/VROPhotometricLightTest.cpp
     ${VIRO_RENDERER_SRC}/VRORendererSettingsTest.cpp
     ${VIRO_RENDERER_SRC}/VROGLTFTest.cpp
     ${VIRO_RENDERER_SRC}/VROToneMappingTest.cpp
     ${VIRO_RENDERER_SRC}/VROPolygonTest.cpp
	 ../ViroRenderer/capi/TestAPI.cpp)

ADD_SUBDIRECTORY(libs/bullet/src/LinearMath)
ADD_SUBDIRECTORY(libs/bullet/src/BulletSoftBody)
ADD_SUBDIRECTORY(libs/bullet/src/BulletDynamics)
ADD_SUBDIRECTORY(libs/bullet/src/BulletCollision)
ADD_SUBDIRECTORY(libs/protobuf/src)
ADD_SUBDIRECTORY(libs/jpeg/src)

SET (VIRO_LINK_LIBS        protobuf-lite)
LIST(APPEND VIRO_LINK_LIBS jpeg)
LIST(APPEND VIRO_LINK_LIBS bullet_linearmath)
LIST(APPEND VIRO_LINK_LIBS bullet_softbody)
LIST(APPEND VIRO_LINK_LIBS bullet_dynamics)
LIST(APPEND VIRO_LINK_LIBS bullet_collision)

SET(VIRO_LINK_FLAGS "-Oz \
					 -s WASM=1 \
                     -s USE_ZLIB=1 \
                     -s USE_FREETYPE=1 \
                     -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' \
                     -s USE_WEBGL2=1 \
                     -s ALLOW_MEMORY_GROWTH=1 \
                     --bind \
                     --preload-file ${CMAKE_SOURCE_DIR}/products/preload@/ \
                     --shell-file ${CMAKE_SOURCE_DIR}/test/viro_shell.html \
                     --emrun")

# Build executables for each test
ADD_EXECUTABLE       (viro_fbx_test ${VIRO_RENDERER_SRC} test/fbx/bootstrap.cpp)
SET_TARGET_PROPERTIES(viro_fbx_test PROPERTIES LINK_FLAGS ${VIRO_LINK_FLAGS})
TARGET_LINK_LIBRARIES(viro_fbx_test ${VIRO_LINK_LIBS})
ADD_CUSTOM_COMMAND(TARGET viro_fbx_test
				   PRE_BUILD
		           COMMAND /bin/sh ${CMAKE_SOURCE_DIR}/copy_preload.sh fbx
                   WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
ADD_CUSTOM_COMMAND(TARGET viro_fbx_test
                   POST_BUILD
                   COMMAND /bin/sh ${CMAKE_SOURCE_DIR}/copy_js.sh
                   WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

ADD_EXECUTABLE       (viro_pbr_test ${VIRO_RENDERER_SRC} test/pbr/bootstrap.cpp)
SET_TARGET_PROPERTIES(viro_pbr_test PROPERTIES LINK_FLAGS ${VIRO_LINK_FLAGS})
TARGET_LINK_LIBRARIES(viro_pbr_test ${VIRO_LINK_LIBS})