//
//  VROScreen.h
//  ViroRenderer
//
//  Created by Raj Advani on 10/23/15.
//  Copyright © 2015 Viro Media. All rights reserved.
//

#ifndef VROScreen_h
#define VROScreen_h

#include <stdio.h>
#include <UIKit/UIKit.h>

class VROScreen {
    
public:
    
    VROScreen(UIScreen *screen);
    
    int getWidth() const;
    int getHeight() const;
    
    float getWidthInMeters() const;
    float getHeightInMeters() const;
    
    void setBorderSizeInMeters(float screenBorderSize);
    float getBorderSizeInMeters() const;
    
private:
    
    UIScreen *_screen;
    CGFloat _scale;
    float _xMetersPerPixel;
    float _yMetersPerPixel;
    float _borderSizeMeters;
    
    float pixelsPerInch(UIScreen *screen);
    
};

#endif /* VROScreen_h */
