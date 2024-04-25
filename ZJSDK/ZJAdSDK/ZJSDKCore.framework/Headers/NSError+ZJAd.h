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
    ZJErrorCodeAd_Unregistered = 100101,

    ZJErrorCodeAd_Timeout = 100200,
    ZJErrorCodeAd_LackLibraries = 100201,
    ZJErrorCodeAd_AllAdReturnError = 100203,

    ZJErrorCodeAd_AdId = 100202,

    ZJErrorCodeAd_is_being_limit = 100301,
    
    
    
    ZJErrorCodeAd_WXLibrarieMissed = 100403,
    ZJErrorCodeAd_WXLibrarieRegistFail = 100404,
    ZJErrorCodeAd_WXNotResponseImp = 100405,
    
    ZJErrorCodeAd_DisplayError = 100500,
    
    ZJErrorCodeAd_MissParameter = 100601,
    ZJErrorCodeAd_AdInvalid = 100602,
    
    ZJErrorCodeAd_app_tradeId_verify_fail = 100701,//媒体激励校验未通过

};


@interface NSError (ZJAd)


+ (NSError *)zjAdError_errorWithCode:(ZJErrorCodeAd)code adItemConfig:(nullable ZJAdUnitModel *)adItemConfig userInfo:(nullable NSDictionary<NSString *, id> *)dict;
+ (NSError *)app_tradeId_verify_fail;
+ (NSError *)errorWithCode:(NSInteger)code message:(nullable NSString *)message;

- (NSDictionary *)convertDictionary;


- (NSString *)convertJSONString;

@end

NS_ASSUME_NONNULL_END
