//
//  ZJNativeExpressAdTableViewCell.h
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ZJSDK/ZJNativeExpressFeedAdManager.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJNativeExpressAdTableViewCell : UITableViewCell


-(void)refreshWithAd:(ZJNativeExpressFeedAd *)ad;

@end

NS_ASSUME_NONNULL_END
