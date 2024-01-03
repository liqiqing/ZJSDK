//
//  ZJNewsAdProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJNewsAdProtocol <NSObject>
/** required.
 由接入方提供urseId
 用于奖励发放的数据校验，是每个用户的唯一标识符。
 */
@property (nonatomic, copy) NSString *userId;


@property (nonatomic, readonly) CGRect adFrame;

- (void)loadAdAndShow;
@end

NS_ASSUME_NONNULL_END
