//
//  ZJNativeExpressAdsViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeExpressAdsViewController.h"
#import <ZJSDK/ZJNativeExpressFeedAdManager.h>
#import "ZJNativeExpressAdTableViewCell.h"
#import "ZJLogView.h"
@interface ZJNativeExpressAdsViewController ()<UITableViewDelegate,UITableViewDataSource,ZJNativeExpressFeedAdManagerDelegate,ZJNativeExpressFeedAdDelegate>

@property (nonatomic,strong)UITableView *tableView;

@property (nonatomic,strong)ZJNativeExpressFeedAdManager *feedAdManager;

@property (nonatomic,strong)NSMutableArray *dataArray;
@property (nonatomic,strong)NSArray <ZJNativeExpressFeedAd *>*adArray;

@property (nonatomic, strong)ZJLogView *logView;
@end

@implementation ZJNativeExpressAdsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    UIButton *refreshBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [refreshBtn setTitle:@"刷新广告" forState:UIControlStateNormal];
    [refreshBtn setBackgroundColor:[UIColor brownColor]];
    [refreshBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [refreshBtn addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:refreshBtn];
    [refreshBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.mas_equalTo(0);
        make.top.mas_equalTo(self.navigationController.navigationBar.frame.size.height+[UIApplication sharedApplication].statusBarFrame.size.height);
        make.height.mas_equalTo(40);
    }];
    
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(refreshBtn.mas_bottom);
        make.left.right.bottom.mas_equalTo(0);
    }];
    
    self.logView = [[ZJLogView alloc]init];
    [self.view addSubview:self.logView];
    [self.logView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.offset(0);
        make.height.mas_equalTo(100);
    }];
    
    [self loadAd];
}

-(void)loadAd{
    [self.logView logMessage:@"loadAd"];
    if (!_feedAdManager) {
        _feedAdManager = [[ZJNativeExpressFeedAdManager alloc] initWithPlacementId:self.adId size:CGSizeMake(self.tableView.frame.size.width, 0)];
        _feedAdManager.delegate = self;
        _feedAdManager.mutedIfCan = YES;
    }
    [_feedAdManager loadAdDataWithCount:3];
}


#pragma mark - ZJNativeExpressFeedAdManagerDelegate
-(void)ZJ_nativeExpressFeedAdManagerSuccessToLoad:(ZJNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *)multipleResultObject{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdManagerSuccessToLoad: %ld",multipleResultObject.count]];
    [self.logView logMessage:[self.feedAdManager valueForKey:@"logString"]];
    //不要保存太多广告，需要在合适的时机手动释放不用的，否则内存会过大
//    if (self.adArray.count > 0) {
//        for (ZJNativeExpressFeedAd *feedAd in self.adArray) {
//            [self.dataArray removeObject:feedAd];
//        }
//    }
    for (int i = 0; i<multipleResultObject.count; i++) {
        ZJNativeExpressFeedAd *feedAd = multipleResultObject[i];
        feedAd.rootViewController = self;
        feedAd.delegate = self;
        [feedAd render];
        
        NSInteger index = i*3;
        if (index >= self.dataArray.count) {
            [self.dataArray addObject:feedAd];
        }else{
            [self.dataArray insertObject:feedAd atIndex:index];
        }
    }
    self.adArray = multipleResultObject;
    [self.tableView reloadData];
}

-(void)ZJ_nativeExpressFeedAdManager:(ZJNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *)error{
    [self.logView logMessage:[NSString stringWithFormat:@"FeedAdDidFailWithError: %@",error]];
    [self.logView logMessage:[self.feedAdManager valueForKey:@"logString"]];
    NSArray *errors =  [self.feedAdManager getFillFailureMessages];
    [self.logView logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
}

#pragma mark - ZJNativeExpressFeedAdDelegate
/**
 * 广告渲染成功
 */
- (void)ZJ_nativeExpressFeedAdRenderSuccess:(ZJNativeExpressFeedAd *)feedAd{
    [self.tableView reloadData];
}
/**
 * 广告渲染失败
 */
- (void)ZJ_nativeExpressFeedAdRenderFail:(ZJNativeExpressFeedAd *)feedAd{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdRenderFail"]];
    
    [self.dataArray removeObject:feedAd];
    [self.tableView reloadData];
}

- (void)ZJ_nativeExpressFeedAdViewWillShow:(ZJNativeExpressFeedAd *)feedAd{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdViewShow"]];
}
- (void)ZJ_nativeExpressFeedAdDidClick:(ZJNativeExpressFeedAd *)feedAd{
    
}
- (void)ZJ_nativeExpressFeedAdDislike:(ZJNativeExpressFeedAd *)feedAd{
    [self.dataArray removeObject:feedAd];
    [self.tableView reloadData];
}
- (void)ZJ_nativeExpressFeedAdDidShowOtherController:(ZJNativeExpressFeedAd *)nativeAd{
    
}
- (void)ZJ_nativeExpressFeedAdDidCloseOtherController:(ZJNativeExpressFeedAd *)nativeAd{
    
}


#pragma mark - UITableViewDataSource

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArray.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    id object =  self.dataArray[indexPath.row];
    if ([object isKindOfClass:[ZJNativeExpressFeedAd class]]) {
        CGFloat height = ((ZJNativeExpressFeedAd *)object).feedView.frame.size.height;
        return height;
    }else{
        return 44;;
    }
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
   UITableViewCell *cell = nil;
    id object =  self.dataArray[indexPath.row];
    if ([object isKindOfClass:[ZJNativeExpressFeedAd class]]) {
        cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(ZJNativeExpressAdTableViewCell.class) forIndexPath:indexPath];
        [(ZJNativeExpressAdTableViewCell *)cell refreshWithAd:(ZJNativeExpressFeedAd *)object];
    }else{
        cell = [self.tableView dequeueReusableCellWithIdentifier:@"ZJDemoNormalCell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.backgroundColor = [UIColor whiteColor];
        cell.textLabel.textColor = [UIColor blackColor];
        cell.textLabel.font = [UIFont boldSystemFontOfSize:16];
        cell.textLabel.text = (NSString *)object;
    }

   return cell;
}
#pragma mark  - Property

-(UITableView*) tableView{
    if(!_tableView){
        _tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        if (@available(iOS 11.0, *)) {
            _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        }else{
            self.automaticallyAdjustsScrollViewInsets = NO;
        }
//        _tableView.estimatedRowHeight = 0;
        _tableView.estimatedSectionFooterHeight = 0;
        _tableView.estimatedSectionHeaderHeight = 0;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        
        [_tableView registerClass:[ZJNativeExpressAdTableViewCell class] forCellReuseIdentifier:NSStringFromClass(ZJNativeExpressAdTableViewCell.class)];
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"ZJDemoNormalCell"];
    }
    
    return _tableView;
}

-(NSMutableArray *)dataArray{
    if (!_dataArray) {
        NSMutableArray *array = [NSMutableArray array];
        for (int i = 0 ; i <= 10; i++) {
            NSString *string = [NSString stringWithFormat:@"数据_%d",i];
            [array addObject:string];
        }
        _dataArray = array;
    }
    return _dataArray;
}

@end
