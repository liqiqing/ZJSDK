//
//  ZJContentPageStyle2ViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJContentPageStyle2ViewController.h"
#import "ZJContentPageSelectedBar.h"
#import <ZJSDK/ZJContentPage.h>
#import <ZJSDK/ZJContentPageStateDelegate.h>
@interface ZJContentPageStyle2ViewController ()<ZJContentPageVideoStateDelegate,ZJContentPageStateDelegate,UIScrollViewDelegate>{
    CGFloat _beginOffsetX;
    NSInteger _lastIndex;
}

@property (nonatomic,strong)ZJContentPage *contentPage;
@property (nonatomic,strong)UIViewController *videoVC;
@property (nonatomic,strong)UIViewController *otherVC;

@property (nonatomic,strong)UIScrollView *scrollView;

@property (nonatomic,strong)ZJContentPageSelectedBar *selectedBar;
@end

@implementation ZJContentPageStyle2ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    _beginOffsetX = 0;
    _lastIndex = 0;
    
    self.contentPage = [[ZJContentPage alloc]initWithPlacementId:self.contentId];
    self.contentPage.videoStateDelegate = self;
    self.contentPage.stateDelegate = self;

    [self setupView];
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

#pragma mark - Method
-(void)setupView{
    [self.view addSubview:self.scrollView];
    [self.view addSubview:self.selectedBar];
    [self.selectedBar mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(0);
        make.height.mas_equalTo(40);
        make.top.mas_equalTo([UIApplication sharedApplication].statusBarFrame.size.height+10);
        make.width.mas_equalTo(200);
    }];
    [self.selectedBar selectIndex:0];
    
    
    [self addChildViewController:self.videoVC];
    [self.scrollView addSubview:self.videoVC.view];
    [self.videoVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.mas_equalTo(0);
        make.width.mas_equalTo(CGRectGetWidth(self.view.frame));
        make.bottom.mas_equalTo(self.view);
    }];
    
    [self addChildViewController:self.otherVC];
    [self.scrollView addSubview:_otherVC.view];
    [_otherVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(0);
        make.left.mas_equalTo(CGRectGetWidth(self.view.frame));
        make.width.mas_equalTo(CGRectGetWidth(self.view.frame));
        make.bottom.mas_equalTo(self.view);
    }];
}


//移除
-(void)removeVC:(UIViewController *)vc{
    [vc beginAppearanceTransition:NO animated:YES];
    [vc willMoveToParentViewController:nil];
    [vc.view removeFromSuperview];
    [vc removeFromParentViewController];
    [vc endAppearanceTransition];
    vc = nil;
}
-(void)addVC{
    if (_videoVC) {
        return;
    }
    [self.videoVC willMoveToParentViewController:self];
    [self addChildViewController:self.videoVC];
    [self.videoVC beginAppearanceTransition:YES animated:YES];
    [self.scrollView addSubview:self.videoVC.view];
    [self.videoVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.mas_equalTo(0);
        make.width.mas_equalTo(CGRectGetWidth(self.view.frame));
        make.bottom.mas_equalTo(self.view);
    }];
}
#pragma mark - UIScrollViewDelegate
-(void)scrollViewDidScroll:(UIScrollView *)scrollView{
    if (scrollView == self.scrollView) {
        CGFloat offsetY = scrollView.contentOffset.x/self.view.frame.size.width;
        if (offsetY == 0) {
            if (_lastIndex != offsetY) {
                [self.videoVC didMoveToParentViewController:self];
                [self.videoVC endAppearanceTransition];
            }
            _lastIndex = offsetY;
            [self.selectedBar selectIndex:0];
        }else if (offsetY == 1){
            [self removeVC:_videoVC];
            _videoVC = nil;
            _lastIndex = offsetY;
            
            [self.selectedBar selectIndex:1];
        }
    }
}

-(void)scrollViewWillBeginDragging:(UIScrollView *)scrollView{
    if (scrollView == self.scrollView) {
        _beginOffsetX = scrollView.contentOffset.x;
        if (_beginOffsetX == self.view.frame.size.width) {
            [self addVC];
        }else{
            
        }
    }
}

#pragma mark - Getter
-(UIScrollView *)scrollView{
    if (!_scrollView) {
        _scrollView = [[UIScrollView alloc]initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
        if (@available(iOS 11, *)) {
            _scrollView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        }else{
            self.automaticallyAdjustsScrollViewInsets = NO;
        }
        _scrollView.delegate = self;
        _scrollView.contentSize = CGSizeMake(self.view.frame.size.width*2, 0);
        _scrollView.pagingEnabled = YES;
        _scrollView.bounces = NO;
        _scrollView.backgroundColor = [UIColor blueColor];
        
    }
    return _scrollView;
}


-(UIViewController *)otherVC{
    if (!_otherVC) {
        _otherVC = [[UIViewController alloc]init];
        _otherVC.view.backgroundColor = [UIColor brownColor];
        UILabel *label = [[UILabel alloc]init];
        label.textColor = [UIColor blackColor];
        label.font = [UIFont systemFontOfSize:20];
        label.text = @"other";
        [_otherVC.view addSubview:label];
        [label mas_makeConstraints:^(MASConstraintMaker *make) {
            make.center.mas_equalTo(0);
        }];
    }
    return _otherVC;
}

-(UIViewController *)videoVC{
    if (!_videoVC) {
        _videoVC = self.contentPage.viewController;
    }
    return _videoVC;
}

-(ZJContentPageSelectedBar *)selectedBar{
    if (!_selectedBar) {
        _selectedBar = [[ZJContentPageSelectedBar alloc]init];
        __weak typeof(self) weakSelf = self;
        [_selectedBar selectActionWithIndex:^(NSInteger index) {
            if (index == 0) {
                [self addVC];
            }
            [weakSelf.scrollView setContentOffset:CGPointMake(weakSelf.view.frame.size.width*index, 0) animated:YES];
        }];
    }
    return _selectedBar;
}

#pragma mark ZJContentPageVideoStateDelegate
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zj_videoDidStartPlay:(id<ZJContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidPause:(id<ZJContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidResume:(id<ZJContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zj_videoDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)finished{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zj_videoDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error{
    NSLog(@"======%s",__FUNCTION__);
}

#pragma mark ZJContentPageStateDelegate

/**
* 内容展示
* @param content 内容模型
*/
- (void)zj_contentDidFullDisplay:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zj_contentDidEndDisplay:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zj_contentDidPause:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zj_contentDidResume:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
@end
