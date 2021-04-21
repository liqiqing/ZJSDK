//
//  ZJSDKCoreConfig.h
//  ZJSDKCoreFramewrok
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKCoreConfig : NSObject
+(instancetype)shared;
@property (nonatomic,copy)NSString *sdkVersion;
@property (nonatomic,copy)NSString *ZJApp_Id;

@property (nonatomic,copy)NSString *secretStr;

@end

NS_ASSUME_NONNULL_END
