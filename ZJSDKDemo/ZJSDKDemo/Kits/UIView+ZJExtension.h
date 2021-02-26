//
//  UIView+ZJExtension.h
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/30.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (ZJExtension)
///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat x;
///< Shortcut forframe.origin.y
@property (nonatomic) CGFloat y;
///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat left;
///< Shortcut forframe.origin.y
@property (nonatomic) CGFloat top;
///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat right;
///< Shortcut for frame.origin.y + frame.size.height
@property (nonatomic) CGFloat bottom;
///< Shortcut for frame.size.width.
@property (nonatomic) CGFloat width;
///< Shortcut for frame.size.height.
@property (nonatomic) CGFloat height;
///< Shortcut for center.x
@property (nonatomic) CGFloat centerX;
///< Shortcut for center.y
@property (nonatomic) CGFloat centerY;
///< Shortcut for frame.origin.
@property (nonatomic) CGPoint origin;
///< Shortcut for frame.size.
@property (nonatomic) CGSize size;


@end

NS_ASSUME_NONNULL_END
