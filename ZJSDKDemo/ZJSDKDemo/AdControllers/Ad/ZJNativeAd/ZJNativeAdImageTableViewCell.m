//
//  ZJNativeAdTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeAdImageTableViewCell.h"

@interface ZJNativeAdImageTableViewCell()



@end

@implementation ZJNativeAdImageTableViewCell


#pragma mark - public
- (void)setupWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject delegate:(id<ZJNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{
    //配置单图广告
    [self.fillView.imageView mas_updateConstraints:^(MASConstraintMaker *make) {
        make.height.mas_equalTo((ScreenWidth-10)*(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue));
        
    }];
    
    self.fillView.delegate = delegate; // adView 广告回调
    self.fillView.viewController = vc; // 跳转 VC
    if (!self.adView) {
        self.adView = [self.fillView registerDataObject:dataObject];
        [self.contentView addSubview:self.adView];
    }
}

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject
{
   CGFloat baseHeigth =  [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
    
    //单图cell
    CGFloat imageHeight = (ScreenWidth-10)*(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue);
    //图片高度+顶部固定高度+底部间隙
    return imageHeight+baseHeigth+8;
}




@end
