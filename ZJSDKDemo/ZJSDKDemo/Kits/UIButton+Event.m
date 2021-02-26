//
//  UIButton+Event.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "UIButton+Event.h"
#import <objc/runtime.h>
static const void *clickEventKey = &clickEventKey;
@interface UIButton ()
{
   
}
@property (nonatomic, copy) ClickEvent clickEvent;
    
@end
@implementation UIButton (Event)
-(void) clickHandle:(ClickEvent)clickEvent{
    self.clickEvent = clickEvent;
    [self addTarget:self action:@selector(clickEventHandle:) forControlEvents:UIControlEventTouchUpInside];
}

-(void) clickEventHandle:(UIButton*) button{
    if(self.clickEvent)
        self.clickEvent(button);
}

- (ClickEvent)clickEvent {
    return objc_getAssociatedObject(self, clickEventKey);
    
}

- (void)setClickEvent:(ClickEvent)clickEvent {
    objc_setAssociatedObject(self, clickEventKey, clickEvent, OBJC_ASSOCIATION_COPY_NONATOMIC);
}
@end
