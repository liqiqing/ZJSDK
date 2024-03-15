//
//  TXAdFeedBinder.h
//  TanxSDK
//
//  Created by Yueyang Gu on 2022/5/11.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TXAdModel.h"
#import "TXAdFeedView.h"
#import "TXAdFeedPlayerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TXAdFeedBinder : NSObject

@property(nonatomic, strong, readonly) TXAdModel *adModel;
@property(nonatomic, strong, readonly) TXAdFeedView *feedView;

/**
 *  需要媒体主动调用销毁Binder，避免出现内存泄露（包含释放播放器）
 */
- (void)destoryBinder;

/**
 *  获取播放器view，需加到feedView使用
 *      1、由于视频播放器比较耗内存，建议使用的时候进行获取，不使用时调用destoryPlayerView及时释放
 *
 *  @return playerView  播放器view
 */
- (nullable TXAdFeedPlayerView *)getVideoAdViewWithFrame:(CGRect)frame
                                              playConfig:(TXAdFeedTemplateConfig *)playConfig;

/**
 *  绑定信息流自渲染view：
 *      1、只传了closeView，而dislikeViews为空的情况下，则点击closeView就是关闭广告；
 *         点击该视图会触发 TXAdFeedManager 的代理方法  onClickCloseFeed:
 *
 *      2、在有dislikeViews的情况下，则选择了具体的关闭理由的视图才是关闭广告。
 *         点击视图会触发 TXAdFeedManager 的代理方法  didCloseFeed:atIndex:
 *
 *  @param feedView               必须继承自TXAdFeedView，自渲染的信息流主视图，广告subview必须加载到feedView里面
 *  @param closeView            关闭按钮视图，可选。
 *  @param dislikeViews     关闭理由视图数组，可选。
 *  @return NSError                 针对feedView会进行判断，如不满足，则返回error；
 */
- (nullable NSError *)bindFeedView:(TXAdFeedView *)feedView
                         closeView:(nullable UIView *)closeView
                      dislikeViews:(nullable NSArray<UIView *> *)dislikeViews;

/**
 *  支持自渲染feedView设置点击区域：
 *      0、一般接入方不需要实现，如需实现请咨询广告sdk开发同学
 *      1、( 需在bindFeedView:closeView:dislikeViews: 之后调用 ，避免出错)
 *      2、传入clickableViews不为空时，只有clickableViews 和 feedView区域可以响应点击进行转化
 *      3、传入clickableViews为空时，默认整个广告可响应点击进行转化
 *
 *  @param clickableViews    可以点击的views
 *  @return NSError                    针对feedView、clickableViews会进行判断，如不满足，则返回error；
 */
- (nullable NSError *)registerFeedViewClickableViews:(NSArray<UIView *> *)clickableViews;

@end

NS_ASSUME_NONNULL_END
