//
//  KSAdSDKManager.h
//  KSAdSDK
//
//  Created by 徐志军 on 2019/8/28.
//  Copyright © 2019 KuaiShou. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<KSUSDKInfo/KSAdSDKError.h>)
#import <KSUSDKInfo/KSAdSDKError.h>
#else
#import "KSAdSDKError.h"
#endif

#if __has_include(<KSUDefine/KSAdSDKLogLevelDefine.h>)
#import <KSUDefine/KSAdSDKLogLevelDefine.h>
#else
#import "KSAdSDKLogLevelDefine.h"
#endif

#if __has_include(<KSUPermission/KSAdPermission.h>)
#import <KSUPermission/KSAdPermission.h>
#else
#import "KSAdPermission.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class KSAdUserInfo;

@interface KSAdSDKManager : NSObject

/// SDK 版本号
@property (nonatomic, readonly, class) NSString *SDKVersion;

/// Auto play video on Non Wi-Fi environment or not, default is NO
@property (nonatomic, assign, class) BOOL dataFlowAutoStart;

/**
 * @brief start ad sdk
 * @param appId             ad app id
 */
+ (void)setAppId:(NSString *)appId;
// optional
+ (void)setAppName:(NSString *)appName;
// optional
+ (void)setUserInfoBlock:(void(^)(KSAdUserInfo *))userInfoBlock;
// optional
+ (void)setAppTag:(NSString *)appTag;
// optional, enable personalized recommendation, default is YES
+ (void)setEnablePersonalRecommend:(BOOL)enable;
/**
 Configure development mode.
 @param level : default KSAdSDKLogLevelNone
 */
// optional
+ (void)setLoglevel:(KSAdSDKLogLevel)level;

+ (void)setAutoHideUIRemoteKeyboardWindow:(BOOL)autoHideUIRemoteKeyboardWindow;

// optional, disable use location status, default is NO
+ (void)setDisableUseLocationStatus:(BOOL)disable;

+ (void)setLocationBlock:(LocationBlock)locationBlock;

// optional, disable use phone status, default is NO
+ (void)setDisableUsePhoneStatus:(BOOL)disable;

+ (void)setIdfaBlock:(IdfaBlock)idfaBlock;

+ (void)setIdfvBlock:(IdfvBlock)idfvBlock;

// optional, disable use network status, default is NO
+ (void)setDisableUseNetworkStatus:(BOOL)disable;

+ (NSString *)appId;

+ (NSString *)deviceId; //获取did

@end

NS_ASSUME_NONNULL_END
