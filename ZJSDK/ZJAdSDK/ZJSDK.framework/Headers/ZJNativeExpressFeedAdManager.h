//
//  ZJNativeExpressFeedAdManager.h
//  ZJSDK
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJAd.h"
#import <ZJSDKCore/ZJNativeExpressFeedAd.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJNativeExpressFeedAdManager ,ZJNativeExpressFeedAd;
@protocol ZJNativeExpressFeedAdManagerDelegate <NSObject>
@optional
///加载成功
- (void)ZJ_nativeExpressFeedAdManagerSuccessToLoad:(ZJNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)feedAdDataArray;

///加载失败
- (void)ZJ_nativeExpressFeedAdManager:(ZJNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end


@interface ZJNativeExpressFeedAdManager : ZJAd

@property (nonatomic, weak) id <ZJNativeExpressFeedAdManagerDelegate> delegate;

@property (nonatomic) CGSize adSize;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;


@property (nonatomic, strong ,readonly) NSArray <ZJNativeExpressFeedAd *> *data;


- (instancetype)initWithPlacementId:(NSString *)placementId size:(CGSize)size;

/**
 * 加载广告，建议最大个数不超过5个
 */
- (void)loadAdDataWithCount:(NSInteger)count;

@end




NS_ASSUME_NONNULL_END
