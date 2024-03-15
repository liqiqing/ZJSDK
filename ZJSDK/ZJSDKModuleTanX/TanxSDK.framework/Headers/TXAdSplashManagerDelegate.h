//
//  TXAdSplashManagerDelegate.h
//  TanxSDK
//
//  Created by guqiu on 2021/12/30.
//  Copyright © 2021 tanx.com. All rights reserved.
//

#ifndef TXAdSplashManagerDelegate_h
#define TXAdSplashManagerDelegate_h

#import "TXAdManagerDelegate.h"

@protocol TXAdSplashManagerDelegate <NSObject,TXAdManagerDelegate>


@optional

/// 开屏开始展示
- (void)onSplashShow;

/// 开屏关闭
- (void)onSplashClose;

/**
 *  方法已经废弃 ，请使用 onAdClick:（跳转逻辑已由 SDK 内部实现）
 *  @param webUrl 如果非空，需要接入方实现H5跳转
 */
- (void)onSplashClickWithWebUrl:(NSString *)webUrl DEPRECATED_MSG_ATTRIBUTE("该接口已废弃，跳转逻辑已由SDK内部实现，点击回调使用onAdClick:方法");

@end

#endif /* TXAdSplashManagerDelegate_h */
