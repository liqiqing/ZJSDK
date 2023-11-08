//
//  MKMD5.h
//  Twideo
//
//  Created by 麻明康 on 2023/9/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKMD5 : NSObject
NSString * md5 (NSString *string,...);
+ (NSString *)md5:(NSString *)string;
@end

NS_ASSUME_NONNULL_END
