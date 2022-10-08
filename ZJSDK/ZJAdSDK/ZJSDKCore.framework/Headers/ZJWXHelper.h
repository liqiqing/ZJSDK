//
//  ZJWXHelper.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/9/27.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, ZJWXApiStatus) {
    ZJWXApiStatusNotIntegration = 0,       //**< 错误或未集成  */
    ZJWXApiStatusNotInstalledWX = 1,        //**< 集成了手机没有安装微信  */
    ZJWXApiStatusReady = 2,         //**< 集成且安装了微信  */
};
@interface ZJWXHelper : NSObject

+ (ZJWXApiStatus)weChatOpenApiStatus;

@end

NS_ASSUME_NONNULL_END
