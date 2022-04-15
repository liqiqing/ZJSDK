//
//  ZJSplashAd.h
//  ZJSDK
//
//  Created by Rare on 2022/2/28.
//  Copyright © 2022 zj. All rights reserved.
//

#import "ZJAd.h"
#import <ZJSDKCore/ZJSplashAdProtocol.h>
NS_ASSUME_NONNULL_BEGIN

@class ZJSplashAd;
@protocol ZJSplashAdDelegate <NSObject>
@optional
/**
 *  开屏广告素材加载成功
 */
- (void)zj_splashAdDidLoad:(ZJSplashAd *)splashAd;

/**
 *  开屏广告成功展示
 */
- (void)zj_splashAdSuccessPresentScreen:(ZJSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked:(ZJSplashAd *)splashAd;

/**
 *  开屏广告即将关闭回调
 */
- (void)zj_splashAdWillClose:(ZJSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed:(ZJSplashAd *)splashAd;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground:(ZJSplashAd *)splashAd;

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd:(ZJSplashAd *)splashAd;

/**
 *  开屏广告错误
 */
- (void)zj_splashAdError:(ZJSplashAd *)splashAd withError:(NSError *)error;

@end


@interface ZJSplashAd : ZJAd <ZJSplashAdProtocol>

@property (nonatomic, weak) id <ZJSplashAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
