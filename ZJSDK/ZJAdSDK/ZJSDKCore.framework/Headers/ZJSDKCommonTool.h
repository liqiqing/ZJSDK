//
//  ZJSDKCommonTool.h
//  ZJOptimizeProject
//
//  Created by Rare on 2021/8/5.
//

#import <Foundation/Foundation.h>
#import "ZJSDKDefines.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKCommonTool : NSObject

+ (UIViewController *)getCurrentViewController;

+ (UIViewController *)getCurrentViewControllerFrom:(UIViewController *)rootVC;

@end

NS_ASSUME_NONNULL_END
