//
//  ZJWKWebViewBridge.h
//  ZJSDK
//
//  Created by Robin on 2020/12/25.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "ZJH5PageDelegate.h"
#import "ZJUser.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJWKWebViewBridge : NSObject

//ZJWKWebViewBridge 2.0方法使用
@property (nonatomic, strong) ZJUser *user;

//ZJWKWebViewBridge 2.0方法使用
- (void)initWithRootViewController:(UIViewController *)viewController delegate:(id<ZJH5PageDelegate>)delegate;

//ZJWKWebViewBridge 2.0方法使用 构建webView前，请先初始化和传入对应的参数
- (void)buildWKWebView:(WKWebView *)wkWebView;


- (void)releaseWKWebView:(WKWebView *)wkWebView;


- (BOOL)runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(nullable NSString *)defaultText initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(NSString * _Nullable result))completionHandler;


- (void)initHostWKWebView:(WKWebView *)wkWebView rootViewController:(UIViewController*)viewController delegate:(id <ZJH5PageDelegate> )delegate DEPRECATED_MSG_ATTRIBUTE("use initWithRootViewController:delegate: instead.");

@end

NS_ASSUME_NONNULL_END
