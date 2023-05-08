//
//  ZJFeedPage.h
//  ZJSDK
//
//  Created by 麻明康 on 2023/1/4.
//  Copyright © 2023 zj. All rights reserved.
//

#import "ZJAd.h"
#import "ZJContentPageStateDelegate.h"
#import <ZJSDKCore/ZJContentInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJFeedPage : ZJAd <ZJContentInfo>
@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;

@end

NS_ASSUME_NONNULL_END
