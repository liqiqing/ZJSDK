//
//  ZJCoreAdAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJAdUnionItemModel.h>
#import <ZJSDKCore/ZJAdDebugLog.h>
#import <ZJSDKCore/ZJBiddingLossRelease.h>
#import <ZJSDKCore/ZJAdEventReport.h>
#import <ZJSDKCore/ZJSDKManager.h>
#import <ZJSDKCore/ZJBiddingReportModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJCoreAdAdapter : NSObject

@property(nonatomic, strong ,readonly) ZJAdUnitModel *config;
///结算价格
@property (nonatomic, strong) NSString *secondPrice;
@property (nonatomic, strong) NSString *cacheTime;


/// 平台判断广告是否已过期（如有）
- (BOOL)pmAdValid;

- (instancetype)initWithAdItemConfig:(ZJAdUnitModel *)adItemConfig;


+ (void)registerPlatform:(NSString*)platform adType:(NSString*)adType adapterClass:(NSString*) adapterClass;

//创建对象使用
+ (instancetype)createWithAdItemConfig:(ZJAdUnitModel *)adItemConfig;



+ (Class)getAdapterClass:(ZJAdUnitModel *)adItemConfig;


/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常，-2表示当前广告类型暂不支持实时竞价
 */
- (NSInteger)eCPM DEPRECATED_MSG_ATTRIBUTE("Use 'ZJNativeAdObject/ZJNativeExpressFeedAd -eCPM' instead.");;

/**
 返回广告的eCPM等级
 
 @return 成功返回一个包含数字的string，@""或nil表示无权限或后台异常
 */
- (NSString *)eCPMLevel;


/// 竞价成功后，将出价排名第二的价格回传
/// @param secondPrice 二价
- (void)biddingSuccess:(NSInteger )secondPrice;


/// 竞价上报，提供更多信息
/// @param model 上报内容model
- (void)biddingSuccessModel:(ZJBiddingReportModel *)model;

/// 竞价上报，提供更多信息
/// @param model 上报内容model
- (void)biddingLossModel:(ZJBiddingReportModel *)model;
/**
 *  竞败之后或未参竞调用
 *  @param price - 本次竞胜方出价（单位：分），必填
 *  @param reason - 广告竞败原因，必填
 *  @param adnID - 本次竞胜方渠道ID，选填；
 *         对于【adnID】字段回传支持3个枚举值，分别代表：
 *         1 - 输给优量汇其它广告，当优量汇目标价报价为本次竞价的最高报价时，可上报此值，仅对混合比价类型的开发者适用；
 *         2 - 输给第三方ADN，当其它ADN报价为本次竞价的最高报价时，可上报此值，您无需回传具体竞胜方渠道；
 *         3 - 输给自售广告主，当自售广告源报价为本次竞价的最高报价时，可上报此值，仅对有自售广告源的开发者使用；
 */
- (void)biddingLoss:(NSInteger)price reason:(ZJBiddingLossReason)reason winnerAdnID:(nullable NSString *)adnID;


+ (NSString*)getAdapterClass:(NSString *)platform adType:(NSString *)adType;
-(void)reportWithEvent:(ZJEventString)event supplementMsg:(nullable NSString *)supplementMsg;
@end

NS_ASSUME_NONNULL_END
