//
//  ZJAdSDKInit.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAdSDKInit : NSObject

+(void)registerPlatform:(NSString *)platform  sdkInitClass:(NSString *) sdkInitClass;

+(instancetype)creatSdkInit:(NSString *)platform;

+(BOOL)hasInit;

+(BOOL)enableDefaultAudioSessionSetting;


-(void)platformInitCompelte:(NSString *) platform;


-(void)registerSDK:(nullable NSDictionary *)config;
-(void)registerSDK:(nullable NSDictionary *)config completeBlock:(nullable void (^) (BOOL complete))block;


@end

NS_ASSUME_NONNULL_END
