//
//  ZJFeedAdAdapter.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/24.
//

#import "ZJCoreAdAdapter.h"
#import "ZJFeedAdProtocol.h"
#import "ZJFeedAdView.h"
NS_ASSUME_NONNULL_BEGIN
@class ZJFeedAdAdapter;
@protocol ZJFeedAdAdapterDelegate <NSObject>

- (void)feedAdAdapterSuccessToLoad:(ZJFeedAdAdapter *)adapter views:(NSArray<__kindof ZJFeedAdView *> *)views;

- (void)feedAdAdapterFailToLoad:(ZJFeedAdAdapter *)adapter error:(NSError *)error;

- (void)feedAdAdapter:(ZJFeedAdAdapter *)adapter feedAdViewRenderSuccess:(ZJFeedAdView *)feedView;
- (void)feedAdAdapter:(ZJFeedAdAdapter *)adapter feedAdViewRenderFail:(ZJFeedAdView *)feedView error:(NSError *)error;
- (void)feedAdAdapter:(ZJFeedAdAdapter *)adapter feedAdViewDidShow:(ZJFeedAdView *)feedView;
- (void)feedAdAdapter:(ZJFeedAdAdapter *)adapter feedAdViewDidClick:(ZJFeedAdView *)feedView;
- (void)feedAdAdapter:(ZJFeedAdAdapter *)adapter feedAdViewDislike:(ZJFeedAdView *)feedView withReason:(NSString*) reason;
- (void)feedAdAdapter:(ZJFeedAdAdapter *)adapter feedAdViewDidClosed:(ZJFeedAdView *)feedView;
- (void)feedAdAdapter:(ZJFeedAdAdapter *)adapter feedAdViewDidCloseDetailController:(ZJFeedAdView *)feedView;


@end

@interface ZJFeedAdAdapter : ZJCoreAdAdapter<ZJFeedAdProtocol>
@property(nonatomic,weak) id<ZJFeedAdAdapterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(ZJAdItemConfig *)adItemConfig adSize:(CGSize) adSize;

- (void)feedAdAdapterSuccessToLoad:(NSArray<__kindof ZJFeedAdView *> *)views;
- (void)feedAdAdapterFailToLoad:(NSError *)error;
- (void)feedAdViewRenderSuccess:(ZJFeedAdView *)feedView;
- (void)feedAdViewRenderFail:(ZJFeedAdView *)feedView error:(NSError *)error;
- (void)feedAdViewDidShow:(ZJFeedAdView *)feedView;
- (void)feedAdViewDidClick:(ZJFeedAdView *)feedView;
- (void)feedAdViewDislike:(ZJFeedAdView *)feedView withReason:(NSString*) reason;
- (void)feedAdViewDidClosed:(ZJFeedAdView *)feedView;
- (void)feedAdViewDidCloseDetailController:(ZJFeedAdView *)feedView;
@end

NS_ASSUME_NONNULL_END
