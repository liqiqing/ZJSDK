//
//  ZJInterstitialAdProtocol.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJInterstitialAdProtocol <NSObject>

///视频静音， 支持部分广播  默认：NO
@property (nonatomic) BOOL mutedIfCan;
///广告size， 支持部分广播
@property (nonatomic, assign) CGSize adSize;

- (void)loadAd;

- (void)presentAdFromRootViewController:(UIViewController*)viewController;

@end

NS_ASSUME_NONNULL_END
