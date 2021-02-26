//
//  ZJAdProtocol.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2020/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJAdProtocol <NSObject>

@required
@property(nonatomic, copy) NSString *placementId;
/**
*  构造方法
*  详解：placementId - 广告位 ID
*/
@optional
- (instancetype)initWithPlacementId:(NSString *)placementId;

@end

NS_ASSUME_NONNULL_END
