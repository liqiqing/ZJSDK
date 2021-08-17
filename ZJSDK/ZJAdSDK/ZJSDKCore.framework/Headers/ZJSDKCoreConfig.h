//
//  ZJSDKCoreConfig.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import "ZJSDKAdEnum.h"
NS_ASSUME_NONNULL_BEGIN


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
