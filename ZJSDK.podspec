#
# Be sure to run `pod lib lint ZJSDK_Pods.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZJSDK'
  s.version          = '2.5.4.12'
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
  s.libraries = 'resolv.9','c++','z','sqlite3','bz2','xml2','c++abi'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  
#  valid_archs = ['armv7', 'i386', 'x86_64', 'arm64']
#  s.pod_target_xcconfig = {
#    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
#  }
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.default_subspecs = 'ZJSDKModuleGDT', 'ZJSDKModuleCSJ', 'ZJSDKModuleKS', 'ZJSDKModuleMTG', 'ZJSDKModuleDSP','ZJSDKModuleSIG','ZJSDKModuleBD'

  s.subspec 'ZJAdSDK' do |ss|
    ss.vendored_frameworks = 'ZJSDK/ZJAdSDK/*.framework'
    ss.preserve_paths = 'ZJSDK/ZJAdSDK/*.framework'
  end
  
  s.subspec 'ZJSDKModuleGDT' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGDT/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'GDTMobSDK', '~> 4.14'
#    4.13.51 bidding竞败上报方法sendLossNotificationWithPrice，4.13.81为sendLossNotificationWithPrice
#   固定到4.13可能会导致crash
  end

  s.subspec 'ZJSDKModuleCSJ' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'Ads-CN', '~> 5.1'
  end

  s.subspec 'ZJSDKModuleKS' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleKS/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
#    ss.vendored_frameworks = 'ZJSDK/ZJSDKModuleKS/KSAdSDK.framework'
    ss.dependency 'KSAdSDK', '~> 3.3.6'
#    bidding广告 3.3.6 以上，内容 3.3.10 以上 sdk 版本
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
    ss.resource = 'ZJSDK/ZJSDKModuleDSP/*.bundle'
    ss.dependency 'ZJSDK/ZJAdSDK'
  end
  
  s.subspec 'ZJSDKModuleSIG' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleSIG/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'SigmobAd-iOS', '~> 4.7'
#   sig更新日志要找运营看，或者自己注册一个账号看一下
  end

  s.subspec 'ZJSDKModuleYM' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleYM/*.a'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.vendored_frameworks = 'ZJSDK/ZJSDKModuleYM/*.framework'
    ss.preserve_paths = 'ZJSDK/ZJSDKModuleYM/*.framework'
    ss.resources = 'ZJSDK/ZJSDKModuleYM/AlicloudCloudCode.framework/AlicloudCloudCode.bundle'
  end
  
  s.subspec 'ZJSDKModuleGoogle' do |ss|
    ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGoogle/*.a'
    ss.source_files       = 'ZJSDK/ZJSDKModuleGoogle/*.h'
    ss.dependency 'ZJSDK/ZJAdSDK'
    ss.dependency 'Google-Mobile-Ads-SDK'
  end
 
 s.subspec 'ZJSDKModuleBD' do |ss|
   ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
   ss.dependency 'ZJSDK/ZJAdSDK'
   ss.dependency 'BaiduMobAdSDK', '~> 4.81'
#  bidding要求 IOS V4.81及以上版本
 end

 s.subspec 'ZJSDKModuleGromore' do |ss|
   ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGromore/*.a'
   ss.dependency 'ZJSDK/ZJAdSDK'
   ss.vendored_frameworks = 'ZJSDK/ZJSDKModuleGromore/**/*.framework'
   ss.preserve_paths = 'ZJSDK/ZJSDKModuleGromore/**/*.framework'
   ss.dependency 'Ads-CN', '~> 5.1'
   ss.dependency 'Google-Mobile-Ads-SDK' , '10.0.0'
   ss.dependency 'GDTMobSDK', '4.14.10'
   ss.dependency 'BaiduMobAdSDK', '5.11'
               
    ss.dependency 'MintegralAdSDK', '7.2.8'
    ss.dependency 'MintegralAdSDK/RewardVideoAd'
    ss.dependency 'MintegralAdSDK/BannerAd'
    ss.dependency 'MintegralAdSDK/SplashAd'
    ss.dependency 'MintegralAdSDK/InterstitialAd'
    ss.dependency 'MintegralAdSDK/NativeAdvancedAd'

    ss.dependency 'KSAdSDK', '~>3.3.38'
 end
 
 s.subspec 'ZJSDKModuleBeiZi' do |ss|
   ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBeiZi/*.a'
   ss.dependency 'ZJSDK/ZJAdSDK'
   ss.dependency 'BeiZiSDK', '4.90.1.26'
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
 
end
