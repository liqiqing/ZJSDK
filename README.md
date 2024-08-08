---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: true

print_background: true
---

# ZJSDK_iOS使用文档 {ignore=true}
## <span id="jump1">版本更新日志</span>
| 最新版本更新日志 | 修订日期  | 修订说明       |
| ---------------- | --------- | -------------- |
|v2.5.8.10|2024-08-08|已知问题修复|
<!-- #### <span id="jump1.2.4">1.2.4、scheme列表添加以下内容</span> -->

历史版本信息见 [历史版本更新日志](#历史版本更新日志)
## <span id="jump1">一、iOS SDK接入说明</span>

### <span id="jump1.1">1.1、工程设置导入framework</span>

#### <span id="jump1.1.1">1.1.1、申请应用的AppID</span>

```
请找运营人员获取应用ID和广告位ID。
```

#### <span id="jump1.1.2">1.1.2、引入framework</span>

**1. CocoaPods接入方式**
***1.1 一般引入方式***
```
#引入常用广告模块  
pod 'ZJSDK'
```
***1.2 拆分模块引入方式***
```
#常用广告模块（如需模块拆分引入，请引入ZJSDKModuleDSP）
pod 'ZJSDK/ZJSDKModuleDSP'#依赖库，引入任何模块都需要依赖此模块，默认引入
pod 'ZJSDK/ZJSDKModuleGDT'#优量汇广告
pod 'ZJSDK/ZJSDKModuleCSJ'#穿山甲广告
pod 'ZJSDK/ZJSDKModuleKS'#快手广告
pod 'ZJSDK/ZJSDKModuleSIG'#Sigmob广告
pod 'ZJSDK/ZJSDKModuleBD'#百度广告
pod 'ZJSDK/ZJSDKModuleBeiZi'#倍孜广告
pod 'ZJSDK/ZJSDKModuleTanX'#TanX广告
```
```
#海外模块(默认不引入)
pod 'ZJSDK/ZJSDKModuleGoogle'#Google广告 
pod 'ZJSDK/ZJSDKModulePangle'#穿山甲海外 
pod 'ZJSDK/ZJSDKModuleMTG'#MTG广告

#聚合广告模块（默认不引入）
#注意：引入多个聚合广告可能会引起一些联盟重复初始化的问题。
pod 'ZJSDK/ZJSDKModuleWM'     #Sigmob to-bid广告
```
***1.3 本地视频内容（类似dy，ks短视频）引入方式***
接入视频内容注意事项，请转到 [2.9.1、ZJContentPage接入注意事项](#-291-font-colorredzjcontentpage接入注意事项font)
```
在以上引入的基础上，将快手库指定为本地内容包
pod 'KSAdSDK',:path => '../ZJSDK/ZJSDKModuleKS'#指定快手库为本地内容库
```



**2.手动方式**

1.获取 framework 文件后直接将 {ZJSDK}文件拖入工程即可。

2.前往项目的Build Setting中的Enable Bitcode设置为NO

3.Build Settings中Other Linker Flags 增加参数-ObjC和-l 'ObjC'，字母o和c大写

4.升级SDK的同学必须同时更新framework和bundle文件，否则可能出现部分页面无法展示的问题，老版本升级的同学需要重新引入ZJSDK.framework，拖入完请确保Copy Bundle Resources中有BUAdSDK.bundle，DSPBundle.bundle等否则可能出现icon图片加载不出来的情况。

**添加依赖库**

工程需要在TARGETS -> Build Phases中找到Link Binary With Libraries，点击“+”，依次添加下列依赖库

- libsqlite3.0.tbd

- JavaScriptCore.framework

- AudioToolbox.framework

- QuickLook.framework

- MessageUI.framework

- AVKit.framework

- DeviceCheck.framework

- CFNetwork.framework

- CoreGraphics.framework

- SafariServices.framework

- StoreKit.framework

- MobileCoreServices.framework

- WebKit.framework

- MediaPlayer.framework

- CoreMedia.framework

- CoreLocation.framework

- AVFoundation.framework

- CoreTelephony.framework

- SystemConfiguration.framework

- AdSupport.framework

- CoreMotion.framework

- Accelerate.framework

- libresolv.9.tbd

- libc++.tbd

- libz.tbd

- libsqlite3.tbd

- libbz2.tbd

- libxml2.tbd

- QuartzCore.framework

- Security.framework

- libc++abi.tbd

  如果以上依赖库增加完仍旧报错，请添加ImageIO.framework。

  SystemConfiguration.framework、CoreTelephony.framework、Security.framework是为了统计app信息使用

**<font color=#FF0000>3.注意事项：</font>**

* 快手广告：
  * 手动导入快手广告需.前往项目的：
     Targets-当前项目-General-Frameworks,Libraries,and Embedded Content。
     <font color=#FF0000>将KSAdSDK.xcframework - Do Not Embed 更改为 Embed & Sign
    否则导入后启动将会闪退</font>
* Google广告：

  * 需要在info.plist 添加GADApplicationIdentifier字段，value为AppId ,如果使用了Google广告sdk且未在info.plist中配置，会导致运行时错误，参考：https://developers.google.com/admob/ios/quick-start#cocoapods

    ```
    <key>GADApplicationIdentifier</key>
    <string>申请的Google广告的appid</string>
    ```
  * Google启用测试广告，参考：https://developers.google.com/admob/ios/test-ads#enable_test_devices
* MTG 广告
  * 手动添加SDK依赖配置
  从Mintegral iOS SDK v7.5.4版本开始，内部用到了Swift语言。如果您在项目中没有使用Swift，您需要确保添加以下依赖项：
  * 选择 Project > BuildSettings > Defines Module: 设置为 Yes
  * 选择 Project > BuildSettings > Search path > Library Search Paths, 并添加如下代码:
    ```
    $(TOOLCHAIN_DIR)/usr/lib/swift/$(PLATFORM_NAME)
    $(TOOLCHAIN_DIR)/usr/lib/swift-5.0/$(PLATFORM_NAME)
    ```
    之后在 Project > BuildSettings > Linking > Runpath search path, 然后添加如下代码:
    ```
    //该路径需要配置在list的第一个
    /usr/lib/swift
    ```
    最后在 Project > BuildSettings > Build option > Always embed swift standard libraries: 设置为 Yes
### <span id="jump1.2">1.2、Xcode编译选项设置</span>

#### <span id="jump1.2.2">1.2.1、运行环境支持</span>

- 支持系统 iOS 11.X 及以上;
- 支持架构： x86-64, armv7, arm64
- SDK编译环境 Xcode 14.0 + （23年4月起，Xcode 14以下编译的包不再支持上架app store）

#### <span id="jump1.1.2.1">1.2.2、添加HTTP权限</span>

- 工程plist文件设置，点击右边的information Property List后边的 "+" 展开

添加 App Transport Security Settings，先点击左侧展开箭头，再点右侧加号，Allow Arbitrary Loads 选项自动加入，修改值为 YES。 SDK API 已经全部支持HTTPS，但是广告主素材存在非HTTPS情况。

```
<key>NSAppTransportSecurity</key>
  <dict>
     <key>NSAllowsArbitraryLoads</key>
   <true/>
</dict>
```

#### <span id="jump1.2.3">1.2.3、添加位置权限</span>

SDK 需要位置权限以更精准的匹配广告，需要在应用的 info.plist 添加相应配置信息，避免 App Store 审核被拒：

```
  Privacy - Location When In Use Usage Description
  Privacy - Location Always and When In Use Usage Description
  Privacy - Location Always Usage Description
  Privacy - Location Usage Description
```
#### <span id="jump1.2.4">1.2.4、scheme列表添加以下内容</span>
用于判断用户设备使用环境，提高安全性，增加收益。
默认状态开启检测断言，需要关闭请联系客服修改配置。
```
    <key>LSApplicationQueriesSchemes</key>
    <array>
        <string>alipayauth</string>
        <string>alipays</string>
        <string>wechat</string>
        <string>weixin</string>
        <string>taobao</string>
        <string>tbopen</string>
        <string>openapp.jdmobile</string>
        <string>pinduoduo</string>
        <string>meituanwaimai</string>
        <string>imeituan</string>
        <string>snssdk1128</string>
        <string>kwai</string>
        <string>cydia</string>
    </array>
```
#### <span id="jump1.2.5">1.2.5、Swift接入准备</span>

1: 新建桥接头文件（bridge.h，推荐放在工程目录下）。这里我们命名为：ZJAdSDKDemoSwift-Bridging-Header.h。在这个文件中import我们需要的所有头文件，代码如下：

```
#import <ZJSDK/ZJSDK.h>
```

2: 左侧目录中选中工程名，在 TARGETS->Build Settings-> Swift Compiler - Code Generation -> Objective-C Bridging Header 中输入桥接文件的路径

### 1.3、iOS14注意事项
#### 1.3.1、iOS 14.5及以上版本ATT权限申请
App Tracking Transparency(ATT) 框架向用户提出应用程序跟踪授权请求，并提供跟踪授权状态。自iOS14.5 开始，在应用程序调用 ATT 向用户提跟踪授权请求之前，IDFA 将不可用。如果应用未提出此请求，应用获取到的 IDFA 将为0，建议您在应用启动时调用，以便我们能够提供更精准的进行广告投放和收入优化。
* 要获取 ATT 权限，请更新您的 Info.plist，添加 NSUserTrackingUsageDescription 字段和自定义文案描述。代码示例：
```
<key>NSUserTrackingUsageDescription</key>
<string>该标识符将用于向您投放个性化广告</string>
```
* 向用户申请权限时，请调用 requestTrackingAuthorizationWithCompletionHandler:方法。我们建议您申请权限后再请求广告，以便广告能准确的获得用户授权状态。
```objc
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
- (void)requestIDFA {
  [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
    // [self loadAd];
  }];
}
```
#### 1.3.2、SKAdNetwork 接入
使用Apple的转化跟踪SKAdNetwork，这意味着即使IDFA不可用，也可以将应用安装归因。
1.在Xcode项目导航器中，选择Info.plist。
2.单击属性列表编辑器中任何键旁边的添加按钮（**+**），以创建一个新的属性键。
3.输入密钥名称SKAdNetworkItems。选择Array。
4.将SKAdNetworkId以字典的形式添加到数组中。
```
//将SKAdNetwork ID 添加到 info.plist 中，以保证 SKAdNetwork 的正确运行
//广点通
SKAdNetworkIdentifier : f7s53z58qe.skadnetwork
//快手
SKAdNetworkIdentifier : r3y5dwb26t.skadnetwork
//sigmob
SKAdNetworkIdentifier : 58922NB4GD.skadnetwork
//MTG
SKAdNetworkIdentifier : kbd757ywx3.skadnetwork
//穿山甲
SKAdNetworkIdentifier : 238da6jt44.skadnetwork
SKAdNetworkIdentifier : x2jnk7ly8j.skadnetwork
SKAdNetworkIdentifier : 22mmun2rn5.skadnetwork
//Google
SKAdNetworkIdentifier : cstr6suwn9.skadnetwork
```
**info.plist代码示例**
```
<key>SKAdNetworkItems</key>
<array>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>238da6jt44.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>x2jnk7ly8j.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>f7s53z58qe.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>58922NB4GD.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>kbd757ywx3.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>22mmun2rn5.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>r3y5dwb26t.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>cstr6suwn9.skadnetwork</string>
    </dict>
</array>
```

### <span id="jump1.4">1.4、初始化SDK</span>

**Objective-C**

开发者需要在AppDelegate#application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions方法中调用以下代码来初始化sdk。

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Override point for customization after application launch.
  [ZJAdSDK registerAppId:@"zj_20201014iOSDEMO"];
  return YES;
}
```

**Swift**

开发者需要在AppDelegate

func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool
//方法中调用以下代码来初始化sdk。

```
ZJAdSDK.registerAppId("zj_20201014iOSDEMO");
```

### <span id="jump1.5">1.5、打包回测</span>
企业账号可直接打包。
公司账号和个人账号打包回测请添加下面两个udid：
```
e36a75f610d3ea9e905c2cdff9720635b37f8c13
```
```
00008101-001150922EF8001E
```
## <span id="jump2">二、加载广告</span>

### <span id="jump2.1">2.1、接入开屏广告(ZJSplashAd)</span>

- 类型说明： 开屏广告主要是 APP 启动时展示的全屏广告视图，开发只要按照接入标准就能够展示设计好的视图。

#### <span id="jump2.1.1">2.1.1、ZJSplashAd广告说明</span>

```
@interface ZJSplashAd : ZJAd

@property(nonatomic,weak) id<ZJSplashAdDelegate> delegate;
/**
* 拉取广告超时时间，默认为3秒
* 详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
*/
@property (nonatomic, assign) CGFloat fetchDelay;

/**
* 发起拉取广告请求，只拉取不展示
* 详解：广告素材及广告图片拉取成功后会回调splashAdDidLoad方法，当拉取失败时会回调zj_splashAdError:方法
*/
- (void) loadAd;

/**
 *  展示广告，
  详解：广告展示成功时会回调zj_splashAdSuccessPresentScreen方法
 */
- (void)showAdInWindow:(UIWindow *)window;

/**
* 展示广告，调用此方法前需调用isAdValid方法判断广告素材是否有效
* 详解：广告展示成功时会回调splashAdSuccessPresentScreen方法，展示失败时会回调zj_splashAdDisplayError:方法
*/
- (void)showAdInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

@end
```

#### <span id="jump2.1.2">2.1.2、ZJSplashAdDelegate</span>

```
@protocol ZJSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
-(void)zj_splashAdDidLoad:(ZJSplashAd *)splashAd;

/**
 *  开屏广告成功展示
 */
-(void)zj_splashAdSuccessPresentScreen:(ZJSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)zj_splashAdClicked:(ZJSplashAd *)splashAd;

/**
*  开屏广告即将关闭回调
*/
- (void)zj_splashAdWillClose:(ZJSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)zj_splashAdClosed:(ZJSplashAd *)splashAd;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)zj_splashAdApplicationWillEnterBackground:(ZJSplashAd *)splashAd;

