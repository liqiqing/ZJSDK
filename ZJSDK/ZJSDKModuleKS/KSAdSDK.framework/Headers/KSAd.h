//
//  KSAd.h
//  KSAdSDK
//
//  Created by 徐志军 on 2019/10/30.
//  Copyright © 2019 KuaiShou. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KSAdInteractionType.h"
#import "KSAdExposureReportParam.h"

NS_ASSUME_NONNULL_BEGIN

@protocol KSAdProtocol <NSObject>

@optional
// 单位:分，只有视频资源下载成功后，这个才可能有值
@property (nonatomic, readonly) NSInteger ecpm;
/// 媒体二次议价, 单位分
- (void)setBidEcpm:(NSInteger)ecpm;
/// 广告曝光失败后上报失败原因
/// @param failureCode 曝光失败原因类型
/// @param reportParam 曝光失败原因描述 reportParam.winEcpm 胜出者的ecpm报价（单位：分）
- (void)reportAdExposureFailed:(KSAdExposureFailureCode)failureCode reportParam:(KSAdExposureReportParam *)reportParam;

@end

@interface KSAd : NSObject<KSAdProtocol>

/// ad interaction type, avaliable after ad load
@property (nonatomic, assign, readonly) KSAdInteractionType interactionType;
/// ad material type, avaliable after ad load
@property (nonatomic, assign, readonly) KSAdMaterialType materialType;

@end

NS_ASSUME_NONNULL_END
