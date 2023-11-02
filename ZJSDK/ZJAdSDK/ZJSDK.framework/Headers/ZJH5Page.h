//
//  ZJH5Ad.h
//  ZJSDK
//
//  Created by Robin on 2020/10/28.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJAd.h"
#import "ZJUser.h"
#import "ZJH5PageDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJH5Page : ZJAd

@property (nonatomic, weak) id <ZJH5PageDelegate> delegate;

/**
 用户信息
 */
@property (nonatomic, strong) ZJUser *user;

/**
 初始化H5页面信息
 @param placementId 广告位id（required）
 @param user 用户信息，由接入方提供，H5页面需要用到用户信息，用于展示和产生每个用户的唯一标识。（required）
 */
- (instancetype)initWithPlacementId:(NSString *)placementId user:(ZJUser *)user delegate:(id <ZJH5PageDelegate>)delegate;


/**
 加载H5广告
 */
- (void)loadH5Page;

/**
 展示H5页面 push 或 present 方式
 如需设置 ZJH5Page+ZJCustom.h 内的H5页面相关UI，请在设置后再调用该方法跳转
 */
- (void)presentH5FromRootViewController:(UIViewController *)rootViewController animated:(BOOL)animated;


/**
 展示H5页面
 */
- (void)showH5Page:(UIViewController*)rootViewController DEPRECATED_MSG_ATTRIBUTE("use presentH5FromRootViewController:animated: instead.");

@end



@interface ZJH5Page (ZJCustom)

/**导航栏返回按钮 图片设置*/
@property (nonatomic, nullable, strong) UIImage *backImage;
/**导航栏返回按钮 文字描述设置*/
@property (nonatomic, nullable, copy) NSAttributedString *backText;

/**导航栏关闭按钮 图片设置*/
@property (nonatomic, nullable, strong) UIImage *closeImage;
/**导航栏关闭按钮 文字描述设置*/
@property (nonatomic, nullable, copy) NSAttributedString *closeText;

/**隐藏导航栏的关闭按钮 默认 :YES*/
//@property (nonatomic, assign) BOOL hiddenCloseButton;

/**导航栏标题， 设置后不会读取网页的标题*/
@property (nonatomic, nullable, copy) NSString *navigationbarTitle;

@end

NS_ASSUME_NONNULL_END
