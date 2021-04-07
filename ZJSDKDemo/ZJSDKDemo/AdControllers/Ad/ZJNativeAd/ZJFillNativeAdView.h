//
//  ZJFillNativeAdView.h
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import <ZJSDKCoreFramewrok/ZJNativeAdView.h>

NS_ASSUME_NONNULL_BEGIN



@interface ZJFillNativeAdView : ZJNativeAdView


@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *descLabel;
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UIButton *clickButton;

@property (nonatomic, strong) UIImageView *appIconImageView;


@end

NS_ASSUME_NONNULL_END
