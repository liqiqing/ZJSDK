//
//  ZJSDKAdEnum.h
//  ZJSDKCore
//
//  Created by Rare on 2021/8/16.
//

#ifndef ZJSDKAdEnum_h
#define ZJSDKAdEnum_h

typedef NS_ENUM(NSUInteger, ZJMediaPlayerStatus) {
    ZJMediaPlayerStatusDefalt = 0,         // 初始状态
    ZJMediaPlayerStatusLoading = 1,         // 加载中
    ZJMediaPlayerStatusPlaying = 2,         // 开始播放
    ZJMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    ZJMediaPlayerStatusError = 4,           // 播放出错
    ZJMediaPlayerStatusStoped = 5,          // 播放停止
};



typedef NS_ENUM(NSInteger,ZJAdSDKLogLevel){
    ZJAdSDKLogLevelNone,
    ZJAdSDKLogLevelAll,
    ZJAdSDKLogLevelWarning,
    ZJAdSDKLogLevelError,
};


#endif /* ZJSDKAdEnum_h */
