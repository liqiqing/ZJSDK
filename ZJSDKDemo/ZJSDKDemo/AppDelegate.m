//
//  AppDelegate.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/8/10.
//  Copyright © 2020 zj. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <ZJSDK/ZJAdSDK.h>
#import "Aspects.h"
#import <ZJSDK/ZJSDK.h>
//#import <GoogleMobileAds/GoogleMobileAds.h>
@interface AppDelegate ()<ZJSplashAdDelegate>

@property(nonatomic,strong) UIWindow *showWindow;

@property (nonatomic,strong)ZJSplashAd *splashAd;
@property (nonatomic,strong)UIView *bottomView;
@property (nonatomic,strong)UIImageView *splashBgImageView;
@end

@implementation AppDelegate

-(UIWindow*) showWindow{
    if(!_showWindow){
        _showWindow = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
        _showWindow.windowLevel = UIWindowLevelAlert +1;
        _showWindow.backgroundColor = [UIColor grayColor];
        //_showWindow.rootViewController
    }
    return _showWindow;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
//    [GADMobileAds sharedInstance].requestConfiguration.testDeviceIdentifiers = @[
//        kGADSimulatorID,
//        @"592b23553d0cbfab544da947731cabe3",
//        @"c31591525cf5c034ccb470fbf6aa8611"];
    
    [ZJAdSDK registerAppId:@"zj_20201014iOSDEMO"];
    NSString *version = [ZJAdSDK SDKVersion];
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    UINavigationController *nc = [[UINavigationController alloc] initWithRootViewController:[[ViewController alloc] init]];
    self.window.rootViewController = nc;
    [self.window makeKeyAndVisible];
    
    [self showSplashAd];
    return YES;
}



- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


-(void)showSplashAd{
    [self.window addSubview:self.splashBgImageView];
    
    self.splashAd = [[ZJSplashAd alloc]initWithPlacementId:@"J5621495755"];
    self.splashAd.fetchDelay = 5;
    self.splashAd.delegate = self;
    self.splashAd.bottomViewSize = self.bottomView.frame.size;
    [self.splashAd loadAd];
}

/**
 *  开屏广告素材加载成功
 */
-(void)zj_splashAdDidLoad:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg------加载成功");
    [self.splashAd showAdInWindow:[UIApplication sharedApplication].keyWindow withBottomView:self.bottomView];
    [self.splashBgImageView removeFromSuperview];
}

/**
 *  开屏广告成功展示
 */
-(void)zj_splashAdSuccessPresentScreen:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----展示成功");
    [self.splashBgImageView removeFromSuperview];
}

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----点击广告");
    [self.splashBgImageView removeFromSuperview];
}

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----开屏关闭");
    [self.splashBgImageView removeFromSuperview];
}

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----切换到后台");
    [self.splashBgImageView removeFromSuperview];
}

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd:(ZJSplashAd*)splashAd{
    NSLog(@"kpgg-----倒计时结束");
    [self.splashBgImageView removeFromSuperview];
}

/**
 *  开屏广告错误
 */
- (void)zj_splashAdError:(ZJSplashAd *)splashAd withError:(NSError *)error{
    NSLog(@"kpgg-----广告错误：%@",error);
    [self.splashBgImageView removeFromSuperview];
}

-(UIImageView *)splashBgImageView{
    if (!_splashBgImageView) {
        _splashBgImageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, ScreenWidth, ScreenHeight)];
        _splashBgImageView.image = [UIImage imageNamed:@"SplashBgX"];
        
    }
    return _splashBgImageView;
}

-(UIView *)bottomView{
    if (!_bottomView) {
        _bottomView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, ScreenWidth, 100)];
        _bottomView.backgroundColor = [UIColor whiteColor];
        
        UILabel *titleLabel = [[UILabel alloc]init];
        titleLabel.textColor = [UIColor brownColor];
        titleLabel.font = [UIFont boldSystemFontOfSize:24];
        titleLabel.text = @"LOGO";
        [_bottomView addSubview:titleLabel];
        [titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.center.mas_equalTo(0);
        }];
    }
    return _bottomView;
}


@end
