//
//  ZJH5Ad.h
//  ZJSDK
//
//  Created by Robin on 2020/10/28.
//  Copyright © 2020 zj. All rights reserved.
//

#import <ZJSDKCoreFramewrok/ZJAd.h>
#import "ZJUser.h"
#import "ZJH5PageDelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface ZJH5Page : ZJAd
@property(nonatomic,weak) id<ZJH5PageDelegate> delegate;
@property(nonatomic,strong) ZJUser *user;
- (instancetype)initWithPlacementId:(NSString *)placementId user:(ZJUser *)user delegate:(id<ZJH5PageDelegate>) delegate;
-(void) loadH5Page;
-(void) showH5Page:(UIViewController*) rootViewController;
@end

NS_ASSUME_NONNULL_END
