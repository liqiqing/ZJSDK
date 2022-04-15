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
    ZJAdSDKLogLevelDebug,
    ZJAdSDKLogLevelWarning,
    ZJAdSDKLogLevelError,
};

typedef NS_ENUM(NSInteger, ZJAdPlatformType) {
    ZJAdPlatform_None,
    ZJAdPlatform_CSJ,
    ZJAdPlatform_GDT,
    ZJAdPlatform_MTG,
    ZJAdPlatform_KS,
    ZJAdPlatform_ZJ,
    ZJAdPlatform_YM,
    ZJAdPlatform_SIG,
    ZJAdPlatform_WW,
    ZJAdPlatform_Google,
    ZJAdPlatform_Baidu,
};



#endif /* ZJSDKAdEnum_h */
