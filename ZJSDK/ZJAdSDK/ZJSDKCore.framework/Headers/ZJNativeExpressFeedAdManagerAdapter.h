//
//  ZJNativeExpressFeedAdManagerAdapter.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/2.
//

#import <ZJSDKCore/ZJMultipleAdAdapter.h>
#import "ZJNativeExpressFeedAd.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@protocol ZJNativeExpressFeedAdManagerApterDelegate;
@interface ZJNativeExpressFeedAdManagerAdapter : ZJMultipleAdAdapter
@property (nonatomic)CGSize adSize;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

@property (nonatomic, strong) NSArray<ZJNativeExpressFeedAd *> *data;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;


@property (nonatomic,weak) id <ZJNativeExpressFeedAdManagerApterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(ZJAdUnitModel *)adItemConfig size:(CGSize)size;


- (void)loadAdWithCount:(NSInteger)adCount;



- (void)ZJFeed_feedAdsManagerSuccessToLoad:(ZJNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)multipleResultObject;
- (void)ZJFeed_feedAdsManager:(ZJNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

@protocol ZJNativeExpressFeedAdManagerApterDelegate <NSObject>
@optional
- (void)ZJFeed_feedAdsManagerSuccessToLoad:(ZJNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)multipleResultObject;

- (void)ZJFeed_feedAdsManager:(ZJNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;
@end
NS_ASSUME_NONNULL_END
