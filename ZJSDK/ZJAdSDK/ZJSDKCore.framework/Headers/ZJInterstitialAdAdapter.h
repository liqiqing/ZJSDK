//
//  ZJInterstitialAdAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//


#import <ZJSDKCore/ZJTierAdAdapter.h>
#import <ZJSDKCore/ZJInterstitialAdProtocol.h>
#import <ZJSDKCore/ZJInterstitialAdAdapterDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJInterstitialAdAdapter : ZJTierAdAdapter<ZJInterstitialAdProtocol>

@property(nonatomic,weak) id<ZJInterstitialAdAdapterDelegate> delegate;

- (void) zj_interstitialAdDidLoad;

- (void) zj_interstitialAdDidLoadFail:(NSError * __nullable)error;

- (void) zj_interstitialAdDidPresentScreen;

- (void) zj_interstitialAdDidClick;

- (void) zj_interstitialAdDidClose;

- (void) zj_interstitialAdDetailDidClose;

- (void) zj_interstitialAdDidFail:(NSError * __nullable)error;

@end

NS_ASSUME_NONNULL_END
