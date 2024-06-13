//
//  ZJTubePageVC.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2024/6/11.
//  Copyright © 2024 zj. All rights reserved.
//

#import "ZJTubePageVC.h"
#import "ZJTubePageStyle1VC.h"

@interface ZJTubePageVC ()

@end

@implementation ZJTubePageVC

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_Tube1]];
    
    [self.loadAdView.loadButton setTitle:@"展示短剧" forState:UIControlStateNormal];
    
    __weak typeof(self) weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        ZJTubePageStyle1VC *contentPage1VC = [[ZJTubePageStyle1VC alloc]init];
        contentPage1VC.contentId = weakSelf.loadAdView.adIDTextField.text;
        [weakSelf.navigationController pushViewController:contentPage1VC animated:YES];
    }];

    [self.loadAdView.showButton setTitle:@"展示短剧" forState:UIControlStateNormal];
    [self.loadAdView.showButton clickHandle:^(UIButton *button) {
        ZJTubePageStyle1VC *contentPage1VC = [[ZJTubePageStyle1VC alloc]init];
        contentPage1VC.contentId = weakSelf.loadAdView.adIDTextField.text;
        [weakSelf.navigationController pushViewController:contentPage1VC animated:YES];
    }];
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
