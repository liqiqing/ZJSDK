//
//  ZJFeedFullVideoAdAdapterView.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJFeedFullVideoAdAdapterView : UIView
@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, copy,readonly) NSString *identifier;
-(void)render;
@end

NS_ASSUME_NONNULL_END
