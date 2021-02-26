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
@interface ZJFeedFullVideoShowViewController ()<UITableViewDataSource,UITableViewDelegate,ZJFeedFullVideoProviderDelegate>
@property (strong, nonatomic) UITableView *tableView;

@property(nonatomic,strong) ZJFeedFullVideoProvider *adProvider;
@property (nonatomic, copy) NSArray *dataSource;
@end

@implementation ZJFeedFullVideoShowViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self.navigationController setNavigationBarHidden:YES animated:NO];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.tableView];
    
    UIButton *closeButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [closeButton setTitle:@"X" forState:UIControlStateNormal];
    closeButton.titleLabel.textColor = [UIColor whiteColor];
    closeButton.titleLabel.font = [UIFont boldSystemFontOfSize:26];
    closeButton.frame = CGRectMake(6, 44, 64, 64);
    [closeButton clickHandle:^(UIButton *button) {
        [self.navigationController popViewControllerAnimated:NO];
    }];
    
    [self.view addSubview:closeButton];
    
    NSMutableArray *datas = [NSMutableArray array];
    for (NSInteger i =0 ; i <= 5; i++) {
        [datas addObject:@"App tableViewcell"];
    }
    self.dataSource = [datas copy];
    [self loadData];
}
- (void)loadData {
    if(!self.adProvider){
        self.adProvider = [[ZJFeedFullVideoProvider alloc] initWithPlacementId:self.placementId delegate:self];
        self.adProvider.adSize = self.view.bounds.size;
    }
    [self.adProvider loadAd:10];
    
}

#pragma mark ZJFeedFullVideoProviderDelegate
/**
 * 广告加载成功
 */
- (void)zj_feedFullVideoProviderLoadSuccess:(ZJFeedFullVideoProvider *)provider views:(NSArray<__kindof ZJFeedFullVideoView *> *)views{
    if (views.count) {
        NSMutableArray *dataSources = [NSMutableArray arrayWithCapacity:0];
        [views enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            ZJFeedFullVideoView *videoView = (ZJFeedFullVideoView *)obj;
            videoView.rootViewController = self;
            // important: 此处会进行WKWebview的渲染，建议一次最多预加载三个广告，如果超过3个会很大概率导致WKWebview渲染失败。
            [videoView render];
            [dataSources addObject:videoView];
        }];
        self.dataSource = [dataSources copy];
    }
    [self.tableView reloadData];
}

-(ZJFeedFullVideoView*)  getShowAdView{
    NSMutableArray *adViews = [NSMutableArray array];
    id objAd = adViews.lastObject;
    [adViews removeLastObject];
    
    if(adViews.count==0){
        [self.adProvider loadAd:10];//Max 3
    }
    return objAd;
}

/**
* 广告加载失败
*/
- (void)zj_feedFullVideoProviderLoadFail:(ZJFeedFullVideoProvider *)provider error:(NSError *_Nullable)error{
    NSLog(@"%s",__func__);
}

/**
 * 广告渲染成功, ZJFeedFullVideoView.size.height has been updated
 */
- (void)zj_feedFullVideoAdViewRenderSuccess:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{
    NSLog(@"%s",__func__);
}

/**
 * 广告渲染失败
 */
- (void)zj_feedFullVideoAdViewRenderFail:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView error:(NSError *_Nullable)error{
    NSLog(@"%s",__func__);
}

/**
 * 广告曝光回调
 */
- (void)zj_feedFullVideoAdViewWillShow:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView{
    
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
        cell.backgroundColor = index%2?[UIColor blueColor]:[UIColor grayColor];
        return cell;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [UIScreen mainScreen].bounds.size.height;
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
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
