//
//  NetService.h
//  ZJSDKCoreFramewrok
//
//  Created by Robin on 2021/1/16.
//

#import <Foundation/Foundation.h>

typedef void (^DataRequestSuccessBlock)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject);
typedef void (^DataRequestFailureBlock)(NSURLSessionDataTask * _Nonnull task, NSError * _Nonnull error);
#define InvokeSuccess(task,obj)    {if(success) dispatch_async(dispatch_get_main_queue(), ^{success(task,obj);});}
#define InvokeFailure(task,err)    {if(failure) dispatch_async(dispatch_get_main_queue(), ^{failure(task,err);});}

NS_ASSUME_NONNULL_BEGIN

@interface ZJBaseNetService : NSObject



+(NSURLSessionDataTask*) getData:(NSString*)urlStr
                      parameters:(nullable NSDictionary*)parameters
                         success:(DataRequestSuccessBlock)success
                         failure:(DataRequestFailureBlock)failure;

+(NSURLSessionDataTask*) getDataInput:(NSString*)urlStr
                           parameters:(NSDictionary*)parameters
                              success:(DataRequestSuccessBlock)success
                              failure:(DataRequestFailureBlock)failure;

+(NSURLSessionDataTask*) postData:(NSString*)urlStr
                       parameters:(NSDictionary*)parameters
                          success:(DataRequestSuccessBlock)success
                          failure:(DataRequestFailureBlock)failure;

+(NSURLSessionDataTask*) encryptPostData:(NSString*)urlStr
                       parameters:(NSDictionary*)parameters
                          success:(DataRequestSuccessBlock)success
                         failure:(DataRequestFailureBlock)failure;

+(NSURLSessionDataTask*) putData:(NSString*)urlStr
                       parameters:(NSDictionary*)parameters
                          success:(DataRequestSuccessBlock)success
                         failure:(DataRequestFailureBlock)failure;


+(NSURLSessionDataTask*) encryptPutData:(NSString*)urlStr
                       parameters:(NSDictionary*)parameters
                          success:(DataRequestSuccessBlock)success
                         failure:(DataRequestFailureBlock)failure;



+(NSDictionary*) buildParameters:(NSDictionary*) source;
@end

NS_ASSUME_NONNULL_END
