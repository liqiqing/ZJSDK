//
//  ZjBannerViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2021/1/31.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJBannerViewController.h"
#import <ZJSDK/ZJBannerAdView.h>

#define ZJBannerHeight 200
@interface ZJBannerViewController ()<ZJBannerAdViewDelegate>


@property(nonatomic,strong) ZJBannerAdView *bannerView;
@end

@implementation ZJBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_Banner1,AdId_Banner2,AdId_Banner3,AdId_Banner4,AdId_Banner5,AdId_Banner6,AdId_Banner7,AdId_Banner8,AdId_Banner9]];
    self.loadAdView.showButton.hidden = YES;
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    if (_bannerView) {
        [_bannerView removeFromSuperview];
        _bannerView = nil;
    }
    CGFloat width = self.view.frame.size.width;
    self.bannerView = [[ZJBannerAdView alloc] initWithPlacementId:adId viewController:self adSize:CGSizeMake(width, ZJBannerHeight)];
    self.bannerView.delegate = self;
    [self.bannerView loadAdAndShow];
    [self addBannerView];
}



-(void)addBannerView{
    if(self.bannerView&&![self.view.subviews containsObject:self.bannerView]){
        CGFloat y = self.view.frame.size.height -ZJBannerHeight-kSafeBottomMargin-50;
        CGRect frame = CGRectMake(0, y, self.view.frame.size.width, ZJBannerHeight);

        self.bannerView.frame = frame;
        [self.view addSubview:self.bannerView];
    }
}


#pragma mark ZJBannerAdViewDelegate
/**
 banner广告加载成功
 */
- (void)zj_bannerAdViewDidLoad:(ZJBannerAdView *)bannerAdView{
    [self logMessage:@"bannerAdViewDidLoad"];
}

/**
 banner广告加载失败
 */
- (void)zj_bannerAdView:(ZJBannerAdView *)bannerAdView didLoadFailWithError:(NSError *_Nullable)error{
    NSArray *errors =  [self.bannerView getFillFailureMessages];
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"bannerAdViewError:%@",error]];
}


/**
 bannerAdView曝光回调
 */
- (void)zj_bannerAdViewWillBecomVisible:(ZJBannerAdView *)bannerAdView{
    [self logMessage:@"bannerAdShow"];
}

/**
 关闭banner广告回调
 */
- (void)zj_bannerAdViewDislike:(ZJBannerAdView *)bannerAdView{
    [self logMessage:@"bannerAdDislike"];
}

/**
 点击banner广告回调
 */
- (void)zj_bannerAdViewDidClick:(ZJBannerAdView *)bannerAdView{
    
}

/**
 关闭banner广告详情页回调
 */
- (void)zj_bannerAdViewDidCloseOtherController:(ZJBannerAdView *)bannerAdView{
    
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
