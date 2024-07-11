//
//  ZJNativeAdAtlasImageTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeAdAtlasImageTableViewCell.h"

@implementation ZJNativeAdAtlasImageTableViewCell

#pragma mark - public
- (void)setupWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject delegate:(id<ZJNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{
    
    
    self.fillView.viewController = vc;
    self.fillView.delegate = delegate;
//    if (!self.fillView) {
        CGFloat imageWidth = (kScreenWidth-20)/3.0;
        CGFloat imageHeight = imageWidth *(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue);
        for (int i = 0; i<dataObject.mediaUrlList.count; i++) {
            NSString *urlString = dataObject.mediaUrlList[i];
            //行
            NSInteger line =floorf(i/3.0);
            //y
            CGFloat y = ZJNativeTopHeight+(line *(imageHeight+5));
            //每一行的位置
            NSInteger index = i - line*3;
            CGFloat x =  5*(index+1)+imageWidth*index;
            
            UIImageView *imageView = [[UIImageView alloc]init];
            imageView.frame = CGRectMake(x,y, imageWidth,imageHeight);
            [imageView sd_setImageWithURL:[NSURL URLWithString:urlString]];
            [self.fillView addSubview:imageView];
        }
        
        
        [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView]];
        [self.contentView addSubview:self.fillView];
        
//        self.fillView.logoView.hidden = YES;
//    }
}

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject
{
    CGFloat baseHeigth =  [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
    CGFloat imageWidth = (kScreenWidth-20)/3.0;
    CGFloat imageHeight = imageWidth *(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue);
    NSInteger totalLine =ceilf(dataObject.mediaUrlList.count/3.0);
    CGFloat totalHeight = totalLine *(imageHeight+5);
    return totalHeight +baseHeigth+8;
}




@end
