//
//  ZJCommon.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/8/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJCommon : NSObject
/** 获取当前日期 */
+ (NSString *)getCurrentDate;
+ (NSString *)getCurrentTime;

/// 当前时间增加minuteOffset分钟
/// @param minuteOffset  增加的分钟数，为负数则为减少
+(NSString *)getCurrentTimeMinuteOffset:(NSInteger)minuteOffset;

/// 判断当前时间是否大于禁止请求的时间
/// @return 默认返回NSOrderedAscending（tA小于B）；NSOrderedSame（A等于B）；NSOrderedDescending（A大于B）；
/// @param timeA 时间A
/// @param timeB 时间B
+(NSComparisonResult)compareTimeA:(NSString*)timeA withTimeB:(NSString*)timeB;

// 判断字符串是否为空（YES：空）
+(BOOL)isEmptyString:(NSString *)string;
+(BOOL)isEmptyNumber:(NSNumber *)number;

+(UIWindow *)getCurrentWindow;
+ (UIWindow *)getKeyWindow;
+(UIViewController *)getCurrentVCFrom:(UIViewController *)vc;
+(UIViewController *)getCurrentVC;
//获取时间戳（毫秒）
+ (NSString *)getTimestampSince1970;
@end

NS_ASSUME_NONNULL_END
