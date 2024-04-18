//
//  ZJRewardVideoAdAdapterDelegate.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJRewardVideoAdAdapter;
@protocol ZJRewardVideoAdAdapterDelegate <NSObject>

- (void)zj_rewardVideoAdAdapterDidLoad:(ZJRewardVideoAdAdapter *)adapter;

- (void)zj_rewardVideoAdAdapterVideoDidLoad:(ZJRewardVideoAdAdapter *)adapter;

- (void)zj_rewardVideoAdAdapterDidShow:(ZJRewardVideoAdAdapter *)adapter;

- (void)zj_rewardVideoAdAdapterDidClose:(ZJRewardVideoAdAdapter *)adapter;

- (void)zj_rewardVideoAdAdapterDidClicked:(ZJRewardVideoAdAdapter *)adapter;

- (void)zj_rewardVideoAdAdapterDidRewardEffective:(ZJRewardVideoAdAdapter *)adapter;

- (void)zj_rewardVideoAdAdapter:(ZJRewardVideoAdAdapter *)adapter serviceCheckResult:(BOOL)success error:(NSError *)error;

- (void)zj_rewardVideoAdAdapterDidPlayFinish:(ZJRewardVideoAdAdapter *)adapter;

- (void)zj_rewardVideoAdAdapter:(ZJRewardVideoAdAdapter *)adapter displayFailWithError:(NSError *)error;

- (void)zj_rewardVideoAdAdapter:(ZJRewardVideoAdAdapter *)adapter didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
