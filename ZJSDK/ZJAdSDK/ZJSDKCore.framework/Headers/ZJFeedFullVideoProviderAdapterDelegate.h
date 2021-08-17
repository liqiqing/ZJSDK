//
//  ZJFeedFullVideoProviderAdapterDelegate.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>
#import "ZJSDKAdEnum.h"
@class ZJFeedFullVideoProviderAdapter,ZJFeedFullVideoView;
NS_ASSUME_NONNULL_BEGIN

@protocol ZJFeedFullVideoProviderAdapterDelegate <NSObject>

/**
 * 广告加载成功
 */
- (void)zj_feedFullVideoProviderAdapterLoadSuccess:(ZJFeedFullVideoProviderAdapter *)adapter views:(NSArray<__kindof ZJFeedFullVideoView *> *)views;

/**
* 广告加载失败
*/
- (void)zj_feedFullVideoProviderAdapterLoadFail:(ZJFeedFullVideoProviderAdapter *)adapter error:(NSError *_Nullable)error;

/**
 * 广告渲染成功, ZJFeedFullVideoView.size.height has been updated
 */
- (void)zj_feedFullVideoAdViewRenderSuccess:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView;

/**
 * 广告渲染失败
 */
- (void)zj_feedFullVideoAdViewRenderFail:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView error:(NSError *_Nullable)error;

/**
 * 广告曝光回调
 */
- (void)zj_feedFullVideoAdViewWillShow:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView;

/**
视频广告播放状态更改回调
*/
- (void)zj_feedFullVideoAdViewStateDidChanged:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView state:(ZJMediaPlayerStatus)playerState;

- (void)zj_feedFullVideoAdViewPlayerDidPlayFinish:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView;

/**
 * 广告点击回调
 */
- (void)zj_feedFullVideoAdViewDidClick:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView;

/**
* 广告详情页面即将展示回调
*/
- (void)zj_feedFullVideoAdViewDetailViewWillPresentScreen:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView;

/**
 *广告详情页关闭回调
 */
- (void)zj_feedFullVideoAdViewDetailViewClosed:(ZJFeedFullVideoProviderAdapter *)adapter view:(ZJFeedFullVideoView*) adView;

@end

NS_ASSUME_NONNULL_END
