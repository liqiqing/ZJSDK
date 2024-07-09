#
# Be sure to run `pod lib lint ZJSDK_Pods.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZJSDK'
  s.version          = '2.5.8.6'
  s.summary          = 'ZJSDK广告'
# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/liqiqing/ZJSDK.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Rare' => 'rarelv@163.com' }
  s.source           = { :git => 'https://github.com/liqiqing/ZJSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  s.ios.deployment_target = '11.0'
  s.platform     = :ios, "11.0"
  
  #依赖的系统frameworks
  s.frameworks = 'UIKit','Foundation','StoreKit','MobileCoreServices','WebKit','MediaPlayer','CoreMedia','CoreLocation','AVFoundation','CoreTelephony','SystemConfiguration','AdSupport','CoreMotion','Accelerate','QuartzCore','Security','ImageIO','CFNetwork','CoreGraphics','SafariServices'

  #依赖的系统静态库
  #z表示libz.tdb,后缀不需要,lib开头的省略lib
  s.libraries = 'resolv.9','c++','z','sqlite3','bz2','xml2','c++abi','sqlite3.0'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64', 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386,arm64' }

#  valid_archs = ['armv7', 'i386', 'x86_64', 'arm64']
#  s.pod_target_xcconfig = {
#    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
#  }
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.default_subspecs = 'ZJSDKModuleGDT', 'ZJSDKModuleCSJ', 'ZJSDKModuleKS', 'ZJSDKModuleDSP','ZJSDKModuleSIG','ZJSDKModuleBD','ZJSDKModuleBeiZi','ZJSDKModuleTanX'

  s.subspec 'ZJAdSDK' do |ss|
    ss.vendored_frameworks = 'ZJSDK/ZJAdSDK/*.framework'
    ss.preserve_paths = 'ZJSDK/ZJAdSDK/*.framework'
  end
  
  s.subspec 'ZJSDKModuleGDT' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGDT/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'GDTMobSDK', '~> 4.14.62'
#    4.14.6开始旧的注册方法标记为废弃，新的注册方法可以调用到
#    4.13.51 bidding竞败上报方法sendLossNotificationWithPrice，4.13.81为sendLossNotificationWithPrice
#   固定到4.13可能会导致crash
  end

  s.subspec 'ZJSDKModuleCSJ' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'Ads-Fusion-CN-Beta', '~> 5.8'
    ss.dependency 'Ads-Fusion-CN-Beta/CSJMediation'
    ss.dependency 'Ads-Fusion-CN-Beta/BUAdSDK'
    ss.dependency 'CSJMAdmobAdapter', '~> 10.0'
    ss.dependency 'CSJMBaiduAdapter', '~> 5.0'
    ss.dependency 'CSJMGdtAdapter', '~> 4.14'
#    ss.dependency 'CSJMKlevinAdapter', '~> 2.11'
    ss.dependency 'CSJMKsAdapter', '~> 3.3'
    ss.dependency 'CSJMMintegralAdapter', '~> 7.3.4'
    ss.dependency 'CSJMSigmobAdapter', '~> 4.8'
#    ss.dependency 'CSJMUnityAdapter', '~> 4.3'
  end
  s.subspec 'ZJSDKModuleKS' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleKS/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
#    ss.vendored_frameworks = 'ZJSDK/ZJSDKModuleKS/KSAdSDK.framework'
    ss.dependency 'KSAdSDK', '~> 3.3.61'
#   3.3.61 以上注册方法与旧版本不一致，最低支持3.3.61，内容包版本号也为3.3.61
  end

  s.subspec 'ZJSDKModuleMTG' do |ss|

    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMTG/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'MintegralAdSDK', '~> 7.0'
    ss.dependency 'MintegralAdSDK/RewardVideoAd'
    ss.dependency 'MintegralAdSDK/BannerAd'
    ss.dependency 'MintegralAdSDK/SplashAd'
    ss.dependency 'MintegralAdSDK/InterstitialAd'
    ss.dependency 'MintegralAdSDK/NativeAdvancedAd'
  end

  s.subspec 'ZJSDKModuleDSP' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleDSP/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'DSPSDK'
  end
  
  s.subspec 'ZJSDKModuleSIG' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleSIG/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'SigmobAd-iOS', '~> 4.7'
