//
//  ZJFloatingAdView.h
//  ZJSDK
//
//  Created by Rare on 2021/7/16.
//  Copyright © 2021 zj. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJFloatingAdView;
@protocol ZJFloatingAdViewDelegate <NSObject>

//广告加载完成
- (void)zj_floatingAdViewDidLoad:(ZJFloatingAdView *)floatingAdView;

//广告加载错误
- (void)zj_floatingAdViewError:(ZJFloatingAdView *)floatingAdView error:(NSError *)error;

//广告点击
- (void)zj_floatingAdViewDidClick:(ZJFloatingAdView *)floatingAdView;

//广告关闭
- (void)zj_floatingAdViewDidClose:(ZJFloatingAdView *)floatingAdView;

@end


@interface ZJFloatingAdView : UIView

- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

@property (nonatomic, weak) id <ZJFloatingAdViewDelegate> delegate;
///placementId - 广告位 ID
@property (nonatomic, copy) NSString *placementId;
///广告是否能够移动 默认 YES
@property (nonatomic, assign) BOOL canMove;
///广告是否需要自动贴边展示 默认 YES
@property (nonatomic, assign) BOOL needMoveToSide;
///广告关闭按钮隐藏 默认 NO
@property (nonatomic, assign) BOOL hiddenCloseButton;
///用来弹出目标页的ViewController，一般为当前ViewController 默认当前widow的viewController
@property (nonatomic, weak) UIViewController *rootViewController;

///加载广告
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
