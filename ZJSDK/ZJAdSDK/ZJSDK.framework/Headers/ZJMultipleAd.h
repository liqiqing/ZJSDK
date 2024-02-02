//
//  ZJMultipleAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2022/11/11.
//  Copyright © 2022 zj. All rights reserved.
//

#import <ZJSDK/ZJAd.h>
#import <ZJSDK/ZJTierAd.h>
#import <ZJSDKCore/ZJMultipleAdAdapter.h>
#import <ZJSDKCore/ZJAdCountdown.h>
#import <ZJSDKCore/ZJAdPreferenceManager.h>
#import <ZJSDKCore/ZJStrategyManager.h>
#import  <ZJSDK/ZJMultipleTierAdLoader.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJMultipleProtocol <NSObject>
@required
-(void)dealSuccessResult;
-(void)dealFailResultWithError:(NSError*)error;
-(ZJMultipleTierAdLoader *)createTierLoader:(NSArray <ZJAdUnitModel *>*)tiers showPriority:(ZJAdShowPriority)showPriority;

@optional
- (NSInteger)getCountDownInterval;
@end



@interface ZJMultipleAd : ZJAd<ZJMultipleProtocol>{
    BOOL _needDelayLoadAd;
    BOOL _takeFastReturnAd;
    NSInteger eCPM1;
    NSInteger eCPM2;
}

//倒计时器
//@property (nonatomic,strong)ZJAdCountdown *countdown;
//数据管理
@property (nonatomic,strong)ZJAdPreferenceManager *adManager;

//错误信息数组
@property (nonatomic,strong)NSMutableArray <NSError *>*adFailArray;

@property (nonatomic,strong)NSMutableString *logString;



//pd广告请求成功数组
@property (nonatomic,strong)NSMutableArray <ZJMultipleAdAdapter *>*successAdaptersPD;

//bd广告请求成功数组
@property (nonatomic,strong)NSMutableArray <ZJMultipleAdAdapter *>*successAdaptersBD;


@property (nonatomic,strong)ZJMultipleAdAdapter *ecpm1Adapter;

@property (nonatomic,strong,nullable)ZJMultipleAdAdapter *currentAdapter;

-(void)loadAdWithCount:(NSUInteger)count;
@end

NS_ASSUME_NONNULL_END
