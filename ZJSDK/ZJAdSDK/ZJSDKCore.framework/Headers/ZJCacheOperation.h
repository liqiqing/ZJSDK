//
//  ZJCacheOperation.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/5/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// A protocol represents cancelable operation.
@protocol ZJCacheOperation <NSObject>

- (void)cancel;

@end
/// NSOperation conform to `ZJCacheOperation`.
@interface NSOperation (ZJCacheOperation) <ZJCacheOperation>

@end

NS_ASSUME_NONNULL_END
