//
//  TXAdTableScreenSlotModel.h
//  TanxSDK
//
//  Created by tongyuecheng on 2023/3/30.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import "TXAdSlotModel.h"


@interface TXAdTableScreenSlotModel : TXAdSlotModel

/**
 *  媒体自定义loadAd超时时间，默认没有超时时间，单位秒
 */
@property (nonatomic, assign) NSTimeInterval loadAdTimeoutInterval;

/**
 *  点击广告 & 关闭关闭广告view，默认：NO
 */
@property (nonatomic, assign) BOOL needAutoCloseAD;

@end
