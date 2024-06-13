//
//  ZJTubePage.h
//  ZJSDK
//
//  Created by 麻明康 on 2024/6/12.
//  Copyright © 2024 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import "ZJContentPageStateDelegate.h"
#import <ZJSDKCore/ZJContentInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJTubePage : ZJAd <ZJContentInfo>
@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;
@end

NS_ASSUME_NONNULL_END
