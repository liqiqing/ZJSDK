//
//  ZJFeedFullVideoProviderAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <ZJSDKCore/ZJMultipleAdAdapter.h>
#import "ZJFeedFullVideoProviderProtocol.h"
#import "ZJFeedFullVideoProviderAdapterDelegate.h"
#import "ZJFeedFullVideoAdAdapterView.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJFeedFullVideoProviderAdapter : ZJMultipleAdAdapter<ZJFeedFullVideoProviderProtocol>

@property(nonatomic,weak) id<ZJFeedFullVideoProviderAdapterDelegate> delegate;

- (void)zj_feedFullVideoProviderAdapterLoadSuccess:(NSArray<__kindof ZJFeedFullVideoAdAdapterView *> *)views;

- (void)zj_feedFullVideoProviderAdapterLoadFail:(NSError *_Nullable)error;

// 广告渲染成功, ZJFeedFullVideoView.size.height has been updated
- (void)zj_feedFullVideoAdViewRenderSuccess:(ZJFeedFullVideoAdAdapterView*) adView;

// 广告渲染失败
- (void)zj_feedFullVideoAdViewRenderFail:(ZJFeedFullVideoAdAdapterView*) adView error:(NSError *_Nullable)error;

// 广告曝光回调
- (void)zj_feedFullVideoAdViewWillShow:(ZJFeedFullVideoAdAdapterView*) adView;

// 视频广告播放状态更改回调  ????
- (void)zj_feedFullVideoAdViewStateDidChanged:(ZJFeedFullVideoAdAdapterView*) adView state:(ZJMediaPlayerStatus)playerState;

// 视频广告播放完成
- (void)zj_feedFullVideoAdViewPlayerDidPlayFinish:(ZJFeedFullVideoAdAdapterView*) adView;

// 广告点击回调
- (void)zj_feedFullVideoAdViewDidClick:(ZJFeedFullVideoAdAdapterView*) adView;

//  广告详情页面即将展示回调
- (void)zj_feedFullVideoAdViewDetailViewWillPresentScreen:(ZJFeedFullVideoAdAdapterView*) adView;

// 广告详情页关闭回调
- (void)zj_feedFullVideoAdViewDetailViewClosed:(ZJFeedFullVideoAdAdapterView*) adView;
@end

NS_ASSUME_NONNULL_END
