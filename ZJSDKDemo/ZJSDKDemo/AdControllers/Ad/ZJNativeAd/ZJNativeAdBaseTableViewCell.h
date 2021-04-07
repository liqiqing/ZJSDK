//
//  ZJNativeAdBaseTableViewCell.h
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ZJSDK/ZJNativeAd.h>
#import "ZJFillNativeAdView.h"
NS_ASSUME_NONNULL_BEGIN
//头部高度。头像、标题，描述+顶部空隙+下部分视图开始的位置
#define ZJNativeTopHeight (45+5+10)
@interface ZJNativeAdBaseTableViewCell : UITableViewCell

@property (nonatomic,strong)ZJFillNativeAdView *fillView;
@property (nonatomic,strong)UIView *adView;



- (void)setupWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject delegate:(id<ZJNativeAdViewDelegate>)delegate vc:(UIViewController *)vc;

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject;




@end

NS_ASSUME_NONNULL_END
