//
//  AliCloudCodeAdSDK.h
//  AlicloudCloudCode
//
//  Created by yannan on 2020/12/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AliCloudCodeAdSDK : NSObject


/// 渠道ID
/// @param channelID 渠道ID
/// @param mediaID 媒体ID
+ (void)setChannelID:(NSString *)channelID mediaID:(NSString *)mediaID;

/// 日志开关
/// @param enable 开关
+ (void)setLogEnable:(BOOL)enable;


/// SDK 初始化
/// @param callBack 初始化状态回调
+ (void)sdkInit:(void (^)(BOOL isSuccess, NSError * _Nullable error))callBack;

/// 云码SDK设备标识符唯一标识
+(NSString *)utdid;

/// 获取云码SDK版本号
+ (NSString *)getVersion;


@end

NS_ASSUME_NONNULL_END
