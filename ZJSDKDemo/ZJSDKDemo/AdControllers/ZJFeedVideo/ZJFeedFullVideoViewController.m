//
//  ZJFeedFullVideoViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/10/13.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJFeedFullVideoViewController.h"
#import "ZJFeedFullVideoShowViewController.h"
@interface ZJFeedFullVideoViewController ()

@end

@implementation ZJFeedFullVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_VideoExpress1,AdId_VideoExpress2,AdId_VideoExpress3]];
}

-(void) viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self.navigationController setNavigationBarHidden:NO animated:NO];
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    ZJFeedFullVideoShowViewController *showVC = [ZJFeedFullVideoShowViewController new];
    showVC.placementId = adId;
    [self.navigationController pushViewController:showVC animated:NO];
    
}



-(void) showAd{
   
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
