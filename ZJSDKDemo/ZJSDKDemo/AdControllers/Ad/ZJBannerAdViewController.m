//
//  ZJBannerAdViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/20.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJBannerAdViewController.h"
#import <ZJSDK/ZJBannerAdView.h>

#define ZJBannerWidth  ScreenWidth
#define ZJBannerHeight 200
@interface ZJBannerAdViewController ()<ZJBannerAdViewDelegate>

@property (nonatomic,strong)ZJBannerAdView *bannerView;

@property (nonatomic,copy)NSString *adId;
@end

@implementation ZJBannerAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"banner广告";
    [self.loadAdView appendAdID:@[@"1080958885885321",@"945778025"]];
    self.loadAdView.showButton.hidden = YES;
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    //gdt@"1080958885885321", csj@"945778025"
    if (_bannerView) {
        [_bannerView removeFromSuperview];
        _bannerView = nil;
    }
    _adId = adId;
    
    [self.view addSubview:self.bannerView];
    [self.bannerView loadAdAndShow];
}

-(ZJBannerAdView *)bannerView{
    if (!_bannerView) {
        _bannerView = [[ZJBannerAdView alloc]initWithPlacementId:_adId viewController:self adSize:CGSizeMake(ScreenWidth, ZJBannerHeight) interval:30];
        _bannerView.frame = CGRectMake(0, ScreenHeight-ZJBannerHeight-SafeBottomMargin-50, ScreenWidth, ZJBannerHeight);
        _bannerView.delegate = self;
    }
    return _bannerView;
}


#pragma mark - ZJBannerAdViewDelegate
/**
 banner广告加载成功
 */
- (void)zj_bannerAdViewDidLoad:(ZJBannerAdView *)bannerAdView{
    NSLog(@"%s",__FUNCTION__);
}

/**
 banner广告加载失败
 */
- (void)zj_bannerAdView:(ZJBannerAdView *)bannerAdView didLoadFailWithError:(NSError *_Nullable)error{
    NSLog(@"%s",__FUNCTION__);
}


/**
 bannerAdView曝光回调
 */
- (void)zj_bannerAdViewWillBecomVisible:(ZJBannerAdView *)bannerAdView{
    NSLog(@"%s",__FUNCTION__);
}

/**
 关闭banner广告回调
 */
- (void)zj_bannerAdViewDislike:(ZJBannerAdView *)bannerAdView{
    NSLog(@"%s",__FUNCTION__);
}

/**
 点击banner广告回调
 */
- (void)zj_bannerAdViewDidClick:(ZJBannerAdView *)bannerAdView{
    NSLog(@"%s",__FUNCTION__);
}

/**
 关闭banner广告详情页回调
 */
- (void)zj_bannerAdViewDidCloseOtherController:(ZJBannerAdView *)bannerAdView{
    NSLog(@"%s",__FUNCTION__);
}

@end
