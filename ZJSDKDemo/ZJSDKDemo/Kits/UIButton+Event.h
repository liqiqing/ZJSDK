//
//  UIButton+Event.h
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void (^ClickEvent)(UIButton *button);
NS_ASSUME_NONNULL_BEGIN

@interface UIButton (Event)
-(void) clickHandle:(ClickEvent)clickEvent;
@end

NS_ASSUME_NONNULL_END
