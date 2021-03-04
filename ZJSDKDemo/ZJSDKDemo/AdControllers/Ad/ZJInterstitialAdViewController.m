//
//  ZJInterstitialAdViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/10/16.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJInterstitialAdViewController.h"
#import <ZJSDK/ZJInterstitialAd.h>

@interface ZJInterstitialAdViewController ()<ZJInterstitialAdDelegate>
{

}
@property(nonatomic,strong) ZJInterstitialAd *interstitialAd;
@end

@implementation ZJInterstitialAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title=@"插屏";

    [self.loadAdView appendAdID:@[@"zjad_G10506",@"zjad_T945551",@"zjad_iOS_ZI0001"]];
    
 
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.interstitialAd = [[ZJInterstitialAd alloc] initWithPlacementId:adId];
    self.interstitialAd.delegate = self;
    [self.interstitialAd loadAd];
}

-(void) showAd{
    if(self.interstitialAd)
        [self.interstitialAd presentAdFromRootViewController:self];//设置 UITabBarController 试试
    
}

#pragma mark ZJInterstitialAdDelegate

- (void) zj_interstitialAdDidLoad:(ZJInterstitialAd*) ad{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

- (void) zj_interstitialAdDidLoadFail:(ZJInterstitialAd*) ad error:(NSError * __nullable)error{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

- (void) zj_interstitialAdDidPresentScreen:(ZJInterstitialAd*) ad{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

- (void) zj_interstitialAdDidClick:(ZJInterstitialAd*) ad{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

- (void) zj_interstitialAdDidClose:(ZJInterstitialAd*) ad{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

- (void) zj_interstitialAdDetailDidClose:(ZJInterstitialAd*) ad{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
}

- (void) zj_interstitialAdDidFail:(ZJInterstitialAd*) ad error:(NSError * __nullable)error{
    NSLog(@"%s",__FUNCTION__);
    [self log:[NSString stringWithFormat:@"%s",__FUNCTION__] message:@""];
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
