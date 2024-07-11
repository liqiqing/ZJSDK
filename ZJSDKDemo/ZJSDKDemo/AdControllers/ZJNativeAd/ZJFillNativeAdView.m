//
//  ZJFillNativeAdView.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJFillNativeAdView.h"

@interface ZJFillNativeAdView()



@end

@implementation ZJFillNativeAdView

-(instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        [self addSubview:self.titleLabel];
        [self addSubview:self.descLabel];
        [self addSubview:self.clickButton];
        [self addSubview:self.imageView];

        [self addSubview:self.appIconImageView];
     
//        [self addSubview:self.videoAdView];
        
        
        [self.clickButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.right.mas_offset(-2);
            make.top.mas_equalTo(10);
            make.width.mas_equalTo(40);
            make.height.mas_equalTo(30);
        }];
        
        
        [self.appIconImageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(5);
            make.top.mas_equalTo(5);
            make.width.mas_equalTo(0);
            make.height.mas_equalTo(45);
        }];
        [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.appIconImageView.mas_right).offset(5);
            make.top.mas_equalTo(5);
            make.right.mas_equalTo(self.clickButton.mas_left).offset(-2);
            make.height.mas_equalTo(22.5);
        }];
        
        [self.descLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.titleLabel.mas_left);
            make.top.mas_equalTo(self.titleLabel.mas_bottom).offset(0);
            make.right.mas_equalTo(self.clickButton.mas_left).offset(-2);
            make.height.mas_equalTo(22.5);
        }];
        
        [self.imageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(5);
            make.top.mas_equalTo(self.descLabel.mas_bottom).offset(10);
            make.width.mas_equalTo(kScreenWidth-10);
            make.height.mas_equalTo(0);
        }];
        

        
    }
    return self;
}


-(void)registerDataObject:(ZJNativeAdObject *)dataObject clickableViews:(nonnull NSArray<UIView *> *)clickableViews{
    self.titleLabel.text = dataObject.title.length > 0?dataObject.title:@"广告标题";
    self.descLabel.text = dataObject.desc;
    
    if (dataObject.iconUrl.length > 0) {
        self.appIconImageView.hidden = NO;
        [self.appIconImageView mas_updateConstraints:^(MASConstraintMaker *make) {
            make.width.mas_equalTo(45);
        }];
        
    }else{
        self.appIconImageView.hidden = YES;
        [self.appIconImageView mas_updateConstraints:^(MASConstraintMaker *make) {
            make.width.mas_equalTo(0);
        }];
    }
    if (dataObject.isAppAd&&dataObject.appName.length > 0) {
        self.titleLabel.text = dataObject.appName;
    }
    
    
    
    
    [self.appIconImageView sd_setImageWithURL:[NSURL URLWithString:dataObject.iconUrl]];
    
    [self.imageView sd_setImageWithURL:[NSURL URLWithString:dataObject.imageUrl]];
 
    if (dataObject.callToAction.length > 0) {
        [self.clickButton setTitle:dataObject.callToAction forState:(UIControlStateNormal)];
    }else{
        if (dataObject.isAppAd) {
            [self.clickButton setTitle:@"下载" forState:(UIControlStateNormal)];
        }else{
            [self.clickButton setTitle:@"打开" forState:(UIControlStateNormal)];
        }
    }
    
    CGSize btnSize = [self.clickButton sizeThatFits:CGSizeZero];
    [self.clickButton mas_updateConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo(btnSize.width);
    }];
    
    
    if (dataObject.materialType == ZJAdMaterialTypeVideo) {
        self.videoAdView.hidden = NO;
        self.imageView.hidden = YES;
    }else if(dataObject.materialType == ZJAdMaterialTypeAtlas){
        self.imageView.hidden = YES;
        self.videoAdView.hidden = YES;
    }else{
        self.imageView.hidden = NO;
        self.videoAdView.hidden = YES;
    }
    
    [super registerDataObject:dataObject clickableViews:clickableViews];
    
    CGRect logoReact = self.logoView.frame;
    logoReact.origin.x = 10;
    logoReact.origin.y = self.frame.size.height-ZJNativeBottomHight-8;
    self.logoView.frame = logoReact;
    [self addSubview:self.logoView];
}



#pragma mark - proerty getter
- (UILabel *)titleLabel
{
    if (!_titleLabel) {
        _titleLabel = [[UILabel alloc] init];
        _titleLabel.font = [UIFont systemFontOfSize:12];
        _titleLabel.accessibilityIdentifier = @"titleLabel_id";
        
    }
    return _titleLabel;
}

- (UIImageView *)imageView
{
    if (!_imageView) {
        _imageView = [[UIImageView alloc] init];
        
        _imageView.accessibilityIdentifier = @"imageView_id";
    }
    return _imageView;
}

- (UILabel *)descLabel
{
    if (!_descLabel) {
        _descLabel = [[UILabel alloc] init];
        _descLabel.font = [UIFont systemFontOfSize:12];
        _descLabel.accessibilityIdentifier = @"descLabel_id";
    }
    return _descLabel;
}

- (UIButton *)clickButton
{
    if (!_clickButton) {
        _clickButton = [[UIButton alloc] init];
        [_clickButton setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
        [_clickButton setBackgroundColor:[[UIColor yellowColor] colorWithAlphaComponent:0.4]];
        _clickButton.accessibilityIdentifier = @"clickButton_id";
        
    }
    return _clickButton;
}



- (UIImageView *)appIconImageView
{
    if (!_appIconImageView) {
        _appIconImageView = [[UIImageView alloc] init];
        _appIconImageView.accessibilityIdentifier = @"iconImageView_id";
    }
    return _appIconImageView;
}




-(void)dealloc{
    
}


@end
