//
//  ZJContentAdapterHorizontalFeedCallBackProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJContentAdapterHorizontalFeedCallBackProtocol <NSObject>
/// 进入横版视频详情页
/// @param viewController 详情页VC
/// @param contentInfo 视频信息
- (void)zjAdapter_horizontalFeedDetailDidEnter:(UIViewController *)viewController contentInfo:(id<ZJContentInfo>)contentInfo;

/// 离开横版视频详情页
/// @param viewController 详情页VC
- (void)zjAdapter_horizontalFeedDetailDidLeave:(UIViewController *)viewController;

/// 视频详情页appear
/// @param viewController 详情页VC
- (void)zjAdapter_horizontalFeedDetailDidAppear:(UIViewController *)viewController;

/// 详情页disappear
/// @param viewController 详情页VC
- (void)zjAdapter_horizontalFeedDetailDidDisappear:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
