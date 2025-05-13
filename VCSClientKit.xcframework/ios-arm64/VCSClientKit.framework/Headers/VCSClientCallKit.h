//
//  VCSClientCallKit.h
//  VCSClientKit
//
//  Created by houli on 2024/5/15.
//

#import <Foundation/Foundation.h>
#import <VCSClientKit/VCSCallModel.h>
#import <VCSClientKit/VCSKitInitOption.h>
NS_ASSUME_NONNULL_BEGIN



/*!
 * Kit层代理协议
 */
@protocol VCSClientKitDelegate <NSObject>

@optional

/// \~chinese 需要Toast的文案
///
/// \~english Need Toast copywriting
/// - Parameter toastText: 文案字符串
- (void)VCSClientKitToastText:(NSString *)toastText;

@end

/*!
 * SDK单例，
 * 用于初始化SDK、
 * 登录/登出/发起视频、
 * 获取当前SDK的版本号等操作。
 */
@interface VCSClientKit : NSObject

/// kit层代理协议
@property (nonatomic, weak) id <VCSClientKitDelegate>                delegate;

/// 获取SDK实例
+ (instancetype)shareKit;

/*!
 *  初始化sdk kit
 */
- (void)initWithOption:(VCSKitInitOption *)option;

/**
 *  登录
 * 用户 App 的 userID（为空的情况下，会进入errorBlock回调 ，不可包含中文或特殊符号，建议使用用户系统 ID 方便 APP 拓展功能）
 */
- (void)loginWithVisitorId:(NSString *_Nonnull)visitorId Success:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

/**
 *  退出登录
 */
- (void)logout:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

/**
 * 发起视频邀请
 */
- (void)videoCall:(VCSCallModel *_Nonnull)model Success:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

/// 开启画中画(设备系统为iOS 15+以上)
- (void)startPictureInPicture;

/// 停止画中画
- (void)stopPictureInPicture;
/**
 * SDK版本号
 * 当前SDK的version
 */
+ (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
