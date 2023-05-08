//
//  ZJSplashAdAdapterDelegate.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJSplashAdAdapter;
@protocol ZJSplashAdAdapterDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
-(void)zj_splashAdAdapterDidLoad:(ZJSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告成功展示
 */
-(void)zj_splashAdAdapterSuccessPresentScreen:(ZJSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdAdapterClicked:(ZJSplashAdAdapter *)splashAdAdapter;


/**
 *  开屏广告即将关闭回调
 */
- (void)zj_splashAdAdapterWillClose:(ZJSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdAdapterClosed:(ZJSplashAdAdapter *)splashAdAdapter;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdAdapterApplicationWillEnterBackground:(ZJSplashAdAdapter *)splashAdAdapter;

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdAdapterCountdownEnd:(ZJSplashAdAdapter*)splashAdAdapter;

/**
 *  开屏广告错误
 */
- (void)zj_splashAdAdapterError:(ZJSplashAdAdapter *)splashAdAdapter withError:(NSError *)error;

/**
 *  开屏广告播放错误
 */
- (void)zj_splashAdAdapterDisplayError:(ZJSplashAdAdapter *)splashAdAdapter withError:(NSError *)error;

/// 奖励触发
- (void)zj_splashAdAdapterDidRewardEffective:(ZJSplashAdAdapter *)splashAdAdapter withInfo:(nullable NSDictionary *)info;
@end

NS_ASSUME_NONNULL_END
