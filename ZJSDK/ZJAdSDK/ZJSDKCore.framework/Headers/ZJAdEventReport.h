//
//  ZJAdEventReport.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import "ZJAdBaseNetworking.h"
#import "NSError+ZJAd.h"
NS_ASSUME_NONNULL_BEGIN

typedef NSString *ZJReportAdTypeString NS_STRING_ENUM;
FOUNDATION_EXPORT NSString * const ZJAdType_SPLASH;//开屏
FOUNDATION_EXPORT NSString * const ZJAdType_REWARD;//激励视频
FOUNDATION_EXPORT NSString * const ZJAdType_H5;//H5
FOUNDATION_EXPORT NSString * const ZJAdType_Banner;//banner
FOUNDATION_EXPORT NSString * const ZJAdType_News;//新闻资讯
FOUNDATION_EXPORT NSString * const ZJAdType_Interstitial;//插屏
FOUNDATION_EXPORT NSString * const ZJAdType_ExpressFullVideoFeed;//视频流 
FOUNDATION_EXPORT NSString * const ZJAdType_ContentVideo;//视频内容 
FOUNDATION_EXPORT NSString * const ZJAdType_NativeExpress;//信息流 
FOUNDATION_EXPORT NSString * const ZJAdType_Native;//原生渲染 
FOUNDATION_EXPORT NSString * const ZJAdType_FullScreenVideo;//全屏视频

typedef NSString *ZJEventString NS_STRING_ENUM;
FOUNDATION_EXPORT NSString * const ZJEvent_START;//开始调用
FOUNDATION_EXPORT NSString * const ZJEvent_Load;//加载成功
FOUNDATION_EXPORT NSString * const ZJEvent_Show;//展示成功
FOUNDATION_EXPORT NSString * const ZJEvent_Finish;//完成
FOUNDATION_EXPORT NSString * const ZJEvent_Click;//点击
FOUNDATION_EXPORT NSString * const ZJEvent_Error;//错误
FOUNDATION_EXPORT NSString * const ZJEvent_Other;//其他信息


@interface ZJAdEventReport : ZJAdBaseNetworking

//事件上报
+ (nullable NSURLSessionTask *)reportEventWithZjad_id:(NSString *)zjad_id adType:(ZJReportAdTypeString)adType event:(ZJEventString)event unionType:(NSString *)unionType zj_pm_id:(NSString *)zj_pm_id supplementMsg:(NSString * _Nullable )supplementMsg otherDic:(NSDictionary * _Nullable)otherDic callback:(void(^)(_Nullable id responseObject, NSError * _Nullable error))callback;



+ (NSString *)getTimestampSince1970;

@end

NS_ASSUME_NONNULL_END
