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
    
    [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView]];
    self.fillView.videoAdView.frame = CGRectMake(0, ZJNativeTopHeight, self.frame.size.width, 150);
    [self.fillView resizeIfNeed];
    [self.contentView addSubview:self.fillView];
    [self.contentView addSubview:self.muteBtn];

//    self.fillView.logoView.hidden = YES;
}


+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject
{
    CGFloat baseHeigth =  [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
     
     //视频cell
     CGFloat videoHeight = 150;
     //图片高度+顶部固定高度+底部间隙
     return videoHeight+baseHeigth+8;
}

-(UIButton *)muteBtn{
    if (!_muteBtn) {
        _muteBtn = [[UIButton alloc]initWithFrame:CGRectMake(self.frame.size.width-30, self.frame.size.height-ZJNativeBottomHight-8, 20, 20)];
//        _muteBtn.backgroundColor = [UIColor redColor];
        [_muteBtn setImage:[UIImage imageNamed:@"sound_open"] forState:UIControlStateNormal];
        [_muteBtn setImage:[UIImage imageNamed:@"sound_close"] forState:UIControlStateSelected];
        [_muteBtn addTarget:self action:@selector(muteAction:) forControlEvents:UIControlEventTouchUpInside];
    }
    return _muteBtn;
}

-(void)muteAction:(UIButton *)sender{
    sender.selected = !sender.selected;
    self.fillView.mutedIfCan = sender.selected;
}
@end
