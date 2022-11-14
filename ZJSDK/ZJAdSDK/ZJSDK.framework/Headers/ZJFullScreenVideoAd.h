//
//  ZJFullScreenVideoAd.h
//  ZJSDK
//
//  Created by Rare on 2022/3/3.
//  Copyright © 2022 zj. All rights reserved.
//

#import <ZJSDK/ZJBiddingAd.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
#import <ZJSDKCore/ZJFullScreenVideoAdAdapter.h>

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
- (void)zj_fullScreenVideoAdDetailDidClose:(ZJFullScreenVideoAd *)ad;

@end

@interface ZJFullScreenVideoAd : ZJBiddingAd <ZJfullScreenVideoAdAdapterDelegate>

@property (nonatomic, weak) id <ZJFullScreenVideoAdDelegate> delegate;

@property (nonatomic, strong)ZJFullScreenVideoAdAdapter *currentAdapter;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

- (void)loadAd;

- (void)presentFullScreenVideoAdFromRootViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
