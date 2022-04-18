//
//  ZJTestViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/11/10.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJSplashWindowVC.h"

@interface ZJSplashWindowVC ()
@property (nonatomic,strong)UIImageView *splashBgImageView;
@end

@implementation ZJSplashWindowVC

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.splashBgImageView];
    
}



-(UIImageView *)splashBgImageView{
    if (!_splashBgImageView) {
        _splashBgImageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight)];
        _splashBgImageView.image = [UIImage imageNamed:@"SplashBgX"];
        
    }
    return _splashBgImageView;
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
