//
//  VROViewCardboard.h
//  ViroRenderer
//
//  Created by Raj Advani on 4/28/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VROView.h"
#import "GCSCardboardView.h"

#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>

@interface VROViewCardboard : GCSCardboardView <GCSCardboardViewDelegate, VROView>

@end
