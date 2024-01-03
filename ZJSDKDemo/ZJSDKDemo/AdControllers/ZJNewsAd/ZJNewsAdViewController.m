//
//  ZJNewsAdViewController.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2022/12/19.
//  Copyright © 2022 zj. All rights reserved.
//

#import "ZJNewsAdViewController.h"
#import <WebKit/WebKit.h>
#import <ZJSDK/ZJNewsAdView.h>
#import <ZJSDKCore/ZJSDKDefines.h>
@interface ZJNewsAdViewController () <ZJNewsAdViewDelegate>
@property(nonatomic,strong) ZJNewsAdView *newsAdView;

@end

@implementation ZJNewsAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //J1321306298
    [self.loadAdView appendAdID:@[AdId_News1,AdId_News2]];
    [self.loadAdView.showButton setHidden:YES];
    [self setBackBarButton];

}
-(void)setBackBarButton{
    //返回按钮
    UIButton *backButton  =  [[UIButton alloc] init];
    backButton.titleLabel.font = [UIFont systemFontOfSize:16];
    backButton.userInteractionEnabled = YES;
    
    //    backButton.frame  =  CGRectMake(12.5, 0, 25, 25);
    // iOS 11 适配
    if (@available(iOS 11, *)) {
        backButton.frame  =  CGRectMake(2.5, 0, 22, 22);
    } else {
        backButton.frame  =  CGRectMake(12.5, 0, 22, 22);
    }
    if (@available(iOS 13.0, *)) {
        [backButton setImage:[UIImage systemImageNamed:@"chevron.backward"] forState:UIControlStateNormal];
        [backButton setImage:[UIImage systemImageNamed:@"chevron.backward"] forState:UIControlStateHighlighted];
    } else {
        [backButton setTitle:@"Back" forState:UIControlStateNormal];
        [backButton setTitle:@"Back" forState:UIControlStateHighlighted];
    }
    backButton.imageEdgeInsets = UIEdgeInsetsMake(2, 2, 2, 2);
    [backButton addTarget: self action:@selector(closeView) forControlEvents: UIControlEventTouchUpInside];
    UIView *leftview = [[UIView alloc]initWithFrame:CGRectMake(0, 0, 40, 22)];
    [leftview addSubview:backButton];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:leftview];
}
//返回按钮
-(void)closeView
{
    if ([self.newsAdView canGoBack]) {
        [self.newsAdView goBack];
    } else {
        if (_newsAdView) {
            [_newsAdView removeFromSuperview];
            _newsAdView = nil;
        } else {
            [self.navigationController popViewControllerAnimated:YES];
        }
    }
}

#pragma mark =============== ZJNewsAdViewDelegate ===============
/**
 news广告加载成功
 */
- (void)zj_newsAdViewDidLoad:(ZJNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];
}

- (void)zj_newsAdViewDidShow:(ZJNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];
}
/**
 news广告加载失败
 */
- (void)zj_newsAdView:(ZJNewsAdView *)newsAdView didLoadFailWithError:(NSError * _Nullable)error{
    [self logMessage:NSStringFromSelector(_cmd)];

    [self.newsAdView removeFromSuperview];

}

/**
 news广告奖励触发回调
 */
- (void)zj_newsAdViewRewardEffective:(ZJNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];

}

/**
 点击news广告回调
 */
- (void)zj_newsAdViewDidClick:(ZJNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];

}

/**
 canGoBack状态监听
 */
- (void)zj_newsAd:(ZJNewsAdView *)newsAd canGoBackStateChange:(BOOL)canGoBack{
    [self logMessage:NSStringFromSelector(_cmd)];
    self.newsAdView.enableGoBackGesture = canGoBack;
    self.newsAdView.enableSlide = !canGoBack;
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    if (_newsAdView) {
        [_newsAdView removeFromSuperview];
        _newsAdView = nil;
    }
    self.newsAdView = [[ZJNewsAdView alloc] initWithPlacementId:adId frame:CGRectMake(0, ZJ_StatusBarHeight+44, kScreenWidth, kScreenHeight-ZJ_StatusBarHeight-44)];
    self.newsAdView.delegate = self;
    self.newsAdView.userId = @"robin6666";
    [self.view addSubview:self.newsAdView];
    
    [self.newsAdView loadAdAndShow];
}

@end
