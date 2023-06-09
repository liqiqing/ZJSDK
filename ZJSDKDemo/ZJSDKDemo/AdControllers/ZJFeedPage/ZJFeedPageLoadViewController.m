//
//  ZJFeedPageLoadViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJFeedPageLoadViewController.h"
#import "ZJFeedPageViewController.h"
#import "ZJContentPageTabBarController.h"
#import "UIButton+Event.h"
@interface ZJFeedPageLoadViewController ()

@end

@implementation ZJFeedPageLoadViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_ContentPage1]];
    
    [self.loadAdView.loadButton setTitle:@"加载广告页" forState:UIControlStateNormal];
    
    __weak typeof(self) weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        ZJFeedPageViewController *feedPage = [[ZJFeedPageViewController alloc]init];
        feedPage.contentId = weakSelf.loadAdView.adIDTextField.text;
        [weakSelf.navigationController pushViewController:feedPage animated:YES];
    }];

    self.loadAdView.showButton.hidden = YES;
}


@end
