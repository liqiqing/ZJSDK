//
//  ZJContentPage.h
//  ZJSDK
//
//  Created by Rare on 2020/12/21.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJAd.h"
#import "ZJContentPageStateDelegate.h"
#import <ZJSDKCore/ZJContentInfo.h>
NS_ASSUME_NONNULL_BEGIN
//typedef NS_ENUM(NSInteger, ZJContentPageType){
//    
//    ZJContentPageDefault = 0,
//    
////    ZJContentPage,
//};
@interface ZJContentPage : ZJAd <ZJContentInfo>

@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;

- (void)tryToRefresh;

@end







NS_ASSUME_NONNULL_END
