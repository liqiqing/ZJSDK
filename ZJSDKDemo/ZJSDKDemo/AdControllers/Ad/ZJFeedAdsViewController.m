//
//  ZJNativeExpressFeedViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJFeedAdsViewController.h"

#import "ZJNativeExpressAdsViewController.h"
@interface ZJFeedAdsViewController ()



@end

@implementation ZJFeedAdsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title=@"模板信息流";
    self.loadAdView.showButton.hidden = YES;
    
    [self.loadAdView appendAdID:@[@"K4000000007",@"K4000000008",@"G2051316683324578",@"G3061112693227741",@"T945740162"]];
    
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    
    ZJNativeExpressAdsViewController *vc = [[ZJNativeExpressAdsViewController alloc]init];
    vc.adId = adId;
    [self.navigationController pushViewController:vc animated:YES];
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
