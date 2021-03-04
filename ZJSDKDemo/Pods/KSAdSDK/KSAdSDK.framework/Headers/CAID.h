//
//  CAID.h
//  CAIDSample
//
//  Created by CDA on 2020/8/26.
//

#import <Foundation/Foundation.h>
#import "CAIDError.h"
#import "CAIDStruct.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^CAIDCallback)(CAIDError *error, CAIDStruct *caidStruct);

@interface CAID : NSObject

// 初始化，传入APPID和公钥
+(instancetype) initCAID:(NSString *)devId pubKey:(NSString *)pubKey;

/*
 * 异步方式请求服务端获取CAID数据，当前线程结束。
 * callback返回结果中回传错误信息和CAID数据
 * CAID数据中包含
 *  1. 当前版本CAID
 *  2. 当前CAID版本号
 *  3. 上一个版本CAID
 *  4. 上一个版本CAID对应版本号
 */
-(void)getCAIDAsyncly:(CAIDCallback)callback;

@end

NS_ASSUME_NONNULL_END
