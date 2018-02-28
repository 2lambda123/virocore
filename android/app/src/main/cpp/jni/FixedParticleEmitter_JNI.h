//
//  FixedParticleEmitter_JNI.cpp
//  ViroRenderer
//
//  Copyright © 2018 Viro Media. All rights reserved.
//

#ifndef ANDROID_FIXED_PARTICLE_EMITTER_JNI_H
#define ANDROID_FIXED_PARTICLE_EMITTER_JNI_H

#include <jni.h>
#include <memory>
#include <VROFixedParticleEmitter.h>
#include "PersistentRef.h"

namespace FixedParticleEmitter {
    inline jlong jptr(std::shared_ptr<VROFixedParticleEmitter> emitter) {
        PersistentRef<VROFixedParticleEmitter> *emitter_p = new PersistentRef<VROFixedParticleEmitter>(emitter);
        return reinterpret_cast<intptr_t>(emitter_p);
    }

    inline std::shared_ptr<VROFixedParticleEmitter> native(jlong emitter_j) {
        PersistentRef<VROFixedParticleEmitter> *emitter_p
                = reinterpret_cast<PersistentRef<VROFixedParticleEmitter> *>(emitter_j);
        return emitter_p->get();
    }
}

#endif //ANDROID_FIXED_PARTICLE_EMITTER_JNI_H
