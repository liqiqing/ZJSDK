//
//  ZJNewsAdProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJNewsAdProtocol <NSObject>
@property (nonatomic, readonly) CGRect adFrame;
- (void)loadAdAndShowWithRemindLab:(BOOL)showRemindLab;
- (void)loadAdAndShow;
@end

NS_ASSUME_NONNULL_END
