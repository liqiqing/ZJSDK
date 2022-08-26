//
//  ZJBiddingLossRelease.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/7/22.
//

#ifndef ZJBiddingLossRelease_h
#define ZJBiddingLossRelease_h

typedef NS_ENUM(NSInteger,ZJBiddingLossReason){
    ZJBiddingLossReason_LowPrice          = 1,        // 竞争力不足，如不是本次竞价的最高出价方，可上报此竞败原因
    ZJBiddingLossReason_LoadTimeout       = 2,        // 返回超时，如在本次竞价中未返回广告，可上报此竞败原因
    ZJBiddingLossReason_NoAd              = 3,        // 无广告回包
    ZJBiddingLossReason_AdDataError       = 4,        // 回包不合法
    ZJBiddingLossReason_Other             = 10001     // 其他
};

#endif /* ZJBiddingLossRelease_h */
