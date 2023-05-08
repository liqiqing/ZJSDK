//
//  ZJUser.h
//  ZJSDK
//
//  Created by Robin on 2020/8/21.
//  Copyright © 2020 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJUser : NSObject
//required. 用户id
@property(nonatomic,copy) NSString* userID;
//optional. 用户昵称
@property(nonatomic,copy) NSString* userName;
//optional. 用户头像
@property(nonatomic,copy) NSString*  userAvatar;
//optional. 用户积分
@property(nonatomic,assign) NSInteger userIntegral;
//optional. 广告位id
@property(nonatomic,copy) NSString *posId;
//optional. 扩展信息
@property(nonatomic,copy) NSString* ext;

- (NSString*)toJsonString;

@end

NS_ASSUME_NONNULL_END
