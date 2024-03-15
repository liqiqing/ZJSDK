//
//  TXAdTableScreenManager.h
//  TanxSDK-iOS
//
//  Created by tongyuecheng on 2023/1/5.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "TXAdManagerDelegate.h"
#import "TXAdModel.h"
#import "TXAdTableScreenSlotModel.h"


NS_ASSUME_NONNULL_BEGIN

@class TXAdTableScreenManager;

typedef void(^TXAdGetTableScreenAdDataBlock)(NSArray <TXAdModel *> * _Nullable tableScreenModels, NSError * _Nullable error);

@protocol TXAdTableScreenManagerDelegate <NSObject,TXAdManagerDelegate>

@optional

/**
 * 广告渲染失败
 * @param model 数据模型
 * @param error 错误信息
 */
- (void)onAdRenderFail:(TXAdModel *)model withError:(NSError *)error;

@end


// 插屏广告管理对象
@interface TXAdTableScreenManager : NSObject

/// 给媒体的回调代理
@property(nonatomic, weak) id<TXAdTableScreenManagerDelegate> delegate;

/**
 *  初始化方法
 *  @param  pid 广告pid
 *  @return instancetype
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *
 *  @param  slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdTableScreenSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/**
 * 发起插屏广告请求，获取广告数据
 * @param adsDataBlock 返回广告数据
 */
- (void)getTableScreenAdsWithAdsDataBlock:(TXAdGetTableScreenAdDataBlock)adsDataBlock;

/**
 * 上报竞价结果
 * param model 数据model(请求数据的回调里拿到的model)
 * @param  result 竞价结果yes/no
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 *  展示广告
 *  在loadAdWithSuccess 成功回调后调用
 *  @param  viewController 当前VC
 *  @param adModel  数据model
 */
- (void)showAdOnRootViewController:(UIViewController *)viewController withModel:(TXAdModel *)adModel;


- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

