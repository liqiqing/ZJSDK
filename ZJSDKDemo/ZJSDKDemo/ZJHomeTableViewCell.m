//
//  ZJHomeTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2022/3/2.
//  Copyright © 2022 zj. All rights reserved.
//

#import "ZJHomeTableViewCell.h"

@interface ZJHomeTableViewCell()

@end

@implementation ZJHomeTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.contentView.backgroundColor = [UIColor whiteColor];
        UIView *bgView = [[UIView alloc]init];
        bgView.backgroundColor = [UIColor colorWithRed:255/255.0 green:250/255.0 blue:240/255.0 alpha:1.0f];
        [self.contentView addSubview:bgView];
        [bgView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.top.offset(6);
            make.bottom.offset(0);
            make.right.offset(-6);
        }];
        
        self.iconImageView = [[UIImageView alloc]init];
        [bgView addSubview:self.iconImageView];
        [self.iconImageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerY.offset(0);
            make.left.offset(6);
            make.size.mas_equalTo(CGSizeMake(30, 30));
        }];
        
        self.titleLabel = [[UILabel alloc] init];
        self.titleLabel.textColor = kMainColor;
        self.titleLabel.font = [UIFont systemFontOfSize:18];
        [bgView addSubview:self.titleLabel];
        [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerY.offset(0);
            make.left.mas_equalTo(self.iconImageView.mas_right).offset(12);
            make.right.offset(-5);
        }];
        
    }
    return self;
}


@end