/**
 * 开屏广告倒记时结束
 */
- (void)zj_splashAdCountdownEnd:(ZJSplashAd*)splashAd;

/**
 *  开屏广告错误
 */
- (void)zj_splashAdError:(ZJSplashAd *)splashAd withError:(NSError *)error;

@end

```

#### <span id="jump2.1.3">2.1.3、加载开屏广告</span>

**Objective-C**

```
self.splashAd = [[ZJSplashAd alloc] initWithPlacementId:@"c887417368"];
self.splashAd.delegate = self;
self.splashAd.fetchDelay = 5.0;
[self.splashAd loadAd];
```

**Swift**

```
splashAd = ZJSplashAd.init(placementId: "zjad_G9040714184494018");
splashAd.delegate = self;
splashAd.fetchDelay = 5.0;
splashAd.load(); 
```

  加载开屏广告具体示例详见Demo中的AppDelegate/ZjSplashViewController

### <span id="jump2.2">2.2、接入激励视频(ZJRewardVideoAd)</span>

- 类型说明： 激励视频广告是一种全新的广告形式，用户可选择观看视频广告以换取有价物，例如虚拟货币、应用内物品和独家内容等等；这类广告的长度为 15-30 秒，不可跳过，且广告的结束画面会显示结束页面，引导用户进行后续动作。userId尽量传真实的userId。

#### <span id="jump2.2.1">2.2.1、ZJRewardVideoAd广告说明</span>

```
@interface ZJRewardVideoAd : ZJAd

