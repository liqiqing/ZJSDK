//
//  ZJDeviceHelper.h
//
//  Created by Rare on 2021/7/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJDeviceHelper : NSObject

///IDFA
+ (NSString *)IDFA;

///UUID
+ (NSString *)UUID;

///IDFV
+ (NSString *)IDFV;

///机型 e.g. @"iPhone7,1"
+ (NSString *)machine;

///手机型号 e.g. @"iPhone_6_Plus"
+ (NSString *)deviceModel;

///系统版本号 e.g. @"4.0"
+ (NSString *)systemVersion;

///系统名称  e.g. @"iOS"
+ (NSString *)systemName;

///设备名称（用户设置）e.g. "My iPhone"
+ (NSString *)userPhoneName;

///类型  e.g. @"iPhone", @"iPod touch"
+ (NSString *)model;

///获取运营商信息 eg:@"中国电信"
+ (NSString *)carrierInfo;

@end

NS_ASSUME_NONNULL_END
