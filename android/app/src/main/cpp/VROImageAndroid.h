//
//  VROImageAndroid.h
//  ViroRenderer
//
//  Created by Raj Advani on 11/10/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining
//  a copy of this software and associated documentation files (the
//  "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to
//  the following conditions:
//
//  The above copyright notice and this permission notice shall be included
//  in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
//  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
//  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef ANDROID_VROIMAGEANDROID_H
#define ANDROID_VROIMAGEANDROID_H

#include "VROImage.h"
#include <jni.h>
#include <string>

class VROImageAndroid : public VROImage {

public:

    // This constructor can only really be used by the Renderer projects
    VROImageAndroid(std::string asset, VROTextureInternalFormat internalFormat);

    // This is the constructor that should be called from JNI
    VROImageAndroid(jobject jbitmap, VROTextureInternalFormat internalFormat);

    // This constructor attempts to get the format based on the bitmap properties/info
    VROImageAndroid(jobject jbitmap);


    virtual ~VROImageAndroid();

    int getWidth() const;
    int getHeight() const;
    unsigned char *getData(size_t *length);
    unsigned char *getGrayscaleData(size_t *length, size_t *stride);

private:

    int _width, _height;
    int _dataLength;
    unsigned char *_data;
    unsigned char *_grayscaleData;

    void convertRgbaToGrayscale(int32_t stride, uint8_t** out_grayscale_buffer);

};

#endif //ANDROID_VROIMAGEANDROID_H
