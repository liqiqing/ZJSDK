//
//  KSFeedAd.h
//  KSAdSDK
//
//  Created by xuzhijun on 2019/11/22.
//

#import <Foundation/Foundation.h>

#if __has_include(<KSUBaseAd/KSAd.h>)
#import <KSUBaseAd/KSAd.h>
#else
#import "KSAd.h"
#endif

#if __has_include(<KSUModel/KSAdInteractionType.h>)
#import <KSUModel/KSAdInteractionType.h>
#else
#import "KSAdInteractionType.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol KSFeedAdDelegate;

@interface KSFeedAd : KSAd

@property (nonatomic, readonly) UIView *feedView;

@property (nonatomic, weak) id<KSFeedAdDelegate> delegate;

- (void)setVideoSoundEnable:(BOOL)enable;

- (void)updatePlayStatusWithPercent:(CGFloat)percent;

@end

@protocol KSFeedAdDelegate <NSObject>
@optional
- (void)feedAdViewWillShow:(KSFeedAd *)feedAd;
- (void)feedAdDidClick:(KSFeedAd *)feedAd;
- (void)feedAdDislike:(KSFeedAd *)feedAd;
- (void)feedAdDidShowOtherController:(KSFeedAd *)nativeAd interactionType:(KSAdInteractionType)interactionType;
- (void)feedAdDidCloseOtherController:(KSFeedAd *)nativeAd interactionType:(KSAdInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END
