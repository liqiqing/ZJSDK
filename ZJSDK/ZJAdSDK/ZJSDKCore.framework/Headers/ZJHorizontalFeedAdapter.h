//
//  ZJHorizontalFeedAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/5.
//

#import <ZJSDKCore/ZJBaseContentAdapter.h>
#import <ZJSDKCore/ZJContentInfo.h>
#import <ZJSDKCore/ZJContentAdapterHorizontalFeedCallBackDelegate.h>
#import <ZJSDKCore/ZJContentAdapterStateProtocol.h>
#import <ZJSDKCore/ZJContentAdapterHorizontalFeedCallBackProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJHorizontalFeedAdapter : ZJBaseContentAdapter<
ZJContentAdapterStateProtocol,
ZJAdapterContentAdapterVideoStateProtocol,
ZJContentAdapterHorizontalFeedCallBackProtocol
>
@property (nonatomic, weak, nullable) id<ZJContentAdapterHorizontalFeedCallBackDelegate> zjAdapter_callBackDelegate;
@end

NS_ASSUME_NONNULL_END
