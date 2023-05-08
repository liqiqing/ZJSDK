//
//  ZJMiniParamAdProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/9/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJMiniParamAdProtocol <NSObject>


/// 向微信注册
/// - Parameters:
///   - appid:微信appid
///   - universalLink: 通用链接
-(BOOL)registerWXApp:(NSString *)appid universalLink:(NSString *)universalLink;


/// 先确保微信已注册再去唤起小程序
/// - Parameters:
///   - orgId: 小程序原始id
///   - path: 小程序路径
-(void)wakeUpMiniParam:(NSString *)orgId path:(nullable NSString *)path;

@end

NS_ASSUME_NONNULL_END
