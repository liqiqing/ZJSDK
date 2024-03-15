//
//  TXAdRewardManager.h
//  TanxSDK
//
//  Created by tongyuecheng on 2023/5/26.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TXAdRewardVideoRewardInfo.h"
#import "TXAdModel.h"
#import "TXAdManagerDelegate.h"
#import "TXAdRewardVideoSlotModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TXAdGetRewardAdsDataBlock)(NSArray <TXAdModel *> * _Nullable rewardAdModels, NSError * _Nullable error);

@protocol TXAdRewardAdsDelegate <NSObject,TXAdManagerDelegate>
@optional

/**
 * 视频下载成功回调，仅激励视频回调（会回调多次）
 * @param model 数据model
 */
- (void)onAdDidDownLoadSuccessWithModel:(TXAdModel *)model;

/**
 * 广告渲染失败回调
 * @param error 错误
 * @param model 数据model
 */
- (void)onAdDidShowFailError:(NSError *)error withModel:(TXAdModel *)model;

/**
 * 广告跳过回调
 * @param model 数据model
 */
- (void)onAdDidSkipWithModel:(TXAdModel *)model;

/**
 * 激励视频播放完成或者出错
 * @param error nil代表播放成功
 * @param model 数据model
 */
- (void)onAdDidFinishPlayingError:(nullable NSError *)error withModel:(TXAdModel *)model;

/**
 * 发奖回调，会调用多次
 * @param rewardInfo 发奖信息（优先使用rewardInfo.rewardInfoDict的数据，
 *                          如rewardInfoDict为nil，使用model确定是哪个广告）
 * @param model 数据model
 */
- (void)onAdDidReceiveRewardInfo:(TXAdRewardVideoRewardInfo *)rewardInfo
                       withModel:(nullable TXAdModel *)model;

@end

@interface TXAdRewardManager : NSObject

/**
 * 回调代理
 */
@property(nonatomic, weak) id<TXAdRewardAdsDelegate> delegate;

/**
 * 初始化方法
 *
 * @param pid 广告pid
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *
 *  @param  slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdRewardVideoSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/**
 * 获取激励广告
 *
 * @param adsDataBlock  广告数据block
 */
- (void)getRewardAdsWithAdsDataBlock:(TXAdGetRewardAdsDataBlock)adsDataBlock;

/**
 * 上报竞价结果
 *
 * @param  model 数据model(请求数据的回调里拿到的model)
 * @param  result 竞价结果yes/no
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 * 展示激励广告
 *      0、广告数据类型是视频， onAdDidDownLoadSuccessWithModel: 回调过后调用
 *      1、广告数据是换端类型，会进行换端；失败，则展示普通激励广告
 *
 * @param viewController  当前所在VC
 * @param adModel                  广告数据model
 */
- (void)showAdFromRootViewController:(UIViewController *)viewController withModel:(TXAdModel *)adModel;

/**
 *  查询发奖接口：
 *      0、通过delegate方法 onAdDidReceiveRewardInfo:withModel:返回当前用户所有发奖结果
 *      1、如无发奖信息，delegate方法不会回调
 *
 *  @param mediaUid   接入方用户id，查询发奖使用；必传
 *  @param pidsList   广告pid数组；必传
 */
- (void)queryRewardPrizeInfoWithMediaUid:(NSString *)mediaUid
                                pidsList:(NSArray *)pidsList;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

