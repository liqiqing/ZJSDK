//
//  ZJNativeExpressFeedAdManagerDelegate.h
//  ZJSDK
//
//  Created by Rare on 2021/1/9.
//  Copyright © 2021 zj. All rights reserved.
//



@class ZJNativeExpressFeedAdManager,ZJNativeExpressFeedAd;
NS_ASSUME_NONNULL_BEGIN
@protocol ZJNativeExpressFeedAdManagerDelegate <NSObject>
@optional
///加载成功
- (void)ZJ_nativeExpressFeedAdManagerSuccessToLoad:(ZJNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)feedAdDataArray;

///加载失败
- (void)ZJ_nativeExpressFeedAdManager:(ZJNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end



NS_ASSUME_NONNULL_END

