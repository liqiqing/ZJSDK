//
//  ZJRewardVideoAdAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//


#import "ZJCoreAdAdapter.h"
#import "ZJRewardVideoAdProtocol.h"
#import "ZJRewardVideoAdAdapterDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJRewardVideoAdAdapter : ZJCoreAdAdapter<ZJRewardVideoAdProtocol>

@property(nonatomic,strong,readonly)UIView *rewardAdapterView;

@property(nonatomic,weak) id<ZJRewardVideoAdAdapterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(ZJAdUnitModel *)adItemConfig userId:(NSString *)userId;

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
