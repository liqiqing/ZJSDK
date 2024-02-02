//
//  ZJAdCountdown.h
//  ZJSDKDemo
//
//  Created by Rare on 2022/2/11.
//  Copyright © 2022 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger,ZJCountdownState){
    ZJCountdownStateNone  = 0,
    ZJCountdownStatePaused,
    ZJCountdownStateResumed,
    ZJCountdownStateRunning,
    ZJCountdownStateEnded,
};

typedef void(^ZJCountdownCallBack) (long remainSec, ZJCountdownState state);

@interface ZJAdCountdown : NSObject

///计时器状态
@property(nonatomic,assign,readonly)ZJCountdownState countdownState;

/**
 @param
 countDownSec : 设置倒计时的时间 &&
 callBack : 倒计时回调
*/
-(void)setCountDown:(long)countDownSec callBack:(ZJCountdownCallBack)callBack;

///开始倒计时
-(void)startCountdown;
///暂停倒计时
-(void)pauseCountdown;
///继续倒计时
-(void)resumeCountdown;
///重新开始倒计时
-(void)reStartCountdown;
///结束倒计时
-(void)stopCountdown;
/////关闭倒计时
//-(void)invalidateTimer;

@end

NS_ASSUME_NONNULL_END
