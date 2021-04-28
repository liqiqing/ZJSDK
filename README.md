# ZJSDK_iOS使用文档

**备注**

| 最新版本更新日志 | 修订日期  | 修订说明       |
| ---------------- | --------- | -------------- |
|v2.0.2       |2021-3-5 |模块拆分，广告优化|
|v2.1.0       |2021-3-12 |广告获取优化,提升容错率|
|v2.2.3 |2021-4-7 |添加自渲染广告，优化H5广告|

## <span id="jump1">一、iOS SDK接入说明</span>

### <span id="jump1.1">1.1、工程设置导入framework</span>

#### <span id="jump1.1.1">1.1.1、申请应用的AppID</span>

```
请找运营人员获取应用ID和广告位ID。
```

#### <span id="jump1.1.2">1.1.2、导入framework</span>

**1. CocoaPods接入方式**



```
#完整的SDK
pod 'ZJSDK'

#如需模块拆分导入，请导入ZJSDKModuleDSP
pod 'ZJSDK/ZJSDKModuleDSP'

pod 'ZJSDK/ZJSDKModuleGDT'#优量汇广告
pod 'ZJSDK/ZJSDKModuleCSJ'#穿山甲广告
pod 'ZJSDK/ZJSDKModuleKS'#快手广告
pod 'ZJSDK/ZJSDKModuleMTG'#MTG广告
```

**2.手动方式**

1.获取 framework 文件后直接将 {ZJSDK}文件拖入工程即可。

2.<font color=#FF0000>前往项目的Build Setting中的Enable Bitcode设置为NO</font>

3.<font color=#FF0000>前往项目的Build Phases，创建Copy Files，修改Destination为Frameworks，Name中添加KSAdSDK.framework</font>

4.为了方便模拟器调试，KSAdSDK 带有x86_64,i386架构，上架App store需要移除对应的这两个架构，请参考:（https://stackoverflow.com/questions/30547283/submit-to-app-store-issues-unsupported-architecture-x86）

*升级SDK的同学必须同时更新framework和bundle文件，否则可能出现部分页面无法展示的问题，老版本升级的同学需要重新引入ZJSDK.framework

*拖入完请确保Copy Bundle Resources中有BUAdSDK.bundle，ZJSDKBundle.bundle否则可能出现icon图片加载不出来的情况。

### <span id="jump1.2">1.2、Xcode编译选项设置</span>

#### <span id="jump1.1.2.1">1.2.1、添加权限</span>

- 工程plist文件设置，点击右边的information Property List后边的 "+" 展开

添加 App Transport Security Settings，先点击左侧展开箭头，再点右侧加号，Allow Arbitrary Loads 选项自动加入，修改值为 YES。 SDK API 已经全部支持HTTPS，但是广告主素材存在非HTTPS情况。

```
<key>NSAppTransportSecurity</key>
  <dict>
     <key>NSAllowsArbitraryLoads</key>
   <true/>
</dict>
```

- Build Settings中Other Linker Flags 增加参数-ObjC，字母o和c大写。

#### <span id="jump1.2.2">1.2.2、运行环境配置</span>



- 支持系统 iOS 9.X 及以上;
- SDK编译环境 Xcode 11;
- 支持架构： x86-64, armv7, arm64,i386

**添加依赖库**

工程需要在TARGETS -> Build Phases中找到Link Binary With Libraries，点击“+”，依次添加下列依赖库

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

  如果以上依赖库增加完仍旧报错，请添加ImageIO.framework。

  SystemConfiguration.framework、CoreTelephony.framework、Security.framework是为了统计app信息使用

#### <span id="jump1.2.3">1.2.3、位置权限</span>

SDK 不会主动获取应用位置权限，当应用本身有获取位置权限逻辑时，需要在应用的 info.plist 添加相应配置信息，避免 App Store 审核被拒：

// 应用根据实际情况配置

```
  Privacy - Location When In Use Usage Description
  Privacy - Location Always and When In Use Usage Description
  Privacy - Location Always Usage Description
  Privacy - Location Usage Description
```

#### <span id="jump1.2.4">1.2.4、Swift接入准备</span>

1: 新建桥接头文件（bridge.h，推荐放在工程目录下）。这里我们命名为：ZJAdSDKDemoSwift-Bridging-Header.h。在这个文件中import我们需要的所有头文件，代码如下：

```
#import <ZJSDK/ZJAdSDK.h>
#import <ZJSDK/ZJH5.h>
#import <ZJSDK/ZJSplashAd.h>
#import <ZJSDK/ZJRewardVideoAd.h>
#import <ZJSDK/ZJInterstitialAd.h>
#import <ZJSDK/ZJFeedFullVideoProvider.h>
```

2: 左侧目录中选中工程名，在 TARGETS->Build Settings-> Swift Compiler - Code Generation -> Objective-C Bridging Header 中输入桥接文件的路径

### <span id="jump1.3">1.3、初始化SDK</span>

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
* 详解：广告素材及广告图片拉取成功后会回调splashAdDidLoad方法，当拉取失败时会回调splashAdFailToPresent方法
*/
- (void) loadAd;

