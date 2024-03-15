//
//  TXAdSplashSlotModel.h
//  TanxSDK
//
//  Created by Evan on 2023/2/22.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import "TXAdSlotModel.h"
#import <UIKit/UIKit.h>

@interface TXAdSplashSlotModel : TXAdSlotModel

/// 请求出错后最大支持的重试次数
@property (nonatomic, assign) NSUInteger retryCount;

/// 允许开屏请求最长时间(推荐设置3秒)
@property (nonatomic, assign) NSTimeInterval waitSyncTimeout;

/// 允许开屏在曝光后，发起预请求广告数据，默认YES
@property (nonatomic, assign) BOOL autoPreLoadData;

/**----------------------------------- 模版UI配置 ------------------------------------**/
/// 跳转按钮颜色
@property (nonatomic, strong) UIColor *jumpTitleColor;

/// 跳转按钮字号大小
@property (nonatomic, strong) UIFont *jumpTitleFont;

/// 最大倒计时
@property (nonatomic, assign) NSInteger maxCountDown;

@end


