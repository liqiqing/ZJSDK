//
//  ZJAdSDK.h
//  ZJSDK
//
//  Created by Rare on 2022/2/18.
//  Copyright © 2022 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJAdSDK : NSObject
/**
 SDK 注册接口，请在 app 初始化时调用。
 @param appId - 媒体ID
*/
+ (void)registerAppId:(NSString *)appId;


/**
 SDK 注册接口，请在 app 初始化时调用，首次调用，网络权限从不可用切换到可用，block可能会回调多次。
 @param appId - 媒体ID
 @param callback 初始化信息
*/
+ (void)registerAppId:(NSString*)appId callback:(void(^)(BOOL completed, NSDictionary *info))callback;

/**
 日志打印设置
 */
+ (void)setLogLevel:(ZJAdSDKLogLevel)level;


/**
 SDK版本号
*/
+ (NSString *)SDKVersion;

/**
 appId
*/
+ (NSString *)appId;


@end

NS_ASSUME_NONNULL_END
