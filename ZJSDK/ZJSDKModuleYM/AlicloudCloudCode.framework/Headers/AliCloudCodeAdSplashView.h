//
//  AliCloudCodeAdSplashView.h
//  AlicloudCloudCode
//
//  Created by yannan on 2020/12/31.
//

#import <UIKit/UIKit.h>
#import "AliCloudCodeAdViewProtocol.h"


@class AliCloudCodeAdSplashView;

NS_ASSUME_NONNULL_BEGIN


@interface AliCloudCodeAdSplashView : UIView

/// 广告代理
@property (nonatomic, weak) id<AliCloudCodeAdSplashViewDelegate> adDelegate;

/// 设置rootViewController 作为广告点击后present的视图父视图使用，如果不传默认使用keywindow作为父视图
@property (nonatomic, weak) UIViewController *rootViewController;


/// 广告初始化构造函数
/// @param slotID slotID
/// @param adSize 传入广告尺寸 会按照传入的尺寸创建
/// @param isFullScreen 是否全屏展示
- (instancetype)initWithSlotID:(NSString *)slotID adSize:(CGSize)adSize isFullScreen:(BOOL)isFullScreen NS_DESIGNATED_INITIALIZER;


/// 创建广告
- (void)loadAdData;

/// 手动移除广告
- (void)removeSplashView;


/*

 非全屏模式
_____________________
|                   |
|  素材展示区域       |
|  建议比例保持2:3    |
|                   |
|                   |
|                   |
|                   |
|                   |
|                   |
|___________________|
|                   |
|  自定义区域         |
|                   |
|___________________|
           

全屏模式
_____________________
|                   |
|                   |
|                   |
|                   |
|                   |
|    素材展示区域     |
|                   |
|                   |
|                   |
|                   |
|                   |
|                   |
|                   |
|___________________|
 
*/

/// 设置开屏广告自定义View
/// 注意: 仅当非全屏模式下设置有用，且自定义View设置的高度要尽量保证素材展示区域比例为2:3
/// 布局在当前开屏广告底部用于放置logo等自定义素材，宽度是当前开屏广告的宽度，高度可以自定义
/// @param view 自定义view
/// @param height 设置自定view的高度 设置的高度要尽量保证上部素材展示区域比例为2:3
- (void)setCustomView:(UIView *)view viewHeight:(CGFloat)height;



- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame  NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE; 
@end

NS_ASSUME_NONNULL_END
