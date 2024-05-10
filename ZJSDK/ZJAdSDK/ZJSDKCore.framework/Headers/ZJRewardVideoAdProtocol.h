//
//  ZJRewardVideoAdProtocol.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
@class UIViewController;
@protocol ZJRewardVideoAdProtocol <NSObject>
/** required.
 由接入方提供urseId
 用于奖励发放的数据校验，是每个用户的唯一标识符。
 */
@property (nonatomic, copy) NSString *userId;
//optional. reward name.
@property (nonatomic, copy) NSString *reward_name;
//optional. number of rewards.
@property (nonatomic, assign) NSInteger reward_amount;
//optional. serialized string.
@property (nonatomic, copy) NSString *extra;

@property (nonatomic, assign) BOOL is_only_notify_self;

@property (nonatomic, copy) NSString *reward_extra;
///激励视频静音， 默认：NO
@property (nonatomic) BOOL videoMuted;
/**加载广告数据*/
- (void)loadAd;
/**广告展示方法
 调用showAdInViewController:方法前要确保激励视频加载完成，请在zj_rewardVideoAdVideoDidLoad:回调中调用该方法
 */
- (void)showAdInViewController:(UIViewController *)viewController;

///交易ID 需开启服务端校验才能获取交易ID
@property (nonatomic, copy, readonly) NSString *trade_id;
///验证dic
@property (nonatomic, copy, readonly) NSDictionary *validationDictionary;


///交易ID
@property (nonatomic, copy, readonly) NSString *trans_id DEPRECATED_MSG_ATTRIBUTE("use trade_id instead.");

@end

NS_ASSUME_NONNULL_END
