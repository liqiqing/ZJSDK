//
//  TXAdFeedTemplateConfig.h
//  TanxSDK
//
//  Created by guqiu on 2022/1/8.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TXAdShowMode) {
    TXAdShowModeNature = 0,     //默认显示自然模式
    TXAdShowModeDark,           //暗黑模式
};

typedef NS_ENUM(NSUInteger, TXAdPlayConfig) {
    
    TXAdPlayConfigNotAutoPlay = 1,        // 不自动播放
    TXAdPlayConfigAutoPlay = 2,           // 自动播放，默认
    TXAdPlayConfigWifiAutoPlay = 3,       // Wifi下自动播放
};

@interface TXAdFeedTemplateConfig : NSObject

/* -------------- 模版渲染，UI配置相关 -------------- */
/// 模板整体宽度，默认：(屏幕宽度- 2*horizontalPadding)，最大值为当前屏幕宽度
@property (nonatomic, assign) CGFloat templateWidth;

/// 左右padding，默认：15，如设置templateWidth，则不需要设置horizontalPadding
@property (nonatomic, assign) CGFloat horizontalPadding;

/// 图片圆角大小，暂时未使用
@property (nonatomic, assign) CGFloat picCorner;

/// 暗黑模式/正常模式，默认显示自然模式
@property (nonatomic, assign) TXAdShowMode showModeDefine;

/// 信息流卡片背景颜色，默认nil
@property (nonatomic, strong) UIColor *cardBgColor;

/// 自定义主标题字体，默认为0，10-最小字号，32.0最大字号
@property (nonatomic, assign) CGFloat mainTitleSize;

- (void)resetConfigTemplateWidthValues;

/* -------------- 自渲染，播放器控制配置 -------------- */
@property (nonatomic, assign) TXAdPlayConfig playConfig; // 默认，自动播放
@property (nonatomic, assign) BOOL setMute; // 默认，静音
@property (nonatomic, assign) BOOL replay;  // 默认 NO，单次播放

/// 下面属性loadingView、playView必须一起设置，单独设置不生效
@property (nonatomic, strong) UIView *loadingView; // 播放视频加载时展示，不传使用sdk默认图片
@property (nonatomic, strong) UIView *playView;    // 播放器暂停时展示，不传使用sdk默认图片

@end

NS_ASSUME_NONNULL_END
