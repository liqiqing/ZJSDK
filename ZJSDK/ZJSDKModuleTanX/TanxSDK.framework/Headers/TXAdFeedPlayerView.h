//
//  TXAdFeedPlayerView.h
//  TanxSDK
//
//  Created by Evan on 2023/3/3.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TXAdModel.h"
#import "TXAdFeedTemplateConfig.h"


NS_ASSUME_NONNULL_BEGIN

@protocol TXAdFeedPlayerViewDelegate <NSObject>

@optional

/**
 * 视频广告加载成功
 */
- (void)onVideoLoadSuccess;

/**
 * 视频广告播放中回调
 */
- (void)onVideoPlaying;

/**
 * 视频广告暂停回调
 */
- (void)onVideoPaused;

/**
 * 视频播放完成回调
 */
- (void)onVideoComplete;

/**
 * 视频缓冲中
 */
- (void)onVideoBuffering;

/**
 *  实时倒计时
 *
 *  @param duration  总时长
 *  @param current    0 1 2 3 4 5 6 7 8 ......
*/
- (void)onVideoProgressUpdateWithDuration:(long)duration current:(long)current;

/**
 *  视频广告播放错误回调
 *  @param error 错误信息
 */
- (void)onVideoError:(NSError *)error;

@end


@interface TXAdFeedPlayerView : UIView

@property (nonatomic, weak) id <TXAdFeedPlayerViewDelegate> delegate;

/**
 * 初始化FeedPlayerView
 *
 * @param adModel 数据model
 * @return TXAdFeedPlayerView
 */
- (instancetype)initWithFrame:(CGRect)frame adModel:(TXAdModel *)adModel NS_DESIGNATED_INITIALIZER;

/**
 * 更新 playerView 播放配置
 *
 * @param config    配置model，playConfig：1、不自动播放 2、自动播放 3、Wifi下自动播放，默认
 *                         setMute，静音，默认YES
 */
 - (void)updatePlayerConfig:(TXAdFeedTemplateConfig *)config;

/**
 * 播放
 */
- (void)play;

/**
 * 暂停
 */
- (void)pause;

/**
 * 设置音量
 * @param volume 音量，0 - 1
 */
- (void)setVolume:(float)volume;

/**
 * 设置静音
 */
- (void)setMute;

/**
 * 恢复系统音量
 */
- (void)resumeVolume;

/*--------------- 不可用方法 ---------------*/
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
