//
//  ZJContentAdapterStateProtocol.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJContentInfo.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJAdapterContentAdapterVideoStateProtocol <NSObject>
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zjAdapter_videoDidStartPlay:(id<ZJContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidPause:(id<ZJContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zjAdapter_videoDidResume:(id<ZJContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zjAdapter_videoDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zjAdapter_videoDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error;
@end

@protocol ZJContentAdapterStateProtocol <NSObject>
/**
* 内容展示
* @param content 内容模型
*/
- (void)zjAdapter_contentDidFullDisplay:(id<ZJContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zjAdapter_contentDidEndDisplay:(id<ZJContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidPause:(id<ZJContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zjAdapter_contentDidResume:(id<ZJContentInfo>)content;


@end

NS_ASSUME_NONNULL_END
