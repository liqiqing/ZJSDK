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

///播放器的播放状态
typedef NS_ENUM(NSInteger,TXAdFeedPlayerStatus){
    TXAdFeedPlayerStatusUnknown = -1,     //  未知
    TXAdFeedPlayerStatusPause    = 1,     //  暂停播放
    TXAdFeedPlayerStatusPlaying,          //  播放中
    TXAdFeedPlayerStatusBuffering,        //  缓冲中
    TXAdFeedPlayerStatusEnd,              //  播放结束
    TXAdFeedPlayerStatusError,            //  播放错误
};

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

- (TXAdFeedPlayerStatus)playerStatus;

/**
 * 播放
 */
- (void)play;

/**
 * 重新播放
 */
- (void)replay;

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
