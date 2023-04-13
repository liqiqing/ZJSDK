//
//  ZJSplashAdAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2020/12/22.
//

#import "ZJTierAdAdapter.h"
#import "ZJSplashAdProtocol.h"
#import "ZJSplashAdAdapterDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJSplashAdAdapter : ZJTierAdAdapter<ZJSplashAdProtocol>


@property(nonatomic,weak) id<ZJSplashAdAdapterDelegate> delegate;

@property(nonatomic,strong,readonly)UIView *splashAdapterView;


/**
 *  开屏广告素材加载成功
 */
- (void)zj_splashAdDidLoad;

/**
 *  开屏广告成功展示
 */
- (void)zj_splashAdSuccessPresentScreen;

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked;


/**
 *  开屏广告即将关闭回调
 */
- (void)zj_splashAdWillClose;

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground;

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd;

/**
 *  开屏广告错误
 */
- (void)zj_splashAdErrorWithError:(nullable NSError *)error;
/**
 *  开屏广告播放错误
 */
- (void)zj_splashAdDisplayError:(NSError *)error;

/// 事件上报
-(void)reportWithEvent:(ZJEventString)event supplementMsg:(nullable NSString *)supplementMsg;


/// 奖励触发
- (void)zj_splashAdDidRewardEffectiveWithInfo:(nullable NSDictionary *)info;


@end

NS_ASSUME_NONNULL_END
