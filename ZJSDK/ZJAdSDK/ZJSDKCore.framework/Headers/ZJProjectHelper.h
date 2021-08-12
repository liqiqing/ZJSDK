//
//  ZJProjectHelper.h
//
//  Created by Rare on 2021/7/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJProjectHelper : NSObject

///包名
+ (NSString *)bundleIdentifier;

///版本号
+ (NSString *)version;

///编译版本
+ (NSString *)build;

///项目名称
+ (NSString *)displayName;

@end

NS_ASSUME_NONNULL_END
