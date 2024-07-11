//
//  ZJNativeAdBaseTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeAdBaseTableViewCell.h"

@implementation ZJNativeAdBaseTableViewCell

-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        
    }
    return self;
}


- (void)setupWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject delegate:(id<ZJNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{
    
}

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject{
    
    return ZJNativeTopHeight+5+ZJNativeBottomHight;
}

    
- (void)prepareForReuse{
    [super prepareForReuse];
    [self.fillView unregisterDataObject];
//    [self.fillView removeFromSuperview];
//    [self.adView removeFromSuperview];
//    _fillView = nil;
//    _adView = nil;
}
    
-(void)dealloc{
    [_fillView unregisterDataObject];
}
    

-(ZJFillNativeAdView *)fillView{
    if (!_fillView) {
        _fillView= [[ZJFillNativeAdView alloc]initWithFrame:self.contentView.bounds];
        
    }
    return _fillView;
}

@end
