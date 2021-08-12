//
//  ZJContentPage.h
//  ZJSDK
//
//  Created by Rare on 2020/12/21.
//  Copyright © 2020 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import "ZJContentPageDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJContentPage : ZJAd

@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;


///内容标识
@property (nonatomic, copy, readonly) NSString *contentInfoId;
///内容类型
@property (nonatomic, assign, readonly) ZJContentInfoType contentInfoType;

///刷新
- (void)tryToRefresh;

@end







NS_ASSUME_NONNULL_END
