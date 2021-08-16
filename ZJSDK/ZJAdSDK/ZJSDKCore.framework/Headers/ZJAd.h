//
//  ZJAd.h
//  ZJSDK
//
//  Created by Robin on 2020/8/21.
//  Copyright © 2020 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZJAdItemConfig.h"
#import "NSError+ZJAd.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJAd : NSObject

@property(nonatomic,copy) NSString *placementId;
/**
*  构造方法
*  详解：placementId - 广告位 ID
*/
- (instancetype)initWithPlacementId:(NSString *)placementId;

@end

NS_ASSUME_NONNULL_END
