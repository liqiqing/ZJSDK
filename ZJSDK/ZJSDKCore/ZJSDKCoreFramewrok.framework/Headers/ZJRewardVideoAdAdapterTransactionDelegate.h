//
//  ZJRewardVideoAdAdapterTransactionDelegate.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^RewardVideoTransactionBlock)(BOOL  successed, id _Nullable result);
@class ZJRewardVideoAdAdapter;
@protocol ZJRewardVideoAdAdapterTransactionDelegate <NSObject>

- (void)zj_rewardVideoAdAdapter:(ZJRewardVideoAdAdapter *)adapter transactionLoad:(NSString*) dataStr resultCallBack:(RewardVideoTransactionBlock) resultCallBack;

- (void)zj_rewardVideoAdAdapter:(ZJRewardVideoAdAdapter *)adapter transactionFinish:(NSDictionary*) params resultCallBack:(RewardVideoTransactionBlock) resultCallBack;



- (void)zj2_rewardVideoAdTradeId:(ZJRewardVideoAdAdapter *)adapter transactionLoad:(NSString*) dataStr resultCallBack:(RewardVideoTransactionBlock) resultCallBack;
@end

NS_ASSUME_NONNULL_END
