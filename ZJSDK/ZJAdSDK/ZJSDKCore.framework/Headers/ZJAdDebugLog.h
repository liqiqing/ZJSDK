//
//  ZJAdDebugLog.h
//  ZJSDKCore
//
//  Created by Rare on 2022/2/24.
//

#import <Foundation/Foundation.h>
#import "ZJSDKAdEnum.h"
#import "ZJSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN
#define ZJ_BaseLog(level, frmt, ...) [ZJAdDebugLog level##LogWithFormat:@"[ZJSDK-%@]-[%s]:\n%@", ZJSDKVersion, #level , [NSString stringWithFormat:frmt, ##__VA_ARGS__]];
#define ZJ_DebugLog(frmt, ...) ZJ_BaseLog(debug,frmt, ##__VA_ARGS__)
#define ZJ_ErrorLog(frmt, ...) ZJ_BaseLog(error,frmt, ##__VA_ARGS__)
#define ZJ_WarningLog(frmt, ...) ZJ_BaseLog(warning,frmt, ##__VA_ARGS__)
@interface ZJAdDebugLog : NSObject

+ (void)debugLogWithFormat:(NSString *)format, ...;
+ (void)errorLogWithFormat:(NSString *)format, ...;
+ (void)warningLogWithFormat:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END
