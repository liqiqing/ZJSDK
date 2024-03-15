//
//  TXAdBidModel.h
//  TanxSDK-iOS
//
//  Created by Evan on 2023/2/22.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TXAdJSONModel.h"

@interface TXAdBidModel : TXAdJSONModel

/// tanx广告价格
@property (nonatomic, copy, readonly)  NSString *bidPrice;

/// 如tanx广告竞价失败，支持回传三方竞价成功的价格
@property (nonatomic, copy)  NSString *winPrice;

@end


