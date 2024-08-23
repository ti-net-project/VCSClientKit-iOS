//
//  VCSError.h
//  VCSClientLib
//
//  Created by houli on 2024/6/14.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSErrorCode.h>
/*!
 *  \~chinese
 *  SDK定义的错误
 *
 *  \~english
 *  SDK defined error
 */
@interface VCSError : NSObject
/*!
 *  \~chinese
 *  错误码
 *
 *  \~english
 *  Error code
 */
@property (nonatomic) VCSErrorCode code;

/*!
 *  \~chinese
 *  错误描述
 *
 *  \~english
 *  Error description
 */
@property (nonatomic, copy) NSString *errorDescription;


/*!
 *  \~chinese
 *  初始化错误实例
 *
 *  @param aDescription  错误描述
 *  @param aCode         错误码
 *
 *  @result 错误实例
 *
 *  \~english
 *  Initialize an error instance
 *
 *  @param aDescription  Error description
 *  @param aCode         Error code
 *
 *  @result Error instance
 */
- (instancetype)initWithDescription:(NSString *)aDescription
                               code:(VCSErrorCode)aCode;

/*!
 *  \~chinese
 *  创建错误实例
 *
 *  @param aDescription  错误描述
 *  @param aCode         错误码
 *
 *  @result 对象实例
 *
 *  \~english
 *  Create a error instance
 *
 *  @param aDescription  Error description
 *  @param aCode         Error code
 *
 *  @result Error instance
 */
+ (instancetype)errorWithDescription:(NSString *)aDescription
                                code:(VCSErrorCode)aCode;

/*!
 *  \~chinese
 *  创建错误实例 后台把错误的信息 都放到了 接口请求失败的回调里了 如果需要获取具体信息和状态码 请使用这个方法
 *
 *  @param error   请求返回的错误实例

 *  @result 对象实例
 *
 *  \~english
 *  Create a error instance
 *
 *  @param error  Error instance
 *
 *  @result Error instance
 */
+ (instancetype)errorWithDescription:(NSError*)error;
@end
