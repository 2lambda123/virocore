//
//  VROARImageTrackingTest.h
//  ViroSample
//
//  Created by Andy Chu on 2/1/18.
//  Copyright © 2018 Viro Media. All rights reserved.
//

#ifndef VROARImageTrackingTest_h
#define VROARImageTrackingTest_h

#include "VRORendererTest.h"
#include "VROARDeclarativeNode.h"

class VROARImageTrackingTest : public VRORendererTest, public VROARDeclarativeNodeDelegate,
public std::enable_shared_from_this<VROARImageTrackingTest> {
public:
    
    VROARImageTrackingTest();
    virtual ~VROARImageTrackingTest();
    
    void build(std::shared_ptr<VRORenderer> renderer,
               std::shared_ptr<VROFrameSynchronizer> frameSynchronizer,
               std::shared_ptr<VRODriver> driver);
    std::shared_ptr<VRONode> getPointOfView() {
        return _pointOfView;
    }
    std::shared_ptr<VROSceneController> getSceneController() {
        return _sceneController;
    }
    
    void onARAnchorAttached(std::shared_ptr<VROARAnchor> anchor);
    void onARAnchorUpdated(std::shared_ptr<VROARAnchor> anchor);
    void onARAnchorRemoved();
    
private:
    
    std::shared_ptr<VRONode> _pointOfView;
    std::shared_ptr<VROSceneController> _sceneController;
    
};

#endif /* VROARImageTrackingTest_h */
