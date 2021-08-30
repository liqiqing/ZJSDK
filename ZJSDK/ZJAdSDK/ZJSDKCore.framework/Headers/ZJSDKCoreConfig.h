//
//  ZJSDKCoreConfig.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import "ZJSDKAdEnum.h"
#import "ZJSDKDefines.h"
NS_ASSUME_NONNULL_BEGIN

#define ZJ_BaseLog(level, frmt, ...) [ZJSDKCoreConfig level##LogWithFormat:@"[ZJSDK-%@]-[%s]:\n%@", ZJSDKVersion, #level , [NSString stringWithFormat:frmt, ##__VA_ARGS__]];
#define ZJ_AllLog(frmt, ...) ZJ_BaseLog(all,frmt, ##__VA_ARGS__)
#define ZJ_ErrorLog(frmt, ...) ZJ_BaseLog(error,frmt, ##__VA_ARGS__)
#define ZJ_WarningLog(frmt, ...) ZJ_BaseLog(warning,frmt, ##__VA_ARGS__)

@interface ZJSDKCoreConfig : NSObject

+ (instancetype)shared;

@property (nonatomic, copy) NSString *AppId;

@property (nonatomic, copy) NSString *secretStr;


@property (nonatomic, assign) ZJAdSDKLogLevel level;

+ (void)allLogWithFormat:(NSString *)format, ...;
+ (void)errorLogWithFormat:(NSString *)format, ...;
+ (void)warningLogWithFormat:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END
