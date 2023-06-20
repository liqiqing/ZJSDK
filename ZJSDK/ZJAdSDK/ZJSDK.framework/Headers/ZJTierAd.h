//
//  ZJTierAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2022/11/11.
//  Copyright © 2022 zj. All rights reserved.
//

#import <ZJSDK/ZJAd.h>
#import <ZJSDKCore/ZJTierAdAdapter.h>
#import <ZJSDKCore/ZJAdCountdown.h>
#import <ZJSDKCore/ZJAdPreferenceManager.h>
#import <ZJSDKCore/ZJStrategyManager.h>
#import "ZJTierAdLoader.h"

NS_ASSUME_NONNULL_BEGIN
@protocol ZJBiddingProtocol <NSObject>
@required
-(void)dealSuccessResult;
-(void)dealFailResultWithError:(NSError*)error;
-(ZJTierAdLoader *)createTierLoader:(NSArray <ZJAdUnitModel *>*)tiers;

@optional
- (NSInteger)getCountDownInterval;
@end



@interface ZJTierAd : ZJAd<ZJBiddingProtocol>{
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
@property (nonatomic,strong)NSMutableArray <ZJTierAdAdapter *>*successAdaptersPD;

//bd广告请求成功数组
@property (nonatomic,strong)NSMutableArray <ZJTierAdAdapter *>*successAdaptersBD;


@property (nonatomic,strong)ZJTierAdAdapter *ecpm1Adapter;

@property (nonatomic,strong,nullable)ZJTierAdAdapter *currentAdapter;

- (void)setCacheAdapter:(ZJTierAdAdapter *)adapter;

-(void)loadAd;
@end

NS_ASSUME_NONNULL_END
