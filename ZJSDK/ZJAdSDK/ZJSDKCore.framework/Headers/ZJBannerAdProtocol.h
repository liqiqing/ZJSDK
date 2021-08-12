//
//  ZJBannerAdProtocol.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/23.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJBannerAdProtocol <NSObject>

@property (nonatomic, readonly) CGSize adSize;

///interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
@property (nonatomic, readonly) NSInteger interval;

@property (nonatomic, weak) UIViewController *viewController;

- (void)loadAdAndShow;

@end

NS_ASSUME_NONNULL_END
