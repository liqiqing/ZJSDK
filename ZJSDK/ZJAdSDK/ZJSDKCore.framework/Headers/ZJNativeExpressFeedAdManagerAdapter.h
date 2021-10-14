//
//  ZJNativeExpressFeedAdManagerAdapter.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/2.
//

#import "ZJCoreAdAdapter.h"
#import "ZJNativeExpressFeedAd.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@protocol ZJNativeExpressFeedAdManagerApterDelegate;
@interface ZJNativeExpressFeedAdManagerAdapter : ZJCoreAdAdapter
@property (nonatomic)CGSize adSize;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

@property (nonatomic, strong) NSArray<ZJNativeExpressFeedAd *> *data;

@property (nonatomic,weak) id <ZJNativeExpressFeedAdManagerApterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(ZJAdItemConfig *)adItemConfig size:(CGSize)size;


- (void)loadAdWithCount:(NSInteger)adCount;

- (void)removeCacheFeedAds;


- (void)ZJFeed_feedAdsManagerSuccessToLoad:(ZJNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)feedAdDataArray;
- (void)ZJFeed_feedAdsManager:(ZJNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

@protocol ZJNativeExpressFeedAdManagerApterDelegate <NSObject>
@optional
- (void)ZJFeed_feedAdsManagerSuccessToLoad:(ZJNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)feedAdDataArray;

- (void)ZJFeed_feedAdsManager:(ZJNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;
@end
NS_ASSUME_NONNULL_END
