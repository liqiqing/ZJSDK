//
//  ZJWebViewController.h
//  ZJSDK
//
//  Created by Robin on 2020/8/21.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "ZJUser.h"
#import "ZJH5PageDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZJWebViewController : UIViewController<WKNavigationDelegate,WKUIDelegate>

@property(nonatomic,copy) NSString *urlStr;
@property(nonatomic,strong) ZJUser *user;
@property(nonatomic,weak) id<ZJH5PageDelegate> delegate;

@property(nonatomic,strong,readonly) WKWebView *webView;



@end

NS_ASSUME_NONNULL_END
