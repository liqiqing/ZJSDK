//
//  ZJMiniParamAdProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/9/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJMiniParamAdProtocol <NSObject>
/// 请先导入微信SDK以唤起微信小程序。由于友盟与微信模块之间的冲突，本SDK默认不帮开发者导入微信依赖库，请开发者根据自身业务集成
/// 原本app内两者都未集成，建议集成微信pod 'WechatOpenSDK'，并导入微信小程序广告模块:pod 'ZJSDK/ZJADWXMiniProgramAdapter'
/// 微信文档：https://developers.weixin.qq.com/doc/oplatform/Mobile_App/Access_Guide/iOS.html
/// 友盟文档：https://developer.umeng.com/docs/128606/cate/128606
-(void)awakeWXMiniParam;
@end

NS_ASSUME_NONNULL_END
