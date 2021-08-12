//
//  ZJContentPageDelegate.h
//  ZJSDK
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#ifndef ZJContentPageDelegate_h
#define ZJContentPageDelegate_h

typedef NS_ENUM(NSUInteger, ZJContentInfoType) {
    ZJContentInfoTypeUnknown,         //未知，正常不会出现
    ZJContentInfoTypeNormal,          //普通信息流
    ZJContentInfoTypeAd,              //SDK内部广告
    ZJContentInfoTypeEmbeded = 100    //外部广告
};
@class  ZJContentPage;
NS_ASSUME_NONNULL_BEGIN
@protocol ZJContentPageVideoStateDelegate <NSObject>
@optional
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zj_videoDidStartPlay:(ZJContentPage *)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidPause:(ZJContentPage *)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidResume:(ZJContentPage *)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zj_videoDidEndPlay:(ZJContentPage *)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zj_videoDidFailedToPlay:(ZJContentPage *)videoContent withError:(NSError *)error;

@end



@protocol ZJContentPageStateDelegate <NSObject>
@optional
/**
* 内容展示
* @param content 内容模型
*/
- (void)zj_contentDidFullDisplay:(ZJContentPage *)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zj_contentDidEndDisplay:(ZJContentPage *)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zj_contentDidPause:(ZJContentPage *)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zj_contentDidResume:(ZJContentPage *)content;


@end

NS_ASSUME_NONNULL_END

#endif /* ZJContentPageDelegate_h */
