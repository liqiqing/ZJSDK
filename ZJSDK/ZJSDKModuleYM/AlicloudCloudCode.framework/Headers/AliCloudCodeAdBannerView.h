//
//  AliCloudCodeAdBannerView.h
//  AlicloudCloudCode
//
//  Created by yannan on 2020/12/31.
//

#import <UIKit/UIKit.h>
#import "AliCloudCodeAdViewProtocol.h"

@class AliCloudCodeAdBannerView;

NS_ASSUME_NONNULL_BEGIN


@interface AliCloudCodeAdBannerView : UIView

/// 广告代理
@property (nonatomic, weak) id<AliCloudCodeAdBannerViewDelegate> adDelegate;

/// 设置rootViewController 作为广告点击后present的视图父视图使用，如果不传默认使用keywindow作为父视图
@property (nonatomic, weak) UIViewController *rootViewController;

/// banner轮播时间(秒) 设置的时间需>30s
@property (nonatomic, assign) NSTimeInterval loopInterval;

/// 广告加载数据
- (void)loadAdData;

/// 广告初始化构造函数
/// @param slotID slotID
/// @param adSize 传入广告尺寸 会按照传入的尺寸创建
- (instancetype)initWithSlotID:(NSString *)slotID adSize:(CGSize)adSize NS_DESIGNATED_INITIALIZER;





- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame  NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE; 
@end

NS_ASSUME_NONNULL_END
