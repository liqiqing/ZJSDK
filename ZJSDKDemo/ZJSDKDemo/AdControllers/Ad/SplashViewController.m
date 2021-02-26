//
//  SplashViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/11/12.
//  Copyright © 2020 zj. All rights reserved.
//

#import "SplashViewController.h"
#import <ZJSDK/ZJAdSDK.h>
#import <ZJSDK/ZJSplashAd.h>
@interface SplashViewController ()<ZJSplashAdDelegate>
@property(nonatomic,strong) ZJSplashAd *splashAd;
@property (strong, nonatomic) UIImageView *imageView;
@end

@implementation SplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view addSubview:self.imageView];
    
    
    self.splashAd = [[ZJSplashAd alloc] initWithPlacementId:@"J8648995207"];
    self.splashAd.delegate = self;
    self.splashAd.fetchDelay = 3.0;
    [self.splashAd loadAd];
    
}

-(void) close{
    if(self.delegate&&[self.delegate respondsToSelector:@selector(splashViewControllerClosed)]){
        [self.delegate splashViewControllerClosed];
    }
    self.delegate = nil;
}


#pragma mark - ZJSplashAdDelegate
/**
 *  开屏广告素材加载成功
 */
-(void)zj_splashAdDidLoad:(ZJSplashAd *)splashAd{
    [self.splashAd showAdInWindow:[UIApplication sharedApplication].keyWindow withBottomView:nil];
    //[self.showWindow makeKeyAndVisible];
    NSLog(@"%s",__FUNCTION__);
    
}

/**
 *  开屏广告成功展示
 */
-(void)zj_splashAdSuccessPresentScreen:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
}

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self close];
}

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self close];
    //self.showWindow.w
}

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground:(ZJSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self close];
}

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd:(ZJSplashAd*)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self close];
}

/**
 *  开屏广告错误
 */
- (void)zj_splashAdError:(ZJSplashAd *)splashAd withError:(NSError *)error{
    NSLog(@"%s",__FUNCTION__);
    [self close];
}

-(UIImageView*) imageView{
    if(!_imageView){
        _imageView = [[UIImageView alloc] initWithFrame:self.view.bounds];
//        _imageView.image = [UIImage imageNamed:@"SplashBg"];//启动图
        _imageView.backgroundColor = [UIColor clearColor];
        _imageView.contentMode = UIViewContentModeScaleAspectFill;
        _imageView.clipsToBounds = YES;
        
        
        UILabel *label = [[UILabel alloc]init];
        label.textColor = [UIColor blackColor];
        label.text = @"ZJSDK";
        label.font = [UIFont systemFontOfSize:37];
        [self.view addSubview:label];
        [label mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerX.mas_equalTo(0);
            make.bottom.mas_equalTo(-(157+SafeBottomMargin));
        }];
    }
    return _imageView;
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
