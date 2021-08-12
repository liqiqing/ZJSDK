//
//  ZJInterstitialAd.h
//  ZJSDK
//
//  Created by Robin on 2020/10/16.
//  Copyright © 2020 zj. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJAd.h>
#import <ZJSDKCore/ZJInterstitialAdProtocol.h>
NS_ASSUME_NONNULL_BEGIN
@class ZJInterstitialAd;
@protocol ZJInterstitialAdDelegate <NSObject>
@optional
///插屏广告加载成功
- (void)zj_interstitialAdDidLoad:(ZJInterstitialAd*)ad;

///插屏广告加载失败
- (void)zj_interstitialAdDidLoadFail:(ZJInterstitialAd*)ad error:(nullable NSError *)error;

///插屏广告展示成功回调
- (void)zj_interstitialAdDidPresentScreen:(ZJInterstitialAd*)ad;

///插屏广告点击回调
- (void)zj_interstitialAdDidClick:(ZJInterstitialAd*)ad;

///插屏广告关闭回调
- (void)zj_interstitialAdDidClose:(ZJInterstitialAd*)ad;

///插屏广告详情页关闭回调
- (void)zj_interstitialAdDetailDidClose:(ZJInterstitialAd*)ad;

///插屏广告其他错误回调
- (void)zj_interstitialAdDidFail:(ZJInterstitialAd*)ad error:(nullable NSError *)error;

@end

@interface ZJInterstitialAd : ZJAd<ZJInterstitialAdProtocol>

@property(nonatomic,weak) id<ZJInterstitialAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<ZJInterstitialAdDelegate>) delegate;

@end

NS_ASSUME_NONNULL_END
