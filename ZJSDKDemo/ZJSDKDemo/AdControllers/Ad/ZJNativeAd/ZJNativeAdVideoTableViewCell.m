//
//  ZJNativeAdVideoTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeAdVideoTableViewCell.h"

@implementation ZJNativeAdVideoTableViewCell

- (void)setupWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject delegate:(id<ZJNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{

//
    
    self.fillView.viewController = vc;
    self.fillView.delegate = delegate;
    
   
    if (!self.adView) {
        self.adView = [self.fillView registerDataObject:dataObject];
        self.fillView.videoAdView.frame = CGRectMake(0, ZJNativeTopHeight, self.frame.size.width, 150);
        [self.contentView addSubview:self.adView];
    }
}


+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject
{
    
    CGFloat baseHeigth =  [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
     
     //视频cell
     CGFloat videoHeight = 150;
     //图片高度+顶部固定高度+底部间隙
     return videoHeight+baseHeigth+8;
}
@end
