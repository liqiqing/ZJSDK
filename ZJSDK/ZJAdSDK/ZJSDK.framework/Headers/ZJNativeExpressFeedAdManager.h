//
//  ZJNativeExpressFeedAdManager.h
//  ZJSDK
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import <ZJSDKCore/ZJAd.h>
#import "ZJNativeExpressFeedAdManagerDelegate.h"
#import <ZJSDKCore/ZJNativeExpressFeedAd.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJNativeExpressFeedAd;
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


@property (nonatomic, strong) NSArray <ZJNativeExpressFeedAd *> *data;


- (instancetype)initWithPlacementId:(NSString *)placementId size:(CGSize)size;

/**
 * 加载广告，建议最大个数不超过5个
 */
- (void)loadAdDataWithCount:(NSInteger)count;

@end




NS_ASSUME_NONNULL_END
