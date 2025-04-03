//
//  VCSCallLib.h
//  VCSClientLib
//
//  Created by houli on 2024/4/23.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSError.h>
#import <VCSClientLib/VCSMessage.h>
#import <VCSClientLib/VCSCallLibEventDelegate.h>
NS_ASSUME_NONNULL_BEGIN
/// RTC相关的配置信息
@interface VCSRTCInnerRegisterModel : NSObject

/// 企业id
@property(nonatomic, assign) NSInteger tenantId;

/// 访客唯一标识
@property(nonatomic, copy, nullable) NSString * name;

/// 声网AppId
@property(nonatomic, copy, nullable) NSString * appId;

/// 声网 rtmToken
@property(nonatomic, copy, nullable) NSString * token;

/// 声网 uid
@property(nonatomic, copy) NSString * uid;

/// 声网 channel
@property(nonatomic, copy) NSString * channel;

@end

/// Lib层通信单例类
@interface VCSCallLib : NSObject

/// RTC相关的配置类
@property (nonatomic, strong) VCSRTCInnerRegisterModel * innerRegisterModel;

/// 创建会话的时候会赋值
@property (nonatomic, strong) NSString * currentRtcSessionId;

/// 获取单例
+ (instancetype)shareCallLib;

/// 初始化RTM
-(void)initAgoraRTMModel:(VCSRTCInnerRegisterModel*)innerRegisterModel withSuccess:(void (^)(void))successBlock withError:(void (^)(VCSError *error))errorBlock;

/// 登录RTM
-(void)vcsLoginRTMWithToken:(NSString *)token Success:(void (^)(void))successBlock error:(void (^)(VCSError *error))errorBlock;

/// 发消息
- (void)vcsSendMessage:(VCSMessage *)aMessage
         completion:(void (^)(VCSError *aError))aCompletionBlock;

/// 重发消息
- (void)vcsResendMessage:(VCSMessage *)aMessage completion:(void (^)( VCSError *))aCompletionBlock;

/// 添加回调代理
- (void)vcsAddDelegate:(id<VCSCallLibEventDelegate>_Nullable)aDelegate delegateQueue:(dispatch_queue_t _Nullable )aQueue;

/// 移除回调代理
- (void)vcsRemoveDelegate:(id<VCSCallLibEventDelegate>_Nullable)aDelegate;

/// 获取渠道接入配置 接口地址:/api/vcs/vcs_visitor/function/setting
/// - Parameters:
///   - configId: 插件ID
///   - aCompletion: 操作回调
- (void)vcsInitSettingWithConfigId:(NSString *)configId Completion:(void (^)(id responseObject, VCSError * error))aCompletion;

/// 获取访客端初始化信息
/// - Parameters:
///   - configId: 插件ID
///   - visitorUid: 用户ID（访客ID）
///   - aCompletion: 操作回调
- (void)vcsGetVisitorInfoWithConfig:(NSString *)configId withVisitorUid:(NSString *)visitorUid WithCompletion:(void (^)(id responseObject, VCSError * error))aCompletion;

/// 根据uid获取通话中用户信息
/// - Parameters:
///   - configid: 插件ID
///   - sessionId: 会话ID
///   - uid: 用户的RTC的uid
///   - aCompletion: 请求回调
- (void)vcsGetUserInfo:(NSString *)configid withSessionId:(NSString *)sessionId withUid:(NSUInteger)uid WithCompletion:(void (^)(id responseObject, VCSError * error))aCompletion;

/// 加入房间事件上报
- (void)vcsJoinChannel:(VCSMessage *)message Completion:(void (^)(id responseObject, VCSError * error))aCompletion;

/// 离开房间事件上报
- (void)vcsleaveChannel:(VCSMessage *)message Completion:(void (^)(id responseObject, VCSError * error))aCompletion;

/// 座席发起回呼，访客响铃事件上报
- (void)vcsVisitorRinging:(VCSMessage *)message Completion:(void (^)(id responseObject, VCSError * error))aCompletion;

/// 创建视频邀请
- (void)vcsCreateVideoInviteMessage:(VCSMessage *)message withVisitorUid:(NSString *)visitorUid Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;

/// 结束视频会话。 未接通前 振铃放弃
- (void )vcsRingGiveUp:(VCSMessage *)message Completion:(void (^)(id responseObject, VCSError * error))aCompletion;

/// 排队人数 访客端
- (void)vcsGetVisitorCurrentWaitingSessionid:(NSString *)rtcSessionId withConfigId:(NSString *)configId Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;

/// 获取付费相关配置
- (void)vcsGetJgrayscaleJsonCompletion:(void (^)(id responseObject, VCSError *error))completion;

/// 访客挂断接口
- (void)vcsHangUpMessageTo:(NSString *)to Completion:(void (^)(VCSError *error))aCompletionBlock;

/// 发送文本消息
/// - Parameters:
///   - message: VCSMessage 对象Model
///   - messageData: 文本内容
///   - aCompletionBlock: 请求回调
- (void)vcsSendChatTextMessage:(VCSMessage *)message withMessageData:(NSDictionary *)messageData withCompletion:(void (^)(VCSError *error))aCompletionBlock;

/// 上传媒体资源
/// - Parameters:
///   - data: 上传的资源数据
///   - fileName: 资源名称
///   - mimeType: 资源类型
///   - type: 对应的后端类型
///   - aCompletionBlock: 上传回调
- (void)vcsUpdataWithFileData:(NSData *)data withFileName:(NSString *)fileName withMimeType:(NSString *)mimeType withType:(NSInteger)type withCompletion:(void (^)(id responseObject, VCSError * error))aCompletionBlock;

