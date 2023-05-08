//
//  ZJInvoker.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/9/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJInvoker : NSObject
+(id)safePerformAction:(SEL)action target:(NSObject *)target withObject:(nullable id)object,...NS_REQUIRES_NIL_TERMINATION;
+(NSArray *)getInstanceMethodList:(NSString *)className;
+(NSArray *)getClassMethodList:(NSString *)className;
+(NSArray *)getMethodList:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
