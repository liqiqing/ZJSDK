//
//  ZJSDKAdConfig.h
//  ZJSDKCore
//
//  Created by Rare on 2022/2/23.
//

#import <Foundation/Foundation.h>
#import "ZJSDKAdEnum.h"
#import "ZJAdsModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKAdConfig : NSObject

+ (instancetype)shared;

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy) NSArray <NSDictionary *>*platforms;

@property (nonatomic, copy) NSArray <ZJAdPositionModel *>*adArray;

@property (nonatomic, copy) NSString *secretStr;

@property (nonatomic, assign) ZJAdSDKLogLevel level;

@end

NS_ASSUME_NONNULL_END
