//
//  ZJImageTextAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/5.
//

#import <ZJSDKCore/ZJBaseContentAdapter.h>
#import <ZJSDKCore/ZJContentInfo.h>
#import <ZJSDKCore/ZJContentAdapterHorizontalFeedCallBackDelegate.h>
#import <ZJSDKCore/ZJContentAdapterImageTextDetailDelegate.h>
#import <ZJSDKCore/ZJContentAdapterStateProtocol.h>
#import <ZJSDKCore/ZJContentAdapterHorizontalFeedCallBackProtocol.h>
#import <ZJSDKCore/ZJContentAdapterImageTextDetailProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJImageTextAdapter : ZJBaseContentAdapter<
ZJContentAdapterStateProtocol,
ZJAdapterContentAdapterVideoStateProtocol,
ZJContentAdapterHorizontalFeedCallBackProtocol,
ZJContentAdapterImageTextDetailProtocol
>

@property (nonatomic, weak, nullable) id<ZJContentAdapterHorizontalFeedCallBackDelegate> zjAdapter_callBackDelegate;
@property (nonatomic, weak, nullable) id<ZJContentAdapterImageTextDetailDelegate> zjAdapter_imageTextDelegate;
@end

NS_ASSUME_NONNULL_END
