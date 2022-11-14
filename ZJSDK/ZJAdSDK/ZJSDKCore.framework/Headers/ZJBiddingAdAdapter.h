//
//  ZJBiddingAdAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/11/11.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJBiddingAdapterProtocol <NSObject>
-(void)loadAd;

@end
@interface ZJBiddingAdAdapter : ZJCoreAdAdapter<ZJBiddingAdapterProtocol>

@end

NS_ASSUME_NONNULL_END
