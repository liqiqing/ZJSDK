//
//  TXAdShowModeModel.h
//  TanxSDK
//
//  Created by 王飞 on 2022/9/8.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TXAdJSONModel.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXAdShowModeModel :  TXAdJSONModel
@property (nonatomic, assign, readwrite) CGFloat title_size;
@property (nonatomic, copy  , readwrite) NSString *title_color;
@property (nonatomic, assign, readwrite) CGFloat ad_size;
@property (nonatomic, copy  , readwrite) NSString *ad_color;
@property (nonatomic, assign, readwrite) CGFloat adv_size;
@property (nonatomic, copy  , readwrite) NSString *adv_color;
@property (nonatomic, copy  , readwrite) NSString *bg_color;
@property (nonatomic, assign, readwrite) CGFloat pic_radius;
@end

NS_ASSUME_NONNULL_END
