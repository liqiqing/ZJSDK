//
//  SplashViewController.h
//  ZJSDKDemo
//
//  Created by Robin on 2020/11/12.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SplashViewControllerDelegate <NSObject>

-(void) splashViewControllerClosed;

@end

@interface SplashViewController : UIViewController

@property(nonatomic,weak) id<SplashViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
