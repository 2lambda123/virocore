//
//  VROGeometrySubstrate.h
//  ViroRenderer
//
//  Created by Raj Advani on 11/18/15.
//  Copyright © 2015 Viro Media. All rights reserved.
//

#ifndef VROGeometrySubstrate_h
#define VROGeometrySubstrate_h

#include <stdio.h>
#include <vector>

class VROLight;
class VRORenderContext;
class VROMatrix4f;

/*
 Represents the geometry in the underlying graphics hardware.
 */
class VROGeometrySubstrate {
    
public:
    
    virtual ~VROGeometrySubstrate() {}
    
    virtual void render(const VRORenderContext &context,
                        const VROMatrix4f &rotation,
                        const VROMatrix4f &transform,
                        const std::vector<std::shared_ptr<VROLight>> &lights) = 0;

};

#endif /* VROGeometrySubstrate_h */
