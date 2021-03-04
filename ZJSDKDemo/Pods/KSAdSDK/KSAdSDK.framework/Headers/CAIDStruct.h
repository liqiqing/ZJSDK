//
//  CAIDStruct.h
//  CAIDSample
//
//  Created by CDA on 2020/12/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CAIDStruct : NSObject

// CAID
@property(nonatomic, copy) NSString *caid;

// CAID当前版本
@property(nonatomic, strong) NSNumber *version;

// 上个版本CAID
@property(nonatomic, copy) NSString *lastVersionCAID;

// 上个版本CAID对应的Version
@property(nonatomic, strong) NSNumber *lastVersion;


@end

NS_ASSUME_NONNULL_END
