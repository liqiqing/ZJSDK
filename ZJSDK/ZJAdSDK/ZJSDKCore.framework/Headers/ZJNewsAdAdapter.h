//
//  ZJNewsAdAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/12/20.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>
#import <ZJSDKCore/ZJNewsAdProtocol.h>
NS_ASSUME_NONNULL_BEGIN
@class ZJNewsAdAdapter;
@protocol ZJNewsAdAdapterDelegate <NSObject>
/**
 news广告加载成功
 */
- (void)zjad_newsAdViewDidLoad:(ZJNewsAdAdapter *)newsAd;

/**
 news广告加载失败
 */
- (void)zjad_newsAdView:(ZJNewsAdAdapter *)newsAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 newsAdView曝光回调
 */
- (void)zjad_newsAdViewDidShow:(ZJNewsAdAdapter *)newsAd;

/**
 关闭news广告回调
 */
- (void)zjad_newsAdViewRewardEffective:(ZJNewsAdAdapter *)newsAd;

/**
 点击news广告回调
 */
- (void)zjad_newsAdViewDidClick:(ZJNewsAdAdapter *)newsAd;

/**
 canGoBack状态监听
 */
- (void)zjad_newsAd:(ZJNewsAdAdapter *)newsAd canGoBackStateChange:(BOOL)canGoBack;

@end

@interface ZJNewsAdAdapter : ZJCoreAdAdapter <ZJNewsAdProtocol>
@property(nonatomic,weak) id<ZJNewsAdAdapterDelegate> delegate;
@property (nonatomic,strong)UIView *adView;
- (instancetype)initWithAdItemConfig:(ZJAdUnitModel *)adItemConfig frame:(CGRect)frame;
@property (nonatomic, readonly) BOOL canGoBack;
@property (nonatomic, readonly) BOOL canGoForward;
@property (nonatomic, assign) BOOL enableGoBackGesture;
@property (nonatomic, assign) BOOL enableSlide;
- (BOOL)goBack;
- (BOOL)goForward;
- (void)removeTimer;

//- (void)reload;
//- (void)stopLoading;

/**
 news广告加载成功
 */
- (void)zjad_newsAdViewDidLoad:(ZJNewsAdAdapter *)newsAd;

/**
 news广告加载失败
 */
- (void)zjad_newsAdView:(ZJNewsAdAdapter *)newsAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 newsAdView曝光回调
 */
- (void)zjad_newsAdViewDidShow:(ZJNewsAdAdapter *)newsAd;

/**
 news广告发奖回调
 */
- (void)zjad_newsAdViewRewardEffective:(ZJNewsAdAdapter *)newsAd;

/**
 点击news广告回调
 */
- (void)zjad_newsAdViewDidClick:(ZJNewsAdAdapter *)newsAd;

/**
 canGoBack状态监听
 */
- (void)zjad_newsAdCanGoBackStateChange:(BOOL)canGoBack;
@end

NS_ASSUME_NONNULL_END
