//
//  ZJCache.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/5/23.
//

#import <Foundation/Foundation.h>
#import "ZJDiskCache.h"
#import "ZJMemoryCache.h"
#import "ZJCacheOperation.h"
NS_ASSUME_NONNULL_BEGIN
#define KEY_CACHE_DIRECTORY  @"ZJCacheData"

typedef void(^ZJNoParamsBlock)(void);
typedef void(^ZJCacheQueryCompletionBlock)(NSDictionary * _Nullable dic);
typedef NSString * _Nullable (^ZJCacheAdditionalCachePathBlock)(NSString * _Nonnull key);
@protocol ZJCache <NSObject>

@required
- (NSDictionary *)queryCacheForKey:(NSString *)key;

- (void)storeDic:(NSDictionary *)dic forKey:(nullable NSString *)key completion:(nullable ZJNoParamsBlock)completionBlock;


- (void)removeDicForKey:(NSString *)key completion:(nullable ZJNoParamsBlock)completionBlock;


- (void)containsDicForKey:(NSString *)key completion:(nullable ZJNoParamsBlock)completionBlock;

- (void)clearAllCacheCompletion:(ZJNoParamsBlock)completionBlock;

@end

@interface ZJCache : NSObject <ZJCache>
@property (nonatomic, class, readonly, nonnull) ZJCache *sharedCache;
@property (nonatomic, strong, readonly, nonnull) id <ZJMemoryCache>memoryCache;
@property (nonatomic, strong, readonly, nonnull) id <ZJDiskCache>diskCache;
@property (nonatomic, copy, nonnull, readonly) NSString *diskCachePath;

@property (nonatomic, copy, nullable) ZJCacheAdditionalCachePathBlock additionalCachePathBlock;



@end
NS_ASSUME_NONNULL_END
