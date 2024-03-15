//
//  TNXASDK.h
//  TNXASDK
//
//  Created by TNXASDK on 8/29/20.
//  Copyright © 2020 TNXASDK. All rights reserved.
// v2.6.0 tanx

#import <Foundation/Foundation.h>

@interface TNXASDK : NSObject

/// 配置自定义域名（需在初始化之前设置,本地会缓存）
/// @param domain 域名字符串 如：https://www.xxxxxx.com
+ (void)configureDomain:(NSString *)domain;

/// SDK初始化，异步请求tnxKey
/// @param completion 请求tnxKey的回调，tnxKey为返回值，如果失败，tnxKey为空字符串@“”
+ (void)init:(void (^)(NSString *tnxKey))completion;

/// SDK初始化，异步请求tnxKey和cValue
/// @param tnxKeyBlock 请求tnxKey的回调，tnxKey为返回值，如果失败，tnxKey为空字符串@“”
/// @param cValueBlock 请求cValue的回调，cValue为返回值，如果失败，cValue为nil
+ (void)init:(void (^)(NSString *tnxKey))tnxKeyBlock cValue:(void (^)(NSArray *cValue))cValueBlock;

/// 同步获得tnxKey，失败返回空字符串@“”
+ (NSString *)getTnxKey;

/// 获取SDK版本号
+ (NSString *)getSDKVersion;

/// 获得resetToken
+ (NSString *)getResetToken;

/// 同步获得cValue，失败返回nil
+ (NSArray *)getCValue;

/// 禁止采集cValue 不会初始化cValue 需在init前调用
+ (void)forbidCValue;
@end
