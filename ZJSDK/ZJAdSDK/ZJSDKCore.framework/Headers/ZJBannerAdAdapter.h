//
//  ZJBannerAdAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/23.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>
#import "ZJBannerAdProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@class ZJBannerAdAdapter;
@protocol ZJBannerAdAdapterDelegate <NSObject>
/**
 banner广告加载成功
 */
- (void)zjad_bannerAdViewDidLoad:(ZJBannerAdAdapter *)bannerAd;

/**
 banner广告加载失败
 */
- (void)zjad_bannerAdView:(ZJBannerAdAdapter *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 bannerAdView曝光回调
 */
- (void)zjad_bannerAdViewWillBecomVisible:(ZJBannerAdAdapter *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)zjad_bannerAdViewDislike:(ZJBannerAdAdapter *)bannerAd;

/**
 点击banner广告回调
 */
- (void)zjad_bannerAdViewDidClick:(ZJBannerAdAdapter *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)zjad_bannerAdViewDidCloseOtherController:(ZJBannerAdAdapter *)bannerAd;

@end

@interface ZJBannerAdAdapter : ZJCoreAdAdapter<ZJBannerAdProtocol>
@property(nonatomic,weak) id<ZJBannerAdAdapterDelegate> delegate;
@property (nonatomic,weak)UIView *adView;


- (instancetype)initWithAdItemConfig:(ZJAdUnitModel *)adItemConfig
                      viewController:(UIViewController *)viewController
                              adSize:(CGSize)adSize;

- (instancetype)initWithAdItemConfig:(ZJAdUnitModel *)adItemConfig
                      viewController:(UIViewController *)viewController
                              adSize:(CGSize)adSize
                            interval:(NSInteger)interval;

/**
 banner广告加载成功
 */
- (void)zjad_bannerAdViewDidLoad:(ZJBannerAdAdapter *)bannerAd;

/**
 banner广告加载失败
 */
- (void)zjad_bannerAdView:(ZJBannerAdAdapter *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 bannerAdView曝光回调
 */
- (void)zjad_bannerAdViewWillBecomVisible:(ZJBannerAdAdapter *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)zjad_bannerAdViewDislike:(ZJBannerAdAdapter *)bannerAd;

/**
 点击banner广告回调
 */
- (void)zjad_bannerAdViewDidClick:(ZJBannerAdAdapter *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)zjad_bannerAdViewDidCloseOtherController:(ZJBannerAdAdapter *)bannerAd;


@end

NS_ASSUME_NONNULL_END
