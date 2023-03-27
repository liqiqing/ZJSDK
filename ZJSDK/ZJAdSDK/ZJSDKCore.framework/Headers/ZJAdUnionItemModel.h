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
FOUNDATION_EXPORT NSString * const ZJ_ADType_SplashFullVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Interstitial;
FOUNDATION_EXPORT NSString * const ZJ_ADType_NewInterstitial;
FOUNDATION_EXPORT NSString * const ZJ_ADType_RewardVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FeedFullVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FullVideoAd;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Banner;
FOUNDATION_EXPORT NSString * const ZJ_ADType_News;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Feed;
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeAd;
FOUNDATION_EXPORT NSString * const ZJ_ADType_ContentPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FeedPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_HorizontalFeed;
FOUNDATION_EXPORT NSString * const ZJ_ADType_ImageTextPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_MiniParam;
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

@property (nonatomic, assign) NSInteger reward_ver;

@property (nonatomic, copy) NSArray <ZJAdUnitModel *>*tiers;

-(NSArray <ZJAdUnitModel *>*)parseUnionItems:(NSArray *)items;

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *zj_adID;

/// 是否为bidding广告位
@property (nonatomic, assign) BOOL is_bidding;
//辅助
@property (nonatomic, assign) NSInteger currentLevel;
@property (nonatomic, assign) NSInteger totalLevels;
@end

@interface ZJAdUnitModel : NSObject

@property (nonatomic, copy) NSString *adId;

@property (nonatomic, assign) BOOL is_enable;

@property (nonatomic, assign) BOOL is_service;


/// 时间戳
@property (nonatomic, copy) NSString *msel;

@property (nonatomic, assign) NSInteger reward_ver;
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
/// 网络错误限制策略
@property (nonatomic, strong) NSString *error_strategy;
/// 连续加载失败限制策略
@property (nonatomic, strong) NSString *load_strategy;

@property (nonatomic, assign) ZJAdPlatformType platformType;

@property (nonatomic, copy) NSString *platform;

///权重 在params中获取
@property (nonatomic, assign) NSInteger weight;
///其它参数
@property (nonatomic, strong) NSDictionary *params;

@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSString *zj_adID;

@property (nonatomic, copy) NSString *pd_price;

/// 是否为bidding广告位
@property (nonatomic, assign) BOOL is_bidding;

///辅助
@property (nonatomic, copy) NSString *adType;

///开屏样式：普通开屏  0，奖励式开屏 1，全屏视频开屏 2
@property (nonatomic, assign) NSInteger splash_type;

///屏蔽开屏摇一摇  仅GDT
@property (nonatomic, copy) NSNumber* shakable;

/**
 * 兜底视频跳转url     DSP
 *
 * 配了就加载兜底视频，小于五位加载不响应跳转，大于5位跳转
*/
@property (nonatomic, copy) NSString* lv_url;

/**
 * 兜底视频跳过时长    DSP
 *
 * 容错区间 (0-8)
 */
@property (nonatomic, copy) NSString* lv_sd;
@end



NS_ASSUME_NONNULL_END
