//
//  ZJContentPageTabBarController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJContentPageTabBarController.h"
#import "ZJContentPageStyle2ViewController.h"
#import "ZJContentPageStyle1ViewController.h"

#define ContentPage1ID AdId_ContentPage1
#define ContentPage2ID AdId_ContentPage1

@interface ZJContentPageTabBarController ()

@end

@implementation ZJContentPageTabBarController

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.navigationController.navigationBarHidden = YES;
}
-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    self.navigationController.navigationBarHidden = NO;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    //ZJContentPageStyle1ViewController;
    ZJContentPageStyle1ViewController *vc1 = [[ZJContentPageStyle1ViewController alloc] init];
    vc1.contentId = ContentPage1ID;
    UINavigationController *navi = [[UINavigationController alloc]initWithRootViewController:vc1];
    navi.title = @"视频style1";
    vc1.title = @"视频style1";
    
    //UIViewController
    UIViewController *vc2 = [[UIViewController alloc] init];
    vc2.view.backgroundColor = [UIColor brownColor];
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 40)];
    label1.center = vc2.view.center;
    label1.textColor = [UIColor blackColor];
    label1.text = @"ContentPage";
    label1.textAlignment = NSTextAlignmentCenter;
    [vc2.view addSubview:label1];
    vc2.title = @"ContentPage";

    //ZJContentPageStyle2ViewController
    ZJContentPageStyle2ViewController *vc3 = [[ZJContentPageStyle2ViewController alloc] init];
//    vc3.view.backgroundColor = [UIColor blueColor];
    vc3.contentId = ContentPage2ID;
    vc3.title = @"视频style2";
    
    //vc4
    UIViewController *vc4 = [[UIViewController alloc] init];
    vc4.view.backgroundColor = [UIColor whiteColor];
    UILabel *label2 = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 40)];
    label2.center = vc4.view.center;
    label2.textColor = [UIColor blackColor];
    label2.text = @"我是个人页";
    label2.textAlignment = NSTextAlignmentCenter;
    [vc4.view addSubview:label2];
    vc4.title = @"我的";

    // 把数据中得视图器交给分栏控制器管理
    // 分栏控制器会自动将其管理的视图控制器的分栏按钮(UITabBarItem)放到分栏上显示
    self.viewControllers = @[navi,vc2, vc3, vc4];

    // 取到分栏控制器的分栏
    // 设置分栏的风格
    self.tabBar.barStyle = UIBarStyleBlack;
    // 是否透明
    self.tabBar.translucent = NO;
    // 设置分栏的前景颜色
    self.tabBar.barTintColor = [UIColor blackColor];
    // 设置分栏元素项的颜色
    self.tabBar.tintColor = [UIColor whiteColor];

    UILongPressGestureRecognizer *longPressGestureRecognizer = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPressGestureRecognizerAction:)];
    [self.view addGestureRecognizer:longPressGestureRecognizer];
}



- (BOOL)shouldAutorotate {
    return NO;
}
- (void)longPressGestureRecognizerAction:(UILongPressGestureRecognizer *)sender{
    if (sender.state == UIGestureRecognizerStateEnded) {
        [self.navigationController popViewControllerAnimated:YES];
    }
}


@end
