//
//  ZJAdEditTextView.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/29.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJAdEditTextView.h"


#define buttonHeight 30
@interface ZJAdEditTextView()
@property(nonatomic,strong) UITextView *logView;

@property(nonatomic,copy) NSArray *adsArray;


@end

@implementation ZJAdEditTextView

+(instancetype) creat:(CGFloat) top{
    CGRect frame = [UIScreen mainScreen].bounds;
    frame.origin.y = top+6;
    frame.size.height = frame.size.height-top-6;
    ZJAdEditTextView *objView = [[ZJAdEditTextView alloc] initWithFrame:frame];
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
        
        [self addSubview:self.adTextView];
        [self.adTextView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self).mas_offset(6);
            make.top.mas_equalTo(self.changeButton);
            make.right.mas_equalTo(self.changeButton.mas_left).offset(-6);
            make.height.mas_equalTo(100);
        }];
        
        [self addSubview:self.loadButton];
        [self.loadButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(self.adTextView.mas_bottom).mas_offset(4);
            make.left.mas_equalTo(self.adTextView);
            make.right.mas_equalTo(self.changeButton);
            make.height.mas_equalTo(36);
        }];
//        [self addSubview:self.showButton];
//        [self.showButton mas_makeConstraints:^(MASConstraintMaker *make) {
//            make.top.mas_equalTo(self.loadButton.mas_bottom).mas_offset(4);
//            make.left.right.mas_equalTo(self.loadButton);
//            make.height.mas_equalTo(36);
//        }];
        [self addSubview:self.logView];
        [self.logView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(self.loadButton.mas_bottom).mas_offset(4);
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
        self.adTextView.text = self.adsArray.firstObject;
}

-(void) changeAdID:(NSString*) adID{
    if(![self.adTextView.text isEqualToString:adID]){
        self.adTextView.text = adID;
        
    }
}


-(UITextView *)logView{
    if(!_logView){
        _logView = [[UITextView alloc] initWithFrame:CGRectMake(0, 70, self.width, self.height-70)];
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
        [_loadButton setTitle:@"加载数据" forState:UIControlStateNormal];
    }
    
    return _loadButton;;
}

//-(UIButton*) showButton{
//    if(!_showButton){
//        _showButton = [UIButton buttonWithType:UIButtonTypeSystem];
//        _showButton.backgroundColor = [UIColor lightGrayColor];
//        [_showButton setTitle:@"展示广告" forState:UIControlStateNormal];
//    }
//    return _showButton;;
//}

-(UIButton*) changeButton{
    if(!_changeButton){
        _changeButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [_changeButton setTitle:@"切换" forState:UIControlStateNormal];
        [_changeButton clickHandle:^(UIButton *button) {
            [self showAdsID];
        }];
    }
    return _changeButton;;
}

-(UITextView *)adTextView{
    if (!_adTextView) {
        _adTextView = [[UITextView alloc]init];
        _adTextView.layer.borderWidth = 1;
        _adTextView.layer.borderColor = [UIColor blackColor].CGColor;
    }
    return _adTextView;
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


@end
