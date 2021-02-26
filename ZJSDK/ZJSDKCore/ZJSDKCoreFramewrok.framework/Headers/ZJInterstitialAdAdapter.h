//
//  ZJInterstitialAdAdapter.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/14.
//


#import "ZJCoreAdAdapter.h"
#import "ZJInterstitialAdProtocol.h"
#import "ZJInterstitialAdAdapterDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJInterstitialAdAdapter : ZJCoreAdAdapter<ZJInterstitialAdProtocol>

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
