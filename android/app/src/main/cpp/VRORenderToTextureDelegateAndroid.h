//
//  VRORenderToTextureDelegateAndroid.h
//  ViroRenderer
//
//  Copyright © 2017 Viro Media. All rights reserved.
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

#ifndef VRO_RENDER_TEXTURE_DELEGATE_ANDROID_H
#define VRO_RENDER_TEXTURE_DELEGATE_ANDROID_H

#include <memory>
#include "VRORenderToTextureDelegate.h"
#include "VROAVRecorderAndroid.h"

class VROAVRecorderAndroid;
class VRORenderTarget;
class VRODriver;

class VRORenderToTextureDelegateAndroid : public VRORenderToTextureDelegate {
public:
    VRORenderToTextureDelegateAndroid(std::shared_ptr<VROAVRecorderAndroid> recorder) {
        _w_recorder = recorder;
    };

    virtual ~VRORenderToTextureDelegateAndroid() {};

    void didRenderFrame(std::shared_ptr<VRORenderTarget> input, std::shared_ptr<VRODriver> driver) {
        std::shared_ptr<VROAVRecorderAndroid> recorder = _w_recorder.lock();
        if (recorder) {
            recorder->onRenderedFrameTexture(input, driver);
        }
    }

private:
    std::weak_ptr<VROAVRecorderAndroid> _w_recorder;
};

#endif //VRO_RENDER_TEXTURE_DELEGATE_ANDROID_H
