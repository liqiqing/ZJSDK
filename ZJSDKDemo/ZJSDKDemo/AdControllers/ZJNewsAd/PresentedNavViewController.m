//
//  PresentedNavViewController.m
//  InteractiveDemo
//
//  Created by 麻明康 on 2023/1/16.
//

#import "PresentedNavViewController.h"

@interface PresentedNavViewController ()<UIGestureRecognizerDelegate>

@end

@implementation PresentedNavViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.interactivePopGestureRecognizer.enabled = NO;
    SEL selector = NSSelectorFromString(@"handleNavigationTransition:");

    //先获取系统设置的代理作为target
    if ([self.interactivePopGestureRecognizer.delegate respondsToSelector:selector]) {
        self.pan = [[UIPanGestureRecognizer alloc] initWithTarget:self.interactivePopGestureRecognizer.delegate action:selector];
        self.pan.delegate = self;
        
        [self.view addGestureRecognizer:self.pan];
    }
    else {  //如果不能添加全屏的返回手势，就添加
        self.interactivePopGestureRecognizer.enabled = YES;
    }
    //后设置代理
    self.interactivePopGestureRecognizer.delegate = self;
}



- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated {
    if (self.viewControllers.count > 0) {
        UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:@"返回" style:(UIBarButtonItemStylePlain) target:self action:@selector(backClick)];
        viewController.navigationItem.leftBarButtonItem = item;
    }

    [super pushViewController:viewController animated:animated];
}

- (void)backClick {
    [self popViewControllerAnimated:YES];
}

//- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer {
//    return self.viewControllers.count > 1;
//}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
