//
//  SWModel.h
//  SliderSwitch
//
//  Created by kkmm on 2019/1/9.
//  Copyright © 2019 kkmm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SliderSwitchProtocol.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface SWModel : NSObject
@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSString *categoryId;
@property(nonatomic,strong) NSString *content_app_id;
@property(nonatomic,strong) UIView <SliderSwitchProtocol>* pageView;
@end

NS_ASSUME_NONNULL_END
