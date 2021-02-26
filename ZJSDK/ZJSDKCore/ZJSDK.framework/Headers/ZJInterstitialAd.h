//
//  ZJInterstitialAd.h
//  ZJSDK
//
//  Created by Robin on 2020/10/16.
//  Copyright © 2020 zj. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <ZJSDK/ZJSDK.h>
#import "ZJAd.h"
#import <ZJSDKCoreFramewrok/ZJInterstitialAdProtocol.h>
NS_ASSUME_NONNULL_BEGIN
@class ZJInterstitialAd;
@protocol ZJInterstitialAdDelegate <NSObject>

- (void) zj_interstitialAdDidLoad:(ZJInterstitialAd*) ad;

- (void) zj_interstitialAdDidLoadFail:(ZJInterstitialAd*) ad error:(NSError * __nullable)error;

- (void) zj_interstitialAdDidPresentScreen:(ZJInterstitialAd*) ad;

- (void) zj_interstitialAdDidClick:(ZJInterstitialAd*) ad;

- (void) zj_interstitialAdDidClose:(ZJInterstitialAd*) ad;

- (void) zj_interstitialAdDetailDidClose:(ZJInterstitialAd*) ad;

- (void) zj_interstitialAdDidFail:(ZJInterstitialAd*) ad error:(NSError * __nullable)error;

@end

@interface ZJInterstitialAd : ZJAd<ZJInterstitialAdProtocol>

@property(nonatomic,weak) id<ZJInterstitialAdDelegate> delegate;



- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<ZJInterstitialAdDelegate>) delegate;


@end

NS_ASSUME_NONNULL_END
