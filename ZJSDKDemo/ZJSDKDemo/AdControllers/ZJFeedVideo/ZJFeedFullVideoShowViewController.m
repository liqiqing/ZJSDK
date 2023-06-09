//
//  ZJFeedFullVideoShowViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/10/19.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJFeedFullVideoShowViewController.h"
#import "ZJFullScreenCell.h"
#import "ZJFeedFullVideoAdCell.h"
#import <ZJSDK/ZJFeedFullVideoProvider.h>
#import "ZJLogView.h"
@interface ZJFeedFullVideoShowViewController ()<UITableViewDataSource,UITableViewDelegate,ZJFeedFullVideoProviderDelegate>
@property (strong, nonatomic) UITableView *tableView;

@property(nonatomic,strong) ZJFeedFullVideoProvider *adProvider;
@property (nonatomic, copy) NSArray *dataSource;
@property (nonatomic, strong)ZJLogView *logView;
@end

@implementation ZJFeedFullVideoShowViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self.navigationController setNavigationBarHidden:YES animated:NO];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.tableView];
    
    UIButton *closeButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [closeButton setImage:[UIImage imageNamed:@"zj_h5_back"] forState:UIControlStateNormal];
    [closeButton setBackgroundColor:[UIColor whiteColor]];
    closeButton.frame = CGRectMake(6, 44, 44, 44);
    closeButton.layer.cornerRadius = 22;
    __weak typeof(self) weakSelf = self;
    [closeButton clickHandle:^(UIButton *button) {
        [weakSelf.navigationController popViewControllerAnimated:NO];
    }];
    
    [self.view addSubview:closeButton];
    
    NSMutableArray *datas = [NSMutableArray array];
    for (NSInteger i =0 ; i <= 5; i++) {
        [datas addObject:@"App tableViewcell"];
    }
    self.dataSource = [datas copy];
    
    self.logView = [[ZJLogView alloc]init];
    [self.view addSubview:self.logView];
    [self.logView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.offset(0);
        make.height.mas_equalTo(100);
    }];
    
    [self loadData];
}

-(void)clickPlayBtn:(UIButton *)btn{
    UITableViewCell *cell = [self.tableView visibleCells].firstObject;
    for (UIView *sV in cell.contentView.subviews) {
        if ([sV isKindOfClass:[ZJFeedFullVideoView class]]) {
            if (btn.selected) {
                [((ZJFeedFullVideoView *)sV) play];
            }else{
                [((ZJFeedFullVideoView *)sV) pause];
            }
            
        }
    }
    btn.selected = !btn.selected;
}

- (void)loadData{
    [self.logView logMessage:@"loadAd"];
    if(!self.adProvider){
        self.adProvider = [[ZJFeedFullVideoProvider alloc] initWithPlacementId:self.placementId];
        self.adProvider.delegate = self;
        self.adProvider.adSize = CGSizeMake(kScreenWidth, kScreenHeight);
    }
    [self.adProvider loadAd:6];
    
}

#pragma mark ZJFeedFullVideoProviderDelegate
/**
 * 广告加载成功
 */
- (void)zj_feedFullVideoProviderLoadSuccess:(ZJFeedFullVideoProvider *)provider views:(NSArray<__kindof ZJFeedFullVideoView *> *)views{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoProviderLoadSuccess: %ld",views.count]];
    [self.logView logMessage:[self.adProvider valueForKey:@"logString"]];
    if (views.count) {
        NSMutableArray *dataSources = [NSMutableArray arrayWithCapacity:0];
        [views enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            ZJFeedFullVideoView *videoView = (ZJFeedFullVideoView *)obj;
            videoView.rootViewController = self;
            // important: 此处会进行WKWebview的渲染，建议一次最多预加载三个广告，如果超过3个会很大概率导致WKWebview渲染失败。
            [videoView render];
            [dataSources addObject:videoView];
            [dataSources addObject:@"App tableViewcell"];
        }];
        self.dataSource = [dataSources copy];
    }
    [self.tableView reloadData];
}



/**
* 广告加载失败
*/
- (void)zj_feedFullVideoProviderLoadFail:(ZJFeedFullVideoProvider *)provider error:(NSError *_Nullable)error{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoProviderLoadFail: %@",error]];
    [self.logView logMessage:[self.adProvider valueForKey:@"logString"]];
    NSArray *errors =  [self.adProvider getFillFailureMessages];
    [self.logView logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
}

/**
 * 广告渲染成功, ZJFeedFullVideoView.size.height has been updated
 */
- (void)zj_feedFullVideoAdViewRenderSuccess:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{
    
}

/**
 * 广告渲染失败
 */
- (void)zj_feedFullVideoAdViewRenderFail:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView error:(NSError *_Nullable)error{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoAdViewRenderFail: %@",error]];
}

/**
 * 广告曝光回调
 */
- (void)zj_feedFullVideoAdViewWillShow:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoAdViewWillShow"]];
}

/**
视频广告播放状态更改回调
*/
- (void)zj_feedFullVideoAdViewStateDidChanged:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView state:(ZJMediaPlayerStatus)playerState{
    
}

/**
视频广告播放完毕
*/
- (void)zj_feedFullVideoAdViewPlayerDidPlayFinish:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{

}

/**
 * 广告点击回调
 */
- (void)zj_feedFullVideoAdViewDidClick:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{
    
}

/**
* 广告详情页面即将展示回调
*/
- (void)zj_feedFullVideoAdViewDetailViewWillPresentScreen:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{
    
}

/**
 *广告详情页关闭回调
 */
- (void)zj_feedFullVideoAdViewDetailViewClosed:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{
    
}

#pragma mark --- tableView dataSource&delegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSUInteger index = indexPath.row;
    id model = self.dataSource[index];
    if ([model isKindOfClass:[ZJFeedFullVideoView class]]) {
        UITableViewCell *cell = nil;
        cell = [self.tableView dequeueReusableCellWithIdentifier:@"ZJFeedFullVideoAdCell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        // 重用BUNativeExpressAdView，先把之前的广告试图取下来，再添加上当前视图
        UIView *subView = (UIView *)[cell.contentView viewWithTag:1000];
        if ([subView superview]) {
            [subView removeFromSuperview];
        }
        UIView *view = model;
        view.tag = 1000;
        [cell.contentView addSubview:view];
        return cell;
    } else {
        ZJFullScreenCell *cell = nil;
        cell = [tableView dequeueReusableCellWithIdentifier:@"ZJFullScreenCell" forIndexPath:indexPath];
        return cell;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [UIScreen mainScreen].bounds.size.height;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
}

#pragma mark Property

-(UITableView*) tableView{
    if(!_tableView){
        _tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _tableView.pagingEnabled = YES;
        #if defined(__IPHONE_11_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_11_0
            if ([_tableView respondsToSelector:@selector(setContentInsetAdjustmentBehavior:)]) {
                if (@available(iOS 11.0, *)) {
                    _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
                    _tableView.estimatedRowHeight = 0;
                }
            }
        #else
            self.automaticallyAdjustsScrollViewInsets = NO;
        #endif
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [_tableView registerClass:[ZJFullScreenCell class] forCellReuseIdentifier:@"ZJFullScreenCell"];
        [_tableView registerClass:[ZJFeedFullVideoAdCell class] forCellReuseIdentifier:@"ZJFeedFullVideoAdCell"];
    }
    return _tableView;
}


@end
