//
//  TXAdSDKInitializtion.h
//  TanxSDK-iOS
//
//  Created by guqiu on 2021/12/15.
//
//⚠️⚠️⚠️本类代码谨慎改动！必须CR

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TXAdSDKInitializtion : NSObject

/**
 *  SDK初始化
 *
 *  @param appID     媒体申请的APPID
 *  @param appKey   媒体获取的appKey
 *  @return       初始化的结果
 */
+ (BOOL)setupSDKWithAppID:(NSString *)appID
                andAppKey:(NSString *)appKey;

/**
 *  SDK初始化
 *
 *  @param appID                         媒体申请的APPID
 *  @param appKey                       媒体获取的appKey
 *  @param realTimeSwitch     媒体是否需要实时曝光（信息流满足曝光条件，立即曝光）
 *  @return                初始化的结果
 */
+ (BOOL)setupSDKWithAppID:(NSString *)appID
                andAppKey:(NSString *)appKey
       withRealTimeSwitch:(BOOL)realTimeSwitch;

@end

NS_ASSUME_NONNULL_END
