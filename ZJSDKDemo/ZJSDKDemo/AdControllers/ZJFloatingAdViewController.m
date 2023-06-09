//
//  ZJFloatingAdViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/7/16.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJFloatingAdViewController.h"
#import <ZJSDK/ZJFloatingAdView.h>
@interface ZJFloatingAdViewController ()<ZJFloatingAdViewDelegate>

@property (nonatomic,strong)ZJFloatingAdView *floatingAd;

@end

@implementation ZJFloatingAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.floatingAd = [[ZJFloatingAdView alloc]initWithPlacementId:AdId_Floating1 frame:CGRectZero];
    self.floatingAd.delegate = self;
    self.floatingAd.backImage = [UIImage imageNamed:@"zj_h5_back"];
    self.floatingAd.hiddenH5CloseButton = YES;
    self.floatingAd.closeText = [[NSAttributedString alloc]initWithString:@"关闭" attributes:@{NSForegroundColorAttributeName:[UIColor redColor]}];
    [self.floatingAd loadAd];
//
//    adView.canMove = YES;
//    adView.needMoveToSide = NO;
}




-(void)zj_floatingAdViewDidLoad:(ZJFloatingAdView *)floatingAdView{
    NSLog(@"======%s",__FUNCTION__);
    [self.view addSubview:floatingAdView];
}

-(void)zj_floatingAdViewError:(ZJFloatingAdView *)floatingAdView error:(NSError *)error{
    NSLog(@"======%s",__FUNCTION__);
}

-(void)zj_floatingAdViewDidClick:(ZJFloatingAdView *)floatingAdView{
    NSLog(@"======%s",__FUNCTION__);
}

-(void)zj_floatingAdViewDidClose:(ZJFloatingAdView *)floatingAdView{
    NSLog(@"======%s",__FUNCTION__);
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
