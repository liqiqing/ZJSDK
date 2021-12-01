//
//  ZjSDK.h
//  ZJSDK
//
//  Created by Robin on 2020/8/18.
//  Copyright © 2020 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKCoreConfig.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJAdSDK : NSObject
/**
 SDK 注册接口，请在 app 初始化时调用。
 @param appId - 媒体ID
*/
+ (void)registerAppId:(NSString *)appId;


+ (BOOL)hasInit;

/**
 在播放音频时是否使用SDK内部对AVAudioSession设置的category及options，默认使用，若不使用，SDK内部不做任何处理，由调用方在展示广告时自行设置；
 SDK设置的category为AVAudioSessionCategoryAmbient，options为AVAudioSessionCategoryOptionDuckOthers
 */
+ (void)enableDefaultAudioSessionSetting:(BOOL)enabled;




/**
 SDK版本号
*/
+ (NSString *)SDKVersion;


/**
 日志打印设置
 */
+ (void)setLogLevel:(ZJAdSDKLogLevel)level;

@end

NS_ASSUME_NONNULL_END
