//
//  KSAdExposureReportParam.h
//  KSUModel
//
//  Created by xuzaihu on 2021/7/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, KSAdExposureFailureCode) {
    KSAdExposureFailureOther                   = 0,    // 其他
    KSAdExposureFailureMediaBasePriceFilter    = 1,    // 媒体侧底价过滤
    KSAdExposureFailureBidFailed               = 2,    // 广告竞价失败
    KSAdExposureFailureCacheInvalid            = 3,    // 缓存失效
    KSAdExposureFailureExposurePriorityReduce  = 4,    // 曝光优先级降低
};

@interface KSAdExposureReportParam : NSObject

// 胜出者的ecpm报价
@property (nonatomic, assign) NSInteger winEcpm;

@end

NS_ASSUME_NONNULL_END
