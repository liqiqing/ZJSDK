//
//  KSAdCAID.h
//  KSAdSDK
//
//  Created by zhangchuntao on 2020/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdCAID : NSObject

+ (instancetype)shared;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (nullable NSString *)caid;
- (nullable NSNumber *)caidVersion;
- (nullable NSString *)lastCaid;
- (nullable NSNumber *)lastCaidVersion;

@end

NS_ASSUME_NONNULL_END
