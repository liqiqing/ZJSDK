//
//  ViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/8/10.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ViewController.h"
@interface ViewController ()<UITableViewDataSource,UITableViewDelegate>
{
    
}

@property(nonatomic,strong) UITableView *tableView;
@property(nonatomic,strong) NSDictionary *ads;
@property(nonatomic,strong) NSArray *adTypes;

@property(nonatomic,strong) NSDictionary *testDic;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"广告联盟";
    self.tableView = [[UITableView alloc]initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    
    [self.view addSubview:self.tableView];
    
//    self.navigationController.navigationBar.translucent = YES;
    
}
#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.adTypes.count;
}

// Row display. Implementers should *always* try to reuse cells by setting each cell's reuseIdentifier and querying for available reusable cells with dequeueReusableCellWithIdentifier:
// Cell gets various attributes set automatically based on table (separators) and data source (accessory views, editing controls)

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *cellIdentifier = @"UITableViewCellIdentifierKey1";
 
    UITableViewCell *cell =[tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if(!cell){
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }
    NSString *key = self.adTypes[indexPath.row];
    cell.textLabel.text = key;
    return cell;
}
#pragma mark -UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{

    NSString *key = self.adTypes[indexPath.row];
    NSString *vcName = self.ads[key];
    UIViewController *vc  = [[NSClassFromString(vcName) alloc] init];
    [self.navigationController pushViewController:vc animated:NO];
}

-(NSArray*) adTypes{
    if(!_adTypes){
        _adTypes = [NSArray arrayWithObjects:@"开屏广告",@"插屏",@"Banner",@"激励视频",@"全屏视频流",@"Feed信息流",@"H5广告",@"视频内容",@"自渲染",@"全屏视频广告",@"自定义H5",@"悬浮广告", nil];
    }
    return _adTypes;;
}


-(NSDictionary*) ads{
    if(!_ads){
        _ads = [NSMutableDictionary dictionaryWithCapacity:0];
        [_ads setValue:@"ZjRewardViewController" forKey:@"激励视频"];
        [_ads setValue:@"ZjSplashViewController" forKey:@"开屏广告"];
        [_ads setValue:@"ZJH5ViewController" forKey:@"H5广告"];
        [_ads setValue:@"ZJFeedFullVideoViewController" forKey:@"全屏视频流"];
        [_ads setValue:@"ZJInterstitialAdViewController" forKey:@"插屏"];
        [_ads setValue:@"ZJContentPageViewController" forKey:@"视频内容"];
        [_ads setValue:@"ZJFeedAdsViewController" forKey:@"Feed信息流"];
        [_ads setValue:@"ZjBannerViewController" forKey:@"Banner"];
        [_ads setValue:@"ZJNativeAdSelectedViewController" forKey:@"自渲染"];
        [_ads setValue:@"ZJFullScreenVideoViewController" forKey:@"全屏视频广告"];
        [_ads setValue:@"ZJJSBridgeViewController" forKey:@"自定义H5"];
        [_ads setValue:@"ZJFloatingAdViewController" forKey:@"悬浮广告"];
        
    }
    return _ads;;
}


@end
