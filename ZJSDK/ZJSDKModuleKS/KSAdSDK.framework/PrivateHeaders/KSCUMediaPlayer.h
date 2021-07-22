//
//  KSCUMediaPlayer.h
//  KSAdSDK
//
//  Created by jie cai on 2020/7/13.
//
#import "KSCUPlayerSDK.h"
#if HAS_IMPORT_KSMediaPlayer
#import <Foundation/Foundation.h>
#import <KSCUPlayer/KSCUPlayerProtocol.h>

NS_ASSUME_NONNULL_BEGIN
/// 集成 KSMediaPlayer 播放器
@interface KSCUMediaPlayer : NSObject<KSCUPlayerProtocol>

+ (void)configNativeCache;

@end

NS_ASSUME_NONNULL_END
#endif

