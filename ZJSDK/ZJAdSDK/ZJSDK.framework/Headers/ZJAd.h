//
//  ZJAd.h
//  ZJSDK
//
//  Created by Rare on 2022/2/25.
//  Copyright © 2022 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJAdDebugLog.h>
#import <ZJSDKCore/NSError+ZJAd.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZJAd : NSObject

@property(nonatomic,copy,readonly) NSString *placementId;
/**
*  构造方法
*  详解：placementId - 广告位 ID
*/
- (instancetype)initWithPlacementId:(NSString *)placementId;



- (NSArray *)getFillFailureMessages;

/**
 * 返回广告的eCPM，广告加载成功后调用有效，单位：分
 
 * @return 成功返回一个大于等于0的值，
 *
 * @Discussion 返回信息说明：
 *
 * -1表示无权限或后台出现异常，
 *
 * -2表示当前广告类型暂不支持实时竞价。
 *
 * -3表示实时竞价二价获取失败，请在收到广告加载成功之后的回调后获取
 *
 * -4表示pd价格获取失败，请在收到广告加载成功之后的回调后获取
 *
 */
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
