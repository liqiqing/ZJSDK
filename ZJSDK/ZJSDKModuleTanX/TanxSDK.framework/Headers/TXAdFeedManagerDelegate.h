//
//  TXAdFeedManagerDelegate.h
//  TanxCoreSDK
//
//  Created by guqiu on 2022/1/4.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#ifndef TXAdFeedManagerDelegate_h
#define TXAdFeedManagerDelegate_h

#import "TXAdManagerDelegate.h"

@protocol TXAdFeedManagerDelegate <NSObject,TXAdManagerDelegate>

@optional

/**
 *  广告滑动跳转回调
 *
 *  @param model 数据model
 */
- (void)onAdSliding:(TXAdModel *)model;

/**
 *  点击了“不喜欢”菜单中的选项
 *
 *  @param model 数据model
 *  @param index  选项次序索引
 */
- (void)onAdClickDislikeOptions:(TXAdModel *)model index:(NSInteger)index;

/**
 *  自渲染支持可点击区域（仅自渲染回调）
 *      0、只有在binder调用registerFeedViewClickableViews:方法才会回调
 *  @param model            数据model
 *  @param clickView   点击的clickView
 */
- (void)onAdClick:(TXAdModel *)model clickView:(UIView *)clickView;

@end


#endif /* TXAdFeedManagerDelegate_h */
