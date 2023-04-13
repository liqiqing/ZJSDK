//
//  ZJNativeAdAdapter.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/29.
//

//#import "ZJMultipleAdAdapter.h"
#import <ZJSDKCore/ZJMultipleAdAdapter.h>
#import <ZJSDKCore/ZJNativeAdObject.h>
NS_ASSUME_NONNULL_BEGIN

@class ZJNativeAdAdapter;
@protocol ZJNativeAdAdapterDelegate <NSObject>
/**
 广告数据回调

 @param multipleResultObject 广告数据数组
 @param error 错误信息
 */
- (void)zjAdapter_nativeAd:(ZJNativeAdAdapter *)adAdapter didLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;


@end



@interface ZJNativeAdAdapter : ZJMultipleAdAdapter

@property (nonatomic,weak)id <ZJNativeAdAdapterDelegate> delegate;


/**
 广告数据回调
 */
- (void)nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;



-(void)loadAdWithCount:(NSInteger)adCount;


@end

NS_ASSUME_NONNULL_END
