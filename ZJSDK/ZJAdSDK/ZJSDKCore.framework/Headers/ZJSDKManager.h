//
//  ZJSDKManager.h
//  ZJSDKCore
//
//  Created by Rare on 2022/2/22.
//

#import <Foundation/Foundation.h>
#import "ZJSDKAdEnum.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKManager : NSObject

+ (instancetype)shared;

- (void)registerAppId:(NSString*)appId;

@property (nonatomic, copy) void(^registrationCompleted)(BOOL completed, NSDictionary *info);

@property (nonatomic, assign, readonly) BOOL registerAppIdEnd;

@property (nonatomic, copy, readonly) NSString *appId;

@property (nonatomic, assign) ZJAdSDKLogLevel level;


- (void)registerPlatform:(NSString *)platform;

@end

NS_ASSUME_NONNULL_END
