//
//  ZJTierAdAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/11/11.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJTierAdapterProtocol <NSObject>
-(void)loadAd;

@end
@interface ZJTierAdAdapter : ZJCoreAdAdapter<ZJTierAdapterProtocol>

@end

NS_ASSUME_NONNULL_END
