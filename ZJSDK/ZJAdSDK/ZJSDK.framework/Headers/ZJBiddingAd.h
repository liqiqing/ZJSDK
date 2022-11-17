//
//  ZJBiddingAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2022/11/11.
//  Copyright © 2022 zj. All rights reserved.
//

#import <ZJSDK/ZJAd.h>
#import <ZJSDKCore/ZJBiddingAdAdapter.h>
#import <ZJSDKCore/ZJAdCountdown.h>
#import <ZJSDKCore/ZJAdPreferenceManager.h>
#import <ZJSDKCore/ZJStrategyManager.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJBiddingProtocol <NSObject>

@required
-(void)dealSuccessResult;
-(void)dealFailResultWithError:(NSError*)error;
-(ZJBiddingAdAdapter *)createAdapterForUnit:(ZJAdUnitModel *)unit;

@optional
- (NSInteger)getCountDownInterval;
@end



@interface ZJBiddingAd : ZJAd<ZJBiddingProtocol>{
    BOOL _needDelayLoadAd;
    BOOL _takeFastReturnAd;
    NSInteger eCPM1;
    NSInteger eCPM2;
}

@property (nonatomic,strong)dispatch_semaphore_t semaphore;
@property (nonatomic, strong) dispatch_queue_t semaphoreQueue;

//倒计时器
@property (nonatomic,strong)ZJAdCountdown *countdown;
//数据管理
@property (nonatomic,strong)ZJAdPreferenceManager *adManager;
//pd广告请求对象数组
@property (nonatomic,strong)NSMutableArray <ZJBiddingAdAdapter *>*adapterArrayPD;
//bd广告请求对象数组
@property (nonatomic,strong)NSMutableArray <ZJBiddingAdAdapter *>*adapterArrayBD;

//pd广告请求成功数组
@property (nonatomic,strong)NSMutableArray <ZJBiddingAdAdapter *>*successAdaptersPD;

//bd广告请求成功数组
@property (nonatomic,strong)NSMutableArray <ZJBiddingAdAdapter *>*successAdaptersBD;


@property (nonatomic,strong)ZJBiddingAdAdapter *ecpm1Adapter;

@property (nonatomic,strong,nullable)ZJBiddingAdAdapter *currentAdapter;

//错误信息数组
@property (nonatomic,strong)NSMutableArray <NSError *>*adFailArray;

@property (nonatomic,strong)NSMutableString *logString;

-(void)loadAd;
-(void)unitAdapterDidLoad:(ZJBiddingAdAdapter *)adapter;
-(void)unitAdapterLoadFail:(ZJBiddingAdAdapter *)adapter error:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
