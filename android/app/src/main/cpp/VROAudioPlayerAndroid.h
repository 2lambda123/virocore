//
//  VROAudioPlayerAndroid.h
//  ViroRenderer
//
//  Created by Raj Advani on 11/17/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#ifndef ANDROID_VROAUDIOPLAYERANDROID_H
#define ANDROID_VROAUDIOPLAYERANDROID_H

#include "VROAudioPlayer.h"
#include "VROAVPlayer.h"
#include <memory>
#include <string>
#include <VROSoundData.h>

class VROAudioPlayerAndroid : public VROAudioPlayer,
                              public VROAVPlayerDelegate,
                              public VROSoundDataDelegate,
                              public std::enable_shared_from_this<VROAudioPlayerAndroid> {

public:

    // If creating a VROAudioPlayerAndroid w/ data, use the static initializer.
    static std::shared_ptr<VROAudioPlayerAndroid> create(std::shared_ptr<VROSoundData> data);

    VROAudioPlayerAndroid(std::string fileName);
    VROAudioPlayerAndroid(std::shared_ptr<VROSoundData> data);
    virtual ~VROAudioPlayerAndroid();

    void setLoop(bool loop);
    void play();
    void pause();
    void setVolume(float volume);
    void setMuted(bool muted);
    void seekToTime(float seconds);
    void setDelegate(std::shared_ptr<VROSoundDelegateInternal> delegate);

    #pragma mark - VROAVPlayerDelegate
    virtual void onPrepared();
    virtual void onFinished();

    #pragma mark VROSoundDataDelegate Implementation
    void dataIsReady();

private:

    void setup();

    VROAVPlayer *_player;
    std::shared_ptr<VROSoundData> _data;

};

#endif //ANDROID_VROAUDIOPLAYERANDROID_H
