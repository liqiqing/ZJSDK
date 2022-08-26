//
//  AppDelegate.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/8/10.
//  Copyright © 2020 zj. All rights reserved.
//

#import "AppDelegate.h"
#import <ZJSDK/ZJAdSDK.h>
#import "Aspects.h"
#import <ZJSDK/ZJSDK.h>
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import "ZJSplashWindowVC.h"
#import "ZJHomeViewController.h"

@interface AppDelegate ()<ZJSplashAdDelegate>

@property (nonatomic, strong) UIWindow *showWindow;

@property (nonatomic, strong) ZJSplashAd *splashAd;

@property (nonatomic, strong) UIView *bottomView;

@end

@implementation AppDelegate

-(UIWindow*) showWindow{
    if(!_showWindow){
        _showWindow = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
        _showWindow.windowLevel = UIWindowLevelAlert +10000;
        _showWindow.backgroundColor = [UIColor clearColor];
        _showWindow.rootViewController = [[ZJSplashWindowVC alloc]init];
    }
    return _showWindow;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            // 获取到权限后，获取idfa
            [self showSplashAd];
        }];
    } else {
        // Fallback on earlier versions
    }

    [ZJAdSDK registerAppId:@"zj_20201014iOSDEMO"];
    [ZJAdSDK setLogLevel:ZJAdSDKLogLevelDebug];
    NSString *version = [ZJAdSDK SDKVersion];
    NSLog(@"ZJSDK版本号：%@",version);
    
    
    self.showWindow.hidden = NO;
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    ZJHomeViewController *homeVC = [[ZJHomeViewController alloc]init];
    UINavigationController *nc = [[UINavigationController alloc] initWithRootViewController:homeVC];
    self.window.rootViewController = nc;
    [self.window makeKeyAndVisible];
    
    

    
    return YES;
}



- (void)applicationWillResignActive:(UIApplication *)application{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}



-(void)showSplashAd{
    self.splashAd = [[ZJSplashAd alloc]initWithPlacementId:@"J8648995207"];
    self.splashAd.fetchDelay = 5;
    self.splashAd.delegate = self;
    self.splashAd.customBottomView = self.bottomView;
    self.splashAd.rootViewController = self.showWindow.rootViewController;
    [self.splashAd loadAd];
}

/**
 *  开屏广告素材加载成功
 */
-(void)zj_splashAdDidLoad:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----加载成功");
    NSArray *errors =  [self.splashAd getFillFailureMessages];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.splashAd showAdInWindow:self.showWindow];
    });
}

/**
 *  开屏广告成功展示
 */
-(void)zj_splashAdSuccessPresentScreen:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----展示成功");
}

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----点击广告");
}

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----开屏关闭");
    dispatch_async(dispatch_get_main_queue(), ^{
        self.showWindow.hidden = YES;
    });
}

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground:(ZJSplashAd *)splashAd{
    NSLog(@"kpgg-----切换到后台");
}

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd:(ZJSplashAd*)splashAd{
    NSLog(@"kpgg-----倒计时结束");
}

/**
 *  开屏广告错误
 */
- (void)zj_splashAdError:(ZJSplashAd *)splashAd withError:(NSError *)error{
    NSArray *errors =  [self.splashAd getFillFailureMessages];
    NSLog(@"开屏广告所有错误信息 %@",errors);
    dispatch_async(dispatch_get_main_queue(), ^{
        self.showWindow.hidden = YES;
    });
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



//收集打印日志
//- (void)redirectNSlogToDocumentFolder{
//    NSString *documentDirectory = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
//
//    NSDateFormatter *dateformat = [[NSDateFormatter  alloc]init];
//    [dateformat setDateFormat:@"yyyy-MM-dd-HH-mm-ss"];
//    NSString *fileName = [NSString stringWithFormat:@"LOG-%@.txt",[dateformat stringFromDate:[NSDate date]]];
//    NSString *logFilePath = [documentDirectory stringByAppendingPathComponent:fileName];
//
//    // 先删除已经存在的文件
//    NSFileManager *defaultManager = [NSFileManager defaultManager];
//    [defaultManager removeItemAtPath:logFilePath error:nil];
//
//    // 将log输入到文件
//    freopen([logFilePath cStringUsingEncoding:NSASCIIStringEncoding], "a+", stdout);
//    freopen([logFilePath cStringUsingEncoding:NSASCIIStringEncoding], "a+", stderr);
//}

@end
