//
//  ZJAdPreferenceManager.h
//  ZJSDKCore
//
//  Created by Rare on 2022/2/23.
//

#import <Foundation/Foundation.h>
#import "ZJAdUnionItemModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJAdPreferenceManager : NSObject

@property (nonatomic, strong, nullable, readonly) ZJAdUnionItemModel *currentPDItem;
@property (nonatomic, strong, nullable, readonly) NSArray <ZJAdUnitModel *>*currentBDItems;

@property (nonatomic,assign, readonly)NSInteger currentLevel;
@property (nonatomic,assign, readonly)NSInteger totalLevels;


@property (nonatomic, strong, nullable, readonly) NSArray <ZJAdUnionItemModel *>*pdItems;


/**获取pd和bd广告
 positionId : 广告位置id
 isFirst是否是首次获取  isFirst == YES 才会调用
 */
- (void)getAdItemsWithPositionId:(NSString *)positionId isFirst:(BOOL)isFirst;



/// cdn获取单个广告位数据
/// - Parameters:
///   - adid: 广告位id
///   - completeBlk: 获取完成（成功或者失败）
- (void)getPositionWithAdid:(NSString *)adid completeBlk:(nullable void (^)(BOOL success ,  NSError * _Nullable error))completeBlk;

///判断是否有下一个层广告 并刷新到下移除
- (BOOL)hasNextLevelAndRefresh;


- (NSInteger)weightWithAdItems:(NSArray <ZJAdUnitModel *>*)adItems;


//是否有广告数据
- (BOOL)hasAdDatas;


//广告类型获取广告位id
+(NSString *)getAdDefaultPlacementId:(NSString *)adType;


@end

NS_ASSUME_NONNULL_END
