//
//  ZJBannerAdView.h
//  ZJSDK
//
//  Created by Rare on 2021/1/23.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJAd.h"
#import <ZJSDKCore/ZJBannerAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJBannerAdView;
@protocol ZJBannerAdViewDelegate <NSObject>
@optional
/**
 banner广告加载成功
 */
- (void)zj_bannerAdViewDidLoad:(ZJBannerAdView *)bannerAdView;

/**
 banner广告加载失败
 */
- (void)zj_bannerAdView:(ZJBannerAdView *)bannerAdView didLoadFailWithError:(NSError * _Nullable)error;

/**
 bannerAdView曝光回调
 */
- (void)zj_bannerAdViewWillBecomVisible:(ZJBannerAdView *)bannerAdView;

/**
 关闭banner广告回调
 */
- (void)zj_bannerAdViewDislike:(ZJBannerAdView *)bannerAdView;

/**
 点击banner广告回调
 */
- (void)zj_bannerAdViewDidClick:(ZJBannerAdView *)bannerAdView;

/**
 关闭banner广告详情页回调
 */
- (void)zj_bannerAdViewDidCloseOtherController:(ZJBannerAdView *)bannerAdView;

@end


@interface ZJBannerAdView : UIView<ZJBannerAdProtocol>

@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, weak, nullable) id <ZJBannerAdViewDelegate> delegate;

/**
   @params
   placementId - 广告位id
   viewController - 视图控制器
   adSize 展示的位置和大小
   interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize
                           interval:(NSInteger)interval;

/**
   @params
   placementId - 广告位id
   viewController - 视图控制器
   adSize 展示的位置和大小
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize;


- (NSArray *)getFillFailureMessages;
@end

NS_ASSUME_NONNULL_END
