//
//  ZJContentPageSelectedBar.h
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/23.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJContentPageSelectedBar : UIView

-(void)selectIndex:(NSInteger)index;

-(void)selectActionWithIndex:(void(^)(NSInteger index))callback;

@end

NS_ASSUME_NONNULL_END
