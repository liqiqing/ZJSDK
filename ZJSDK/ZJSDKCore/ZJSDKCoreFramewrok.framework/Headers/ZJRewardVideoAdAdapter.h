//
//  ZJRewardVideoAdAdapter.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/14.
//

#import <ZJSDKCoreFramewrok/ZJSDKCoreFramewrok.h>
#import <UIKit/UIKit.h>
#import "ZJCoreAdAdapter.h"
#import "ZJRewardVideoAdProtocol.h"
#import "ZJRewardVideoAdAdapterDelegate.h"
#import "ZJRewardVideoAdAdapterTransactionDelegate.h"


NS_ASSUME_NONNULL_BEGIN

@interface ZJRewardVideoAdAdapter : ZJCoreAdAdapter<ZJRewardVideoAdProtocol>
@property(nonatomic,strong,readonly)UIView *rewardAdapterView;
@property(nonatomic,weak) id<ZJRewardVideoAdAdapterDelegate> delegate;
@property(nonatomic,weak) id<ZJRewardVideoAdAdapterTransactionDelegate> transactionDelegate;

- (instancetype)initWithAdItemConfig:(ZJAdItemConfig *)adItemConfig userId:(NSString *)userId;

- (void) loadSettingWith:(id<ZJRewardVideoAdProtocol>) rewardVideoAd;

- (void)zj_rewardVideoAdDidLoad;

- (void)zj_rewardVideoAdVideoDidLoad;

- (void)zj_rewardVideoAdDidShow;

- (void)zj_rewardVideoAdDidClose;

- (void)zj_rewardVideoAdDidClicked;

- (void)zj_rewardVideoAdDidRewardEffective;

- (void)zj_rewardVideoAdDidPlayFinish;

- (void)zj_rewardVideoAdDidFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
