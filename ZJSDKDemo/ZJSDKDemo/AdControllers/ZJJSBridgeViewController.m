//
//  ZJJSBridgeViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/12/25.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJJSBridgeViewController.h"
#import <WebKit/WebKit.h>
#import <ZJSDK/ZJWKWebViewBridge.h>
@interface ZJJSBridgeViewController ()<WKNavigationDelegate,WKUIDelegate,ZJH5PageDelegate>
{
    WKWebView *_webView;
    bool _hasLoad;
}

@property(nonatomic,strong,readonly) WKWebView *webView;
@property (nonatomic, strong) ZJWKWebViewBridge *zjWKWebViewBridge;
@end

@implementation ZJJSBridgeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.automaticallyAdjustsScrollViewInsets = NO;
    // Do any additional setup after loading the view.
    [self.view addSubview:self.webView];
    self.zjWKWebViewBridge = [ZJWKWebViewBridge new];
    ZJUser *user = [[ZJUser alloc]init];
    user.userID = @"123456";
    user.userName = @"xxxzz";
    [self.zjWKWebViewBridge initWithRootViewController:self delegate:self];
    self.zjWKWebViewBridge.user = user;
    [self.zjWKWebViewBridge buildWKWebView:self.webView];
    
    
//    [self.zjWKWebViewBridge initHostWKWebView:self.webView rootViewController:self delegate:self];
    
    
    //self.zjWKWebViewBridge.delegate = self;//可选
    

    NSString *htmlFile = [[NSBundle mainBundle]pathForResource:@"JSSdkTest" ofType:@"html"];
    NSURL *baseUrl = [NSURL fileURLWithPath:htmlFile isDirectory: YES];
    NSString *indexContent = [NSString stringWithContentsOfFile:htmlFile encoding: NSUTF8StringEncoding error:nil];
    [self.webView loadHTMLString:indexContent baseURL:baseUrl];
    
//    NSURL *url = [NSURL URLWithString:@"http://192.168.0.128:8080/#/"];
//    NSMutableURLRequest *req = [[NSMutableURLRequest alloc]initWithURL:url];
//    [req setValue:url.absoluteString forHTTPHeaderField:@"Referer"];
//    [self.webView loadRequest:req];
    
//    NSURL *url = [NSURL URLWithString:@"http://static.jrongjie.com/zjprodect-demo/news/index.html"];
//    NSURLRequest *req = [[NSURLRequest alloc]initWithURL:url];
//    [self.webView loadRequest:req];
}

#pragma mark - WKUIDelegate

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler{
    NSURL *url = navigationAction.request.URL;
    NSString *urlStr = (url) ?url.absoluteString:@"";
    if([urlStr containsString:@"//itunes.apple.com/"]||[urlStr containsString:@"//apps.apple.com/"]){
        [[UIApplication sharedApplication] openURL:url];
        decisionHandler(WKNavigationActionPolicyAllow);
        return;
    }else if (url.scheme&&([url.scheme hasPrefix:@"alipays"]||[url.scheme hasPrefix:@"alipay"])){
        // NOTE: 跳转支付宝App
        BOOL bSucc = [[UIApplication sharedApplication] canOpenURL:url];
        if(bSucc){
            [[UIApplication sharedApplication]openURL:url];
        }else{
            UIAlertController *alertViewController = [UIAlertController alertControllerWithTitle:@"提示" message:@"未检测到支付宝客户端，请安装后重试。" preferredStyle:UIAlertControllerStyleAlert];
            [alertViewController addAction:[UIAlertAction actionWithTitle:@"立即安装" style:UIAlertActionStyleDefault handler:nil]];
            [self presentViewController:alertViewController animated:YES completion:nil];
        }
        decisionHandler(WKNavigationActionPolicyAllow);
        return;
    }else if (url.scheme&&([url.scheme hasPrefix:@"tbopen"]||[url.scheme hasPrefix:@"tbopens"])){
        // NOTE: 跳转支付宝App
        BOOL bSucc = [[UIApplication sharedApplication] canOpenURL:url];
        if(bSucc){
            [[UIApplication sharedApplication]openURL:url];
        }else{
            UIAlertController *alertViewController = [UIAlertController alertControllerWithTitle:@"提示" message:@"未检测到淘宝客户端，请安装后重试。" preferredStyle:UIAlertControllerStyleAlert];
            [alertViewController addAction:[UIAlertAction actionWithTitle:@"立即安装" style:UIAlertActionStyleDefault handler:nil]];
            [self presentViewController:alertViewController animated:YES completion:nil];
        }
        decisionHandler(WKNavigationActionPolicyAllow);
        return;
    }else if(url.scheme&&![url.scheme hasPrefix:@"http"]){
        [[UIApplication sharedApplication]openURL:url];
        decisionHandler(WKNavigationActionPolicyAllow);
        return;
    }
    

    if (navigationAction.navigationType==WKNavigationTypeLinkActivated) {//二级
        //self.closeButton.hidden = NO;
    }else if (navigationAction.navigationType==WKNavigationTypeBackForward) {//判断是返回类型
        
    }
    //这句是必须加上的，不然会异常
    decisionHandler(WKNavigationActionPolicyAllow);
}





