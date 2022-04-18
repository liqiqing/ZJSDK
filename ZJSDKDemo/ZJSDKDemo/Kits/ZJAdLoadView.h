//
//  ZJAdLoadView.h
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIButton+Event.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJAdLoadView : UIView

@property(nonatomic,strong,readonly) UIButton *loadButton;
@property(nonatomic,strong,readonly) UIButton *showButton;
@property(nonatomic,strong,readonly) UITextField *adIDTextField;
@property(nonatomic,weak) UIViewController *rootViewController;

+(instancetype)creat:(CGFloat)top;
-(void)clearLog;
-(void)addLog:(NSString *)log;
-(void)appendAdID:(NSArray *)adsID;

@end

NS_ASSUME_NONNULL_END
