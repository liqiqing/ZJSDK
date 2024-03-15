//
//  TXAdManagerDelegate.h
//  TanxSDK
//
//  Created by guqiu on 2021/12/30.
//  Copyright © 2021 tanx.com. All rights reserved.
//

#ifndef TXAdManagerDelegate_h
#define TXAdManagerDelegate_h

#import "TXAdModel.h"

@protocol TXAdManagerDelegate <NSObject>

@optional

/**
 *  广告点击回调，或者触发了摇一摇跳转（跳转逻辑sdk实现）
 *
 *  @param model 数据model
 */
- (void)onAdClick:(TXAdModel *)model;

/**
 *  广告load失败回调，error code详细查看：https://tanxsdk.yuque.com/staff-vdu2kd/wk7mhx/xmp66rp7p8k63tu8/
 *
 *  @param model 数据model
 *  @param error 错误
 */
- (void)onAdLoadFail:(TXAdModel *)model error:(NSError *)error;

/**
 *  广告开始展示
 *
 *  @param model 数据model
 */
- (void)onAdShow:(TXAdModel *)model;

/**
 *  广告关闭
 *
 *  @param model 数据model
 */
- (void)onAdClose:(TXAdModel *)model;

/**
 *  广告渲染成功
 *
 *  @param model 数据model
 */
- (void)onAdRenderSuccess:(TXAdModel *)model;

/**
 *  广告曝光
 *
 *  @param model 数据model
 */
- (void)onAdExposing:(TXAdModel *)model;

/**
 *  跳转到h5，如接入方接管跳转落地页，则需要实现此代理方法
 *
 *  @param webUrl  跳转地址
 */
- (void)onAdJumpToWeb:(NSString *)webUrl;

@end


#endif /* TXAdManagerDelegate_h */
