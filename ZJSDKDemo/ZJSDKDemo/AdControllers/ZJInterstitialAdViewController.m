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
    [self.loadAdView appendAdID:@[AdId_Interstitial1,AdId_Interstitial2,AdId_Interstitial3,AdId_Interstitial4,AdId_Interstitial5,AdId_Interstitial7]];
    
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.interstitialAd = [[ZJInterstitialAd alloc] initWithPlacementId:adId];
    self.interstitialAd.delegate = self;
    self.interstitialAd.mutedIfCan = YES;
    [self.interstitialAd loadAd];
}

-(void) showAd{
    if(self.interstitialAd)
        [self.interstitialAd presentAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
    
}

#pragma mark ZJInterstitialAdDelegate

- (void)zj_interstitialAdDidLoad:(ZJInterstitialAd*)ad{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    [self logMessage:@"interstitialAdDidLoad"];
    [self logMessage:[ad valueForKey:@"logString"]];
}

- (void)zj_interstitialAdDidLoadFail:(ZJInterstitialAd*) ad error:(NSError * __nullable)error{
    [self logMessage:[self.interstitialAd valueForKey:@"logString"]];
    NSArray *errors =  [self.interstitialAd getFillFailureMessages];
    NSLog(@"所有错误信息 %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"interstitialAdDidLoadFail : %@",error]];
}

- (void)zj_interstitialAdDidPresentScreen:(ZJInterstitialAd*)ad{
    self.interstitialAd.mutedIfCan = NO;
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"interstitialAdDidPresentScreen"];
    
}

- (void)zj_interstitialAdDidClick:(ZJInterstitialAd*)ad{
    
}

- (void)zj_interstitialAdDidClose:(ZJInterstitialAd*)ad{
    [self logMessage:@"interstitialAdDidClose"];
}

- (void)zj_interstitialAdDetailDidClose:(ZJInterstitialAd*)ad{
    
}

- (void)zj_interstitialAdDidFail:(ZJInterstitialAd*)ad error:(NSError * __nullable)error{
    [self logMessage:[NSString stringWithFormat:@"interstitialAdError : %@",error]];
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
