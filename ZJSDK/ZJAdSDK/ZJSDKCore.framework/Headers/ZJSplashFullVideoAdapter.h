//
//  ZJSplashFullVideoAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/8/1.
//

#import "ZJSplashAdAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJSplashFullVideoAdapter : ZJSplashAdAdapter
///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

-(void)showAdInWindow:(UIWindow *)window;
/**
 *  展示广告，调用此方法前需调用isAdValid方法判断广告素材是否有效
 */
- (void)showAdInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

-(void)presentAdFromRootViewController:(UIViewController*)viewController;

- (void)zj_fullScreenVideoDidLoad;

- (void)zj_fullScreenVideoDidLoadFail:(NSError * __nullable)error;

- (void)zj_fullScreenVideoDidPresentScreen;

- (void)zj_fullScreenVideoDidClick;

- (void)zj_fullScreenVideoDidClose;

- (void)zj_fullScreenVideoDetailDidClose;

- (void)zj_fullScreenVideoDidFail:(NSError * __nullable)error;

-(void)zj_fullScreenVideoPlayerStatus:(ZJMediaPlayerStatus)status;

-(void)zj_fullScreenVideoDetailDidPresent;

@end

NS_ASSUME_NONNULL_END
