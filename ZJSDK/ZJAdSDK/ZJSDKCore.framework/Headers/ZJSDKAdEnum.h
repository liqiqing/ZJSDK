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
    ZJAdPlatform_Gromore,
    ZJAdPlatform_BeiZi,
    ZJAdPlatform_WM,
    ZJAdPlatform_Pangle,
};

typedef NS_ENUM(NSInteger, ZJAdType){
    
    ZJAdType_Unknow                 = 0,
    ZJAdType_SPLASH                 = 1,
    
    ZJAdType_REWARD                 = 3,
    ZJAdType_H5                     = 4,
    ZJAdType_Banner                 = 5,//banner
    ZJAdType_Interstitial           = 6,//插屏
    ZJAdType_ExpressFullVideoFeed   = 7,//视频流 
    ZJAdType_ContentVideo           = 8,//视频内容 
    ZJAdType_Native                 = 9,//原生渲染 
    
    ZJAdType_NativeExpress          = 11,//信息流 
    ZJAdType_FullScreenVideo        = 12,//全屏视频
    
    
    ZJAdType_News                   = 21,//新闻资讯
    ZJAdType_WXMiniProgram          = 22
};


#endif /* ZJSDKAdEnum_h */
