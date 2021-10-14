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

-(void) loadAd;

-(void)presentAdFromRootViewController:(UIViewController*)  viewController;



///视频静音， 默认：NO  
@property (nonatomic) BOOL mutedIfCan;

@end

NS_ASSUME_NONNULL_END
