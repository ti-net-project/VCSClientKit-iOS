//
//  VCSCallLibEventDelegate.h
//  VCSClientLib
//
//  Created by houli on 2024/5/13.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSMessage.h>
#import <VCSClientLib/VCSKeyCenter.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Lib层事件代理协议
 */
@protocol VCSCallLibEventDelegate <NSObject>

@optional

/// 收到消息的回调
- (void)messagesDidReceive:(VCSMessage *)aMessages;

/*!
 *  \~chinese
 *  收到VCS 创建视频会话的事件 只有访客主动发起的时候才会通知
 *  @param parameter   视频会话创建的参数
 */
- (void)onTicketDidReceiveRtcSessionCreateEvent:(NSDictionary *)parameter;

/*!
 *  \~chinese
 *  接收到访客主动发起的视频请求
 *  @param keyCenter   创建视频请求必要的参数
 *  @param message: 消息体
 */
- (void)onCallReceivedVisitorParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  接收到座席主动发起的视频请求
 *  @param keyCenter   创建视频请求必要的参数
 *  @param message: 消息体
 */
- (void)onCallReceivedAgentParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  座席回呼 主动发起的视频请求 确认事件
 */
- (void)onCallReceivedAgentSureParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  座席回呼  取消回呼
 */
- (void)onCallReceivedAgentCancelCallBackParameter:(VCSKeyCenter *)keyCenter withMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  通话中 座席主动挂断
 */
- (void)onCallReceivedAgentHangUpMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *  通话中 监控关闭通话
 */
- (void)onCallReceivedMonitorCloseMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *    通话中异常参数
 */
- (void)onCallReceivedExceptionMessage:(VCSMessage*)message;

/*!
 *  \~chinese
 *    第三方座席进来 获取对应的座席信息
 *  @param thirdAgentNickName   座席昵称
 *  @param uid 用户ID
 *  @param message 消息体
 *
 *  \~english
 *    Receiving a Video request
 *
 */
- (void)onCallReceivedInvitation:(NSString *)thirdAgentNickName withUid:(NSString *)uid withMessage:(VCSMessage *)message;
/*!
 *  \~chinese
 *     VCS 独立访客端 收到 座席拒绝的通知
 *
 */
- (void)onCallHangUpInvitationWithMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *     VCS 独立访客端 收到 座席响铃超时未接听的通知
 *
 */
- (void)onCallAgentRingTimeoutMessage:(VCSMessage*)message;


/*!
 *  \~chinese
 *     VCS 独立访客端 收到 座席信息推送
 *
 */
- (void)onCallLinkMessagePush:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *     VCS 独立访客端 收到 ocr 识别
 *
 */
- (void)onCallLOcrIdentify:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *     VCS 独立访客端 收到 身份认证
 *
 */
- (void)onCallFaceIdentify:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *     VCS 独立访客端 收到 数字签名
 *
 */
- (void)onCallSignIdentify:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *   收到满意度
 */
- (void)onEnquiryInviteParameter:(NSDictionary *)enquiryInvite withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *   远程控制 -> 麦克风 通知
 */
- (void)onMuteLocalAudioStreamParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *   远程控制 -> 摄像头
 */
- (void)onMuteLocalVideoStreamParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *   远程控制 -> 切换摄像头
 */
- (void)onSwitchCameraParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *   远程控制 -> 对焦
 */
- (void)onFocusingOnParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *    flashlight
 *    远程控制 -> 手电筒
 */
- (void)onFlashlightParameter:(NSDictionary *)dic withMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *    VCSNewChatMsg
 *    视频通话中有新消息进来的cmd通知
 */
- (void)onVCSNewChatCMDMsgWithMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *    VCSNewChatMsg
 *    视频排队 超时 接收到的cmd 通知
 */
- (void)onVCSWaitTimeoutCloseKefuRtcWaitCallMsgWithMessage:(VCSMessage *)message;

/*!
 *  \~chinese
 *       视频通话中 收到消息的通知
 *  @param aMessages  消息列表<VCSMessage>
 */
- (void)on_VCSMessagesDidReceive:(NSArray<VCSMessage *> *)aMessages;

/**
 * 引擎全局内错误信息事件回调
 *
 * @param errorCode         错误码
 * @param errorMessage   错误描述
 */
- (void)onError:(VCSErrorCode)errorCode errorMessage:(nonnull NSString *)errorMessage;

/**
 * 白板 加入房间必要参数
 * ⚠️当前版本未支持
 */

- (void)onRoomDataReceivedParameter:(NSDictionary *)roomData;


@end

NS_ASSUME_NONNULL_END


