//
//  ZJNewsAdViewController.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2022/12/19.
//  Copyright © 2022 zj. All rights reserved.
//

#import "ZJNewsAdViewController.h"
#import "BaiduMobAdSDK/BaiduMobCpuInfoManager.h"
#import "BaiduMobAdSDK/BaiduMobAdCommonConfig.h"
#import <WebKit/WebKit.h>
#import <ZJSDK/ZJNewsAdView.h>

@interface ZJNewsAdViewController () <ZJNewsAdViewDelegate>
@property(nonatomic,strong) ZJNewsAdView *newsAdView;

@end

@implementation ZJNewsAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //J1321306298
    [self.loadAdView appendAdID:@[@"J1321306298"]];
    self.loadAdView.showButton.hidden = YES;
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
    //    NewPostViewController*postView= (NewPostViewController*)self.parent;
    //    postView.isFromImagePicker=1;
    [self.newsAdView goBack];
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
    self.newsAdView = [[ZJNewsAdView alloc] initWithPlacementId:adId frame:self.view.bounds];
    self.newsAdView.delegate = self;
    [self.newsAdView loadAdAndShow];
    [self.view addSubview:self.newsAdView];
}
#pragma mark =============== ZJNewsAdViewDelegate ===============
/**
 news广告加载成功
 */
- (void)zj_newsAdViewDidLoad:(ZJNewsAdView *)newsAdView{
    NSLog(@"====：%@",NSStringFromSelector(_cmd));
}

/**
 news广告加载失败
 */
- (void)zj_newsAdView:(ZJNewsAdView *)newsAdView didLoadFailWithError:(NSError * _Nullable)error{
    NSLog(@"====：%@",NSStringFromSelector(_cmd));
}

/**
 news广告奖励触发回调
 */
- (void)zj_newsAdViewRewardEffective:(ZJNewsAdView *)newsAdView{
    NSLog(@"====：%@",NSStringFromSelector(_cmd));
}

/**
 点击news广告回调
 */
- (void)zj_newsAdViewDidClick:(ZJNewsAdView *)newsAdView{
    NSLog(@"====：%@",NSStringFromSelector(_cmd));
}


@end