@property(nonatomic,copy) NSString *userId; //userId尽量传真实的userId

@property(nonatomic,weak) id<ZJRewardVideoAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId userId:(NSString *)userId;

/**
*  发起拉取广告请求，只拉取不展示
*  详解：广告素材及广告图片拉取成功后会回调splashAdDidLoad方法，当拉取失败时会回调splashAdFailToPresent方法
*/
- (void) loadAd;

- (void) showAdInViewController:(UIViewController*)viewController;
@end
```

#### <span id="jump2.2.2">2.2.2、ZJRewardVideoAdDelegate广告说明</span>

```
@protocol ZJRewardVideoAdDelegate <NSObject>

@optional
/**
广告数据加载成功回调
 ⚠️请勿在该回调内调用 showAdInViewController:方法（需视频下载完成）
@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdDidLoad:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频数据下载成功回调，已经下载过的视频会直接回调，在这里调用展示广告的方法。
 ✅ showAdInViewController: 方法请在该回调中执行 ， 广告展示需要在视频下载完成后才能展示，
@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdVideoDidLoad:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频广告展示
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidShow:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClose:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidClicked:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 奖励触发
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidRewardEffective:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频广告视频播放完成
 @param rewardedVideoAd ZJRewardVideoAd 实例
 */
- (void)zj_rewardVideoAdDidPlayFinish:(ZJRewardVideoAd *)rewardedVideoAd;

/**
 视频广告各种错误信息回调
 @param rewardedVideoAd ZJRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)zj_rewardVideoAd:(ZJRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;
@end
```

#### <span id="jump2.2.3">2.2.3、加载激励视频</span>

**Objective-C**

```
self.rewardVideoAd = [[ZJRewardVideoAd alloc] initWithPlacementId:@"KS90010001" userId:@"robin6666"];
self.rewardVideoAd.delegate = self;
[self.rewardVideoAd loadAd];
```

**Swift**

```
self.rewardVideoAd = ZJRewardVideoAd.init(placementId: adId as String, userId: "robin6666")
self.rewardVideoAd.delegate = self;
self.rewardVideoAd.load()
```

加载广告具体示例详见Demo中的ZjRewardViewController。

### <span id="jump2.3">2.3、接入插屏广告(ZJInterstitialAd)</span>

- 类型说明： 插屏广告是移动广告的一种常见形式，在应用开流程中弹出，当应用展示插页式广告时，用户可以选择点按广告，访问其目标网址，也可以将其关闭，返回应用。

#### <span id="jump2.3.1">2.3.1、ZJInterstitialAd说明</span>

```
@interface ZJInterstitialAd : ZJAd

@property(nonatomic,weak) id<ZJInterstitialAdDelegate> delegate;

-(void) loadAd;

-(void)presentAdFromRootViewController:(UIViewController*)  viewController;

@end
```

#### <span id="jump2.3.2">2.3.2、ZJInterstitialAdDelegate广告说明</span>

```
@protocol ZJInterstitialAdDelegate <NSObject>
//广告数据加载成功回调
- (void) zj_interstitialAdDidLoad:(ZJInterstitialAd*) ad;
//广告数据加载失败回调
- (void) zj_interstitialAdDidLoadFail:(ZJInterstitialAd*) ad error:(NSError * __nullable)error;
//广告展示
- (void) zj_interstitialAdDidPresentScreen:(ZJInterstitialAd*) ad;
//广告点击
- (void) zj_interstitialAdDidClick:(ZJInterstitialAd*) ad;
//广告关闭
- (void) zj_interstitialAdDidClose:(ZJInterstitialAd*) ad;
//详情页关闭
- (void) zj_interstitialAdDetailDidClose:(ZJInterstitialAd*) ad;
//其他错误
- (void) zj_interstitialAdDidFail:(ZJInterstitialAd*) ad error:(NSError * __nullable)error;

@end
```

#### <span id="jump2.3.3">2.3.3、加载插屏广告</span>

**Objective-C**

```
self.interstitialAd = [[ZJInterstitialAd alloc] initWithPlacementId:@"zjad_G10506"];
self.interstitialAd.delegate = self;
[self.interstitialAd loadAd];
```

**Swift**

```
interstitialAd = ZJInterstitialAd.init(placementId: adId as String);
interstitialAd.delegate = self;
interstitialAd.load();
```

加载广告具体示例详见Demo中的ZJInterstitialAdViewController。

### <span id="jump2.4">2.4、接入全屏视频信息流(ZJFeedFullVideoView)</span>

- 类型说明：本SDK为接入方提供竖版视频信息流广告，该广告适合在竖版全屏视频流中使用，接入方可以控制视频暂停或继续播放，默认视频播放不可干预，视频广告相关配置可以在平台设置。 支持的广告尺寸： 全屏竖版。

#### <span id="jump2.4.1">2.4.1、ZJFeedFullVideoProvider，ZJFeedFullVideoView说明</span>

```
@interface ZJFeedFullVideoProvider : ZJAd
//请求广告尺寸
@property(nonatomic,assign) CGSize adSize;

@property(nonatomic,weak) id<ZJFeedFullVideoProviderDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId;

//count 返回广告最大数量
-(void) loadAd:(NSInteger) count;

@end
```

#### <span id="jump2.4.2">2.4.2、ZJFeedFullVideoProviderDelegate广告说明</span>

```
@protocol ZJFeedFullVideoProviderDelegate <NSObject>

/**
 * 广告加载成功
 */
- (void)zj_feedFullVideoProviderLoadSuccess:(ZJFeedFullVideoProvider *)provider views:(NSArray<__kindof ZJFeedFullVideoView *> *)views;

