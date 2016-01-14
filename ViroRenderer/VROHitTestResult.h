//
//  VROHitTestResult.h
//  ViroRenderer
//
//  Created by Raj Advani on 1/13/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#ifndef VROHitTestResult_h
#define VROHitTestResult_h

#include "VROVector3f.h"
#include <memory>

class VROGeometry;

class VROHitTestResult {
    
public:
    
    VROHitTestResult(std::shared_ptr<VROGeometry> geometry, VROVector3f location) :
        _geometry(geometry),
        _location(location)
    {}
    
    ~VROHitTestResult() {}
    
    std::shared_ptr<VROGeometry> getGeometry() const {
        return _geometry;
    }
    
    VROVector3f getLocation() const {
        return _location;
    }
    
private:
    
    std::shared_ptr<VROGeometry> _geometry;
    VROVector3f _location;
    
};

#endif /* VROHitTestResult_h */
