//
//  ZJSDKDefines.h
//  ZJOptimizeProject
//
//  Created by Rare on 2021/7/29.
//
#import <UIKit/UIKit.h>

#ifndef ZJSDKDefines_h
#define ZJSDKDefines_h

#define ZJ_ScreenHeight [UIScreen mainScreen].bounds.size.height

#define ZJ_ScreenWidth [UIScreen mainScreen].bounds.size.width

#define ZJ_StatusBarHeight [UIApplication sharedApplication].statusBarFrame.size.height

#define ZJ_IPHONEXSeries zj_is_iphoneXSeries_screen()

#define ZJ_DefaultNavigationBarHeight \
({CGFloat navigationBarHeight = 44; \
if (ZJ_IPHONEXSeries)  { \
navigationBarHeight = 44+ZJ_SafeAreaInsetsTop; \
}else{ \
navigationBarHeight = 44+ZJ_StatusBarHeight; \
} \
(navigationBarHeight);})

#define ZJ_SafeAreaInsetsBottom \
({CGFloat bottom = 0; \
if (@available(iOS 11.0, *))  { \
bottom = zj_visibleWindow().safeAreaInsets.bottom; \
} \
(bottom);})

#define ZJ_SafeAreaInsetsTop \
({CGFloat top = 0; \
if (@available(iOS 11.0, *)) { \
top = zj_visibleWindow().safeAreaInsets.top; \
} \
(top);})


/**---------------------------------------------------*/
//强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
//弱引用
#define zj_weakify(object)  __weak typeof(object) weak##object = object;
//强引用
#define zj_strongify(object)  __strong typeof(object) object = weak##object;
/**---------------------------------------------------*/


FOUNDATION_EXPORT UIWindow * zj_visibleWindow(void);

FOUNDATION_EXPORT BOOL zj_is_iphoneXSeries_screen(void);

FOUNDATION_EXPORT NSString * const ZJSDKVersion;


#endif /* ZJSDKDefines_h */
