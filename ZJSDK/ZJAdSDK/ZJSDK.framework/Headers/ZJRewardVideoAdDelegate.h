//
//  ZJRewardAdDelegate.h
//  ZJSDK
//
//  Created by Robin on 2020/9/14.
//  Copyright © 2020 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
@class  ZJRewardVideoAd;
NS_ASSUME_NONNULL_BEGIN

@protocol ZJRewardVideoAdDelegate <NSObject>
@optional
/**
广告数据加载成功回调
@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdDidLoad:(ZJRewardVideoAd *)rewardedVideoAd;

/**
视频数据下载成功回调，已经下载过的视频会直接回调，在这里调用展示广告的方法
@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdVideoDidLoad:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频广告展示
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidShow:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClose:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClicked:(ZJRewardVideoAd *)rewardedVideoAd;


/**
 视频广告播放达到激励条件回调
 @param rewardedVideoAd ZJRewardVideoAd 实例，
 可以从rewardedVideoAd获取此次广告行为的交易id  ：trade_id
 */
- (void)zj_rewardVideoAdDidRewardEffective:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频广告视频播放完成
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidPlayFinish:(ZJRewardVideoAd *)rewardedVideoAd;


/**
 视频广告各种错误信息回调
 @param rewardedVideoAd ZJRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)zj_rewardVideoAd:(ZJRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
