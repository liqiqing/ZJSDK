//
//  ZJNativeExpressAdsViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeExpressAdsViewController.h"
//#import <ZJSDK/ZJNativeExpressFeedAdManager.h>
#import "ZJNativeExpressAdTableViewCell.h"
@interface ZJNativeExpressAdsViewController ()//<UITableViewDelegate,UITableViewDataSource,ZJNativeExpressFeedAdManagerDelegate,ZJNativeExpressFeedAdDelegate>

@property (nonatomic,strong)UITableView *tableView;

//@property (nonatomic,strong)ZJNativeExpressFeedAdManager *feedAd;

@property (nonatomic,strong)NSMutableArray *dataArray;
//@property (nonatomic,strong)NSArray <ZJNativeExpressFeedAd *>*adArray;
@end

@implementation ZJNativeExpressAdsViewController

//- (void)viewDidLoad {
//    [super viewDidLoad];
//    // Do any additional setup after loading the view.
//    UIButton *refreshBtn = [UIButton buttonWithType:UIButtonTypeCustom];
//    [refreshBtn setTitle:@"刷新广告" forState:UIControlStateNormal];
//    [refreshBtn setBackgroundColor:[UIColor brownColor]];
//    [refreshBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
//    [refreshBtn addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
//    [self.view addSubview:refreshBtn];
//    [refreshBtn mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.left.right.mas_equalTo(0);
//        make.top.mas_equalTo(self.navigationController.navigationBar.frame.size.height+[UIApplication sharedApplication].statusBarFrame.size.height);
//        make.height.mas_equalTo(40);
//    }];
//    
//    [self.view addSubview:self.tableView];
//    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.mas_equalTo(refreshBtn.mas_bottom);
//        make.left.right.bottom.mas_equalTo(0);
//    }];
//    [self loadAd];
//}
//
//-(void)loadAd{
//    if (!_feedAd) {
//        _feedAd = [[ZJNativeExpressFeedAdManager alloc] initWithPlacementId:self.adId size:CGSizeMake(self.tableView.frame.size.width, 0)];
//    }
//    _feedAd.delegate = self;
//    [_feedAd loadAdDataWithCount:3];
//}
//
//
//#pragma mark - ZJNativeExpressFeedAdManagerDelegate
//-(void)ZJ_nativeExpressFeedAdManagerSuccessToLoad:(ZJNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *)feedAdDataArray{
//    NSLog(@"%s",__FUNCTION__);
//    //不要保存太多广告，需要在合适的时机手动释放不用的，否则内存会过大
//    if (self.adArray.count > 0) {
//        for (ZJNativeExpressFeedAd *feedAd in self.adArray) {
//            [self.dataArray removeObject:feedAd];
//        }
//    }
//    for (int i = 0; i<feedAdDataArray.count; i++) {
//        ZJNativeExpressFeedAd *feedAd = feedAdDataArray[i];
//        feedAd.rootViewController = self;
//        feedAd.delegate = self;
//        [feedAd render];
//        
//        NSInteger index = i*3;
//        if (index >= self.dataArray.count) {
//            [self.dataArray addObject:feedAd];
//        }else{
//            [self.dataArray insertObject:feedAd atIndex:index];
//        }
//    }
//    self.adArray = feedAdDataArray;
////    [self.tableView reloadData];
//}
//
//-(void)ZJ_nativeExpressFeedAdManager:(ZJNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *)error{
//    NSLog(@"%s",__FUNCTION__);
//}
//
//#pragma mark - ZJNativeExpressFeedAdDelegate
///**
// * 广告渲染成功
// */
//- (void)ZJ_nativeExpressFeedAdRenderSuccess:(ZJNativeExpressFeedAd *)feedAd{
//    NSLog(@"%s",__FUNCTION__);
//    [self.tableView reloadData];
//}
///**
// * 广告渲染失败
// */
//- (void)ZJ_nativeExpressFeedAdRenderFail:(ZJNativeExpressFeedAd *)feedAd{
//    NSLog(@"%s",__FUNCTION__);
//}
//
//- (void)ZJ_nativeExpressFeedAdViewWillShow:(ZJNativeExpressFeedAd *)feedAd{
//    NSLog(@"%s",__FUNCTION__);
//}
//- (void)ZJ_nativeExpressFeedAdDidClick:(ZJNativeExpressFeedAd *)feedAd{
//    NSLog(@"%s",__FUNCTION__);
//}
//- (void)ZJ_nativeExpressFeedAdDislike:(ZJNativeExpressFeedAd *)feedAd{
//    NSLog(@"%s",__FUNCTION__);
//    [self.dataArray removeObject:feedAd];
//    [self.tableView reloadData];
//}
//- (void)ZJ_nativeExpressFeedAdDidShowOtherController:(ZJNativeExpressFeedAd *)nativeAd{
//    NSLog(@"%s",__FUNCTION__);
//}
//- (void)ZJ_nativeExpressFeedAdDidCloseOtherController:(ZJNativeExpressFeedAd *)nativeAd{
//    NSLog(@"%s",__FUNCTION__);
//}
//
//
//#pragma mark - UITableViewDataSource
//
//-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
//    return self.dataArray.count;
//}
//
//-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
//    id object =  self.dataArray[indexPath.row];
//    if ([object isKindOfClass:[ZJNativeExpressFeedAd class]]) {
//        return ((ZJNativeExpressFeedAd *)object).feedView.height;
//    }else{
//        return 44;;
//    }
//}
//
//-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
//   UITableViewCell *cell = nil;
//    id object =  self.dataArray[indexPath.row];
//    if ([object isKindOfClass:[ZJNativeExpressFeedAd class]]) {
//        cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(ZJNativeExpressAdTableViewCell.class) forIndexPath:indexPath];
//        [(ZJNativeExpressAdTableViewCell *)cell refreshWithAd:(ZJNativeExpressFeedAd *)object];
//    }else{
//        cell = [self.tableView dequeueReusableCellWithIdentifier:@"ZJDemoNormalCell" forIndexPath:indexPath];
//        cell.selectionStyle = UITableViewCellSelectionStyleNone;
//        cell.backgroundColor = [UIColor whiteColor];
//        cell.textLabel.textColor = [UIColor blackColor];
//        cell.textLabel.font = [UIFont boldSystemFontOfSize:16];
//        cell.textLabel.text = (NSString *)object;
//    }
//
//   return cell;
//}
//#pragma mark  - Property
//
//-(UITableView*) tableView{
//    if(!_tableView){
//        _tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds];
//        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
//        if (@available(iOS 11.0, *)) {
//            _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
//        }else{
//            self.automaticallyAdjustsScrollViewInsets = NO;
//        }
//        _tableView.estimatedRowHeight = 0;
//        _tableView.estimatedSectionFooterHeight = 0;
//        _tableView.estimatedSectionHeaderHeight = 0;
//        _tableView.delegate = self;
//        _tableView.dataSource = self;
//        
//        [_tableView registerClass:[ZJNativeExpressAdTableViewCell class] forCellReuseIdentifier:NSStringFromClass(ZJNativeExpressAdTableViewCell.class)];
//        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"ZJDemoNormalCell"];
//    }
//    
//    return _tableView;
//}
//
//-(NSMutableArray *)dataArray{
//    if (!_dataArray) {
//        NSMutableArray *array = [NSMutableArray array];
//        for (int i = 0 ; i <= 10; i++) {
//            NSString *string = [NSString stringWithFormat:@"数据_%d",i];
//            [array addObject:string];
//        }
//        _dataArray = array;
//    }
//    return _dataArray;
//}

@end
