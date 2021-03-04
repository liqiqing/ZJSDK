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
@property (nonatomic,strong)NSString *sdkVersion;
@property (nonatomic,strong)NSString *ZJApp_Id;
@end

NS_ASSUME_NONNULL_END
