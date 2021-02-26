//
//  ZJAdEditTextView.h
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/29.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIButton+Event.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJAdEditTextView : UIView

@property (nonatomic,strong)UITextView *adTextView;

@property(nonatomic,strong) UIButton *loadButton;

@property(nonatomic,strong) UIButton *changeButton;

@property(nonatomic,weak) UIViewController *rootViewController;

+(instancetype) creat:(CGFloat) top;

-(void) clearLog;

-(void) addLog:(NSString*) log;

-(void) appendAdID:(NSArray*) adsID;
@end

NS_ASSUME_NONNULL_END
