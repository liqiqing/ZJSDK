//
//  ZJH5AdDelegate.h
//  ZJSDK
//
//  Created by Robin on 2020/10/28.
//  Copyright © 2020 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJUser;
@protocol ZJH5PageDelegate <NSObject>

@optional

//H5Ad加载完成
-(void) onZjH5PageLoaded:(ZJUser*)user error:(nullable NSError*) error;

//H5Ad错误
-(void) onZjH5PageError:(ZJUser*)user error:(NSError*) error;

//H5Ad关闭
-(void) onZjH5PageWillClose:(ZJUser*)user;

//H5操作回调
//积分不足
-(void) onIntegralNotEnough:(ZJUser*) user needIntegral:(NSInteger) integral;
//积分消耗
-(void) onIntegralExpend:(ZJUser*) user expendIntegral:(NSInteger) integral;
//积分奖励
-(void) onIntegralReward:(ZJUser*) user rewardIntegral:(NSInteger) integral;

//奖励发放,奖励积分
-(void) onZjH5PageAdRewardProvide:(ZJUser*) user rewardIntegral:(NSInteger) integral;

//用户页面的行为操作
-(void) onZjH5PageUserBehavior:(ZJUser*) user behavior:(NSString*) behavior;


//广告回调
//广告激励视频加载成功
-(void) onZjH5PageAdRewardLoaded:(ZJUser*) user trans_id:(NSString*) trans_id;

//广告激励视频触发激励（观看视频大于一定时长或者视频播放完毕）
-(void) onZjH5PageAdRewardValid:(ZJUser*) user trans_id:(NSString*) trans_id;

//广告点击
-(void) onZjH5PageAdRewardClick:(ZJUser*) user ;

//广告加载错误
-(void) onZjH5PageAdReward:(ZJUser*) user didFailWithError:(NSError*) error;


@end


NS_ASSUME_NONNULL_END
