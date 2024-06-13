//
//  ZJTubePageAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/6/12.
//

#import "ZJBaseTubeAdapter.h"
#import <ZJSDKCore/ZJContentInfo.h>
#import <ZJSDKCore/ZJContentAdapterStateDelegate.h>
#import <ZJSDKCore/ZJContentAdapterStateProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJTubePageAdapter : ZJBaseTubeAdapter<
ZJContentAdapterStateProtocol,
ZJAdapterContentAdapterVideoStateProtocol
>
/// 任务完成回调
- (void)zjAdapter_contentTaskComplete:(id<ZJContentInfo>)content;
///  视频状态代理
@property (nonatomic, weak) id <ZJAdapterContentAdapterVideoStateDelegate> zjAdapter_videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id <ZJContentAdapterStateDelegate> zjAdapter_stateDelegate;
@end

NS_ASSUME_NONNULL_END
