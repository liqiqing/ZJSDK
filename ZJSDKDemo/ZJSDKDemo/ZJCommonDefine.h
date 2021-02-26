//
//  ZJCommonDefine.h
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/30.
//  Copyright © 2020 zj. All rights reserved.
//

#ifndef ZJCommonDefine_h
#define ZJCommonDefine_h

//Macro
#define M_IsIphoneX [UIDevice isIphoneX]
#define M_NAVI_HEIGHT (M_IsIphoneX ? 88 : 64)

#define ScreenWidth  ([UIScreen mainScreen].bounds.size.width)
#define ScreenHeight ([UIScreen mainScreen].bounds.size.height)

/*底部安全区域高度*/
#define SafeBottomMargin (M_IsIphoneX ? 34.0 : 0)

#endif /* ZJCommonDefine_h */
