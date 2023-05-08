//
//  ZJFeedFullVideoAdAdapterView.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJFeedFullVideoAdAdapterView : UIView

@property (nonatomic, weak) UIViewController *rootViewController;

@property (nonatomic, copy,readonly) NSString *identifier;

-(void)render;

///手动控制 播放|暂停
@property (nonatomic, assign) BOOL canControlPlayState;

- (void)play;

- (void)pause;
@end

NS_ASSUME_NONNULL_END
