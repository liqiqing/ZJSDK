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

#if __has_include(<KSUSDKInfo/KSAdUserInfo.h>)
#import <KSUSDKInfo/KSAdUserInfo.h>
#else
#import "KSAdUserInfo.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface KSAdSDKManager : NSObject

/// SDK 版本号
@property (nonatomic, readonly, class) NSString *SDKVersion;

/// Auto play video on Non Wi-Fi environment or not, default is NO
@property (nonatomic, assign, class) BOOL dataFlowAutoStart;
/**
 * @brief start ad sdk
 * @param appId             ad app id
 */
/// 内容联盟SDK、广告联盟SDK使用
+ (void)setAppId:(NSString *)appId;
/// 仅使用电商联盟SDK，初始化时使用，appKey，wbIndex 需要联系商务申请
+ (KSAdErrorCode)startWithAppId:(NSString *)appId appKey:(NSString *)appKey wbIndex:(NSString *)wbIndex;

// optional
+ (void)setAppName:(NSString *)appName;
// optional
+ (void)setUserInfoBlock:(void(^)(KSAdUserInfo *))userInfoBlock;
// optional
+ (void)setAppTag:(NSString *)appTag;
// optional, enable personalized recommendation, default is YES
+ (void)setEnablePersonalRecommend:(BOOL)enable;
// optional, enable programmatic recommendation, default is YES
+ (void)setEnableProgrammaticRecommend:(BOOL)enable;
/// Configure user info.
/// @param age optional 年龄段
/// @param gender optional 性别
/// @param interest optional 兴趣标签
+ (void)setUserAge:(KSAdUserInfoThirdAgeType)age
            gender:(KSAdUserInfoThirdGengerType)gender
          interest:(NSString *_Nullable)interest;
/// Configure appInfo content.
/// @param prevTitle optional 内容标签（广告展示前文章标题）
/// @param postTitle optional 内容标签（广告展示后文章标题）
/// @param historyTitle optional 内容标签（用户最近浏览文章标题）
/// @param channel optional 频道标签
+ (void)setContentPrevTitle:(NSString *_Nullable)prevTitle
                  postTitle:(NSString *_Nullable)postTitle
               historyTitle:(NSString *_Nullable)historyTitle
                    channel:(NSString *_Nullable)channel;
// optional 媒体底价
+ (void)setCpmBidFloor:(NSInteger)cpmBidFloor;
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
