//
//  ZJFullScreenVideoAdAdapter.h
//  ZJSDKCore
//
//  Created by Rare on 2021/4/27.
//

#import <ZJSDKCore/ZJTierAdAdapter.h>
#import <UIKit/UIKit.h>
#import "ZJSDKAdEnum.h"
NS_ASSUME_NONNULL_BEGIN
@class ZJFullScreenVideoAdAdapter;
@protocol ZJfullScreenVideoAdAdapterDelegate <NSObject>

- (void)zj_fullScreenVideoAdapterDidLoad:(ZJFullScreenVideoAdAdapter*)adapter;

- (void)zj_fullScreenVideoAdapterDidLoadFail:(ZJFullScreenVideoAdAdapter*)adapter error:(NSError * __nullable)error;

- (void)zj_fullScreenVideoAdapterDidPresentScreen:(ZJFullScreenVideoAdAdapter*)adapter;

- (void)zj_fullScreenVideoAdapterDidClick:(ZJFullScreenVideoAdAdapter*)adapter;

- (void)zj_fullScreenVideoAdapterDidClose:(ZJFullScreenVideoAdAdapter*)adapter;

- (void)zj_fullScreenVideoAdapterDidFail:(ZJFullScreenVideoAdAdapter*)adapter error:(NSError * __nullable)error;

- (void)zj_fullScreenVideoAdapter:(ZJFullScreenVideoAdAdapter*)adapter  playerStatus:(ZJMediaPlayerStatus)playerStatus;

- (void)zj_fullScreenVideoAdapterDetailDidClose:(ZJFullScreenVideoAdAdapter*)adapter;

- (void)zj_fullScreenVideoAdapterDetailDidPresent:(ZJFullScreenVideoAdAdapter*)adapter;

@end


@interface ZJFullScreenVideoAdAdapter : ZJTierAdAdapter


@property(nonatomic,weak) id<ZJfullScreenVideoAdAdapterDelegate> delegate;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

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
