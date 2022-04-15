//
//  ZJCoreAdAdapter.h
//  ZJSDKCore
//
//  Created by Robin on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJAdUnionItemModel.h>
#import <ZJSDKCore/ZJAdDebugLog.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJCoreAdAdapter : NSObject

@property(nonatomic, strong ,readonly) ZJAdUnitModel *config;

- (instancetype)initWithAdItemConfig:(ZJAdUnitModel *)adItemConfig;


+ (void)registerPlatform:(NSString*)platform adType:(NSString*)adType adapterClass:(NSString*) adapterClass;

//创建对象使用
+ (instancetype)createWithAdItemConfig:(ZJAdUnitModel *)adItemConfig;



+ (Class)getAdapterClass:(ZJAdUnitModel *)adItemConfig;


@end

NS_ASSUME_NONNULL_END
