//
//  ZJWXMiniParamAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2022/9/20.
//  Copyright © 2022 zj. All rights reserved.
//

#import "ZJAd.h"
#import <ZJSDKCore/ZJMiniParamAdProtocol.h>
NS_ASSUME_NONNULL_BEGIN

@class ZJWXMiniParamAd;
@protocol ZJWXMiniParamAdDelegate <NSObject>
@optional
/**
 *  小程序唤起成功
 */
- (void)zj_miniParamAdDidAwake:(ZJWXMiniParamAd *)miniParamAd;


/**
 *  小程序唤起失败
 */
- (void)zj_miniParamAdAwakeFail:(ZJWXMiniParamAd *)miniParamAd error:(NSError *)error;

- (void)zj_miniParamAd:(ZJWXMiniParamAd *)miniParamAd onResp:(id)resp;
@end


@interface ZJWXMiniParamAd : ZJAd <ZJMiniParamAdProtocol>

@property (nonatomic, weak) id <ZJWXMiniParamAdDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