// 输入框
- (void)webView:(WKWebView *)webView runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(nullable NSString *)defaultText initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(NSString * _Nullable result))completionHandler{
    //必须调用
    if(![self.zjWKWebViewBridge runJavaScriptTextInputPanelWithPrompt:prompt defaultText:defaultText initiatedByFrame:frame completionHandler:completionHandler]){
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:prompt message:@"" preferredStyle:UIAlertControllerStyleAlert];
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.text = defaultText;
        }];
        [alertController addAction:([UIAlertAction actionWithTitle:@"完成" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            completionHandler(alertController.textFields[0].text?:@"");
        }])];
        [self presentViewController:alertController animated:YES completion:nil];
    }
    
}

#pragma mark - WKNavigationDelegate

// 页面开始加载时调用
- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(WKNavigation *)navigation{

}
// 当内容开始返回时调用
- (void)webView:(WKWebView *)webView didCommitNavigation:(WKNavigation *)navigation{

}
// 页面加载完成之后调用
- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation{
    self.title = webView.title;
}
// 页面加载失败时调用
- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation{

}
//这个代理是服务器redirect时调用 接收到服务器跳转请求之后调用
- (void)webView:(WKWebView *)webView didReceiveServerRedirectForProvisionalNavigation:(WKNavigation *)navigation{

}



//根据webView、navigationAction相关信息决定这次跳转是否可以继续进行,这些信息包含HTTP发送请求，如头部包含User-Agent,Accept,refer
// 在发送请求之前，决定是否跳转的代理
//- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler{
//
//    if (navigationAction.navigationType==WKNavigationTypeLinkActivated) {//二级
//        //self.closeButton.hidden = NO;
//    }else if (navigationAction.navigationType==WKNavigationTypeBackForward) {//判断是返回类型
//
//    }
//    decisionHandler(WKNavigationActionPolicyAllow);
//}

//这个代理方法表示当客户端收到服务器的响应头，根据response相关信息，可以决定这次跳转是否可以继续进行。
// 在收到响应后，决定是否跳转
- (void)webView:(WKWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler{

    NSLog(@"%@",navigationResponse.response.URL.absoluteString);
    //允许跳转
    decisionHandler(WKNavigationResponsePolicyAllow);
    //不允许跳转
    //decisionHandler(WKNavigationResponsePolicyCancel);
}

/**
 *  准备加载页面。等同于UIWebViewDelegate: - webView:shouldStartLoadWithRequest:navigationType
 *
 *  @param webView
 *  @param navigation
 */
//- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation{
//}



-(WKWebView *)webView{
    if(!_webView){
        WKUserContentController *wkUController = [[WKUserContentController alloc] init];
        //[wkUController addUserScript:wkUScript];
        WKWebViewConfiguration *wkWebConfig = [[WKWebViewConfiguration alloc] init];
        wkWebConfig.preferences=[[WKPreferences alloc] init];
        wkWebConfig.preferences.minimumFontSize=10;
        wkWebConfig.preferences.javaScriptEnabled=YES;
        wkWebConfig.websiteDataStore = [WKWebsiteDataStore defaultDataStore];
        
        [wkWebConfig.preferences setValue:@YES forKey:@"allowFileAccessFromFileURLs"];
        if (@available(iOS 10.0, *)) {
             [wkWebConfig setValue:@YES forKey:@"allowUniversalAccessFromFileURLs"];
        }
        //wkWebConfig.preferences.javaScriptCanOpenWindowsAutomatically=NO;
        wkWebConfig.userContentController = wkUController;
        _webView = [[WKWebView alloc] initWithFrame:self.view.bounds configuration:wkWebConfig];;
        _webView.scrollView.showsVerticalScrollIndicator = NO;
        _webView.autoresizingMask = UIViewAutoresizingFlexibleHeight;
        _webView.navigationDelegate = self;
        _webView.UIDelegate = self;
        
        [_webView sizeToFit];
        [_webView setAutoresizesSubviews:YES];
        [_webView setAllowsBackForwardNavigationGestures:true];
    }
    return _webView;
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
