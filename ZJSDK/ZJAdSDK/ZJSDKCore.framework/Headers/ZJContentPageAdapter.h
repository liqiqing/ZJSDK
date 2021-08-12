//
//  ZJContentPageAdapter.h
//  ZJSDK
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "ZJCoreAdAdapter.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJAdapterContentAdapterVideoStateDelegate,ZJContentAdapterStateDelegate;

@interface ZJContentPageAdapter : ZJCoreAdAdapter

@property (nonatomic, strong) UIViewController *viewController;

///  视频状态代理
@property (nonatomic, weak) id <ZJAdapterContentAdapterVideoStateDelegate> zjAdapter_videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id <ZJContentAdapterStateDelegate> zjAdapter_stateDelegate;


- (void)loadContentPageWithDeeplink:(NSString *)deepLink;

- (void)tryToRefresh;


//内容标识
@property (nonatomic,copy)NSString *contentInfoId;
//内容类型
//ZJContentInfoTypeUnknown = 0,         //未知，正常不会出现
// ZJContentInfoTypeNormal = 1,          //普通信息流
// ZJContentInfoTypeAd = 2,              //SDK内部广告
//ZJContentInfoTypeEmbeded = 100    //外部广告
@property (nonatomic,assign)NSInteger contentInfoType;

/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zjAdapter_videoDidStartPlay:(ZJContentPageAdapter *)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidPause:(ZJContentPageAdapter *)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidResume:(ZJContentPageAdapter *)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zjAdapter_videoDidEndPlay:(ZJContentPageAdapter *)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zjAdapter_videoDidFailedToPlay:(ZJContentPageAdapter *)videoContent withError:(NSError *)error;


/**
* 内容展示
* @param content 内容模型
*/
- (void)zjAdapter_contentDidFullDisplay:(ZJContentPageAdapter *)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zjAdapter_contentDidEndDisplay:(ZJContentPageAdapter *)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidPause:(ZJContentPageAdapter *)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidResume:(ZJContentPageAdapter *)content;


-(void)loadAd NS_UNAVAILABLE;

@end



@protocol ZJAdapterContentAdapterVideoStateDelegate <NSObject>
@optional
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zjAdapter_videoDidStartPlay:(ZJContentPageAdapter *)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidPause:(ZJContentPageAdapter *)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidResume:(ZJContentPageAdapter *)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zjAdapter_videoDidEndPlay:(ZJContentPageAdapter *)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zjAdapter_videoDidFailedToPlay:(ZJContentPageAdapter *)videoContent withError:(NSError *)error;

@end



@protocol ZJContentAdapterStateDelegate <NSObject>
@optional
/**
* 内容展示
* @param content 内容模型
*/
- (void)zjAdapter_contentDidFullDisplay:(ZJContentPageAdapter *)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zjAdapter_contentDidEndDisplay:(ZJContentPageAdapter *)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidPause:(ZJContentPageAdapter *)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidResume:(ZJContentPageAdapter *)content;


@end

NS_ASSUME_NONNULL_END
