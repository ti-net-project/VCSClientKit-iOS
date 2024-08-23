//
//  VCSClientKitConfig.h
//  VCSClientKit
//
//  Created by houli on 2024/5/16.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSInitOption.h>

NS_ASSUME_NONNULL_BEGIN
// 屏幕共享模块的配置信息
@interface VCSScreenShareOption : NSObject
//屏幕共享的ExtensionBundleId
@property (nonatomic, strong) NSString * screenShareExtensionBundleId;
//屏幕共享通信是通过appGroup通信appGroupName 就是在开发者账号上创建的appGroup的名字
@property (nonatomic, strong) NSString * appGroupName;
@end

/// 初始化配置类
@interface VCSKitInitOption : VCSInitOption
//TODO: 这里需要添加文档的地址，目前使用的是上海平台的域名代替的
/*!
 *  \~chinese
 *   需要屏幕共享时 要配置这个参数
 */
@property (nonatomic, strong) VCSScreenShareOption * shareOption;
@end

NS_ASSUME_NONNULL_END
