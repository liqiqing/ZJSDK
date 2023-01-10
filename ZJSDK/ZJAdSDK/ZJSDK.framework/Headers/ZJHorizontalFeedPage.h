//
//  ZJHorizontalFeedPage.h
//  ZJSDK
//
//  Created by 麻明康 on 2023/1/5.
//  Copyright © 2023 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import "ZJContentPageHorizontalFeedCallBackDelegate.h"
#import <ZJSDKCore/ZJContentInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJHorizontalFeedPage : ZJAd <ZJContentInfo>
@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <ZJContentPageHorizontalFeedCallBackDelegate> callBackDelegate;

@end

NS_ASSUME_NONNULL_END
