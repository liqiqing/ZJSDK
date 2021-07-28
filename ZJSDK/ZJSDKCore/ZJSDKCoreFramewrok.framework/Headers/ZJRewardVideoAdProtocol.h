//
//  ZJRewardVideoAdProtocol.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class UIViewController;
@protocol ZJRewardVideoAdProtocol <NSObject>

@property(nonatomic,copy) NSString *userId;
@property(nonatomic,copy) NSString *reward_name;
@property(nonatomic,assign) NSInteger reward_amount;
//交易ID
@property(nonatomic,copy,readonly) NSString *trans_id DEPRECATED_MSG_ATTRIBUTE("use trade_id instead.");
//交易ID
@property(nonatomic,copy,readonly) NSString *trade_id;

@property (nonatomic) BOOL videoMuted;

@property(nonatomic,copy) NSString *extra;

//验证dic
@property(nonatomic,copy,readonly) NSDictionary *validationDictionary;

- (void) loadAd;
- (void) showAdInViewController:(UIViewController*)viewController;

@end

NS_ASSUME_NONNULL_END
