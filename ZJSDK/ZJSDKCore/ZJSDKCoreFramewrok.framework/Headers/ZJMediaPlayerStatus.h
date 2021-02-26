//
//  ZJMediaPlayerStatus.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/14.
//



typedef NS_ENUM(NSUInteger, ZJMediaPlayerStatus) {
    ZJMediaPlayerStatusDefalt = 0,         // 初始状态
    ZJMediaPlayerStatusLoading = 1,         // 加载中
    ZJMediaPlayerStatusPlaying = 2,         // 开始播放
    ZJMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    ZJMediaPlayerStatusError = 4,           // 播放出错
    ZJMediaPlayerStatusStoped = 5,          // 播放停止
};


