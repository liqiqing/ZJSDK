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
    [self.loadAdView appendAdID:@[AdId_FullScreenVideo1,AdId_FullScreenVideo2,AdId_FullScreenVideo3,AdId_FullScreenVideo4,AdId_FullScreenVideo5,AdId_FullScreenVideo6]];
}

-(void)loadAd:(NSString*) adId{
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
- (void)zj_fullScreenVideoAdDidLoad:(ZJFullScreenVideoAd*)ad{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    NSArray *errors =  [self.fullVideoAd getFillFailureMessages];
    NSLog(@"所有错误信息 %@",errors);
    [self logMessage:@"fullScreenVideoAdDidLoad"];
    [self logMessage:[self.fullVideoAd valueForKey:@"logString"]];
}
//广告加载失败
- (void)zj_fullScreenVideoAdDidLoadFail:(ZJFullScreenVideoAd*)ad error:(NSError * __nullable)error{
    [self logMessage:[self.fullVideoAd valueForKey:@"logString"]];
    NSArray *errors =  [self.fullVideoAd getFillFailureMessages];
    NSLog(@"所有错误信息 %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"fullScreenVideoAdDidLoadFail : %@",error]];
}

//广告展示
- (void)zj_fullScreenVideoAdDidShow:(ZJFullScreenVideoAd *)ad{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"fullScreenVideoAdDidShow"];
}
//广告点击
- (void)zj_fullScreenVideoAdDidClick:(ZJFullScreenVideoAd *)ad{
    
}
//广告关闭
- (void)zj_fullScreenVideoAdDidClose:(ZJFullScreenVideoAd *)ad{
    [self logMessage:@"fullScreenVideoAdDidClose"];
}
//广告详情页关闭
- (void)zj_fullScreenVideoAdDetailDidClose:(ZJFullScreenVideoAd *)ad{
    
}
//广告错误
- (void)zj_fullScreenVideoAdDidFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error{
    [self logMessage:[NSString stringWithFormat:@"fullScreenVideoAdError : %@",error]];
}

//广告播放状态
-(void)zj_fullScreenVideoAd:(ZJFullScreenVideoAd *)ad playerStatusChanged:(ZJMediaPlayerStatus)playerStatus{
    
}

//广告详情页打开
- (void)zj_fullScreenVideoAdDetailDidPresent:(ZJFullScreenVideoAd*)ad{
    
}

@end
