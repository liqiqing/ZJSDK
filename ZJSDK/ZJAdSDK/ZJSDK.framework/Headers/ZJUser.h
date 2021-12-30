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
//required
@property(nonatomic,copy) NSString* userID;
@property(nonatomic,copy) NSString* userName;
@property(nonatomic,copy) NSString*  userAvatar;
@property(nonatomic,assign) NSInteger userIntegral;
@property(nonatomic,copy) NSString* ext;

-(NSString*) toJsonString;

@end

NS_ASSUME_NONNULL_END
