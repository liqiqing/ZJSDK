//
//  ZJMultipleTierAdLoader.h
//  ZJSDK
//
//  Created by 麻明康 on 2023/2/23.
//  Copyright © 2023 zj. All rights reserved.
//

#import <ZJSDKCore/ZJSDKCore.h>
#import <ZJSDKCore/ZJMultipleAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJMultipleTierProtocol <NSObject>

@required
-(ZJMultipleAdAdapter *)createTierAdapterForUnit:(ZJAdUnitModel *)unit;
@optional

- (NSInteger)getCountDownInterval;
@end

@interface ZJMultipleTierAdLoader : NSObject <ZJMultipleTierProtocol>

typedef void(^MultipleRequestLevelCompleteBlk)( NSMutableArray <ZJMultipleAdAdapter *>* _Nullable successAdapters, NSMutableArray <NSError *>*_Nullable tierFailArray);

@property (nonatomic,strong)dispatch_semaphore_t semaphore;
@property (nonatomic, strong) dispatch_queue_t semaphoreQueue;
@property (nonatomic, assign) CGFloat timeoutInterval;
@property (nonatomic, assign) ZJAdShowPriority showPriority;

@property (nonatomic, nullable, copy) MultipleRequestLevelCompleteBlk completeBlk;

@property (nonatomic, strong) NSArray <ZJAdUnitModel *>* currentTiers;
//广告请求对象数组
@property (nonatomic,readonly)NSMutableArray <ZJMultipleAdAdapter *>*adapterArray;

//广告请求成功数组
@property (nonatomic,strong)NSMutableArray <ZJMultipleAdAdapter *>*successAdapters;

//错误信息数组
@property (nonatomic,strong)NSMutableArray <NSError *>*tierFailArray;

//倒计时器
@property (nonatomic,strong)ZJAdCountdown *countdown;

@property (nonatomic, assign) long timeout;


- (instancetype)initWithTiers:(NSArray <ZJAdUnitModel *>*)tiers
                     timeoutInterval:(CGFloat)timeoutInterval
                        showPriority:(ZJAdShowPriority)showPriority;

-(void)startLoadWithCount:(NSUInteger)count;

-(void)unitAdapterDidLoad:(ZJMultipleAdAdapter *)adapter resultArray:(NSArray *)resultArray;
-(void)unitAdapterLoadFail:(ZJMultipleAdAdapter *)adapter error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