/**
* 广告加载失败
*/
- (void)zj_feedFullVideoProviderLoadFail:(ZJFeedFullVideoProvider *)provider error:(NSError *_Nullable)error;

/**
 * 广告渲染成功, ZJFeedFullVideoView.size.height has been updated
 */
- (void)zj_feedFullVideoAdViewRenderSuccess:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView;

/**
 * 广告渲染失败
 */
- (void)zj_feedFullVideoAdViewRenderFail:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView error:(NSError *_Nullable)error;

/**
 * 广告曝光回调
 */
- (void)zj_feedFullVideoAdViewWillShow:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView;

/**
视频广告播放状态更改回调
*/
- (void)zj_feedFullVideoAdViewStateDidChanged:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView state:(ZJMediaPlayerStatus)playerState;
/**
视频广告播放完毕
*/
- (void)zj_feedFullVideoAdViewPlayerDidPlayFinish:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView;

/**
 * 广告点击回调
 */
- (void)zj_feedFullVideoAdViewDidClick:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView;

/**
* 广告详情页面即将展示回调
*/
- (void)zj_feedFullVideoAdViewDetailViewWillPresentScreen:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView;

/**
 *广告详情页关闭回调
 */
- (void)zj_feedFullVideoAdViewDetailViewClosed:(ZJFeedFullVideoProvider *)provider view:(ZJFeedFullVideoView*) adView;

@end
```

#### <span id="jump2.4.3">2.4.3、加载全屏视频信息流</span>

**Objective-C**

```
- (void)loadData {
  if(!self.adProvider){
    self.adProvider = [[ZJFeedFullVideoProvider alloc] initWithPlacementId:@"KS90010003"];
    self.adProvider.delegate = self;
    self.adProvider.adSize = self.view.bounds.size;
  }
  [self.adProvider loadAd:5];
}

/** 
* 广告加载成功
*/
- (void)zj_feedFullVideoProviderLoadSuccess:(ZJFeedFullVideoProvider *)provider views:(NSArray<__kindof ZJFeedFullVideoView *> *)views{

  if (views.count) {
    NSMutableArray *dataSources = [NSMutableArray arrayWithCapacity:0];
    [views enumerateObjectsUsingBlock:^(id _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
      ZJFeedFullVideoView *videoView = (ZJFeedFullVideoView *)obj;
      videoView.rootViewController = self;
      // important: 此处会进行WKWebview的渲染，建议一次最多预加载三个广告，如果超过3个会很大概率导致WKWebview渲染失败。
      [videoView render];
      [dataSources addObject:videoView];
    }];
    self.dataSource = [dataSources copy];
  }
  [self.tableView reloadData];
}
```

**Swift**

```
self.adProvider = ZJFeedFullVideoProvider.init(placementId: self.placementId! as String, delegate: self);
self.adProvider.adSize = self.view.bounds.size;
self.adProvider.loadAd(8);

/** 
* 广告加载成功
*/
func zj_feedFullVideoProviderLoadSuccess(_ provider: ZJFeedFullVideoProvider, views: [ZJFeedFullVideoView]) {
    var dataArray:Array<Any> = []
    for dataObject in views {
      dataArray.append(dataObject)
      dataArray.append("demo")
    }
    self.dataSource = dataArray
    self.tableView!.reloadData()
  }
```

加载广告具体示例详见Demo中的ZJFeedFullVideoShowViewController。

### <span id="jump2.5">2.5、接入模板信息流(ZJNativeExpressFeedAdManager)</span>

#### <span id="jump2.5.1">2.5.1、ZJNativeExpressFeedAdManager，ZJNativeExpressFeedAd说明</span>

```
@interface ZJNativeExpressFeedAdManager : ZJAd

@property(nonatomic,weak) id<ZJNativeExpressFeedAdManagerDelegate> delegate;

@property (nonatomic)CGSize adSize;

@property (nonatomic, strong) NSArray<ZJNativeExpressFeedAd *> *data;

-(instancetype)initWithPlacementId:(NSString *)placementId size:(CGSize)size;

/**
 * 加载广告，建议最大个数不超过5个
 */
-(void)loadAdDataWithCount:(NSInteger)count;

@end



//ZJNativeExpressFeedAd
@interface ZJNativeExpressFeedAd : NSObject

@property (nonatomic,strong,readonly) UIView *feedView;

/**
 * Whether render is ready
 */
@property (nonatomic, assign,readonly) BOOL isReady;

@property(nonatomic,weak) id<ZJNativeExpressFeedAdDelegate> delegate;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/*
 *required [必选]
 *原生模板广告渲染
 */
- (void)render;

@end

