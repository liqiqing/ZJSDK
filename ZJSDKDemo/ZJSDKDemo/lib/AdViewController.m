//
//  AdViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/10/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "AdViewController.h"

@interface AdViewController ()
{
    ZJAdLoadView *_loadAdView;
}
@end

@implementation AdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view addSubview:self.loadAdView];
    __weak typeof(self)weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        [weakSelf loadAd:self.loadAdView.adIDTextField.text];
    }];

    [self.loadAdView.showButton clickHandle:^(UIButton *button) {
        [weakSelf showAd];
    }];
}

-(void) loadAd:(NSString*) adId{
    [self.loadAdView clearLog];
    [self.loadAdView addLog:[NSString stringWithFormat:@"%@-[%@]",@"loadAd:",adId]];
}

-(void) showAd{
    
}

-(void) log:(NSString*) fun message:(NSString*) msg{
    [self.loadAdView addLog:[NSString stringWithFormat:@"%@-%@",fun,msg?msg:@""]];
}

-(ZJAdLoadView*) loadAdView{
    if(!_loadAdView){
        _loadAdView = [ZJAdLoadView creat:M_NAVI_HEIGHT];
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
