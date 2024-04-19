//
//  ZJSplashViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/16.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJSplashViewController.h"
#import "ZJAdLoadView.h"
#import <ZJSDK/ZJSplashAd.h>
#import "AppDelegate.h"
#import <ZJSDK/ZJAdSDK.h>

@interface ZJSplashViewController ()<ZJSplashAdDelegate>
@property(nonatomic,strong) ZJSplashAd *splashAd;
@property(nonatomic,strong) UIView *bottomView;
@end

@implementation ZJSplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_Splash1,AdId_Splash2,AdId_Splash3,AdId_Splash4,AdId_Splash5,AdId_Splash6,AdId_Splash7,AdId_Splash8,AdId_Splash9,AdId_Splash10,AdId_Splash11]];
}


-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.splashAd = [[ZJSplashAd alloc] initWithPlacementId:adId];
    self.splashAd.delegate = self;
    self.splashAd.fetchDelay = 5.0;
    self.splashAd.rootViewController = self;
    self.splashAd.customBottomView = self.bottomView;
    [self.splashAd loadAd];
}

-(void)showAd{
    if(self.splashAd){
        [self.splashAd showAdInWindow:[UIApplication sharedApplication].keyWindow];
    }
}


-(UIView *)bottomView{
    if (!_bottomView) {
        _bottomView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, kScreenWidth, 100)];
        _bottomView.backgroundColor = [UIColor whiteColor];
        
        UILabel *titleLabel = [[UILabel alloc]init];
        titleLabel.textColor = [UIColor redColor];
        titleLabel.font = [UIFont boldSystemFontOfSize:24];
        titleLabel.text = @"LOGO";
        [_bottomView addSubview:titleLabel];
        [titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.center.mas_equalTo(0);
        }];
    }
    return _bottomView;
}

#pragma mark - ZJSplashAdDelegate
/**
 *  开屏广告素材加载成功
 */
-(void)zj_splashAdDidLoad:(ZJSplashAd *)splashAd{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    [self logMessage:@"splashAdDidLoad"];
    [self logMessage:[splashAd valueForKey:@"logString"]];
}

/**
 *  开屏广告成功展示
 */
-(void)zj_splashAdSuccessPresentScreen:(ZJSplashAd *)splashAd{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"splashAdShow"];
}


/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked:(ZJSplashAd *)splashAd{
    
}

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed:(ZJSplashAd *)splashAd{
    [self logMessage:@"splashAdClosed"];
}


/**
 *  开屏广告即将关闭回调
 */
- (void)zj_splashAdWillClose:(ZJSplashAd *)splashAd{
    
}


/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground:(ZJSplashAd *)splashAd{
    
}

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd:(ZJSplashAd*)splashAd{
    
}

/**
 *  开屏广告错误
 */
- (void)zj_splashAdError:(ZJSplashAd *)splashAd withError:(NSError *)error{
    [self logMessage:[splashAd valueForKey:@"logString"]];
    NSArray *errors =  [self.splashAd getFillFailureMessages];
    NSLog(@"开屏广告所有错误信息 ====== %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"splashAdError : %@",error]];
}

/**
 *  开屏广告播放错误
 */
- (void)zj_splashAdDisplayError:(ZJSplashAd *)splashAd withError:(NSError *)error{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"zj_splashAdDisplayError"];
}

- (void)zj_splashAdDidRewardEffective:(ZJSplashAd *)splashAd withInfo:(NSDictionary *)info{
    [self logMessage:[NSString stringWithFormat:@"奖励触发，奖励信息信息 %@",info]];

}


-(void)dealloc{
    
}

@end
