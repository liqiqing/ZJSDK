//
//  ZJAd.h
//  ZJSDK
//
//  Created by Rare on 2022/2/25.
//  Copyright © 2022 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJAdDebugLog.h>
#import <ZJSDKCore/NSError+ZJAd.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZJAd : NSObject

@property(nonatomic,copy,readonly) NSString *placementId;
/**
*  构造方法
*  详解：placementId - 广告位 ID
*/
- (instancetype)initWithPlacementId:(NSString *)placementId;



- (NSArray *)getFillFailureMessages;

@end

NS_ASSUME_NONNULL_END
