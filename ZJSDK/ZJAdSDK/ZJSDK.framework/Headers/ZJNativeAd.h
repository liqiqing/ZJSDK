//
//  ZJNativeAd.h
//  ZJSDK
//
//  Created by Rare on 2021/3/29.
//  Copyright © 2021 zj. All rights reserved.
//

//#import "ZJAd.h"
#import <ZJSDKCore/ZJNativeAdObject.h>
#import <ZJSDKCore/ZJNativeAdView.h>
#import "ZJMultipleAd.h"
NS_ASSUME_NONNULL_BEGIN

@protocol ZJNativeAdDelegate <NSObject>
@optional
/**自渲染广告加载回调*/
- (void)zj_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;

@end

@interface ZJNativeAd : ZJMultipleAd

@property (nonatomic, weak) id <ZJNativeAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
