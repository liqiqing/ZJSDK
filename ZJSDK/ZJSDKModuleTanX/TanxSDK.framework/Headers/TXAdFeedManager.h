//
//  TXAdFeedManager.h
//  TanxSDK
//
//  Created by guqiu on 2022/1/4.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "TXAdFeedManagerDelegate.h"
#import "TXAdFeedTemplateConfig.h"
#import "TXAdFeedView.h"
#import "TXAdFeedBinder.h"
#import "TXAdModel.h"
#import "TXAdFeedSlotModel.h"

@class TXAdFeedModule;

NS_ASSUME_NONNULL_BEGIN

/// 渲染模式枚举
typedef NS_ENUM(NSUInteger, TXAdFeedRenderMode) {
    TXAdFeedRenderModeTemplate = 1,     // 模板渲染
    TXAdFeedRenderModeCustom = 2,       // 自渲染
};

/// 广告类型
typedef NS_ENUM(NSUInteger, TXAdFeedAdType) {
    TXAdFeedAdTypeImage = 1,       // 图片广告
    TXAdFeedAdTypeVideo = 2,       // 视频广告
};

/// 获取广告数据回调block
typedef void(^TXAdFeedAdsBlock)(NSArray <TXAdModel *> * _Nullable viewModelArray, NSError * _Nullable error);

@interface TXAdFeedModule : NSObject

/// 模板内容
@property (nonatomic, strong) UIView *view;

/// 模板的size
@property (nonatomic, assign) CGSize size;

/// 当前数据源
@property (nonatomic, strong) TXAdModel *adModel;

- (void)destoryFeedModule;

@end

@interface TXAdFeedManager : NSObject


@property (nonatomic, weak) id<TXAdFeedManagerDelegate> delegate;

/// 初始化配置参数model
@property (nonatomic, copy, readonly) TXAdFeedSlotModel *slotModel;

/**
 *  初始化方法
 *
 *  @param slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdFeedSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *
 *  @param pid 广告pid
 *  @return instancetype
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  发起feed广告请求，返回广告数据：
 *  1、媒体可获取通过 TXAdModel.bid.bidPrice 获取报价，并返回竞价结果，若为空则表明该媒体没有获取权限；
 *
 *  @param adCount                    获取多少个广告
 *  @param renderMode             渲染模式（模板渲染 or 自渲染）
 *  @param adsBlock                 广告数据block
 */
- (void)getFeedAdsWithAdCount:(NSInteger)adCount
                   renderMode:(TXAdFeedRenderMode)renderMode
                     adsBlock:(TXAdFeedAdsBlock)adsBlock;

/**
 *  上报竞价结果（媒体如果选择竞价，则调用；不需要，则忽略）
 *
 *  @param model 数据
 *  @param result 结果YES/NO
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 *  通过广告数据获取广告模板
 *
 *  @param modelArray      广告数据
 *  @param config               广告模版配置
 *  @return NSArray             广告模板数组
 */
- (NSArray <TXAdFeedModule *> *)renderFeedTemplateWithModel:(NSArray <TXAdModel *> *)modelArray
                                                     config:(TXAdFeedTemplateConfig *)config;

/**
 *  媒体自己渲染广告UI，通过广告数据获取广告Binder
 *
 *  @param modelArray      广告数据
 *  @return NSArray             广告字渲染Binder数组
 */
- (NSArray <TXAdFeedBinder *> *)customRenderingBinderWithModels:(NSArray <TXAdModel *> *)modelArray;

/**
 *  重新设置一遍Feed信息流的UII配置（当发生了字体变化、暗黑模式和正常模式切换的情况）
 *
 *  @param config 配置
 */
- (void)resetFeedConfig:(TXAdFeedTemplateConfig *)config;


#pragma mark - Unavailable
/// ("该接口已废弃，请使用 initWithSlotModel: or initWithPid:")
- (instancetype) init NS_UNAVAILABLE;

/// ("该接口已废弃，请使用 initWithSlotModel: or initWithPid:")
+ (instancetype) new  NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
