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

@interface ZJNativeAdBaseTableViewCell : UITableViewCell

@property (nonatomic,strong)ZJFillNativeAdView *fillView;
//@property (nonatomic,strong)UIView *adView;



- (void)setupWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject delegate:(id<ZJNativeAdViewDelegate>)delegate vc:(UIViewController *)vc;

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject;




@end

NS_ASSUME_NONNULL_END
