//
//  ZJFeedAd.h
//  ZJSDK
//
//  Created by Robin on 2021/1/24.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJAd.h"
#import <ZJSDKCoreFramewrok/ZJFeedAdProtocol.h>
#import <ZJSDKCoreFramewrok/ZJFeedAdView.h>
NS_ASSUME_NONNULL_BEGIN
@class ZJFeedAd;
@protocol ZJFeedAdDelegate <NSObject>

- (void)feedAdSuccessToLoad:(ZJFeedAd *)feedAd views:(NSArray<__kindof ZJFeedAdView *> *)views;

- (void)feedAdFailToLoad:(ZJFeedAd *)feedAd error:(NSError *)error;

- (void)feedAd:(ZJFeedAd *)feedAd feedAdViewRenderSuccess:(ZJFeedAdView *)feedView;
- (void)feedAd:(ZJFeedAd *)feedAd feedAdViewRenderFail:(ZJFeedAdView *)feedView error:(NSError *)error;
- (void)feedAd:(ZJFeedAd *)feedAd feedAdViewDidShow:(ZJFeedAdView *)feedView;
- (void)feedAd:(ZJFeedAd *)feedAd feedAdViewDidClick:(ZJFeedAdView *)feedView;
- (void)feedAd:(ZJFeedAd *)feedAd feedAdViewDislike:(ZJFeedAdView *)feedView withReason:(NSString*) reason;
- (void)feedAd:(ZJFeedAd *)feedAd feedAdViewDidClosed:(ZJFeedAdView *)feedView;
- (void)feedAd:(ZJFeedAd *)feedAd feedAdViewDidCloseDetailController:(ZJFeedAdView *)feedView;

@end

@interface ZJFeedAd : ZJAd<ZJFeedAdProtocol>
@property(nonatomic,weak) id<ZJFeedAdDelegate> delegate;
- (instancetype)initWithPlacementId:(NSString *)placementId adSize:(CGSize) adSize;

@end

NS_ASSUME_NONNULL_END
