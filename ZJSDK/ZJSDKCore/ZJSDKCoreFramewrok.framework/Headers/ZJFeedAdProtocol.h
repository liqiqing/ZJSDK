//
//  ZJFeedAdProtocol.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol ZJFeedAdProtocol <NSObject>
//请求广告尺寸
@property(nonatomic,assign) CGSize adSize;
-(void) loadAd:(NSInteger) count;
@end

NS_ASSUME_NONNULL_END
