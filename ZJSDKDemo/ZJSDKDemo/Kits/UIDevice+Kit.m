//
//  UIDevice+Kit.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/10/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "UIDevice+Kit.h"

@implementation UIDevice (Kit)

+(BOOL) isIphoneX{
    BOOL iPhoneXSeries = NO;
    if (UIDevice.currentDevice.userInterfaceIdiom != UIUserInterfaceIdiomPhone) {
        return iPhoneXSeries;
    }
    
    if (@available(iOS 11.0, *)) {
        UIWindow *mainWindow = [[[UIApplication sharedApplication] delegate] window];
        if (mainWindow.safeAreaInsets.bottom > 0.0) {
            iPhoneXSeries = YES;
        }
       }
    return iPhoneXSeries;

}

@end
