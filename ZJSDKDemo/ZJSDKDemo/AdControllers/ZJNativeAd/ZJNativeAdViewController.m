//
//  ZJNativeAdViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJNativeAdViewController.h"
#import <ZJSDK/ZJNativeAd.h>
#import "ZJNativeAdImageTableViewCell.h"
#import "ZJNativeAdAtlasImageTableViewCell.h"
#import "ZJNativeAdVideoTableViewCell.h"
#import "ZJLogView.h"
@interface ZJNativeAdViewController ()<ZJNativeAdDelegate,UITableViewDataSource,UITableViewDelegate,ZJNativeAdViewDelegate>
@property (strong, nonatomic) UITableView *tableView;

@property (nonatomic,strong)ZJNativeAd *nativeAd;

@property (nonatomic,strong)NSMutableArray <ZJNativeAdObject *>*dataArray;

@property (nonatomic, strong)ZJLogView *logView;
@end

@implementation ZJNativeAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dataArray = [NSMutableArray array];
    self.view.backgroundColor = [UIColor whiteColor];
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
    
    self.nativeAd = [[ZJNativeAd alloc] initWithPlacementId:self.adId];
    self.nativeAd.delegate = self;
    [self.nativeAd loadAdWithCount:4];
    
    
}

-(void)loadAd{
    [self.nativeAd loadAdWithCount:2];
}


- (void)zj_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error{
    if (!error &&nativeAdObjects.count > 0) {
        [self.logView logMessage:[NSString stringWithFormat:@"nativeAdDidLoaded: %ld",nativeAdObjects.count]];
        [self.dataArray addObjectsFromArray:nativeAdObjects];
        [self.tableView reloadData];
        
    }else{
        [self.logView logMessage:[NSString stringWithFormat:@"nativeAdDidError: %@",error]];
        NSLog(@"自渲染错误回调:%@",error);
    }
    [self.logView logMessage:[self.nativeAd valueForKey:@"logString"]];
}

#pragma mark  - Property

-(UITableView*) tableView{
    if(!_tableView){
        
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, kNavigationBarHeight+4, kScreenWidth, kScreenHeight-kNavigationBarHeight-4)];
        _tableView.backgroundColor = [[UIColor grayColor]colorWithAlphaComponent:0.6];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        if (@available(iOS 11.0, *)) {
            _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        }else{
            self.automaticallyAdjustsScrollViewInsets = NO;
        }
        _tableView.estimatedRowHeight = 0;
        _tableView.estimatedSectionFooterHeight = 0;
        _tableView.estimatedSectionHeaderHeight = 0;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        
        [_tableView registerClass:[ZJNativeAdImageTableViewCell class] forCellReuseIdentifier:NSStringFromClass(ZJNativeAdImageTableViewCell.class)];
        [_tableView registerClass:[ZJNativeAdAtlasImageTableViewCell class] forCellReuseIdentifier:NSStringFromClass(ZJNativeAdAtlasImageTableViewCell.class)];
        [_tableView registerClass:[ZJNativeAdVideoTableViewCell class] forCellReuseIdentifier:NSStringFromClass(ZJNativeAdVideoTableViewCell.class)];
    }
    
    return _tableView;
}


#pragma mark - UITableViewDataSource

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArray.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    ZJNativeAdObject  *object =  self.dataArray[indexPath.row];
    
    if (object.materialType == ZJAdMaterialTypeVideo) {
        return [ZJNativeAdVideoTableViewCell cellHeightWithUnifiedNativeAdDataObject:object];
    } else if (object.materialType == ZJAdMaterialTypeAtlas){
        return [ZJNativeAdAtlasImageTableViewCell cellHeightWithUnifiedNativeAdDataObject:object];
    }else {
        return [ZJNativeAdImageTableViewCell cellHeightWithUnifiedNativeAdDataObject:object];
    }
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    ZJNativeAdObject *object =  self.dataArray[indexPath.row];
    if (object.materialType == ZJAdMaterialTypeVideo) {
        ZJNativeAdVideoTableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(ZJNativeAdVideoTableViewCell.class) forIndexPath:indexPath];
        [cell setupWithUnifiedNativeAdDataObject:object delegate:self vc:self];
        return cell;
    } else if (object.materialType == ZJAdMaterialTypeAtlas){
        ZJNativeAdAtlasImageTableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(ZJNativeAdAtlasImageTableViewCell.class) forIndexPath:indexPath];
        [cell setupWithUnifiedNativeAdDataObject:object delegate:self vc:self];
        return cell;
    }else {
        ZJNativeAdImageTableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(ZJNativeAdImageTableViewCell.class) forIndexPath:indexPath];
        [cell setupWithUnifiedNativeAdDataObject:object delegate:self vc:self];
        return cell;
    }
    
    
}

-(void)dealloc{
    
}
#pragma mark - ZJNativeAdViewDelegate
//广告曝光回调
-(void)zj_nativeAdViewWillExpose:(UIView *)nativeAdView{
    NSLog(@"%s",__FUNCTION__);
}
//广告点击回调
-(void)zj_nativeAdViewDidClick:(UIView *)nativeAdView{
    NSLog(@"%s",__FUNCTION__);
}
//广告详情页关闭回调
-(void)zj_nativeAdDetailViewClosed:(UIView *)nativeAdView{
    NSLog(@"%s",__FUNCTION__);
}
//广告详情页面即将展示回调
-(void)zj_nativeAdDetailViewWillPresentScreen:(UIView *)nativeAdView{
    NSLog(@"%s",__FUNCTION__);
}
@end
