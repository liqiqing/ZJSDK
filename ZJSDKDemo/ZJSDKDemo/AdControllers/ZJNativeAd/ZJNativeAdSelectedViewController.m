//
//  ZJNativeAdSelectedViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeAdSelectedViewController.h"
#import "ZJNativeAdViewController.h"


@interface ZJNativeAdSelectedViewController ()

@end

@implementation ZJNativeAdSelectedViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_NativeRender1,AdId_NativeRender2,AdId_NativeRender3,AdId_NativeRender4,AdId_NativeRender5,AdId_NativeRender6]];
    
}
-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    ZJNativeAdViewController *nativeAdVC = [[ZJNativeAdViewController alloc]init];
    nativeAdVC.adId = adId;
    [self.navigationController pushViewController:nativeAdVC animated:YES];
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
