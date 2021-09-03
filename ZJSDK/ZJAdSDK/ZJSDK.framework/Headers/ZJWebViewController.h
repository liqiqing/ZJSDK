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

@property (nonatomic, strong, readonly) WKWebView *webView;

@property (nonatomic, copy) NSString *urlStr;

@property (nonatomic, strong) ZJUser *user;

@property (nonatomic, weak) id <ZJH5PageDelegate> delegate;



/**导航栏返回按钮*/
@property (nonatomic, strong) UIImage *backImage;
@property (nonatomic, copy) NSAttributedString *backText;

/**导航栏关闭按钮*/
@property (nonatomic, strong) UIImage *closeImage;
@property (nonatomic, copy) NSAttributedString *closeText;

/**隐藏导航栏的关闭按钮*/
@property (nonatomic, assign)BOOL hiddenCloseButton;

/**导航栏标题， 设置后不会读取网页的标题*/
@property (nonatomic, copy) NSString *navigationbarTitle;

@end

NS_ASSUME_NONNULL_END
