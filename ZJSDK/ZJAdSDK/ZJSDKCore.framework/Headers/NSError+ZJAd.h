//
//  NSError+ZJAd.h
//  ZJSDKCore
//
//  Created by Rare on 2021/6/9.


#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJAdUnionItemModel.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,ZJErrorCodeAd){
    ZJErrorCodeAd_Unknown = 100100,
    ZJErrorCodeAd_Timeout = 100200,
    ZJErrorCodeAd_LackLibraries = 100201,
    ZJErrorCodeAd_AdId = 100202,
    ZJErrorCodeAd_is_being_limit = 100301
};


@interface NSError (ZJAd)


+ (NSError *)zjAdError_errorWithCode:(ZJErrorCodeAd)code adItemConfig:(nullable ZJAdUnitModel *)adItemConfig userInfo:(nullable NSDictionary<NSString *, id> *)dict;


- (NSDictionary *)convertDictionary;


- (NSString *)convertJSONString;

@end

NS_ASSUME_NONNULL_END