/**
* 展示广告，调用此方法前需调用isAdValid方法判断广告素材是否有效
* 详解：广告展示成功时会回调splashAdSuccessPresentScreen方法，展示失败时会回调splashAdFailToPresent方法
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

- 类型说明： 激励视频广告是一种全新的广告形式，用户可选择观看视频广告以换取有价物，例如虚拟货币、应用内物品和独家内容等等；这类广告的长度为 15-30 秒，不可跳过，且广告的结束画面会显示结束页面，引导用户进行后续动作。

#### <span id="jump2.2.1">2.2.1、ZJRewardVideoAd广告说明</span>

```
@interface ZJRewardVideoAd : ZJAd

@property(nonatomic,copy) NSString *userId;

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
@param rewardedVideoAd ZJRewardVideoAd 实例
*/
- (void)zj_rewardVideoAdDidLoad:(ZJRewardVideoAd *)rewardedVideoAd;

/**
视频数据下载成功回调，已经下载过的视频会直接回调
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

- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<ZJInterstitialAdDelegate>) delegate;

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
- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<ZJFeedFullVideoProviderDelegate>) delegate;

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
    self.adProvider = [[ZJFeedFullVideoProvider alloc] initWithPlacementId:@"KS90010003" delegate:self];
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

### <span id="jump2.6">2.6、接入Banner广告(ZJBannerAdView)</span>

#### <span id="jump2.6.1">2.6.1、ZJBannerAdView说明</span>

```
/**
 *  @params
 *  placementId - 广告位id
 *  viewController - 视图控制器
 *  adSize 展示的位置和大小
 *  interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize
                           interval:(NSInteger)interval;

/**
 *  @params
 *  placementId - 广告位id
 *  viewController - 视图控制器
 *  adSize 展示的位置和大小
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize;
/**
 *  拉取并展示广告
 */
- (void)loadAdAndShow;
```

#### <span id="jump2.6.2">2.6.2、ZJBannerAdViewDelegate说明</span>

```
/**
 banner广告加载成功
 */
- (void)zj_bannerAdViewDidLoad:(ZJBannerAdView *)bannerAdView;

/**
 banner广告加载失败
 */
- (void)zj_bannerAdView:(ZJBannerAdView *)bannerAdView didLoadFailWithError:(NSError *_Nullable)error;

/**
 bannerAdView曝光回调
 */
- (void)zj_bannerAdViewWillBecomVisible:(ZJBannerAdView *)bannerAdView;

/**
 关闭banner广告回调
 */
- (void)zj_bannerAdViewDislike:(ZJBannerAdView *)bannerAdView;

/**
 点击banner广告回调
 */
- (void)zj_bannerAdViewDidClick:(ZJBannerAdView *)bannerAdView;

/**
 关闭banner广告详情页回调
 */
- (void)zj_bannerAdViewDidCloseOtherController:(ZJBannerAdView *)bannerAdView;
```

#### <span id="jump2.6.3">2.6.3、加载Banner广告</span>

```
-(void)loadAd:(NSString*)adId{
    if (!_bannerView) {
         CGFloat bannerHight = 100;
        _bannerView = [[ZJBannerAdView alloc]initWithPlacementId:adId viewController:self adSize:CGSizeMake(ScreenWidth, bannerHight) interval:30];
        _bannerView.frame = CGRectMake(0, 100, ScreenWidth, bannerHight);
        _bannerView.delegate = self;
        [self.view addSubview:_bannerView];
        [_bannerView loadAdAndShow];
    }
}
```

加载广告具体示例详见Demo中的ZJBannerAdAdapter。



### 2.7、接入自渲染广告(ZJNativeAd)

#### 2.7.1、ZJNativeAd说明

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

#### 2.7.2、加载ZJNativeAd广告 ####

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

### 2.8、接入全屏视频广告(ZJFullScreenVideoAd)</span>

#### 2.8.1、ZJFullScreenVideoAd说明

```
@interface ZJFullScreenVideoAd : ZJAd

@property(nonatomic,weak) id<ZJFullScreenVideoAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId delegate:(id<ZJFullScreenVideoAdDelegate>) delegate;
//加载广告
-(void) loadAd;
//展示全屏视频广告
-(void)presentFullScreenVideoAdFromRootViewController:(UIViewController*)viewController;

@end
```

#### 2.8.2、ZJFullScreenVideoAdDelegate广告说明

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

#### 2.8.3、加载全屏视频广告

```
self.fullVideoAd = [[ZJFullScreenVideoAd alloc] initWithPlacementId:adId];
self.fullVideoAd.delegate = self;
[self.fullVideoAd loadAd];
```


加载广告具体示例详见Demo中的ZJFullScreenVideoViewController。




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

@property(nonatomic,strong) ZJUser *user;

- (instancetype)initWithPlacementId:(NSString *)placementId user:(ZJUser *)user delegate:(id<ZJH5PageDelegate>) delegate;

-(void) loadH5Page;

-(void) showH5Page:(UIViewController*) rootViewController;
```

#### <span id="jump3.1.2">3.1.2、ZJH5Delegate说明</span>

```
@protocol ZJH5Delegate <NSObject>

@optional

//H5Ad加载完成
-(void) onZjH5PageLoaded:(ZJUser*) user error:(nullable NSError*) error;

//H5Ad错误
-(void) onZjH5PageError:(ZJUser*) user error:(NSError*) error;

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
