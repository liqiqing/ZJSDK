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

@property(nonatomic,strong) NSDictionary *testDic;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"ZJSDKDemo";
    self.tableView = [[UITableView alloc]initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    
    [self.view addSubview:self.tableView];
}
#pragma mark - UITableViewDataSource

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    if (section == 0) {
        return self.ads.count;
    }else{
        return self.testDic.count;
    }
    
}

-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 44;
}
-(CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    return 0.1;
}
-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    if (section == 0) {
        return @"ad";
    }else{
        return @"test";
    }
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
    if (indexPath.section == 0) {
        NSString *key = self.ads.allKeys[indexPath.row];
        cell.textLabel.text = key;
    }else{
        NSString *key = self.testDic.allKeys[indexPath.row];
        cell.textLabel.text = key;
    }
    
    return cell;
}
#pragma mark -UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    NSString *key;
    NSString *vcName;
    if (indexPath.section == 0) {
        key = self.ads.allKeys[indexPath.row];
        vcName = self.ads[key];
    }else{
        key = self.testDic.allKeys[indexPath.row];
        vcName = self.testDic[key];
    }
    UIViewController *vc  = [[NSClassFromString(vcName) alloc] init];
    [self.navigationController pushViewController:vc animated:NO];
}



-(NSDictionary*) ads{
    if(!_ads){
        _ads = [NSMutableDictionary dictionaryWithCapacity:0];
        [_ads setValue:@"ZjRewardViewController" forKey:@"激励视频"];
        [_ads setValue:@"ZjSplashViewController" forKey:@"开屏广告"];
        [_ads setValue:@"ZJH5ViewController" forKey:@"H5内容"];
        [_ads setValue:@"ZJFeedFullVideoViewController" forKey:@"全屏视频流"];
        [_ads setValue:@"ZJInterstitialAdViewController" forKey:@"插屏"];
        [_ads setValue:@"ZJContentPageViewController" forKey:@"视频内容"];
        [_ads setValue:@"ZJFeedAdsViewController" forKey:@"模板信息流"];
        [_ads setValue:@"ZJBannerAdViewController" forKey:@"Banner"];
        
    }
    return _ads;;
}
-(NSDictionary *)testDic{
    if (!_testDic) {
        _testDic = [NSMutableDictionary dictionaryWithCapacity:1];
        [_testDic setValue:@"ZJH5JSViewController" forKey:@"H5调试"];
    }
    return _testDic;
}

@end
