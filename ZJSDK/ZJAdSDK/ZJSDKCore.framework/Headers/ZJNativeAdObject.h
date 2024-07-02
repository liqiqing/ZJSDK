//
//  ZJNativeAdObject.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/29.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ZJAdMaterialType) {
    ZJAdMaterialTypeUnkown      =       0,      // 未知
    ZJAdMaterialTypeVideo       =       1,      // 视频
    ZJAdMaterialTypeSingle      =       2,      // 单图
    ZJAdMaterialTypeAtlas       =       3,      // 多图
};
NS_ASSUME_NONNULL_BEGIN

@interface ZJNativeAdObject : NSObject

/**
 广告类型
 */
@property (nonatomic, readonly) ZJAdMaterialType materialType;


/**
 广告标题  部分广告没有title
 */
@property (nonatomic, copy, readonly) NSString *title;

/**
 广告描述
 */
@property (nonatomic, copy, readonly) NSString *desc;

/**
 广告大图Url
 */
@property (nonatomic, copy, readonly) NSString *imageUrl;

/**
 素材宽度，单图广告代表大图 imageUrl 宽度、多图广告代表小图 mediaUrlList 宽度
 */
@property (nonatomic, readonly) NSInteger imageWidth;

/**
 素材高度，单图广告代表大图 imageUrl 高度、多图广告代表小图 mediaUrlList 高度
 */
@property (nonatomic, readonly) NSInteger imageHeight;

/**
 多图广告的图片Url集合
 */
@property (nonatomic, copy, readonly) NSArray *mediaUrlList;

/**
 应用类广告App 图标Url
 */
@property (nonatomic, copy, readonly) NSString *iconUrl;

/**
 是否为应用类广告
 */
@property (nonatomic, readonly) BOOL isAppAd;
/**
 应用类广告App app名称
 */
@property (nonatomic, copy, readonly) NSString *appName;

/**
 应用类广告的星级（5星制度）
 */
@property (nonatomic, readonly) CGFloat appRating;



/**
 广告对应的CTA文案，自定义CTA视图时建议使用此字段
 广告对应的callToAction文案，比如“立即预约”或“电话咨询”, 自定义callToAction视图时建议使用此字段
 该字段在部分广告类型中可能为空
 */
@property (nonatomic, readonly) NSString *callToAction;

/**
返回广告是否可以跳过，用于做前贴片场景
@return YES 表示可跳过、NO 表示不可跳过
*/
@property (nonatomic, readonly) BOOL skippable;

/**
 * 视频广告时长，单位 ms
 */
@property (nonatomic, readonly) CGFloat duration;



@property (nonatomic, copy, readonly)NSString *platform;

/**
 * 返回广告的eCPM，广告加载成功后调用有效，单位：分
 
 * @return 成功返回一个大于等于0的值，
 *
 * @Discussion 返回信息说明：
 *
 * -1表示无权限或后台出现异常，
 *
 * -2表示当前广告类型暂不支持实时竞价。
 *
 * -3表示实时竞价二价获取失败，请在收到广告加载成功之后的回调后获取
 *
 * -4表示pd价格获取失败，请在收到广告加载成功之后的回调后获取
 *
 */
- (NSInteger)eCPM;




@end

NS_ASSUME_NONNULL_END
