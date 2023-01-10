//
//  ZJImageTextPage.h
//  ZJSDK
//
//  Created by 麻明康 on 2023/1/5.
//  Copyright © 2023 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJContentInfo.h>
#import "ZJContentPageHorizontalFeedCallBackDelegate.h"
#import "ZJImageTextDetailDelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface ZJImageTextPage : ZJAd <ZJContentInfo>
@property (nonatomic, readonly) UIViewController *viewController;

@property (nonatomic, weak) id <ZJContentPageHorizontalFeedCallBackDelegate> callBackDelegate;
@property (nonatomic, weak) id <ZJImageTextDetailDelegate> imageTextDelegate;

@end

NS_ASSUME_NONNULL_END
