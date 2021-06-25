//
//  ZJAdItemConfig.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2020/12/22.
//

#import <Foundation/Foundation.h>
extern NSString * _Nonnull  const ADType_Splash;
extern NSString * _Nonnull  const ADType_Interstitial;
extern NSString * _Nonnull  const ADType_RewardVideo;
extern NSString * _Nonnull  const ADType_FeedFullVideo;
extern NSString * _Nonnull  const ADType_Banner;
extern NSString * _Nonnull  const ADType_Feed;
extern NSString * _Nonnull  const ADType_Feed1;
extern NSString * _Nonnull  const ADType_NativeAd;
extern NSString * _Nonnull  const ADType_ContentPage;
extern NSString * _Nonnull  const ADType_FullVideoAd;

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger,ZJAdPlatformType){
    ZJAdPlatform_None,
    ZJAdPlatform_CSJ,
    ZJAdPlatform_GDT,
    ZJAdPlatform_MTG,
    ZJAdPlatform_KS,
    ZJAdPlatform_ZJ,
    ZJAdPlatform_YM,
    ZJAdPlatform_WW,
};

@interface ZJAdItemConfig : NSObject<NSCoding>
@property(nonatomic,copy) NSString *zj_appID;
@property(nonatomic,copy) NSString *zj_adID;
@property(nonatomic,copy) NSString *appId;
@property(nonatomic,copy) NSString *adId;
@property(nonatomic,copy) NSString *adType;
@property(nonatomic,copy) NSString *platform;
@property(nonatomic,assign)ZJAdPlatformType platformType;
@property(nonatomic,strong) NSDictionary *params;

@property(nonatomic,assign)BOOL is_service;

-(instancetype) initWith:(NSDictionary *) dic;
@end

NS_ASSUME_NONNULL_END
