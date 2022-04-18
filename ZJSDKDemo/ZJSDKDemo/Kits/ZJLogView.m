//
//  ZJLogView.m
//  ZJSDKDemo
//
//  Created by Rare on 2022/3/3.
//  Copyright © 2022 zj. All rights reserved.
//

#import "ZJLogView.h"

@interface ZJLogView()
@property (nonatomic,strong)UITextView *logView;
@end

@implementation ZJLogView
-(instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        [self addSubview:self.logView];
        [self.logView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.edges.mas_equalTo(0);
        }];
        
        UIButton *closeBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [closeBtn setImage:[UIImage imageNamed:@"close_white"] forState:UIControlStateNormal];
        [closeBtn addTarget:self action:@selector(clickClose:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:closeBtn];
        [closeBtn mas_makeConstraints:^(MASConstraintMaker *make) {
            make.right.top.mas_equalTo(0);
            make.size.mas_equalTo(CGSizeMake(30, 30));
        }];
    }
    return self;
}
-(void)clickClose:(UIButton *)btn{
    [self removeFromSuperview];
}

-(void)clearLog{
    self.logView.text = @"";
}
-(void)logMessage:(NSString *)log{
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    formatter.dateFormat = @"HH:mm:ss";
    NSString *str = [NSString stringWithFormat:@"[%@] %@",[formatter stringFromDate:[NSDate date]],log];
    NSString *text = self.logView.text;
    if (text.length > 0) {
        text = [NSString stringWithFormat:@"%@\n%@",self.logView.text,str];
    }else{
        text = str;
    }
    self.logView.text = text;
    [self.logView scrollRangeToVisible:NSMakeRange(self.logView.text.length, 1)];
}

-(UITextView *)logView{
    if(!_logView){
        _logView = [[UITextView alloc] initWithFrame:self.bounds];
        _logView.scrollEnabled = YES;
        _logView.textColor = [UIColor whiteColor];
        _logView.backgroundColor = [UIColor blackColor];
        _logView.editable = NO;
        _logView.font = [UIFont systemFontOfSize:16];
        _logView.showsVerticalScrollIndicator = YES;
        _logView.layoutManager.allowsNonContiguousLayout= NO;
    }
    return _logView;
}
@end
