//
//  ZJBaseContentAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/4.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJBaseContentAdapter : ZJCoreAdAdapter

@property (nonatomic, strong) UIViewController *viewController;
-(void)reportWithEvent:(ZJEventString)event supplementMsg:(nullable NSString *)supplementMsg;

- (void)loadContentPageWithDeeplink:(NSString *)deepLink;

-(void)loadAd NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
