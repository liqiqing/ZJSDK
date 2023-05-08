//
//  ZJNewsAdView.h
//  ZJSDK
//
//  Created by 麻明康 on 2022/12/20.
//  Copyright © 2022 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJNewsAdProtocol.h>
NS_ASSUME_NONNULL_BEGIN
@class ZJNewsAdView;
@protocol ZJNewsAdViewDelegate <NSObject>
@optional
/**
 news广告加载成功
 */
- (void)zj_newsAdViewDidLoad:(ZJNewsAdView *)newsAdView;

/**
 news广告加载失败
 */
- (void)zj_newsAdView:(ZJNewsAdView *)newsAdView didLoadFailWithError:(NSError * _Nullable)error;

/**
 newsAdView曝光回调
 */
- (void)zj_newsAdViewDidShow:(ZJNewsAdView *)newsAdView;

/**
 关闭news广告回调
 */
- (void)zj_newsAdViewRewardEffective:(ZJNewsAdView *)newsAdView;

/**
 点击news广告回调
 */
- (void)zj_newsAdViewDidClick:(ZJNewsAdView *)newsAdView;

/**
 canGoBack状态监听
 */
- (void)zj_newsAd:(ZJNewsAdView *)newsAd canGoBackStateChange:(BOOL)canGoBack;
@end
@interface ZJNewsAdView : UIView <ZJNewsAdProtocol>
@property (nonatomic, copy, readonly) NSString *placementId;
@property (nonatomic, assign) BOOL enableGoBackGesture;
@property (nonatomic, assign) BOOL enableSlide;

@property (nonatomic, weak, nullable) id <ZJNewsAdViewDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

- (void)loadAdAndShow;
- (BOOL)canGoBack;
- (void)goBack;
@end

NS_ASSUME_NONNULL_END
