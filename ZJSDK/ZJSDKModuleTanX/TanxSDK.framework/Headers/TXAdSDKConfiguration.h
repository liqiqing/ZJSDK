//
//  TXAdSDKConfiguration.h
//  TanxSDK-iOS
//
//  Created by guqiu on 2021/12/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXAdSDKConfiguration : NSObject

/// 当前的APPID(只读)
@property (nonatomic, copy, readonly) NSString *appID;
@property (nonatomic, copy, readonly) NSString *appKey;

/// 当前是否禁止获取idfa(只读)
@property (nonatomic, assign, readonly) BOOL forbiddenUseIDFA;

/// 媒体自定义用户质量,字段格式{"key":["value"]}
@property (nonatomic, strong) NSDictionary<NSString *,NSArray *> * userTag;

/// 单例初始化
+ (instancetype)sharedConfiguration;

/// 获取SDK版本号
+ (NSString *)sdkVersion;

/// 获取SDK构建号
+ (double)sdkBuildNumber;

/// 获取SDK idfv
+ (NSString *)idfv;

/// 禁止广告填充，默认填充，针对所有广告生效
/// @param disableFill YES - 禁止广告填充
- (void)disallowAdPlacement:(BOOL)disableFill;

/// 是否禁止SDK获取idfa
/// @param forbiddened YES:禁止获取
- (void)forbiddenUseIDFA:(BOOL)forbiddened;

/// 禁止SDK获取idfa前提下，外部媒体通过该接口传递IDFA
/// @param idfa 外部传入的idfa
- (void)setSDKIDFA:(NSString *)idfa;

/// 外部媒体通过该接口传递IDFV
- (void)setSDKIDFV:(NSString *)idfv;

/// 外部媒体通过该接口传递经纬度
/// @param lon 经度
/// @param lat 纬度
- (void)setSDKLBSLon:(NSString *)lon lat:(NSString *)lat;


/*------------------注：下面方法、属性，已废弃------------------*/

/// 已废弃，信息流广告默认支持实时曝光
@property (nonatomic, assign) BOOL realTimeSwitch NS_UNAVAILABLE;

/// 已废弃，请使用TXAdFeedTemplateConfig.mainTitleSize
@property (nonatomic, assign) CGFloat titleSize  NS_UNAVAILABLE;

/// 是否可以设置字体大小，已废弃，请使用TXAdFeedTemplateConfig.mainTitleSize
@property (nonatomic, assign) BOOL customTitleSizeSwitch  NS_UNAVAILABLE;

/// 外部媒体通过该接口设置标题字体大小，已废弃，请使用TXAdFeedTemplateConfig.mainTitleSize
- (void)setTitleSize:(CGFloat )titleSize  NS_UNAVAILABLE;

/// 已废弃，请使用TXAdFeedTemplateConfig.mainTitleSize
- (void)closeCustomTitleSize  NS_UNAVAILABLE;

// 媒体用户ID 仅做透传给服务端，已废弃，请使用TXAdRewardVideoSlotModel.mediaUid
@property (nonatomic, strong) NSString * mediaUid NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
