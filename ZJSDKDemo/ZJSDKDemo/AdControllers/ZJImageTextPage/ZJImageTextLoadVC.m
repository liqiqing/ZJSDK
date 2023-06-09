//
//  ZJImageTextLoadVC.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2023/1/5.
//  Copyright © 2023 zj. All rights reserved.
//

#import "ZJImageTextLoadVC.h"

#import "ZJImageTextVC.h"
#import "ZJContentPageTabBarController.h"
#import "UIButton+Event.h"
@interface ZJImageTextLoadVC ()

@end

@implementation ZJImageTextLoadVC

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_ContentPage1]];
    
    [self.loadAdView.loadButton setTitle:@"加载广告页" forState:UIControlStateNormal];
    
    __weak typeof(self) weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        ZJImageTextVC *imageTextVC = [[ZJImageTextVC alloc]init];
        imageTextVC.contentId = weakSelf.loadAdView.adIDTextField.text;
        [weakSelf.navigationController pushViewController:imageTextVC animated:YES];
    }];

    self.loadAdView.showButton.hidden = YES;
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
