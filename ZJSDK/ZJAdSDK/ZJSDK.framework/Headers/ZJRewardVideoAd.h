//
//  ZJRewardAd.h
//  ZJSDK
//
//  Created by Robin on 2020/8/24.
//  Copyright © 2020 zj. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJAd.h>
#import <ZJSDKCore/ZJRewardVideoAdProtocol.h>
#import "ZJRewardVideoAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJRewardVideoAd : ZJAd <ZJRewardVideoAdProtocol>

@property (nonatomic, weak) id <ZJRewardVideoAdDelegate> delegate;

/**激励视频初始化方法
@param placementId   required 激励视频广告位ID
@param userId   required 由媒体提供urseId， 用于奖励发放的数据校验，是每个用户的唯一标识符。
 */
- (instancetype)initWithPlacementId:(NSString *)placementId userId:(NSString *)userId;

- (instancetype)initWithPlacementId:(NSString *)placementId NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
