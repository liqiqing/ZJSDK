//
//  ZJContentAdapterImageTextDetailProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJContentAdapterImageTextDetailProtocol <NSObject>

/// 进入图文详情页
/// @param detailViewController 图文详情页VC
/// @param feedId feedId
- (void)zjAdapter_imageTextDetailDidEnter:(UIViewController *)detailViewController feedId:(NSString *)feedId;

/// 离开图文详情页
/// @param detailViewController 图文详情页VC
- (void)zjAdapter_imageTextDetailDidLeave:(UIViewController *)detailViewController;

/// 图文详情页appear
/// @param detailViewController 图文详情页VC
- (void)zjAdapter_imageTextDetailDidAppear:(UIViewController *)detailViewController;

/// 图文详情页disappear
/// @param detailViewController 图文详情页VC
- (void)zjAdapter_imageTextDetailDidDisappear:(UIViewController *)detailViewController;

/// 图文详情加载结果
/// @param detailViewController 图文详情页VC
/// @param success 是否成功
/// @param error error
- (void)zjAdapter_imageTextDetailDidLoadFinish:(UIViewController *)detailViewController sucess:(BOOL)success error:(NSError *)error;

/// 图文详情阅读进度
/// @param detailViewController 图文详情页VC
/// @param isFold 是否折叠
/// @param totalHeight 详情总高度
/// @param seenHeight 已经看过的高度
- (void)zjAdapter_imageTextDetailDidScroll:(UIViewController *)detailViewController isFold:(BOOL)isFold totalHeight:(CGFloat)totalHeight seenHeight:(CGFloat)seenHeight;
@end

NS_ASSUME_NONNULL_END
