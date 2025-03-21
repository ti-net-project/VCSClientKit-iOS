//
//  VCSOptions.h
//  VCSClientLib
//
//  Created by houli on 2024/4/24.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/// 初始化SDK的Model类
@interface VCSInitOption : NSObject
//TODO: 这里需要添加文档的地址，目前使用的是上海平台的域名代替的
/**
 *  \~chinese
 *   客服服务器地址
 *   只能在[VCSClient initializeSDKWithOptions:]中设置，不能在程序运行过程中动态修改
 *
 *  \~english
 *   Server address
 *   It can only be set in [VCClient initialized SDK WithOptions:] and cannot be dynamically modified during program execution
 */
@property (nonatomic,copy) NSString *rtcEndpoint;

/*!
 *  \~chinese
 *  插件配置id
 *
 *  \~english
 *  config Id
 */
@property (nonatomic,copy) NSString *configId;

/*!
 *  \~chinese
 *  控制台是否输出log, 默认为NO
 *
 *  \~english
 *  Whether print log to console, default is NO
 */
@property (nonatomic, assign) BOOL enableConsoleLog;

/*!
 *  \~chinese
 *   是否开启观测云, 默认为YES
 *
 *   \~english
 *   Is it enabled guance, default is NO
 */
@property (nonatomic, assign) BOOL enableFTMobileSDK;

/*!
 *  \~chinese
 *   附加参数
 *
 *  \~english
 *   Additional parameters
 *
 */
@property(nonatomic, readwrite) NSDictionary *advanceParams;

@end

NS_ASSUME_NONNULL_END