```

#### <span id="jump2.5.2">2.5.2、ZJNativeExpressFeedAdManagerDelegate ZJNativeExpressFeedAdDelegate说明</span>

```
@protocol ZJNativeExpressFeedAdManagerDelegate <NSObject>
@optional
//数据加载成功
- (void)ZJ_nativeExpressFeedAdManagerSuccessToLoad:(ZJNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)feedAdDataArray;
//数据加载失败
- (void)ZJ_nativeExpressFeedAdManager:(ZJNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

@protocol ZJNativeExpressFeedAdDelegate <NSObject>
@optional
//ZJNativeExpressFeedAd
/**
 * 广告渲染成功
 */
- (void)ZJ_nativeExpressFeedAdRenderSuccess:(ZJNativeExpressFeedAd *)feedAd;
/**
 * 广告渲染失败
 */
- (void)ZJ_nativeExpressFeedAdRenderFail:(ZJNativeExpressFeedAd *)feedAd;

/**
 *广告即将展示
 */
- (void)ZJ_nativeExpressFeedAdViewWillShow:(ZJNativeExpressFeedAd *)feedAd;
/**
 *广告点击
 */
- (void)ZJ_nativeExpressFeedAdDidClick:(ZJNativeExpressFeedAd *)feedAd;
/**
 *不喜欢该广告
 */
- (void)ZJ_nativeExpressFeedAdDislike:(ZJNativeExpressFeedAd *)feedAd;
/**
 *展示落地页
 */
- (void)ZJ_nativeExpressFeedAdDidShowOtherController:(ZJNativeExpressFeedAd *)nativeAd;
/**
 *关闭落地页
 */
- (void)ZJ_nativeExpressFeedAdDidCloseOtherController:(ZJNativeExpressFeedAd *)nativeAd;
@end

```

#### <span id="jump2.5.3">2.5.3、加载模板信息流广告</span>

```
if (!_feedAd) {
    _feedAd = [[ZJNativeExpressFeedAdManager alloc] initWithPlacementId:@"K4000000007" size:CGSizeMake(self.tableView.frame.size.width, 0)];
  }
_feedAd.delegate = self;
[_feedAd loadAdDataWithCount:3];

//数据加载成功
-(void)ZJ_nativeExpressFeedAdManagerSuccessToLoad:(ZJNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *)feedAdDataArray{
  //不要保存太多广告，需要在合适的时机手动释放不用的，否则内存会过大
  if (self.adArray.count > 0) {
    for (ZJNativeExpressFeedAd *feedAd in self.adArray) {
      [self.dataArray removeObject:feedAd];
    }
  }
  for (int i = 0; i<feedAdDataArray.count; i++) {
    ZJNativeExpressFeedAd *feedAd = feedAdDataArray[i];
    feedAd.rootViewController = self;
    feedAd.delegate = self;
    [feedAd render];    
    NSInteger index = i*3;
    if (index >= self.dataArray.count) {
      [self.dataArray addObject:feedAd];
    }else{
      [self.dataArray insertObject:feedAd atIndex:index];
    }
  }
  self.adArray = feedAdDataArray;
//  [self.tableView reloadData];
}

/**
 * 广告渲染成功
 */
- (void)ZJ_nativeExpressFeedAdRenderSuccess:(ZJNativeExpressFeedAd *)feedAd{
    [self.tableView reloadData];
}
```

加载广告具体示例详见Demo中的ZJNativeExpressAdsViewController。

### 2.6、接入自渲染广告(ZJNativeAd)

#### 2.6.1、ZJNativeAd说明

自渲染广告返回数据模型（ZJNativeAdObject），通过数据模型由开发者渲染视图 ，视图渲染需要基于ZJNativeAdView上进行扩展。

```
/*
*  详解：placementId - 广告位 ID
*/
- (instancetype)initWithPlacementId:(NSString *)placementId;

//加载广告个数
-(void)loadAdWithCount:(NSInteger)adCount

/*自渲染广告加载的回调*/
- (void)zj_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error;
```

#### 2.6.2、加载ZJNativeAd广告 ####

```
//加载广告
self.nativeAd = [[ZJNativeAd alloc] initWithPlacementId:self.adId];
self.nativeAd.delegate = self;
[self.nativeAd loadAdWithCount:8];

///广告回调
- (void)zj_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)nativeAdObjects error:(NSError * _Nullable)error{
    if (!error &&nativeAdObjects.count > 0) {
        self.dataArray = nativeAdObjects.mutableCopy;
        [self.tableView reloadData];
        
    }else{
        NSLog(@"error:%@",error);
    }
}
```

通过ZJNativeAdView 注册数据，生成adView

```
self.fillView.viewController = vc;
self.fillView.delegate = delegate;
self.adView = [self.fillView registerDataObject:dataObject];
[self.contentView addSubview:self.adView];
```

加载广告示例详见demo中的 ZJNativeAdViewController。

### 2.7、接入全屏视频广告(ZJFullScreenVideoAd)</span>

#### 2.7.1、ZJFullScreenVideoAd说明

```
@interface ZJFullScreenVideoAd : ZJAd

@property(nonatomic,weak) id<ZJFullScreenVideoAdDelegate> delegate;

//加载广告
-(void) loadAd;

//展示全屏视频广告
-(void)presentFullScreenVideoAdFromRootViewController:(UIViewController*)viewController;

@end
```

#### 2.7.2、ZJFullScreenVideoAdDelegate广告说明

```
@protocol ZJFullScreenVideoAdDelegate <NSObject>
//广告加载成功
- (void) zj_fullScreenVideoAdDidLoad:(ZJFullScreenVideoAd*) ad;
//广告加载失败
- (void) zj_fullScreenVideoAdDidLoadFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error;
//广告展示
- (void) zj_fullScreenVideoAdDidShow:(ZJFullScreenVideoAd*) ad;
//广告点击
- (void) zj_fullScreenVideoAdDidClick:(ZJFullScreenVideoAd*) ad;
//广告关闭
- (void) zj_fullScreenVideoAdDidClose:(ZJFullScreenVideoAd*) ad;
//广告错误
- (void) zj_fullScreenVideoAdDidFail:(ZJFullScreenVideoAd*) ad error:(NSError * __nullable)error;

//广告播放状态回调
- (void)zj_fullScreenVideoAd:(ZJFullScreenVideoAd*)ad  playerStatusChanged:(ZJMediaPlayerStatus)playerStatus;

//广告详情页打开
- (void)zj_fullScreenVideoAdDetailDidPresent:(ZJFullScreenVideoAd*)ad;
//广告详情页关闭
- (void) zj_fullScreenVideoAdDetailDidClose:(ZJFullScreenVideoAd*) ad;

@end
```

#### 2.7.3、加载全屏视频广告

```
self.fullVideoAd = [[ZJFullScreenVideoAd alloc] initWithPlacementId:adId];
self.fullVideoAd.delegate = self;
[self.fullVideoAd loadAd];
```

加载广告具体示例详见Demo中的ZJFullScreenVideoViewController。

### 2.8、视频内容和短剧(ZJContentPage、ZJTubePage)</span>

#### 2.8.1、<font color=red>ZJContentPage、ZJTubePage接入注意事项</font>
由于内容包没有放在 CocoaPods 的公共仓库，需要⾃⾏将 podspec ⽂件放⼊⼯程⾥，然后在 Podfile ⾥指定路径，参考如下:
```
 pod 'KSAdSDK', :path => '../ZJSDK/ZJSDKModuleKS/KS' 
 ```
二：如不是通过pod导入，打包发布之前，需要去掉快手内容包的x86_64框架，具体的拆分合并命令参考以下
```
cd [KSAdSDK.framework所在的目录]
mkdir ./bak
cp -r KSAdSDK.framework ./bak
lipo KSAdSDK.framework/KSAdSDK -thin armv7 -output KSAdSDK_armv7
lipo KSAdSDK.framework/KSAdSDK -thin arm64 -output KSAdSDK_arm64
lipo -create KSAdSDK_armv7 KSAdSDK_arm64 -output KSAdSDK
mv KSAdSDK KSAdSDK.framework/
```

#### 2.8.2、ZJContentPage说明
```
@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;


///内容标识
@property (nonatomic, copy, readonly) NSString *contentInfoId;
///内容类型
@property (nonatomic, assign, readonly) ZJContentInfoType contentInfoType;

