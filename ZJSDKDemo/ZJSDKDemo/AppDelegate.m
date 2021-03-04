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
#import "SplashViewController.h"
#import "Aspects.h"
@interface AppDelegate ()<SplashViewControllerDelegate>

@property(nonatomic,strong) UIWindow *showWindow;
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
    
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    
    SplashViewController *splashVC = [[SplashViewController alloc] init];
    splashVC.delegate = self;
    
   
    self.window.rootViewController = splashVC;
    
    [ZJAdSDK registerAppId:@"zj_20201014iOSDEMO"];
    
    //com.zj.shop.towmall.hwxs
    //zj_20201014iOSDEMO

   
    [self.window makeKeyAndVisible];
    
   
    return YES;
}

-(void) splashViewControllerClosed{
    UINavigationController *nc = [[UINavigationController alloc] initWithRootViewController:[[ViewController alloc] init]];
    self.window.rootViewController = nc;
    UIViewController *vc  = [[NSClassFromString(@"ZjSplashViewController") alloc] init];
    self.showWindow.rootViewController = vc;
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




@end
