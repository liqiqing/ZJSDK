//
//  ZJCoreAdAdapter.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import "ZJAdProtocol.h"
#import "ZJAdItemConfig.h"
NS_ASSUME_NONNULL_BEGIN



@interface ZJCoreAdAdapter : NSObject<ZJAdProtocol>

@property(nonatomic,copy) NSString *platform;
@property(nonatomic,copy) NSString *placementId;
@property(nonatomic,copy) NSString *zj_adID;
@property(nonatomic,copy) NSString *zj_appID;
@property(nonatomic,strong) ZJAdItemConfig *config;


+(void) registerPlatform:(NSString*) platform adType:(NSString*) adType adapterClass:(NSString*) adapterClass;
+(NSString*) getAdapterClass:(NSString*) platform adType:(NSString*) adType;
+ (Class)getAdapterClass:(ZJAdItemConfig *)adItemConfig;
+ (instancetype)createWithAdItemConfig:(ZJAdItemConfig *)adItemConfig;

- (instancetype)initWithAdItemConfig:(ZJAdItemConfig *)adItemConfig;
- (BOOL)hasReady;
- (BOOL)hasInit;

@end

NS_ASSUME_NONNULL_END
