//
//  ZJFullScreenVideoViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/27.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJFullScreenVideoViewController.h"
#import <ZJSDK/ZJFullScreenVideoAd.h>
@interface ZJFullScreenVideoViewController ()<ZJFullScreenVideoAdDelegate>
@property (nonatomic,strong)ZJFullScreenVideoAd *fullVideoAd;
@end

@implementation ZJFullScreenVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title=@"全屏视频";

    [self.loadAdView appendAdID:@[@"J6134483187"]];
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.fullVideoAd = [[ZJFullScreenVideoAd alloc] initWithPlacementId:adId];
    self.fullVideoAd.delegate = self;
    [self.fullVideoAd loadAd];
}

-(void) showAd{
    if(self.fullVideoAd)
        [self.fullVideoAd presentFullScreenVideoAdFromRootViewController:self];
    
}

//广告加载成功
- (void) zj_fullScreenVideoAdDidLoad:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告加载失败
- (void) zj_fullScreenVideoAdDidLoadFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

//广告展示
- (void) zj_fullScreenVideoAdDidShow:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告点击
- (void) zj_fullScreenVideoAdDidClick:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告关闭
- (void) zj_fullScreenVideoAdDidClose:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告详情页关闭
- (void) zj_fullScreenVideoAdDetailDidClose:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告错误
- (void) zj_fullScreenVideoAdDidFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

-(void)zj_fullScreenVideoAd:(ZJFullScreenVideoAd *)ad playerStatusChanged:(ZJMediaPlayerStatus)playerStatus{
    NSLog(@"%ld",playerStatus);
}

//广告详情页打开
- (void)zj_fullScreenVideoAdDetailDidPresent:(ZJFullScreenVideoAd*)ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

@end
