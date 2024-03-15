//
//  TXAdRewardVideoRewardInfo.h
//  TanxSDK
//
//  Created by Yueyang Gu on 2022/6/21.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXAdRewardVideoRewardInfo : NSObject

/**
 *  是否发奖，YES时为发奖
 */
@property (nonatomic, assign) BOOL isValid;

/**
 *  发奖信息dict
 *  {
 *      "pid"                   : "mm_1_2_4",
 *      "task_type"         : 3,                                        // 发奖类型 2 浏览 3 下单
 *      "session_id"        : "mock_session_id2",         // 奖励id，唯一，投放时和广告绑定
 *      "complete_time" : "20231129 12:30:03",       // 任务完成时间
 *      "reward_name"   : "mock_reward_name2",    // 奖励名称
 *      "reward_count"   : 1                                        // 奖励数量
 *  }
 */
@property (nonatomic,   copy) NSDictionary *rewardInfoDict;

@end

NS_ASSUME_NONNULL_END
