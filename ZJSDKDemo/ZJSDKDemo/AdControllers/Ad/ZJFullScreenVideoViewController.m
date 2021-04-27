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
- (void) zj_FullScreenVideoAdDidLoad:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告加载失败
- (void) zj_FullScreenVideoAdDidLoadFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

//广告展示
- (void) zj_FullScreenVideoAdDidShow:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告点击
- (void) zj_FullScreenVideoAdDidClick:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告关闭
- (void) zj_FullScreenVideoAdDidClose:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告详情页关闭
- (void) zj_FullScreenVideoAdDetailDidClose:(ZJFullScreenVideoAd*) ad{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}
//广告错误
- (void) zj_FullScreenVideoAdDidFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error{
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

@end
