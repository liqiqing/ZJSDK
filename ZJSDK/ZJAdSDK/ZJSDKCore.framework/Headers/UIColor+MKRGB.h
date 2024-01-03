//
//  UIColor+MKRGB.h
//  YKXQ
//
//  Created by 麻明康 on 2020/10/22.
//  Copyright © 2020 YiYa. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
#pragma mark =============== Colors ===============
//RGB颜色
#define ColorRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:a]
#define ColorRGB(r, g, b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]

//十六进制颜色
#define ColorHEX(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

@interface UIColor (MKRGB)
+ (UIColor *) colorFromHexRGB:(NSString *) inColorString;
#pragma mark === Some wonderful color
+ (UIColor *)tiffanyBlue;
+ (UIColor *)avocadoGreen;
+ (UIColor *)JesterRed;
+ (UIColor *)LipstickRed;
+ (UIColor *)NFBlue;
+ (UIColor *)NFPink;
@end

NS_ASSUME_NONNULL_END
