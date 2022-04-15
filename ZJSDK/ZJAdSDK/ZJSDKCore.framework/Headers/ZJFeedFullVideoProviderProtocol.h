//
//  ZJFeedFullVideoProviderProtocol.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol ZJFeedFullVideoProviderProtocol <NSObject>

//请求广告尺寸
@property (nonatomic, assign) CGSize adSize;

- (void)loadAd:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
