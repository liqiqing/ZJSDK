//
//  ZjRewardViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZjRewardViewController.h"
#import <ZJSDK/ZJRewardVideoAd.h>
@interface ZjRewardViewController ()<ZJRewardVideoAdDelegate>
{
   
}
@property(nonatomic,strong) ZJRewardVideoAd *rewardVideoAd;

@end

@implementation ZjRewardViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title=@"激励视频";
    
   [self.loadAdView appendAdID:@[@"KS90010001",@"c945709452",@"zjad_G8020744212936426",@"33011044",@"zjad_T945484376",@"zjad_M240919",@"zjad_iOS_ZR0001"]];
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.rewardVideoAd = [[ZJRewardVideoAd alloc] initWithPlacementId:adId userId:@"robin6666"];
    self.rewardVideoAd.delegate = self;
    [self.rewardVideoAd loadAd];
}



#pragma mark - ZJRewardVideoAdDelegate
/**
广告数据加载成功回调

@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdDidLoad:(ZJRewardVideoAd *)rewardedVideoAd{
    NSLog(@"%s",__FUNCTION__);
    //rewardedVideoAd.trans_id;
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:rewardedVideoAd.trans_id];
}
/**
视频数据下载成功回调，已经下载过的视频会直接回调

@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdVideoDidLoad:(ZJRewardVideoAd *)rewardedVideoAd{
    NSLog(@"%s",__FUNCTION__);
    //[self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
    //[self performSelector:@selector(showAd) withObject:nil afterDelay:0.3];
}

-(void) showAd{
    if(self.rewardVideoAd)
       [self.rewardVideoAd showAdInViewController:self];
}

/**
 视频广告展示

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidShow:(ZJRewardVideoAd *)rewardedVideoAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}



/**
 视频播放页关闭

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClose:(ZJRewardVideoAd *)rewardedVideoAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
    
    [self performSelector:@selector(reloadAd) withObject:nil afterDelay:0.5];
}

-(void) reloadAd{
    [self.rewardVideoAd loadAd];
}

/**
 视频广告信息点击

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClicked:(ZJRewardVideoAd *)rewardedVideoAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

- (void)zj_rewardVideoAdDidRewardEffective:(ZJRewardVideoAd *)rewardedVideoAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

/**
 视频广告视频播放完成

 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidPlayFinish:(ZJRewardVideoAd *)rewardedVideoAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}


/**
 视频广告各种错误信息回调

 @param rewardedVideoAd ZJRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)zj_rewardVideoAd:(ZJRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error{
    NSLog(@"%s",__FUNCTION__);
    
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
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
