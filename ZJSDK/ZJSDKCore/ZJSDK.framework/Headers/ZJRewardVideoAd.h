//
//  ZJRewardAd.h
//  ZJSDK
//
//  Created by Robin on 2020/8/24.
//  Copyright © 2020 zj. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <ZJSDKCoreFramewrok/ZJAd.h>
#import <ZJSDKCoreFramewrok/ZJRewardVideoAdProtocol.h>
#import "ZJRewardVideoAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJRewardVideoAd : ZJAd<ZJRewardVideoAdProtocol>

@property(nonatomic,weak) id<ZJRewardVideoAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId userId:(NSString *)userId;

@end

NS_ASSUME_NONNULL_END