/// 电子签名事件上报
/// - Parameters:
///   - status: 事件状态
///   - params: 电子签名的其他参数
///   - aCompletion: 上报回调
- (void)vcsSignEvent:(NSInteger)status withParams:(NSDictionary *)params withCompletion:(void(^)(id  responseObject, VCSError *error))aCompletion;

/// 设备麦克风/摄像头异常事件上报
/// - Parameters:
///   - message: 消息体
///   - aCompletion: 上报回调
- (void)vcsDeviceError:(VCSMessage *)message withCompletion:(void(^)(id  responseObject, VCSError *error))aCompletion;

#pragma mark - 屏幕共享相关
/// 访客开启屏幕共享
- (void)vcsShareScreenStartMessageTo:(NSString *)to Completion:(void (^)(VCSError *error))aCompletionBlock;

/// 访客关闭屏幕共享
- (void)vcsShareScreenStopMessageTo:(NSString *)to Completion:(void (^)(VCSError *error))aCompletionBlock;


/// 上传sdk 版本及信息
//- (void)vcsUploadSdkVersionVisitorUserName:(NSString *)visitorUserName Completion:(void (^)(id responseObject, VCSError *error))completion;

/// 上传用户地区信息
- (void)vcsSaveVisitorRegionWithUserName:(NSString *)username WithCompletion:(void (^)(id responseObject, VCSError *error))completion;

/// 退出RTM登陆
- (void)vcsLogoutCompletion:(void (^)(VCSError *error))aCompletionBlock;

#pragma mark - 座席回呼相关
/// 访客同意 座席主动发过来的 视频邀请
- (void)vcsVisitorAcceptInvitationMessage:(VCSMessage *)message Completion:(void (^)(VCSError * error))aCompletion;

/// VISITOR_REJECT   访客拒接（振铃过程中访客主动挂断）
- (void)vcsVisitorRejectInvitationMessage:(VCSMessage *)message Completion:(void (^)(VCSError * error))aCompletion;

#pragma mark - 满意度相关
/// 访客提交评价
- (void)vcsSubmitVisitorEnquirySessionid:(NSString *)rtcSessionId withScore:(NSInteger)score withComment:(NSString *)comment withTagData:(NSArray *)tagData Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;


#pragma mark - 信息推送
/// 提交签名
- (void)vcsCommitSignData:(NSData *)data withImserviceNum:(NSString *)imServiceNum withFlowId:(NSString *)flowId Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;
/// 信息推送 上报接口
- (void)vcsPushBusinessReportImServiceNum:(NSString *)imServiceNum WithFlowId:(NSString *)flowId withAction:(NSString *)action  withType:(NSString *)type  withUrl:(NSString *)url withContent:(NSString *)content Completion:(void(^)(id  responseObject, VCSError *error))aCompletion;


/*!
 *  \~chinese
 *   vec 独立访客端 远程协助 回传状态
 *
 *  @- Parameter imserviceNum:   im服务号
 *  @- Parameter on: 事件
 *  @- Parameter aContent: 文本内容
 */
- (VCSMessage *)vcsVisitorCallBackStateCmdMessageWithImserviceNum:(NSString *)imserviceNum withOn:(BOOL)on  withAction:(NSString *)action content:(NSString *)aContent;

/*!
 *  \~chinese
 *   vec 访客端  获取视频超时 时间
 */
- (void)vcsGetVideoLineUpTimeOutCompletion:(void (^)(id responseObject, VCSError *error))completion;


/// 聊天频道订阅
- (void)subscribeChatChannel:(NSString *)channel;


/// 取消频道订阅
/// - Parameters:
///   - channel: 频道号
///   - completion: 取消订阅回调
- (void)vcsUnsubscribeWithChannel:(NSString *)channel withCompletion:(void (^)(id responseObject, VCSError *error))completion;


/// 获取RTM版本号
+ (NSString*)rtmSDKVersion;

#pragma mark ======================= 白板相关 =======================================
/// 加入白板
/// ⚠️当前版本未支持
- (void)joinWhiteBoardRoom:(NSString *)to Completion:(void (^)(VCSError *error))aCompletionBlock;

/// 文档上传
/// ⚠️当前版本未支持
- (void)whiteBoardUploadFileWithFilePath:(NSString *)filePath
                            fileData:(NSData *)data
                            fileName:(NSString *)fileName
                            mimeType:(NSString *)mimeType
                             progress:(void (^)(int64_t total, int64_t now)) progress
                            completion:(void(^)(id responseObject,VCSError *error))completion;


/// 文档转换
/// ⚠️当前版本未支持
- (void)vcs_wordConverterPptPage:(NSString *)url type:(nonnull NSString *)type completion:(nonnull void (^)(id _Nonnull, VCSError * _Nonnull))completion;

/// 文档转换进度
/// ⚠️当前版本未支持
- (void)vcs_wordConverterPptPageProgress:(NSString *)url type:(NSString *)type callId:(NSString *)callId taskId:(NSString *)taskid completion:(void (^)(id, VCSError *))completion;

/// 转码签名
/// ⚠️当前版本未支持
- (void)vcs_whiteConverterPptPage:(NSDictionary *) page completion:(void (^)(id _Nonnull responseObject, VCSError * _Nonnull error))completion;


@end

NS_ASSUME_NONNULL_END

