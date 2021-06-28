//
//  AliCloudCodeAdViewProtocol.h
//  AlicloudCloudCode
//
//  Created by yannan on 2021/1/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class AliCloudCodeAdSplashView;
@class AliCloudCodeAdInterstitialView;
@class AliCloudCodeAdBannerView;

NS_ASSUME_NONNULL_BEGIN


@protocol AliCloudCodeAdViewProtocol <NSObject>

/// 广告开始加载
/// @param aliccAdView aliccAdView
- (void)aliccAdViewLoadStart:(UIView *)aliccAdView;


/// 广告数据源加载成功
/// @param aliccAdView aliccAdView
- (void)aliccAdViewLoadSuccess:(UIView *)aliccAdView;


/// 广告数据源加载失败
/// @param aliccAdView aliccAdView
/// @param error error
- (void)aliccAdViewLoadFail:(UIView *)aliccAdView error:(NSError * __nullable)error;


/// 广告渲染成功
/// @param aliccAdView aliccAdView
- (void)aliccAdViewRenderSuccess:(UIView *)aliccAdView;


/// 广告渲染失败
/// @param aliccAdView aliccAdView
/// @param error error
- (void)aliccAdViewRenderFail:(UIView *)aliccAdView error:(NSError * __nullable)error;


/// 广告将要展示
/// @param aliccAdView aliccAdView
- (void)aliccAdViewWillVisible:(UIView *)aliccAdView;


/// 广告展示
/// @param aliccAdView aliccAdView
- (void)aliccAdViewDidVisible:(UIView *)aliccAdView;


/// 广告将要关闭
/// @param aliccAdView aliccAdView
- (void)aliccAdViewWillClose:(UIView *)aliccAdView;


/// 广告关闭
/// @param aliccAdView aliccAdView
- (void)aliccAdViewDidClose:(UIView *)aliccAdView;


@end




#pragma mark - 开屏广告代理
/// 开屏广告
@protocol AliCloudCodeAdSplashViewDelegate <AliCloudCodeAdViewProtocol>

/// 开屏广告: 广告点击事件
/// @param splashAdView splashAdView
- (void)aliccAdSplashViewDidClick:(AliCloudCodeAdSplashView *)splashAdView;

/// 开屏广告: "跳过"按钮点击
/// @param splashAdView splashAdView
- (void)aliccAdSplashViewDidClickSkip:(AliCloudCodeAdSplashView *)splashAdView;

/// 开屏广告: 倒计时结束事件
/// @param splashAdView splashAdView
- (void)aliccAdSplashViewCountdownToZero:(AliCloudCodeAdSplashView *)splashAdView;


@end


#pragma mark - 插屏广告代理
/// 插屏广告
@protocol AliCloudCodeAdInterstitialViewDelegate <AliCloudCodeAdViewProtocol>


/// 插屏广告: 广告点击事件
/// @param interstitialAdView interstitialAdView
- (void)aliccAdInterstitialViewDidClick:(AliCloudCodeAdInterstitialView *)interstitialAdView;


/// 插屏广告: "关闭"按钮点击事件
/// @param interstitialAdView interstitialAdView
- (void)aliccAdInterstitialViewCloseClick:(AliCloudCodeAdInterstitialView *)interstitialAdView;


@end



#pragma mark - banner广告代理
/// banner广告
@protocol AliCloudCodeAdBannerViewDelegate <AliCloudCodeAdViewProtocol>


/// banner广告: 广告点击事件
/// @param bannerAdView bannerAdView
- (void)aliccAdBannerViewDidClick:(AliCloudCodeAdBannerView *)bannerAdView;


/// banner广告: "关闭"按钮点击事件
/// @param bannerAdView bannerAdView
- (void)aliccAdBannerViewCloseClick:(AliCloudCodeAdBannerView *)bannerAdView;


@end







NS_ASSUME_NONNULL_END
