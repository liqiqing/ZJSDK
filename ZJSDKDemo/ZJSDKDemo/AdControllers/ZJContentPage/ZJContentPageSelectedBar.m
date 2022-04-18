//
//  ZJContentPageSelectedBar.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/23.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJContentPageSelectedBar.h"
@interface ZJContentPageSelectedBar()
@property (nonatomic,strong)UIButton *videoBtn;
@property (nonatomic,strong)UIButton *otherBtn;

@property (nonatomic,assign)NSInteger index;


@property (nonatomic,copy)void(^selectIndexBlock)(NSInteger index);
@end

@implementation ZJContentPageSelectedBar

-(instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        [self addSubview:self.videoBtn];
        [self.videoBtn mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.bottom.mas_equalTo(0);
            make.width.mas_equalTo(60);
            make.centerX.mas_equalTo(-40);
        }];
        
        [self addSubview:self.otherBtn];
        [self.otherBtn mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.bottom.mas_equalTo(0);
            make.width.mas_equalTo(60);
            make.centerX.mas_equalTo(40);
        }];
    }
    return self;
}

-(void)selectIndex:(NSInteger)index{
    self.index = index;
}

-(void)selectActionWithIndex:(void(^)(NSInteger index))callback{
    self.selectIndexBlock = callback;
}

-(void)setIndex:(NSInteger)index{
    _index = index;
    if (index == 0) {
        _videoBtn.titleLabel.font = [UIFont boldSystemFontOfSize:18];
        _otherBtn.titleLabel.font = [UIFont systemFontOfSize:16];
    }else if(index == 1){
        _videoBtn.titleLabel.font = [UIFont systemFontOfSize:16];
        _otherBtn.titleLabel.font = [UIFont boldSystemFontOfSize:18];
    }
}



-(void)clickIndexBtn:(UIButton *)btn{
    if (_index == btn.tag) {
        return;
    }
    self.index = btn.tag;
    if (self.selectIndexBlock) {
        self.selectIndexBlock(self.index);
    }
}


-(UIButton *)videoBtn{
    if (!_videoBtn) {
        _videoBtn = [self createButtonWithTitle:@"推荐"];
        _videoBtn.tag = 0;
    }
    return _videoBtn;
}

-(UIButton *)otherBtn{
    if (!_otherBtn) {
        _otherBtn = [self createButtonWithTitle:@"其他"];
        _otherBtn.tag = 1;
    }
    return _otherBtn;
}

-(UIButton *)createButtonWithTitle:(NSString *)title{
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont systemFontOfSize:16];
    [btn addTarget:self action:@selector(clickIndexBtn:) forControlEvents:UIControlEventTouchUpInside];
    return btn;
}
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
