//
//  ZJAdBaseNetworking.h
//  ZJOptimizeProject
//
//  Created by Rare on 2021/8/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAdBaseNetworking : NSObject


+ (nullable NSURLSessionDataTask *)GET:(NSString *)URLString
parameters:(nullable id)parameters
   headers:(nullable NSDictionary <NSString *, NSString *> *)headers
  progress:(nullable void (^)(NSProgress *downloadProgress))downloadProgress
   success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
                      failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;



+ (nullable NSURLSessionDataTask *)POST:(NSString *)URLString
               parameters:(nullable id)parameters
                  headers:(nullable NSDictionary <NSString *, NSString *> *)headers
                 progress:(nullable void (^)(NSProgress *uploadProgress))uploadProgress
                  success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
                   failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;



+ (nullable NSURLSessionDataTask *)PUT:(NSString *)URLString
                            parameters:(nullable id)parameters
                               headers:(nullable NSDictionary <NSString *, NSString *> *)headers
                               success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
                               failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
