//
//  ZJFeedAdView.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/24.
//

#import <UIKit/UIKit.h>
#import "ZJFeedAdViewProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJFeedAdView : UIView<ZJFeedAdViewProtocol>
@property(nonatomic,weak) UIViewController *rootViewController;
@end

NS_ASSUME_NONNULL_END
