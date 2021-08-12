//
//  ZJNativeAdAdapter.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/29.
//

#import "ZJCoreAdAdapter.h"
#import "ZJNativeAdObject.h"
NS_ASSUME_NONNULL_BEGIN
@protocol ZJNativeAdAdapterDelegate <NSObject>
/**
 广告数据回调

 @param nativeAdObjects 广告数据数组
 @param error 错误信息
 */
- (void)zjAdapter_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;


@end



@interface ZJNativeAdAdapter : ZJCoreAdAdapter

@property (nonatomic,weak)id <ZJNativeAdAdapterDelegate> delegate;


/**
 广告数据回调
 */
- (void)nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;



-(void)loadAdWithCount:(NSInteger)adCount;

@end

NS_ASSUME_NONNULL_END
