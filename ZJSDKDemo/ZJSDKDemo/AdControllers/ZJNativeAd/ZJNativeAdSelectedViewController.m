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
    [self.loadAdView appendAdID:@[@"J1550041411",@"J4141714551",@"J5437957302",@"KS90010003"]];
    
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
