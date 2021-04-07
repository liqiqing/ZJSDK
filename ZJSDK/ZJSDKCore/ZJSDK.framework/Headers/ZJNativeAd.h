//
//  ZJNativeAd.h
//  ZJSDK
//
//  Created by Rare on 2021/3/29.
//  Copyright © 2021 zj. All rights reserved.
//

#import <ZJSDKCoreFramewrok/ZJAd.h>
#import <ZJSDKCoreFramewrok/ZJNativeAdProtocol.h>
#import <ZJSDKCoreFramewrok/ZJNativeAdObject.h>
#import <ZJSDKCoreFramewrok/ZJNativeAdView.h>
NS_ASSUME_NONNULL_BEGIN

@protocol ZJNativeAdDelegate <NSObject>

@optional
- (void)zj_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;

@end

@interface ZJNativeAd : ZJAd <ZJNativeAdProtocol>

@property (nonatomic,weak)id <ZJNativeAdDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
