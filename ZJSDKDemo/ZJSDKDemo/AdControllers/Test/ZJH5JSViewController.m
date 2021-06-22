//
//  ZJH5JSViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/29.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJH5JSViewController.h"
#import "ZJAdEditTextView.h"
#import "ZJJSBridgeViewController.h"
@interface ZJH5JSViewController ()

@property (nonatomic,strong)ZJAdEditTextView *loadAdView;

@end

@implementation ZJH5JSViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.loadAdView];
    __weak typeof(self)weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        [weakSelf loadAd:self.loadAdView.adTextView.text];
    }];
    
    [self.loadAdView appendAdID:@[
        @"http://static.jrongjie.com/zjsdk_project/cyc/index.html#/home"
        ,@"http://static.jrongjie.com/zjsdk_project/guess-idioms/index.html#/",
    @"http://static.jrongjie.com/zjsdk_project/paopaotu-game/game.html"]];
}

-(void) loadAd:(NSString*) adId{
    [self.loadAdView clearLog];
    ZJJSBridgeViewController *vc = [[ZJJSBridgeViewController alloc]init];
    vc.urlString = adId;
    [self.navigationController pushViewController:vc animated:YES];
}


-(void) log:(NSString*) fun message:(NSString*) msg{
    [self.loadAdView addLog:[NSString stringWithFormat:@"%@-%@",fun,msg?msg:@""]];
}


-(ZJAdEditTextView*) loadAdView{
    if(!_loadAdView){
        _loadAdView = [ZJAdEditTextView creat:M_NAVI_HEIGHT];
        _loadAdView.rootViewController = self;
    }
    return _loadAdView;;
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
