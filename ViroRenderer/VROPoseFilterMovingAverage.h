//
//  VROPoseFilterMovingAverage.h
//  ViroKit
//
//  Created by Raj Advani on 2/26/19.
//  Copyright © 2019 Viro Media. All rights reserved.
//

#ifndef VROPoseFilterMovingAverage_h
#define VROPoseFilterMovingAverage_h

#include "VROPoseFilter.h"

/*
 Simple moving average filter for joint data.
 */
class VROPoseFilterMovingAverage : public VROPoseFilter {
public:
    
    VROPoseFilterMovingAverage(float trackingPeriodMs, float confidenceThreshold) :
        VROPoseFilter(trackingPeriodMs, confidenceThreshold) {}
    virtual ~VROPoseFilterMovingAverage() {}
    
    virtual JointMap doFilter(const JointMap &jointWindow);
    
};

#endif /* VROPoseFilterMovingAverage_h */
