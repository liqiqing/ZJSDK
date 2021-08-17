//
//  ZJNativeAd.h
//  ZJSDK
//
//  Created by Rare on 2021/3/29.
//  Copyright © 2021 zj. All rights reserved.
//

#import <ZJSDKCore/ZJAd.h>
#import <ZJSDKCore/ZJNativeAdObject.h>
#import <ZJSDKCore/ZJNativeAdView.h>
NS_ASSUME_NONNULL_BEGIN

@protocol ZJNativeAdDelegate <NSObject>
@optional

- (void)zj_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;

@end

@interface ZJNativeAd : ZJAd

@property (nonatomic, weak) id <ZJNativeAdDelegate> delegate;

- (void)loadAdWithCount:(NSInteger)adCount;

@end

NS_ASSUME_NONNULL_END
