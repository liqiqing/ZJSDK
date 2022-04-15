//
//  ZJInterstitialAdAdapterDelegate.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJInterstitialAdAdapter;
@protocol ZJInterstitialAdAdapterDelegate <NSObject>

- (void)zj_interstitialAdAdapterDidLoad:(ZJInterstitialAdAdapter *)adapter;

- (void)zj_interstitialAdAdapterDidLoadFail:(ZJInterstitialAdAdapter *)adapter error:(NSError * __nullable)error;

- (void)zj_interstitialAdAdapterDidPresentScreen:(ZJInterstitialAdAdapter *)adapter;

- (void)zj_interstitialAdAdapterDidClick:(ZJInterstitialAdAdapter *)adapter;

- (void)zj_interstitialAdAdapterDidClose:(ZJInterstitialAdAdapter *)adapter;

- (void)zj_interstitialAdAdapterDetailDidClose:(ZJInterstitialAdAdapter *)adapter;

- (void)zj_interstitialAdAdapterDidFail:(ZJInterstitialAdAdapter *)adapter error:(NSError * __nullable)error;
@end

NS_ASSUME_NONNULL_END
