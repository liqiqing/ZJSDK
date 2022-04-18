//
//  ZJContentPageStyle1ViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJContentPageStyle1ViewController.h"
#import <ZJSDK/ZJContentPage.h>
#import <ZJSDK/ZJContentPageDelegate.h>
@interface ZJContentPageStyle1ViewController ()<ZJContentPageVideoStateDelegate,ZJContentPageStateDelegate>

@property (nonatomic,strong)ZJContentPage *contentPage;
@end

@implementation ZJContentPageStyle1ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.contentPage = [[ZJContentPage alloc]initWithPlacementId:self.contentId];
    self.contentPage.videoStateDelegate = self;
    self.contentPage.stateDelegate = self;
    UIViewController *vc = self.contentPage.viewController;
    
    CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
    vc.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
    [self addChildViewController:vc];
    [self.view addSubview:vc.view];
//    [vc.view mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.mas_equalTo(200);
//        make.left.right.mas_equalTo(0);
//        make.bottom.mas_equalTo(-80);
//    }];
}

#pragma mark ZJContentPageVideoStateDelegate
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zj_videoDidStartPlay:(ZJContentPage *)videoContent{
    NSLog(@"%s",__FUNCTION__);
}
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidPause:(ZJContentPage *)videoContent{
    NSLog(@"%s",__FUNCTION__);
}
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidResume:(ZJContentPage *)videoContent{
    NSLog(@"%s",__FUNCTION__);
}
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zj_videoDidEndPlay:(ZJContentPage *)videoContent isFinished:(BOOL)finished{
    NSLog(@"%s",__FUNCTION__);
}
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zj_videoDidFailedToPlay:(ZJContentPage *)videoContent withError:(NSError *)error{
    NSLog(@"%s，%@",__FUNCTION__,error);
}

#pragma mark ZJContentPageStateDelegate

/**
* 内容展示
* @param content 内容模型
*/
- (void)zj_contentDidFullDisplay:(ZJContentPage *)content{
    NSLog(@"%s",__FUNCTION__);
}
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zj_contentDidEndDisplay:(ZJContentPage *)content{
    NSLog(@"%s",__FUNCTION__);
}
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zj_contentDidPause:(ZJContentPage *)content{
    NSLog(@"%s",__FUNCTION__);
}
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zj_contentDidResume:(ZJContentPage *)content{
    NSLog(@"%s",__FUNCTION__);
}

@end
