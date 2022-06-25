//
//  ZJAdUnionItemModel.h
//  ZJSDKCore
//
//  Created by Rare on 2022/2/24.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const ZJ_ADType_Splash;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Interstitial;
FOUNDATION_EXPORT NSString * const ZJ_ADType_NewInterstitial;
FOUNDATION_EXPORT NSString * const ZJ_ADType_RewardVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FeedFullVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Banner;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Feed;
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeAd;
FOUNDATION_EXPORT NSString * const ZJ_ADType_ContentPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FullVideoAd;

typedef NS_ENUM(NSInteger,ZJAdShowPriority){
    ZJAdShowPriority_normal,
    ZJAdShowPriority_weight
};
@class ZJAdUnitModel;
@interface ZJAdUnionItemModel : NSObject

@property (nonatomic, assign) ZJAdShowPriority showPriority;
@property (nonatomic, assign) NSInteger show_genre;

@property (nonatomic, copy) NSString *pd_price;

@property (nonatomic, assign) BOOL is_service;

@property (nonatomic, copy) NSArray <ZJAdUnitModel *>*tiers;

-(NSArray <ZJAdUnitModel *>*)parseUnionItems:(NSArray *)items;

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *zj_adID;

//辅助
@property (nonatomic, assign) NSInteger currentLevel;
@property (nonatomic, assign) NSInteger totalLevels;
@end

@interface ZJAdUnitModel : NSObject

@property (nonatomic, copy) NSString *adId;

@property (nonatomic, assign) BOOL is_enable;

@property (nonatomic, assign) BOOL is_service;
///当日限制次数
@property (nonatomic, assign) NSInteger limit_num;
///开始次数
@property (nonatomic, assign) NSInteger start_num;
///加载次数
@property (nonatomic, assign) NSInteger loaded_num;
///曝光次数
@property (nonatomic, assign) NSInteger exposed_num;

/// 正在被限制
@property (nonatomic, assign) BOOL is_being_limit;

@property (nonatomic, strong) NSString *error_strategy;

@property (nonatomic, assign) ZJAdPlatformType platformType;
@property (nonatomic, copy) NSString *platform;

///权重 在params中获取
@property (nonatomic, assign) NSInteger weight;
///其它参数
@property (nonatomic, strong) NSDictionary *params;

@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSString *zj_adID;

@property (nonatomic, copy) NSString *pd_price;

///辅助
@property (nonatomic, copy) NSString *adType;


@end



NS_ASSUME_NONNULL_END
