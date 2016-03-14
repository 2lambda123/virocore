//
//  VROTransformConstraint.h
//  ViroRenderer
//
//  Created by Raj Advani on 3/9/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#ifndef VROTransformConstraint_h
#define VROTransformConstraint_h

#include "VROConstraint.h"
#include <functional>

class VROTransformConstraint : public VROConstraint {
    
public:
    
    VROTransformConstraint(std::function<VROMatrix4f(const VRONode &node, VROMatrix4f transform,
                                                     const VRORenderContext &context)> function) :
        
        _function(function)
    {}
    
    VROMatrix4f getTransform(const VRONode &node, VROMatrix4f transform,
                             const VRORenderContext &context);
    
private:
    
    std::function<VROMatrix4f(const VRONode &node, VROMatrix4f transform,
                              const VRORenderContext &context)> _function;
    
};

#endif /* VROTransformConstraint_h */
