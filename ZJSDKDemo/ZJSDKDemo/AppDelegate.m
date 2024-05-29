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
#import <ZJSDKCore/ZJCacheManager.h>
//#import <ZJSDKCore/ZJInvoker.h>

@interface AppDelegate ()<ZJSplashAdDelegate>

@property (nonatomic, strong) UIWindow *showWindow;

@property (nonatomic, strong) ZJSplashAd *splashAd;

@property (nonatomic, strong) UIView *bottomView;

@property (nonatomic) BOOL appHasLoaded;

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

    [ZJAdSDK registerAppId:ZJ_Appid];
//    [ZJAdSDK registerAppId:@"Z6010318419"];
    [ZJAdSDK setLogLevel:ZJAdSDKLogLevelDebug];
    NSString *version = [ZJAdSDK SDKVersion];
    NSLog(@"ZJSDK版本号：%@",version);

    self.showWindow.hidden = NO;
//    NSArray *method = [ZJInvoker getInstanceMethodList:@"MTGNativeAdvancedAd"];

    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    ZJHomeViewController *homeVC = [[ZJHomeViewController alloc]init];
    UINavigationController *nc = [[UINavigationController alloc] initWithRootViewController:homeVC];
    self.window.rootViewController = nc;
    [self.window makeKeyAndVisible];
    
    

    
    return YES;
}


- (void)applicationDidBecomeActive:(UIApplication *)application{
    if (!_appHasLoaded) {
        _appHasLoaded = YES;
        // 请求idfa，此方法在iOS15上需要放到applicationDidBecomeActive内执行，可能会被其他询问覆盖
        if (@available(iOS 14, *)) {
            // iOS14及以上版本需要先请求权限
            ATTrackingManagerAuthorizationStatus status = ATTrackingManager.trackingAuthorizationStatus;
            if (status == ATTrackingManagerAuthorizationStatusNotDetermined) {
                //用户未做选择或未弹窗
                dispatch_semaphore_t sem = dispatch_semaphore_create(0);
                [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
    //                if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
                        //是否允许获取idfa只影响广告投放精准度
                        dispatch_async(dispatch_get_main_queue(), ^{
                            [self showSplashAd];
                        });
    //                }
                    dispatch_semaphore_signal(sem);
                }];
                dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
            }else{
                [self showSplashAd];
                NSLog(@"ATT User not allowed");
            }
        }else{
            [self showSplashAd];
        }
    }
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

- (void)applicationWillTerminate:(UIApplication *)application{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}



-(void)showSplashAd{
    self.splashAd = [[ZJSplashAd alloc]initWithPlacementId:AdId_Splash1];
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
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.splashAd showAdInWindow:self.showWindow];
    });}

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


/**
 *  开屏广告播放错误
 */
- (void)zj_splashAdDisplayError:(ZJSplashAd *)splashAd withError:(NSError *)error{
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
