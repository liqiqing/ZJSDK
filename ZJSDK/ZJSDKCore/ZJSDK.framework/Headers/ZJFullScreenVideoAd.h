//
//  ZJFullScreenVideoAd.h
//  ZJSDK
//
//  Created by Rare on 2021/4/27.
//  Copyright © 2021 zj. All rights reserved.
//

#import <ZJSDKCoreFramewrok/ZJAd.h>

NS_ASSUME_NONNULL_BEGIN
@class ZJFullScreenVideoAd;
@protocol ZJFullScreenVideoAdDelegate <NSObject>

//广告加载成功
- (void) zj_FullScreenVideoAdDidLoad:(ZJFullScreenVideoAd*) ad;
//广告加载失败
- (void) zj_FullScreenVideoAdDidLoadFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error;
//广告展示
- (void) zj_FullScreenVideoAdDidShow:(ZJFullScreenVideoAd*) ad;
//广告点击
- (void) zj_FullScreenVideoAdDidClick:(ZJFullScreenVideoAd*) ad;
//广告关闭
- (void) zj_FullScreenVideoAdDidClose:(ZJFullScreenVideoAd*) ad;
//广告详情页关闭
- (void) zj_FullScreenVideoAdDetailDidClose:(ZJFullScreenVideoAd*) ad;
//广告错误
- (void) zj_FullScreenVideoAdDidFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error;

@end

@interface ZJFullScreenVideoAd : ZJAd

@property(nonatomic,weak) id<ZJFullScreenVideoAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<ZJFullScreenVideoAdDelegate>) delegate;

-(void) loadAd;

-(void)presentFullScreenVideoAdFromRootViewController:(UIViewController*)viewController;


@end

NS_ASSUME_NONNULL_END
