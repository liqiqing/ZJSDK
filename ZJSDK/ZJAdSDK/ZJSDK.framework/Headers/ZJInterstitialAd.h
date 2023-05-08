//
//  ZJInterstitialAd.h
//  ZJSDK
//
//  Created by Rare on 2022/3/1.
//  Copyright © 2022 zj. All rights reserved.
//

#import <ZJSDK/ZJTierAd.h>
#import <ZJSDKCore/ZJInterstitialAdProtocol.h>
#import <ZJSDKCore/ZJInterstitialAdAdapter.h>

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

@interface ZJInterstitialAd : ZJTierAd<ZJInterstitialAdProtocol>

@property(nonatomic,weak) id<ZJInterstitialAdDelegate>delegate;

@property (nonatomic,strong,nullable)ZJInterstitialAdAdapter *currentAdapter;
@end

NS_ASSUME_NONNULL_END
