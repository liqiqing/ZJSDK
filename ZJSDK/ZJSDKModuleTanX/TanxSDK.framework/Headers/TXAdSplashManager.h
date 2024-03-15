//
//  TXAdSplashManager.h
//  TanxSDK
//
//  Created by XY on 2021/12/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TXAdSplashManagerDelegate.h"
#import "TXAdModel.h"
#import "TXAdSplashTemplateConfig.h"
#import "TXAdSplashSlotModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 获取广告数据回调block
typedef void(^TXAdGetSplashAdDataBlock)(NSArray <TXAdModel *> * _Nullable splashModels, NSError * _Nullable error);

@interface TXAdSplashManager : NSObject

/// 代理需要实现的协议
@property (nonatomic, weak) id<TXAdSplashManagerDelegate> delegate;

/// 初始化配置参数model
@property (nonatomic, copy, readonly) TXAdSplashSlotModel *slotModel;

/**
 *  初始化方法
 *
 *  @param slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdSplashSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *
 *  @param pid 广告pid
 *  @return instancetype
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  预请求，接口已经废弃
 */
- (void)preGetSplashAdData NS_UNAVAILABLE;

/**
 *  发起获取开屏广告请求获取广告数据
 *
 *  @param adsDataBlock    返回广告数据
 */
- (void)getSplashAdsWithAdsDataBlock:(TXAdGetSplashAdDataBlock)adsDataBlock;

/**
 *  上报竞价结果（媒体如果选择竞价，则调用；不需要，则忽略）
 *
 *  @param model 数据
 *  @param result 结果YES/NO
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 *  通过广告数据获取开屏广告模板
 *
 *  @param model     开屏广告数据
 *  @return UIView   开屏广告模板
 */
- (nullable UIView *)renderSplashTemplateWithAdModel:(TXAdModel *)model config:(TXAdSplashTemplateConfig *)config;

/**
 *  删除本地缓存的开屏素材
 *
 *  @param finishBlock block
 */
- (void)removeLocalMaterials:(dispatch_block_t)finishBlock;

/**
 *  删除缓存JSON数据
 */
- (void)removeLocalData;

/**
 *  删除开屏的所有缓存数据
 */
- (void)removeLocalAssets;


#pragma mark - Unavailable
/// ("该接口不可用，请使用 initWithSlotModel: or initWithPid:")
- (instancetype) init NS_UNAVAILABLE;

/// ("该接口不可用，请使用 initWithSlotModel: or initWithPid:")
+ (instancetype) new  NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
