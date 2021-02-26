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
NS_ASSUME_NONNULL_BEGIN

@interface ZJWKWebViewBridge : NSObject


-(void) initHostWKWebView:( WKWebView*) wkWebView rootViewController:(UIViewController*) viewController delegate:(id<ZJH5PageDelegate>)delegate;
-(void) releaseWKWebView:( WKWebView*) wkWebView;
-(BOOL) runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(nullable NSString *)defaultText initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(NSString * _Nullable result))completionHandler;
@end

NS_ASSUME_NONNULL_END
