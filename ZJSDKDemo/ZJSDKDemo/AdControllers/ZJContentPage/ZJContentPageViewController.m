//
//  ZJContentPageViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJContentPageViewController.h"
#import "ZJContentPageStyle1ViewController.h"
#import "ZJContentPageTabBarController.h"
#import "UIButton+Event.h"
@interface ZJContentPageViewController ()

@end

@implementation ZJContentPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_ContentPage1]];
    
    [self.loadAdView.loadButton setTitle:@"style1" forState:UIControlStateNormal];
    
    __weak typeof(self) weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        ZJContentPageStyle1ViewController *contentPage1VC = [[ZJContentPageStyle1ViewController alloc]init];
        contentPage1VC.contentId = weakSelf.loadAdView.adIDTextField.text;
        [weakSelf.navigationController pushViewController:contentPage1VC animated:YES];
    }];

    [self.loadAdView.showButton setTitle:@"style2(长按返回)" forState:UIControlStateNormal];
    [self.loadAdView.showButton clickHandle:^(UIButton *button) {
        //demo 使用的ID K90010005
        ZJContentPageTabBarController *contentPage2VC = [[ZJContentPageTabBarController alloc]init];
        [weakSelf.navigationController pushViewController:contentPage2VC animated:YES];

    }];
}


@end
