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




//@protocol VCSClientKitDelegate <NSObject>
//
//@optional
///// 返回当前呼叫页面的显示样式
///// - Parameter type: 显示枚举
//- (void)currentDisplayType:(VCSClientCallDisplayType)type;
//
//@end

/// SDK单例
@interface VCSClientKit : NSObject

///// 呼叫代理
//@property (nonatomic, weak) id <VCSClientKitDelegate>                delegate;
//

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

/**
 * sdk 版本号
 *  当前SDK的version
 */
+ (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
