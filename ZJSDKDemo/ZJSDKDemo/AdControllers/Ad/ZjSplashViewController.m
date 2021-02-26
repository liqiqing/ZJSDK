//
//  ZjSplashViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/16.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZjSplashViewController.h"
#import "ZJAdLoadView.h"
#import <ZJSDK/ZJSplashAd.h>
#import "AppDelegate.h"
@interface ZjSplashViewController ()<ZJSplashAdDelegate>
@property(nonatomic,strong) ZJSplashAd *splashAd;

@end

@implementation ZjSplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title=@"开屏广告";
   
    [self.loadAdView appendAdID:@[@"J8648995207",@"c887417368",@"zjad_G9040714184494018",@"zjad_T887381439",@"zjad_M235223"]];
    
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.splashAd = [[ZJSplashAd alloc] initWithPlacementId:adId];
    
    self.splashAd.delegate = self;
    self.splashAd.fetchDelay = 3.0;
    //self.splashAd.bottomViewSize = CGSizeMake([UIScreen mainScreen].bounds.size.width, 70);
    [self.splashAd loadAd];
}

-(void) showAd{
    if(self.splashAd){
        UIWindow *window = [UIApplication sharedApplication].windows.firstObject;
        
        UIView *bottomView = [UIView new];
        CGFloat width = [UIScreen mainScreen].bounds.size.width;
        bottomView.backgroundColor = UIColor.blueColor;
        bottomView.frame = CGRectMake(0, 0, width, 70);
        
        [self.splashAd showAdInWindow:window withBottomView:bottomView];
    }
}

#pragma mark - ZJSplashAdDelegate
/**
 *  开屏广告素材加载成功
 */
-(void)zj_splashAdDidLoad:(ZJSplashAd *)splashAd{
    //[self showAd];
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

/**
 *  开屏广告成功展示
 */
-(void)zj_splashAdSuccessPresentScreen:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd:(ZJSplashAd*)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

/**
 *  开屏广告错误
 */
- (void)zj_splashAdError:(ZJSplashAd *)splashAd withError:(NSError *)error{
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
