//
//  ZJAdLoadView.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJAdLoadView.h"
#define    ColorFromRGB(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define customGray1Color ColorFromRGB(234, 234, 234)
#define customGray2Color ColorFromRGB(224, 224, 224)
#define customGray3Color ColorFromRGB(212, 212, 221)

#define viewWidth self.frame.size.width
#define viewHeight self.frame.size.height

#define buttonHeight 30
@interface ZJAdLoadView ()
{
    UIButton *_loadButton;
    UIButton *_showButton;
    UITextField *_adIDTextField;
}
@property(nonatomic,strong) UITextView *logView;
@property(nonatomic,strong) UIButton *changeButton;
@property(nonatomic,copy) NSArray *adsArray;
@end

@implementation ZJAdLoadView

+(instancetype) creat:(CGFloat) top{
    CGRect frame = [UIScreen mainScreen].bounds;
    frame.origin.y = top+6;
    frame.size.height = frame.size.height-top-6;
    ZJAdLoadView *objView = [[ZJAdLoadView alloc] initWithFrame:frame];
    return objView;
}

-(instancetype) initWithFrame:(CGRect)frame{
    if(self=[super initWithFrame:frame]){
        [self addSubview:self.changeButton];
        [self.changeButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.right.mas_equalTo(self).mas_offset(-6);
            make.top.mas_equalTo(self);
            make.size.mas_equalTo(CGSizeMake(100, 36));
        }];
        
        [self addSubview:self.adIDTextField];
        [self.adIDTextField mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self).mas_offset(6);
            make.centerY.mas_equalTo(self.changeButton);
            make.right.mas_equalTo(self.changeButton.mas_left).offset(-6);
        }];
        
        [self addSubview:self.loadButton];
        [self.loadButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(self.changeButton.mas_bottom).mas_offset(4);
            make.left.mas_equalTo(self.adIDTextField);
            make.right.mas_equalTo(self.changeButton);
            make.height.mas_equalTo(36);
        }];
        [self addSubview:self.showButton];
        [self.showButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(self.loadButton.mas_bottom).mas_offset(4);
            make.left.right.mas_equalTo(self.loadButton);
            make.height.mas_equalTo(36);
        }];
        [self addSubview:self.logView];
        [self.logView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(self.showButton.mas_bottom).mas_offset(4);
            make.left.right.bottom.mas_equalTo(self);
        }];
    }
    return self;
}

-(void) clearLog{
    self.logView.text = @"";
}
-(void) addLog:(NSString*) log{
    self.logView.text = [NSString stringWithFormat:@"%@\n%@",self.logView.text,log];
}


-(void) appendAdID:(NSArray*) adsID{
    self.adsArray = adsID;
    if(self.adsArray.count>0)
        self.adIDTextField.text = self.adsArray.firstObject;
}

-(void) changeAdID:(NSString*) adID{
    if(![self.adIDTextField.text isEqualToString:adID]){
        self.adIDTextField.text = adID;
        
    }
}


-(UITextView *)logView{
    if(!_logView){
        _logView = [[UITextView alloc] initWithFrame:CGRectMake(0, 70, viewWidth, viewHeight-70)];
        _logView.scrollEnabled = YES;
        _logView.textColor = [UIColor blackColor];
        _logView.editable = NO;
    }
    return _logView;
}


-(UIButton*) loadButton{
    if(!_loadButton){
        _loadButton = [UIButton buttonWithType:UIButtonTypeSystem];
        _loadButton.backgroundColor = [UIColor cyanColor];
        [_loadButton setTitle:@"加载广告" forState:UIControlStateNormal];
    }
    
    return _loadButton;;
}

-(UIButton*) showButton{
    if(!_showButton){
        _showButton = [UIButton buttonWithType:UIButtonTypeSystem];
        _showButton.backgroundColor = [UIColor lightGrayColor];
        [_showButton setTitle:@"展示广告" forState:UIControlStateNormal];
    }
    return _showButton;;
}

-(UIButton*) changeButton{
    if(!_changeButton){
        _changeButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [_changeButton setTitle:@"切换广告ID" forState:UIControlStateNormal];
        [_changeButton clickHandle:^(UIButton *button) {
            [self showAdsID];
        }];
    }
    return _changeButton;;
}

-(UITextField *)adIDTextField{
    if(!_adIDTextField){
        _adIDTextField = [UITextField new];
        _adIDTextField.borderStyle = UITextBorderStyleLine;
    }
    return _adIDTextField;
}

-(void) showAdsID{
    //初始化一个UIAlertController的警告框
    UIAlertController *alertController = [[UIAlertController alloc] init];
    UIAlertAction *cancle = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
    
    }];
    [alertController addAction:cancle];
    if(self.adsArray.count>0){
        for (NSString *adIdStr in self.adsArray) {
            UIAlertAction *alAction = [UIAlertAction actionWithTitle:adIdStr style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
                [self changeAdID:adIdStr];
            }];
            [alertController addAction:alAction];
        }
    }else{
        UIAlertAction *alAction = [UIAlertAction actionWithTitle:@"没有设置广告ID" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
            
        }];
        [alertController addAction:alAction];
    }
  
    [self.rootViewController presentViewController:alertController animated:true completion:nil];
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