///刷新
- (void)tryToRefresh;
```
#### 2.8.3、加载视频内容
```
    self.contentPage = [[ZJContentPage alloc]initWithPlacementId:self.contentId];
    self.contentPage.videoStateDelegate = self;
    self.contentPage.stateDelegate = self;
    UIViewController *vc = self.contentPage.viewController;
    if(vc){
        CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
        vc.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
        [self addChildViewController:vc];
        [self.view addSubview:vc.view];
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
```
加载广告具体示例详见Demo中的 :
ZJContentPageStyle1ViewController
ZJContentPageStyle2ViewController
ZJContentPageTabBarController

其他样式：
ZJFeedPageViewController  //瀑布流
ZJHorizontalFeedPageVC    //横版

#### 2.8.4、加载短剧
```
    self.tubePage = [[ZJTubePage alloc]initWithPlacementId:self.contentId];
    self.tubePage.videoStateDelegate = self;
    self.tubePage.stateDelegate = self;
    self.weakTubeVC = self.tubePage.viewController;
    if(self.weakTubeVC){
        [self addChildViewController:self.weakTubeVC];
        [self.view addSubview:self.weakTubeVC.view];
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
```
加载广告具体示例详见Demo中的 :
ZJTubePageStyle1VC

### <span id="jump2.9">2.9、接入新闻资讯广告(ZJNewsAdView)</span>

#### <span id="jump2.9.1">2.9.1、ZJNewsAdView说明</span>

```
/**
 *  @params
 *  placementId - 广告位id
 *  frame - 视图frame
 */
- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

/**
 *  拉取并展示广告
 */
- (void)loadAdAndShow;

/**
 *  返回web的上一页
 */
- (void)goback;
```

#### <span id="jump2.9.2">2.9.2、ZJNewsAdViewDelegate说明</span>

```
/**
 news广告加载成功
 */
- (void)zj_newsAdViewDidLoad:(ZJNewsAdView *)newsAdView;

/**
 news广告加载失败
 */
- (void)zj_newsAdView:(ZJNewsAdView *)newsAdView didLoadFailWithError:(NSError * _Nullable)error;

/**
 newsAdView曝光回调
 */
- (void)zj_newsAdViewDidShow:(ZJNewsAdView *)newsAdView;

/**
 关闭news广告回调
 */
- (void)zj_newsAdViewRewardEffective:(ZJNewsAdView *)newsAdView;

/**
 点击news广告回调
 */
- (void)zj_newsAdViewDidClick:(ZJNewsAdView *)newsAdView;

/**
 canGoBack状态监听。开放此回调主要为了应对一些可能的手势冲突的场景，一般情况按照demo写法就可，不要动它。
 */
- (void)zj_newsAd:(ZJNewsAdView *)newsAd canGoBackStateChange:(BOOL)canGoBack;

```
## <span id="jump3">三、接入H5内容页</span>

### <span id="jump3.1">3.1、接入H5内容</span>

SDK为接入方提供了定制H5内容页：游戏，测试,积分消耗...

#### <span id="jump3.1.1">3.1.1、ZJH5Page说明</span>

ZJUser *user；
userID;//用户ID
userName;//用户名称
userAvatar;//用户头像URL
userIntegral;//用户积分
ext = "";//扩展参数
self.zjH5 = [ZJH5 new];

```
@property(nonatomic,weak) id<ZJH5PageDelegate> delegate;

@property (nonatomic, strong) ZJUser *user;

- (instancetype)initWithPlacementId:(NSString *)placementId user:(ZJUser *)user delegate:(id <ZJH5PageDelegate>)delegate;

- (void)loadH5Page;

- (void)presentH5FromRootViewController:(UIViewController *)rootViewController animated:(BOOL)animated;
```

#### <span id="jump3.1.2">3.1.2、ZJH5Delegate说明</span>

```
@protocol ZJH5Delegate <NSObject>

@optional

//H5Ad加载完成
-(void) onZjH5PageLoaded:(ZJUser*) user error:(nullable NSError*) error;

//H5Ad错误
-(void) onZjH5PageError:(ZJUser*) user error:(NSError*) error;

//H5Ad关闭
-(void) onZjH5PageWillClose:(ZJUser*)user;

//H5操作回调
//积分不足
-(void) onIntegralNotEnough:(ZJUser*) user needIntegral:(NSInteger) integral;

//积分消耗
-(void) onIntegralExpend:(ZJUser*) user expendIntegral:(NSInteger) integral;

//积分奖励
-(void) onIntegralReward:(ZJUser*) user rewardIntegral:(NSInteger) integral;

//奖励发放,奖励积分
-(void) onZjH5PageAdRewardProvide:(ZJUser*) user rewardIntegral:(NSInteger) integral;

//用户页面的行为操作
-(void) onZjH5PageUserBehavior:(ZJUser*) user behavior:(NSString*) behavior;

//广告回调
//广告激励视频加载成功
-(void) onZjH5PageAdRewardLoaded:(ZJUser*) user trans_id:(NSString*) trans_id;

//广告激励视频触发激励（观看视频大于一定时长或者视频播放完毕）
-(void) onZjH5PageAdRewardValid:(ZJUser*) user trans_id:(NSString*) trans_id;

//广告点击
-(void) onZjH5PageAdRewardClick:(ZJUser*) user ;

//广告加载错误
-(void) onZjH5PageAdReward:(ZJUser*) user didFailWithError:(NSError*) error;

@end
```

#### <span id="jump3.1.3">3.1.3、加载H5内容页</span>

**Objective-C**

```
ZJUser *user = [ZJUser new];
user.userID = @"00012282";
user.userName = @“用户名";
user.userAvatar = @“用户头像";
user.userIntegral = 10000;
user.ext = @"超级无敌4";
self.zjH5Page = [[ZJH5Page alloc] initWithPlacementId:adId user:user delegate:self];
[self.zjH5Page loadH5Page];
```

加载广告具体示例详见Demo中的ZJH5ViewController。

### 3.2、悬浮广告
#### 3.2.1、ZJFloatingAdView说明

```
- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

@property (nonatomic, weak) id <ZJFloatingAdViewDelegate> delegate;
///placementId - 广告位 ID
@property (nonatomic, copy) NSString *placementId;
///广告是否能够移动 默认 YES
@property (nonatomic, assign) BOOL canMove;
///广告是否需要自动贴边展示 默认 YES
@property (nonatomic, assign) BOOL needMoveToSide;
///用来弹出目标页的ViewController，一般为当前ViewController 默认当前widow的viewController
@property (nonatomic, weak) UIViewController *rootViewController;

///加载广告
- (void)loadAd;
```

H5详情页可配置参数
```
@interface ZJFloatingAdView (ZJH5PageCustom)
/**导航栏返回按钮 图片设置*/
@property (nonatomic, nullable, strong) UIImage *backImage;
/**导航栏返回按钮 文字描述设置*/
@property (nonatomic, nullable, copy) NSAttributedString *backText;

/**导航栏关闭按钮 图片设置*/
@property (nonatomic, nullable, strong) UIImage *closeImage;
/**导航栏关闭按钮 文字描述设置*/
@property (nonatomic, nullable, copy) NSAttributedString *closeText;

/**隐藏导航栏的关闭按钮 */
@property (nonatomic, assign) BOOL hiddenH5CloseButton;

/**导航栏标题， 设置后不会读取网页的标题*/
@property (nonatomic, nullable, copy) NSString *navigationbarTitle;
@end
```
#### 3.2.2、ZJFloatingAdView使用
```
self.floatingAd = [[ZJFloatingAdView alloc]initWithPlacementId:@"J2952950117" frame:CGRectZero];
self.floatingAd.delegate = self;
self.floatingAd.hiddenH5CloseButton = YES;
[self.floatingAd loadAd];


//加载成功回调
-(void)zj_floatingAdViewDidLoad:(ZJFloatingAdView *)floatingAdView{
    NSLog(@"%s",__FUNCTION__);
    [self.view addSubview:floatingAdView];
}

```


## 历史版本更新日志

| 历史版本更新日志 | 修订日期  | 修订说明       |
| ---------------- | --------- | -------------- |
|v2.5.8.10|2024-08-08|已知问题修复|
|v2.5.8.9|2024-07-25|自渲染类型自定点击事件视图优化|
|v2.5.8.8|2024-07-11|自渲染类型增加百度。增加resize接口，在设置ZJNativeAdView.videoAdView.frame后调用。|
|v2.5.8.7|2024-07-10|隐私协议文件更新|
|v2.5.8.6|2024-07-09|百度SDK更新，适配接口更新，百度不在支持banner，删除对应适配器|
|v2.5.8.5|2024-07-05|联盟SDK更新，接入文档调整，MTG调整为不默认引入|
|v2.5.8.4|2024-07-01|自渲染：<br> 1，静音状态可变，控制开关由object类更换到view类。<br> 2，不再默认添加联盟logo，改为由接入方主动添加。<br> 3，修复快手自渲染部分情况没有获取标题问题。<br>demo：<br> 1，增加静音控制按钮及其图标。<br> 2，增加logo添加示例（ZJFillNativeAdView）|
|v2.5.8.3|2024-07-01|增加自渲染静音控制接口|
|v2.5.8.2|2024-06-26|增加自渲染bidding能力|
|v2.5.8.0|2024-06-13|新增快手短剧|
|v2.5.7.10|2024-06-06|DSPSDK更新.<br>兼容部分联盟回调逻辑.<br>部分联盟不支持自定义window中展示，开屏接入方式更换，如之前按照demo中appdelegate的方式接入开屏，辛苦按照当前demo更换一下接入方式。|
|v2.5.7.9|2024-05-21|SIG新老接口更换|
|v2.5.7.8|2024-05-17|更新SIG618版本（便于手动集成媒体更新，pod直接通过pod更新即可<br>已知问题修复|
|v2.5.7.6|2024-05-14|修复已知问题<br>快手最低支持版本提高至3.3.61|
|v2.5.7.5|2024-05-10|快手内容包更新适配|
|v2.5.7.3|2024-04-25|信息流bidding <br>修复已知问题|
|v2.5.7.2|2024-04-18|百度SDK更新，适配新的激励上报 <br>增加隐私协议PrivacyInfo <br>新增scheme列表配置要求，参考[1.2.4](#span-idjump124124-scheme列表添加以下内容span)|
|v2.5.7.1|2024-03-21|h5页面UI优化，调整状态栏，导航栏高度获取|
|v2.5.7.0|2024-03-16|新增Tanx接入。需要新增依赖库：libsqlite3.0.tbd|
|v2.5.6.5|2024-02-28|已知问题修复|
|v2.5.6.4|2024-02-19|适配百度信息流更新|
|v2.5.6.3|2024-02-02|已知问题修复|
|v2.5.6.2|2024-01-23|减少分类使用|
|v2.5.6.1|2024-01-22|快手SDK更新，动态兼容新旧版本|
|v2.5.6.0|2024-01-18|已知问题修复|
|v2.5.5.7|2024-01-12|已知问题修复|
|v2.5.5.6|2024-01-05|已知问题修复|
|v2.5.5.5|2024-01-03|1，gdt依赖库更新适配 <br>2，穿山甲转用融合sdk，适配。不在依赖gromore <br> 3，已知问题修复 |
|v2.5.5.4|2023-11-27|1，增加pangle模块 <br>2，穿山甲新sdk适配 <br>3，百度接口更新 |
|v2.5.5.3|2023-11-09|1，倍孜加入比价 <br>2，已知问题修复|
|v2.5.5.2|2023-11-08|1，修复已知问题|
|v2.5.5.0|2023-10-20|1，百度信息流接入 <br>2，PangleSDK接入 <br>3，穿山甲sdk更新适配 <br>4，修复已知问题|
|v2.5.4.17|2023-09-04|线程问题优化|
|v2.5.4.14|2023-07-27|修复已知问题|
|v2.5.4.13|2023-07-19|DSP音量问题|
|v2.5.4.12|2023-07-18|增加事件上报，激励、插屏、全屏视频摇一摇，状态栏隐藏时候状态栏高度获取|
|v2.5.4.11|2023-07-04|多线程优化|
|v2.5.4.9|2023-06-21|多线程优化<br>视频内容引入方式优化|
|v2.5.4.8|2023-06-20|修复已知问题|
|v2.5.4.5|2023-06-18|1，修复100100问题<br>2，有配置本地兜底时，取消兜底层层级逻辑逻辑|
|v2.5.4.4|2023-06-09|1，各联盟重复初始化配置<br>2，广告增加缓存逻辑    <br>3，增加cdn刷新，广告生效更快|
|v2.5.4.3|2023-05-08|增加ecpm获取权限配置|
|v2.5.4.2|2023-04-27|不去调用快手的.titleFontSize，避免审核被拒置|
|v2.5.4.0|2023-04-17|1，新增聚合平台 <br>2，视频内容引入方式优化|
|v2.5.3.9|2023-03-27|1，已知问题修复|
|v2.5.3.6|2023-03-14|1，新闻资讯接口文档更新 <br>2，H5Ad增加关闭h5回调 <br>3，修复已知问题|
|v2.5.3.0|2023-02-22|1，新闻资讯优化、新增新闻资讯多标签列表样式，<br>2，修复已知问题|
|v2.5.2.5|2023-01-18|1，新增视频内容广告样式，<br>2，对原视频内容代理和回调接口有做调整：<font color=red size=4><br>&emsp;&emsp;--原ZJContentPageDelegate改为ZJContentPageStateDelegate<br>&emsp;&emsp;--回调方法中(ZJContentPage *)videoContent修改为(id&lt;ZJContentInfo&gt;)videoContent</font>    <br>3，XCode14下视频内容接入方式更新，详见[2.8.1、ZJContentPage接入注意事项](#281-font-colorredzjcontentpage接入注意事项font)|
|v2.5.2.4|2022-12-22|新增新闻资讯类型广告|
|v2.5.2.1|2022-11-17|重构部分广告的请求逻辑|
|v2.5.1.0|2022-10-12|三方库冲突兼容|
|v2.5.0.1|2022-08-29|增加激励校验，bidding逻辑|
|v2.4.1.3|2022-06-24|适配穿山甲更新，增加错误限制策略|
|v2.4.0.1|2022-04-18|更新广告加载逻辑|
|v2.3.13|2021-02-09|修复bug， 添加Google广告|
|v2.3.12.5|2021-01-20| 添加插屏广告，全屏视频广告填充|
|v2.3.11.6|2021-12-01| 修复bug，视频内容需单独引入|
|v2.3.11|2021-10-25| 信息流填充优化，修复sdk已知问题|
|v2.3.9.5|2021-9-17| 兼容gif图和悬浮广告优化|
|v2.3.9|2021-8-27|新增Sigmob广告|
|v2.3.8.3|2021-8-17|激励视频校验2.0|
|v2.3.8.2|2021-8-13|开屏添加即将关闭回调，自渲染广告logoView|
|v2.3.8|2021-8-8|优化网络请求，优化版本兼容|
|v2.3.6|2021-7-28|激励视频校验优化|
|v2.3.2|2021-7-6|开屏广告优化，优化广告填充|
|v2.3.0|2021-6-28|添加广告平台|
|v2.2.12|2021-6-8|添加全屏视频广告类型，优化自渲染广告接入，完善广告回调信息|
|v2.2.3 |2021-4-7 |添加自渲染广告，优化H5广告|
|v2.1.0|2021-3-12|广告获取机制优化，提升容错率|
|v2.0.2|2021-3-5|模块拆分，广告优化|
| v1.0.21          |2020-1-26  |新增banner广告，广告数据获取优化 |
| v1.0.20          | 2020-1-14 | 增加新广告类型 |




<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [版本更新日志](#span-idjump1版本更新日志span)
- [一、iOS SDK接入说明](#span-idjump1一-ios-sdk接入说明span)
  - [1.1、工程设置导入framework](#span-idjump1111-工程设置导入frameworkspan)
    - [1.1.1、申请应用的AppID](#span-idjump111111-申请应用的appidspan)
    - [1.1.2、引入framework](#span-idjump112112-引入frameworkspan)
  - [1.2、Xcode编译选项设置](#span-idjump1212-xcode编译选项设置span)
    - [1.2.1、运行环境支持](#span-idjump122121-运行环境支持span)
    - [1.2.2、添加HTTP权限](#span-idjump1121122-添加http权限span)
    - [1.2.3、添加位置权限](#span-idjump123123-添加位置权限span)
    - [1.2.4、scheme列表添加以下内容](#span-idjump124124-scheme列表添加以下内容span)
    - [1.2.5、Swift接入准备](#span-idjump125125-swift接入准备span)
  - [1.3、iOS14注意事项](#13-ios14注意事项)
    - [1.3.1、iOS 14.5及以上版本ATT权限申请](#131-ios-145及以上版本att权限申请)
    - [1.3.2、SKAdNetwork 接入](#132-skadnetwork-接入)
  - [1.4、初始化SDK](#span-idjump1414-初始化sdkspan)
  - [1.5、打包回测](#span-idjump1515-打包回测span)
- [二、加载广告](#span-idjump2二-加载广告span)
  - [2.1、接入开屏广告(ZJSplashAd)](#span-idjump2121-接入开屏广告zjsplashadspan)
    - [2.1.1、ZJSplashAd广告说明](#span-idjump211211-zjsplashad广告说明span)
    - [2.1.2、ZJSplashAdDelegate](#span-idjump212212-zjsplashaddelegatespan)
    - [2.1.3、加载开屏广告](#span-idjump213213-加载开屏广告span)
  - [2.2、接入激励视频(ZJRewardVideoAd)](#span-idjump2222-接入激励视频zjrewardvideoadspan)
    - [2.2.1、ZJRewardVideoAd广告说明](#span-idjump221221-zjrewardvideoad广告说明span)
    - [2.2.2、ZJRewardVideoAdDelegate广告说明](#span-idjump222222-zjrewardvideoaddelegate广告说明span)
    - [2.2.3、加载激励视频](#span-idjump223223-加载激励视频span)
  - [2.3、接入插屏广告(ZJInterstitialAd)](#span-idjump2323-接入插屏广告zjinterstitialadspan)
    - [2.3.1、ZJInterstitialAd说明](#span-idjump231231-zjinterstitialad说明span)
    - [2.3.2、ZJInterstitialAdDelegate广告说明](#span-idjump232232-zjinterstitialaddelegate广告说明span)
    - [2.3.3、加载插屏广告](#span-idjump233233-加载插屏广告span)
  - [2.4、接入全屏视频信息流(ZJFeedFullVideoView)](#span-idjump2424-接入全屏视频信息流zjfeedfullvideoviewspan)
    - [2.4.1、ZJFeedFullVideoProvider，ZJFeedFullVideoView说明](#span-idjump241241-zjfeedfullvideoproviderzjfeedfullvideoview说明span)
    - [2.4.2、ZJFeedFullVideoProviderDelegate广告说明](#span-idjump242242-zjfeedfullvideoproviderdelegate广告说明span)
    - [2.4.3、加载全屏视频信息流](#span-idjump243243-加载全屏视频信息流span)
  - [2.5、接入模板信息流(ZJNativeExpressFeedAdManager)](#span-idjump2525-接入模板信息流zjnativeexpressfeedadmanagerspan)
    - [2.5.1、ZJNativeExpressFeedAdManager，ZJNativeExpressFeedAd说明](#span-idjump251251-zjnativeexpressfeedadmanagerzjnativeexpressfeedad说明span)
    - [2.5.2、ZJNativeExpressFeedAdManagerDelegate ZJNativeExpressFeedAdDelegate说明](#span-idjump252252-zjnativeexpressfeedadmanagerdelegate-zjnativeexpressfeedaddelegate说明span)
    - [2.5.3、加载模板信息流广告](#span-idjump253253-加载模板信息流广告span)
  - [2.6、接入自渲染广告(ZJNativeAd)](#26-接入自渲染广告zjnativead)
    - [2.6.1、ZJNativeAd说明](#261-zjnativead说明)
    - [2.6.2、加载ZJNativeAd广告 ####](#262-加载zjnativead广告-)
  - [2.7、接入全屏视频广告(ZJFullScreenVideoAd)</span>](#27-接入全屏视频广告zjfullscreenvideoadspan)
    - [2.7.1、ZJFullScreenVideoAd说明](#271-zjfullscreenvideoad说明)
    - [2.7.2、ZJFullScreenVideoAdDelegate广告说明](#272-zjfullscreenvideoaddelegate广告说明)
    - [2.7.3、加载全屏视频广告](#273-加载全屏视频广告)
  - [2.8、视频内容和短剧(ZJContentPage、ZJTubePage)</span>](#28-视频内容和短剧zjcontentpage-zjtubepagespan)
    - [2.8.1、ZJContentPage、ZJTubePage接入注意事项](#281-font-colorredzjcontentpage-zjtubepage接入注意事项font)
    - [2.8.2、ZJContentPage说明](#282-zjcontentpage说明)
    - [2.8.3、加载视频内容](#283-加载视频内容)
    - [2.8.4、加载短剧](#283-加载短剧)
  - [2.9、接入新闻资讯广告(ZJNewsAdView)](#span-idjump2929-接入新闻资讯广告zjnewsadviewspan)
    - [2.9.1、ZJNewsAdView说明](#span-idjump291291-zjnewsadview说明span)
    - [2.9.2、ZJNewsAdViewDelegate说明](#span-idjump292292-zjnewsadviewdelegate说明span)
- [三、接入H5内容页](#span-idjump3三-接入h5内容页span)
  - [3.1、接入H5内容](#span-idjump3131-接入h5内容span)
    - [3.1.1、ZJH5Page说明](#span-idjump311311-zjh5page说明span)
    - [3.1.2、ZJH5Delegate说明](#span-idjump312312-zjh5delegate说明span)
    - [3.1.3、加载H5内容页](#span-idjump313313-加载h5内容页span)
  - [3.2、悬浮广告](#32-悬浮广告)
    - [3.2.1、ZJFloatingAdView说明](#321-zjfloatingadview说明)
    - [3.2.2、ZJFloatingAdView使用](#322-zjfloatingadview使用)
- [历史版本更新日志](#历史版本更新日志)

<!-- /code_chunk_output -->



