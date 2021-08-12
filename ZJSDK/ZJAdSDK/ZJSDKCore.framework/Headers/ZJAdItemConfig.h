//
//  ZJAdItemConfig.h
//  ZJSDKCore
//
//  Created by Robin on 2020/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NSString *ZJAdTypeString NS_STRING_ENUM;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Splash;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Interstitial;
FOUNDATION_EXPORT NSString * const ZJ_ADType_RewardVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FeedFullVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Banner;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Feed;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Feed1;
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeAd;
FOUNDATION_EXPORT NSString * const ZJ_ADType_ContentPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FullVideoAd;

typedef NS_ENUM(NSInteger, ZJAdPlatformType) {
    ZJAdPlatform_None,
    ZJAdPlatform_CSJ,
    ZJAdPlatform_GDT,
    ZJAdPlatform_MTG,
    ZJAdPlatform_KS,
    ZJAdPlatform_ZJ,
    ZJAdPlatform_YM,
    ZJAdPlatform_WW,
};

@interface ZJAdItemConfig : NSObject <NSCoding>
@property (nonatomic, copy) NSString *zj_appID;
@property (nonatomic, copy) NSString *zj_adID;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *adId;
@property (nonatomic, copy) NSString *adType;
@property (nonatomic, copy) NSString *platform;
@property (nonatomic, assign) ZJAdPlatformType platformType;
@property (nonatomic, strong) NSDictionary *params;
@property (nonatomic, assign) BOOL is_service;
@property (nonatomic, assign) BOOL is_enable;
- (instancetype)initWith:(NSDictionary *)dic;
@end

NS_ASSUME_NONNULL_END