#   sig更新日志要找运营看，或者自己注册一个账号看一下
  end
#
#  s.subspec 'IPDSDKModuleYM' do |ss|
#    ss.vendored_libraries = 'IPDSDK/IPDSDKModuleYM/*.a'
#    ss.dependency 'IPDSDK/IPDAdSDK'
#    ss.vendored_frameworks = 'IPDSDK/IPDSDKModuleYM/*.framework'
#    ss.preserve_paths = 'IPDSDK/IPDSDKModuleYM/*.framework'
#    ss.resources = 'IPDSDK/IPDSDKModuleYM/AlicloudCloudCode.framework/AlicloudCloudCode.bundle'
#  end
  
  s.subspec 'ZJSDKModuleGoogle' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGoogle/*.a'
    ss.source_files       = 'ZJSDK/ZJSDKModuleGoogle/*.h'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'Google-Mobile-Ads-SDK'
  end
 
 s.subspec 'ZJSDKModuleBD' do |ss|
   ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
   ss.dependency 'ZJSDK/ZJAdSDK'
   ss.dependency 'BaiduMobAdSDK', '~> 5.36'
#  5.36 接口变更
 end
 
  s.subspec 'ZJSDKModulePangle' do |ss|
   ss.vendored_libraries = 'ZJSDK/ZJSDKModulePangle/*.a'
   ss.dependency 'ZJSDK/ZJAdSDK'
   ss.dependency 'Ads-Global'
 end

 s.subspec 'ZJSDKModuleBeiZi' do |ss|
   ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBeiZi/*.a'
   ss.dependency 'ZJSDK/ZJAdSDK'
   ss.dependency 'BeiZiSDK-iOS/BeiZiSDK-iOS', '~>4.90'
 end
 
  s.subspec 'ZJSDKModuleWM' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleWM/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'ToBid-iOS', '2.6.0'
    ss.dependency 'BaiduMobAdSDK', '5.11'
   
    ss.dependency 'MintegralAdSDK', '7.2.9'
    ss.dependency 'MintegralAdSDK/RewardVideoAd'
    ss.dependency 'MintegralAdSDK/BannerAd'
    ss.dependency 'MintegralAdSDK/SplashAd'
    ss.dependency 'MintegralAdSDK/InterstitialAd'
    ss.dependency 'MintegralAdSDK/NativeAdvancedAd'
    
    ss.dependency 'KSAdSDK', '~>3.3.38'
    ss.dependency 'Google-Mobile-Ads-SDK' , '10.0.0'
    ss.dependency 'GDTMobSDK', '4.14.10'
    ss.dependency 'Ads-CN', '5.0.0.5'
 end
  s.subspec 'ZJSDKModuleTanX' do |ss|
 
   ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTanX/*.a'
   ss.dependency 'ZJSDK/ZJAdSDK'
   ss.source_files         = 'ZJSDK/ZJSDKModuleTanX/*.h'
   ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleTanX/*.framework'
   ss.resource             = 'ZJSDK/ZJSDKModuleTanX/*.bundle'
   ss.preserve_paths       = 'ZJSDK/ZJSDKModuleTanX/*.framework'
 
   # ss.dependency 'MintegralAdSDK/RewardVideoAd'
   # ss.dependency 'MintegralAdSDK/BannerAd'
   # ss.dependency 'MintegralAdSDK/SplashAd'
   # ss.dependency 'MintegralAdSDK/InterstitialAd'
   # ss.dependency 'MintegralAdSDK/NativeAdvancedAd'
 end
end
