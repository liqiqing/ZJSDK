//
//  NSError+ZJAd.h
//  ZJSDKCore
//
//  Created by Rare on 2021/6/9.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJAdUnionItemModel.h>
NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger,ZJAdErrorCode){
    ZJAdErrorCode_Unknown = 100100,
    ZJAdErrorCode_Timeout = 100200,
    ZJAdErrorCode_LackLibraries = 100201,
    ZJAdErrorCode_AdId = 100202
};

@interface NSError (ZJAd)


+ (NSError *)zjAdError_errorWithCode:(ZJAdErrorCode)code adItemConfig:(nullable ZJAdUnitModel *)adItemConfig userInfo:(nullable NSDictionary<NSString *, id> *)dict;


- (NSDictionary *)convertDictionary;


- (NSString *)convertJSONString;

@end

NS_ASSUME_NONNULL_END
