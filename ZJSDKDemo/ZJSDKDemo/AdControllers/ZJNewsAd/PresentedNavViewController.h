//
//  PresentedNavViewController.h
//  InteractiveDemo
//
//  Created by 麻明康 on 2023/1/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PresentedNavViewController : UINavigationController
@property (nonatomic, strong) UIPanGestureRecognizer *pan;
@end

NS_ASSUME_NONNULL_END
