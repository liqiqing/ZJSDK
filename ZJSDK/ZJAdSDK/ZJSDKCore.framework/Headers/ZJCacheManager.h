//
//  ZJCacheManager.h
//  ZJSDKCore
//
//  Created by Mountain King on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import "ZJCache.h"
NS_ASSUME_NONNULL_BEGIN

typedef void (^ZJCacheCompletionBlock)(NSDictionary* _Nullable dic,NSError *_Nullable error , NSString *key);

/// 缓存管理类
@interface ZJCacheManager : NSObject

@property (strong, nonatomic, readonly, nonnull) id<ZJCache> zjCache;


+ (instancetype)sharedManager;

#pragma mark =============== 存 ===============

/// 根据key存字典
/// @param dic 每个key对应一个字典
/// @param key key
-(void)storeDic:(nullable NSDictionary*)dic forKey:(nonnull NSString *)key;


/// 根据key存字典 存储到磁盘为异步（内存清理为同步，不需回调）。
/// @param dic 每个key对应一个字典
/// @param key key
/// @param completedBlock 异步存储到磁盘完成的block
-(void)storeDic:(nullable NSDictionary*)dic forKey:(nonnull NSString *)key completed:(nullable ZJCacheCompletionBlock)completedBlock;

#pragma mark =============== 取 ===============

-(NSDictionary *)loadCacheForKey:(nonnull NSString *)key;



#pragma mark =============== 清理 ===============

/// 清理包括内存和磁盘里的所有缓存
/// @param completionBlock 磁盘清理完成的会调（内存清理为同步，不需回调）
- (void)cleanCacheOnCompletion:(ZJNoParamsBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
