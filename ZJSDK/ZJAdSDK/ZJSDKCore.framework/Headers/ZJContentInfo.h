//
//  ZJContentInfo.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, ZJContentInfoType) {
    ZJContentInfoTypeUnknown,         //未知，正常不会出现
    ZJContentInfoTypeNormal,          //普通信息流
    ZJContentInfoTypeAd,              //SDK内部广告
    ZJContentInfoTypeEmbeded = 100    //外部广告
};

NS_ASSUME_NONNULL_BEGIN

@protocol ZJContentInfo <NSObject>

//内容标识
- (NSString *)contentInfoId;
//内容类型
//ZJContentInfoTypeUnknown = 0,         //未知，正常不会出现
// ZJContentInfoTypeNormal = 1,          //普通信息流
// ZJContentInfoTypeAd = 2,              //SDK内部广告
//ZJContentInfoTypeEmbeded = 100    //外部广告
- (NSInteger)contentInfoType;

@end

NS_ASSUME_NONNULL_END
