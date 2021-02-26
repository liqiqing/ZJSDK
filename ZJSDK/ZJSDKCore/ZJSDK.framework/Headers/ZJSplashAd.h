//
//  ZJSplashAd.h
//  ZJSDK
//
//  Created by Robin on 2020/8/21.
//  Copyright © 2020 zj. All rights reserved.
//
#import <UIKit/UIKit.h>

#import "ZJAd.h"
#import <ZJSDKCoreFramewrok/ZJSplashAdProtocol.h>
//#import "ZJSplashAdProtocol.h"
#import "ZJSplashAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJSplashAd : ZJAd<ZJSplashAdProtocol>
{
    
}

@property(nonatomic,weak) id<ZJSplashAdDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
