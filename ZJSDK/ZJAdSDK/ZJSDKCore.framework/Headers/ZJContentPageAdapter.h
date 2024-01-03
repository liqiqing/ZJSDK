//
//  ZJContentPageAdapter.h
//  ZJSDK
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import <ZJSDKCore/ZJBaseContentAdapter.h>
#import <ZJSDKCore/ZJContentInfo.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJContentAdapterStateDelegate.h>
#import <ZJSDKCore/ZJContentAdapterStateProtocol.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZJContentPageAdapter : ZJBaseContentAdapter<
ZJContentAdapterStateProtocol,
ZJAdapterContentAdapterVideoStateProtocol
>

/// 任务完成回调
- (void)zjAdapter_contentTaskComplete:(id<ZJContentInfo>)content;
///  视频状态代理
@property (nonatomic, weak) id <ZJAdapterContentAdapterVideoStateDelegate> zjAdapter_videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id <ZJContentAdapterStateDelegate> zjAdapter_stateDelegate;

- (void)tryToRefresh;

@end

NS_ASSUME_NONNULL_END
