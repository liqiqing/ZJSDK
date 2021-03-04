//
//  ZJBannerAdViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/20.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJBannerAdViewController.h"
#import <ZJSDK/ZJBannerAdView.h>


#define ZJBannerHeight 200
@interface ZJBannerAdViewController ()<ZJBannerAdViewDelegate>

@property (nonatomic,strong)ZJBannerAdView *bannerView;

@property (nonatomic,copy)NSString *adId;
@end

@implementation ZJBannerAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"banner广告";
    [self.loadAdView appendAdID:@[@"J7722563364",@"1080958885885321",@"945778025",@"zjad_iOS_ZB0001"]];
    self.loadAdView.showButton.hidden = YES;
}

-(void) loadAd:(NSString*) adId{
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



-(void) addBannerView{
    if(self.bannerView&&![self.view.subviews containsObject:self.bannerView]){
        CGFloat y = self.view.frame.size.height -ZJBannerHeight-SafeBottomMargin-50;
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
   
}

/**
 banner广告加载失败
 */
- (void)zj_bannerAdView:(ZJBannerAdView *)bannerAdView didLoadFailWithError:(NSError *_Nullable)error{
    
}


/**
 bannerAdView曝光回调
 */
- (void)zj_bannerAdViewWillBecomVisible:(ZJBannerAdView *)bannerAdView{
    
}

/**
 关闭banner广告回调
 */
- (void)zj_bannerAdViewDislike:(ZJBannerAdView *)bannerAdView{
    
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
