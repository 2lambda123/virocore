//
//  VROPoseFilterLowPass.h
//  ViroKit
//
//  Created by Raj Advani on 2/27/19.
//  Copyright © 2019 Viro Media. All rights reserved.
//

#ifndef VROPoseFilterLowPass_h
#define VROPoseFilterLowPass_h

#include "VROPoseFilter.h"

/*
 Exponential (low-pass) filter for pose data.
 */
class VROPoseFilterLowPass : public VROPoseFilter {
public:
    
    VROPoseFilterLowPass(float trackingPeriodMs, float confidenceThreshold) :
        VROPoseFilter(trackingPeriodMs, confidenceThreshold) {}
    virtual ~VROPoseFilterLowPass() {}
    
    VROPoseFrame doFilter(const std::vector<VROPoseFrame> &frames, const VROPoseFrame &combinedFrame,
                          const VROPoseFrame &newFrame);

};

#endif /* VROPoseFilterLowPass_h */
