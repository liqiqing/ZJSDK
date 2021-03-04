//
//  CAIDError.h
//  CAIDSample
//
//  Created by CDA on 2020/9/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const CAIDErrorNone;
extern NSString *const CAIDErrorInitRSAInfo;
extern NSString *const CAIDErrorServerInfo;
extern NSString *const CAIDErrorAlreadyRequesting;

@interface CAIDError : NSObject

typedef enum CAIDErrorCode{
    
    CAIDErrorCodeNone = 0,             // 无错误
    CAIDErrorCodeInitError = 1001,     // 初始化错误
    CAIDErrorCodeServerError = 1002,   // 服务端报错
    CAIDErrorCodeAlreadyRequesting = 1003,   // CAID已经在拉取中
    
} CAIDErrorCode;

@property(nonatomic, assign) CAIDErrorCode code;
@property(nonatomic, copy) NSString *message;

+(CAIDError *)errorWithCode:(CAIDErrorCode)code message:(NSString *)format, ...;

-(void) print;

@end

NS_ASSUME_NONNULL_END
