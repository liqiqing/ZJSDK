//
//  ZJFullScreenVideoAd.h
//  ZJSDK
//
//  Created by Rare on 2021/4/27.
//  Copyright © 2021 zj. All rights reserved.
//

#import <ZJSDKCore/ZJAd.h>
#import <ZJSDKCore/ZJMediaPlayerStatus.h>
#import <ZJSDKCore/ZJSDKCore.h>
NS_ASSUME_NONNULL_BEGIN
@class ZJFullScreenVideoAd;
@protocol ZJFullScreenVideoAdDelegate <NSObject>

//广告加载成功
- (void)zj_fullScreenVideoAdDidLoad:(ZJFullScreenVideoAd *)ad;

//广告加载失败
- (void)zj_fullScreenVideoAdDidLoadFail:(ZJFullScreenVideoAd *)ad error:(nullable NSError *)error;

//广告展示
- (void)zj_fullScreenVideoAdDidShow:(ZJFullScreenVideoAd *)ad;

//广告点击
- (void)zj_fullScreenVideoAdDidClick:(ZJFullScreenVideoAd *)ad;

//广告关闭
- (void)zj_fullScreenVideoAdDidClose:(ZJFullScreenVideoAd *)ad;

//广告错误
- (void)zj_fullScreenVideoAdDidFail:(ZJFullScreenVideoAd *)ad error:(nullable NSError *)error;

//广告播放状态回调
- (void)zj_fullScreenVideoAd:(ZJFullScreenVideoAd *)ad  playerStatusChanged:(ZJMediaPlayerStatus)playerStatus;

//广告详情页打开
- (void)zj_fullScreenVideoAdDetailDidPresent:(ZJFullScreenVideoAd *)ad;

//广告详情页关闭
- (void)zj_fullScreenVideoAdDetailDidClose:(ZJFullScreenVideoAd *) ad;

@end

@interface ZJFullScreenVideoAd : ZJAd

@property (nonatomic, weak) id <ZJFullScreenVideoAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id <ZJFullScreenVideoAdDelegate>)delegate;

- (void)loadAd;

- (void)presentFullScreenVideoAdFromRootViewController:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
