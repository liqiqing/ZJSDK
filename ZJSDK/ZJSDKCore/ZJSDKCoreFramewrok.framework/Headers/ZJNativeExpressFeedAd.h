//
//  ZJNativeExpressFeedAd.h
//  ZJSDKCoreFramewrok
//
//  Created by Rare on 2021/3/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@class ZJNativeExpressFeedAd;
@protocol ZJNativeExpressFeedAdDelegate <NSObject>
@optional
/**
 * 广告渲染成功
 */
- (void)ZJ_nativeExpressFeedAdRenderSuccess:(ZJNativeExpressFeedAd *)feedAd;
/**
 * 广告渲染失败
 */
- (void)ZJ_nativeExpressFeedAdRenderFail:(ZJNativeExpressFeedAd *)feedAd;

/**
 *广告即将展示
 */
- (void)ZJ_nativeExpressFeedAdViewWillShow:(ZJNativeExpressFeedAd *)feedAd;
/**
 *广告点击
 */
- (void)ZJ_nativeExpressFeedAdDidClick:(ZJNativeExpressFeedAd *)feedAd;
/**
 *不喜欢该广告
 */
- (void)ZJ_nativeExpressFeedAdDislike:(ZJNativeExpressFeedAd *)feedAd;
/**
 *展示落地页
 */
- (void)ZJ_nativeExpressFeedAdDidShowOtherController:(ZJNativeExpressFeedAd *)nativeAd;
/**
 *关闭落地页
 */
- (void)ZJ_nativeExpressFeedAdDidCloseOtherController:(ZJNativeExpressFeedAd *)nativeAd;

@end


@interface ZJNativeExpressFeedAd : NSObject

@property (nonatomic,strong,readonly) UIView *feedView;

/**
 * Whether render is ready
 */
@property (nonatomic, assign,readonly) BOOL isReady;


@property(nonatomic,weak) id<ZJNativeExpressFeedAdDelegate> delegate;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/*
 *required [必选]
 *原生模板广告渲染
 */
- (void)render;

@end

NS_ASSUME_NONNULL_END
