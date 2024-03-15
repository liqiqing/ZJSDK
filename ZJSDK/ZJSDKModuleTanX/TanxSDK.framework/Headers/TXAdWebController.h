//
//  TXAdWebController.h
//  TanxSDK
//
//  Created by 凡 on 2023/2/22.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 点击返回按钮通知
extern NSString *const kTXAdWebControllerNavBackBtnClicked;

@interface TXAdWebController : UIViewController

/// 设置webview url
@property (nonatomic, copy) NSString *url;

/// 返回按钮
@property (nonatomic, strong, readonly) UIButton *navBackBtn;

@end

NS_ASSUME_NONNULL_END
