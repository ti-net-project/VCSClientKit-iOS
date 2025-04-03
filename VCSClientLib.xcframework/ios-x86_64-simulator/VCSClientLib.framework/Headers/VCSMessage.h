//
//  VCSMessage.h
//  VCSClientLib
//
//  Created by houli on 2024/4/23.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, VCSMessageType) {
    /**cmd类型*/
    VCSMessageType_cmd    = 0,
};

/// 消息Event类型枚举
typedef NS_ENUM (NSInteger, VCSMessageEventType) {
    /**访客主动邀请视频*/
    VCSMessageEventType_liveStreamInvitation    = 0,
    /**访客取消邀请视频*/
    VCSMessageEventType_visitorCancelInvitation,
    /**通话中访客挂断电话*/
    VCSMessageEventType_calling_visitorHangup,
    /**座席回呼访客接受视频邀请*/
    VCSMessageEventType_callBack_visitorAcceptInvitation,
    /**座席回呼访客拒绝视频邀请*/
    VCSMessageEventType_callBack_visitorRejectInvitation,
    /**加入房间*/
    VCSMessageEventType_joinChannel,
    /**离开房间*/
    VCSMessageEventType_leaveChannel,
    /**访客侧响铃*/
    VCSMessageEventType_visitorRinging,
    /**访客开始屏幕共享*/
    VCSMessageEventType_shareScreenStart,
    /**访客结束屏幕共享*/
    VCSMessageEventType_shareScreenStop,
    /**访客主动发起白板*/
    VCSMessageEventType_whiteboardInvitaion,
    /**访客发送聊天消息*/
    VCSMessageEventType_SendChatMessage,
    /**访客电子签名操作成功*/
    VCSMessageEventType_SignSuccess,
    /**访客电子签名操作失败*/
    VCSMessageEventType_SignFail,
    /**访客取消电子签名操作*/
    VCSMessageEventType_SignCancel,
    
    
};
NS_ASSUME_NONNULL_BEGIN

/// 访客信息Model
@interface VCSVisitorInfo : NSObject
/// 真实名字 对应trueName
@property (nonatomic, copy) NSString* name;

/// 昵称 不能为空
@property (nonatomic, copy) NSString* nickName;

/// qq
@property (nonatomic, copy) NSString* qq;

/// 企业名称
@property (nonatomic, copy) NSString* companyName;

/// 电话
@property (nonatomic, copy) NSString* phone;

/// 描述
@property (nonatomic, copy) NSString* desc;

/// 邮箱
@property (nonatomic, copy) NSString* email;

/// 自定义字段传参集成用户信息 userDefineColumn: '{"WQQ":"帅哥","QAZ":"LLLLLLLTTTTTTTT"}',
@property (nonatomic, copy) NSString* userDefineColumn;

/// 自定义数据
@property (nonatomic, copy) NSMutableDictionary* customDic;

/// 当前属性的集合
-(NSMutableDictionary *)content;

@end

/// 消息Model
@interface VCSMessage : NSObject

/// 消息id
@property (nonatomic, copy) NSString *messageId;

/// 会话id
@property (nonatomic, copy) NSString *rtcSessionId;

/// 消息来自于哪里
@property (nonatomic, copy) NSString *from;

/// 消息送达到哪里
@property (nonatomic, copy) NSString *to;

/// 消息内容
@property (nonatomic, copy) NSString *text;

/// 消息事件类型
@property (nonatomic, assign) VCSMessageEventType eventMessageType;

/// 访客信息
@property (nonatomic, strong) VCSVisitorInfo *visitorInfo;

/*!
 *  \~chinese
 *  消息体
 *
 *  \~english
 *  Message body
 */
@property (nonatomic, strong) NSDictionary *body;

/*!
 *  \~chinese
 *  消息扩展
 *
 *  Key值类型必须是NSString, Value值类型必须是NSString或者 NSNumber类型的 BOOL, int, unsigned in, long long, double.
 *
 *  \~english
 *  Message extention
 *
 *  Key type must be NSString, Value type must be NSString or NSNumber of BOOL, int, unsigned in, long long, double.
 */
@property (nonatomic, copy) NSDictionary *ext;

- (void)addAttributeDictionary:(NSDictionary *)dic;
- (void)addMsgTypeDictionary:(NSDictionary *)dic;
- (void)addAttributeWithSessionExt:(NSDictionary *)dic;
- (void)addVisitorInfoContent:(NSDictionary *)dic;
@end

NS_ASSUME_NONNULL_END

