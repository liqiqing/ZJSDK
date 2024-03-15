//
//  TXAdRewardVideoSlotModel.h
//  TanxSDK
//
//  Created by tongyuecheng on 2023/3/30.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import "TXAdSlotModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TXAdRewardVideoAdDefaultAudioState) {
    // 以有声状态开始播放
    TXAdRewardVideoAdDefaultAudioStateVocal = 0,
    // 以静音状态开始播放
    TXAdRewardVideoAdDefaultAudioStateMuted,
};

@interface TXAdRewardVideoSlotModel : TXAdSlotModel

/// 媒体用户id
@property (nonatomic,   copy) NSString *mediaUid;

/**
 *  是否自动核销发奖（查询接口即核销），默认YES，
 *  （如设置YES，在调用查询发奖接口时，会自动帮忙核销发奖；下次查询时，不会返回已核销数据）
 */
@property (nonatomic, assign) BOOL autoVerification;

/**
 *  是否自动调用查询发奖接口，默认NO
 *  （如设置YES，在广告show时调用，主要查询当前show时相关pid是否有历史奖励信息）
 */
@property (nonatomic, assign) BOOL autoQueryPrizeInfo;

/// 媒体自定义loadAd超时时间，默认没有超时时间，单位秒
@property (nonatomic, assign) NSTimeInterval loadAdTimeoutInterval;

/// 激励视频开始播放时，音频默认状态，可设成以静音状态开始播放。
@property (nonatomic, assign) TXAdRewardVideoAdDefaultAudioState defaultAudioState;

@end

NS_ASSUME_NONNULL_END
