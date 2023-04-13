//
//  ZJMultipleAdAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/3/7.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJMultipleAdAdapterProtocol <NSObject>
-(void)loadAdWithCount:(NSUInteger)count;

@end
@interface ZJMultipleAdAdapter : ZJCoreAdAdapter<ZJMultipleAdAdapterProtocol>
@property (nonatomic,strong,readonly)NSArray *multipleResultObject;

@end

NS_ASSUME_NONNULL_END
