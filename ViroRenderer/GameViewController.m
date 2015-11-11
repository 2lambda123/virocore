//
//  GameViewController.m
//  ViroRenderer
//
//  Created by Raj Advani on 10/13/15.
//  Copyright © 2015 Raj Advani. All rights reserved.
//

#import "GameViewController.h"
#import "SharedStructures.h"
#import "VROAnimation.h"
#import "VRORenderContextMetal.h"
#import "VROScene.h"
#import "VROLayer.h"
#import "VROMath.h"
#import "VROImageUtil.h"
#import "VROView.h"

@implementation GameViewController
{
    // view
    MTKView *_view;
    
    VROScene *_scene;
    VROView *_testView;
}

- (void)setupRendererWithView:(MTKView *)view context:(VRORenderContext *)renderContext {
    [self _loadAssetsWithContext:renderContext];
}

- (void)shutdownRendererWithView:(MTKView *)view {
    
}

- (void)_loadAssetsWithContext:(VRORenderContext *)context {
    _scene = new VROScene();
    
    size_t dataLength;
    int width, height;
    void *data = VROImageLoadTextureDataRGBA8888("boba", &dataLength, &width, &height);
    
    std::shared_ptr<VROLayer> layerA = std::make_shared<VROLayer>(*context);
    layerA->setFrame(VRORectMake(-1.0, 0, 2, 2.0, 2.0));
    layerA->setBackgroundColor({ 1.0, 0.0, 0.0, 1.0 });
    layerA->setContents(data, dataLength, width, height);
    
    std::shared_ptr<VROLayer> layerB = std::make_shared<VROLayer>(*context);
    layerB->setFrame(VRORectMake(1.0, 1.0, 1.0, 1.0));
    layerB->setBackgroundColor({ 0.0, 0.0, 1.0, 1.0 });
    layerB->setContents(data, dataLength, width, height);
    
    _testView = [[VROView alloc] initWithFrame:CGRectMake(0, 0, 50, 50) context:context];
    _testView.vroLayer->setFrame(VRORectMake(0, 0, 1.0, 1.0));
    
    [_testView setBackgroundColor:[UIColor clearColor]];
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 50, 50)];
    [label setText:@"Test"];
    [label setBackgroundColor:[UIColor clearColor]];
    [label setTextColor:[UIColor whiteColor]];
    [label setFont:[UIFont systemFontOfSize:16]];
    
    [_testView addSubview:label];
    [_testView update];
    
    _scene->addLayer(layerA);
    layerA->addSublayer(layerB);
    layerB->addSublayer(_testView.vroLayer);
    
    free (data);
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        layerA->setPosition({0.0, 0.0, 2.0});
    });
}

- (void)prepareNewFrameWithHeadViewMatrix:(matrix_float4x4)headViewMatrix {
    
}

- (void)renderEye:(VROEyeType)eye context:(VRORenderContext *)renderContext {
    _scene->render(*renderContext);
}

- (void)renderViewDidChangeSize:(CGSize)size context:(VRORenderContext *)context {

}

@end

