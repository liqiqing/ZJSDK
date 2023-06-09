//
//  ZJMiniParamViewController.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2022/9/20.
//  Copyright © 2022 zj. All rights reserved.
//

#import "ZJMiniParamViewController.h"
#import <ZJSDK/ZJWXMiniParamAd.h>
@interface ZJMiniParamViewController () <ZJWXMiniParamAdDelegate>
@property(nonatomic,strong) ZJWXMiniParamAd *miniParamAd;

@end

@implementation ZJMiniParamViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_MiniParam1]];
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    
    self.miniParamAd = [[ZJWXMiniParamAd alloc] initWithPlacementId:adId];
    self.miniParamAd.delegate = self;
    [self.miniParamAd wakeUpMiniParam];
}


/**
 *  微信唤起失败
 */
- (void)zj_miniParamAdAwakeFail:(ZJWXMiniParamAd *)miniParamAd error:(NSError *)error{
    NSArray *errors =  [self.miniParamAd getFillFailureMessages];
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"bannerAdViewError:%@",error]];
}

/**
 *  微信唤起成功
 */
- (void)zj_miniParamAdDidAwake:(ZJWXMiniParamAd *)miniParamAd{
    [self logMessage:@"唤起微信小程序成功"];
}

- (void)zj_miniParamAd:(ZJWXMiniParamAd *)miniParamAd onResp:(id)resp{
    [self logMessage:@"收到微信回调信息"];
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
