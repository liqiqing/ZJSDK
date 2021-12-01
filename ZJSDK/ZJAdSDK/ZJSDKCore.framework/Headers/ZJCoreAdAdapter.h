//
//  ZJCoreAdAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJAdItemConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJCoreAdAdapter : NSObject

@property(nonatomic,copy) NSString *platform;
@property(nonatomic,copy) NSString *placementId;
@property(nonatomic,copy) NSString *zj_adID;
@property(nonatomic,copy) NSString *zj_appID;
@property(nonatomic,strong) ZJAdItemConfig *config;


+ (void)registerPlatform:(NSString*)platform adType:(NSString*)adType adapterClass:(NSString*) adapterClass;
+ (NSString *)getAdapterClass:(NSString*)platform adType:(NSString*)adType;
+ (Class)getAdapterClass:(ZJAdItemConfig *)adItemConfig;
+ (instancetype)createWithAdItemConfig:(ZJAdItemConfig *)adItemConfig;

- (instancetype)initWithAdItemConfig:(ZJAdItemConfig *)adItemConfig;
- (BOOL)hasReady;
- (BOOL)hasInit;

@end

NS_ASSUME_NONNULL_END
