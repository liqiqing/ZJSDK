//
//  ZjRewardViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJRewardViewController.h"
#import <ZJSDK/ZJSDK.h>
#import "ZJSplashWindowVC.h"
@interface ZJRewardViewController ()<ZJRewardVideoAdDelegate>
{
   
}
@property(nonatomic,strong) ZJRewardVideoAd *rewardVideoAd;

@end

@implementation ZJRewardViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
   [self.loadAdView appendAdID:@[@"J4008472476",@"c945709452",@"zjad_iOS_ZR0001",@"zjad_T945484376"]];
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.rewardVideoAd = [[ZJRewardVideoAd alloc] initWithPlacementId:adId userId:@"robin6666"];
    self.rewardVideoAd.reward_name = @"奖励欢乐豆";
    self.rewardVideoAd.reward_amount = 10;
    self.rewardVideoAd.extra = @"123";
    self.rewardVideoAd.delegate = self;
    [self.rewardVideoAd loadAd];
}

-(void) showAd{
    if(self.rewardVideoAd)
       [self.rewardVideoAd showAdInViewController:self];
}


-(void) reloadAd{
    [self.rewardVideoAd loadAd];
}

#pragma mark - ZJRewardVideoAdDelegate
/**
广告数据加载成功回调

@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdDidLoad:(ZJRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"rewardVideoAdDidLoad"];
}
/**
视频数据下载成功回调，已经下载过的视频会直接回调

@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdVideoDidLoad:(ZJRewardVideoAd *)rewardedVideoAd{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    NSArray *errors =  [self.rewardVideoAd getFillFailureMessages];
    NSLog(@"激励视频所有错误信息 %@",errors);
    [self logMessage:@"rewardVideoAdVideoDidLoad"];
    [self logMessage:[self.rewardVideoAd valueForKey:@"logString"]];
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
}


/**
 视频广告展示

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidShow:(ZJRewardVideoAd *)rewardedVideoAd{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"rewardVideoAdDidShow"];
}

//奖励触发
- (void)zj_rewardVideoAdDidRewardEffective:(ZJRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"RewardEffective"];
    NSLog(@"===== %@",rewardedVideoAd.trade_id);
    NSLog(@"%s",__FUNCTION__);
}
/**
 视频播放页关闭

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClose:(ZJRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"rewardVideoAdDidClose"];
}

/**
 视频广告信息点击

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClicked:(ZJRewardVideoAd *)rewardedVideoAd{
    
}


/**
 视频广告视频播放完成

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidPlayFinish:(ZJRewardVideoAd *)rewardedVideoAd{
    
}


/**
 视频广告各种错误信息回调

 @param rewardedVideoAd ZJRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)zj_rewardVideoAd:(ZJRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error{
    [self logMessage:[self.rewardVideoAd valueForKey:@"logString"]];
    NSArray *errors =  [self.rewardVideoAd getFillFailureMessages];
    NSLog(@"激励视频所有错误信息 %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"rewardedVideoAdError : %@",error]];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
