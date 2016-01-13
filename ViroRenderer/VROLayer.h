//
//  VROLayer.h
//  ViroRenderer
//
//  Created by Raj Advani on 10/13/15.
//  Copyright © 2015 Viro Media. All rights reserved.
//

#ifndef VROLayer_h
#define VROLayer_h

#include <stdio.h>
#include "VRORenderContext.h"
#include "VRORect.h"
#include <vector>
#include <stack>
#include <memory>
#include "VROByteBuffer.h"
#include "VROGeometry.h"
#include "VROMatrix4f.h"
#include "VRONode.h"
#include "VROMaterial.h"

class VROLayer : public VRONode {
    
public:
    
    VROLayer(const VRORenderContext &context);
    virtual ~VROLayer();
    
    virtual void setContents(UIImage *image);
    
    virtual void setFrame(VRORect frame);
    virtual void setBounds(VRORect bounds);
    virtual void setPosition(VROPoint point);
    
    VRORect getFrame() const;
    VRORect getBounds() const;
    VROPoint getPosition() const;
    
    std::shared_ptr<VROMaterial> getMaterial();
    
private:
    
    /*
     Position and size of the layer in 3D space or in its parent layer's
     2D space.
     */
    VRORect _frame;
    
    void onFrameUpdate();
    
};

#endif /* VROLayer_h */
