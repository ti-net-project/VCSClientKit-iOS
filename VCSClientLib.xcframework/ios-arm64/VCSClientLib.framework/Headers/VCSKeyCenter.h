//
//  VCSKeyCenter.h
//  VCSClientLib
//
//  Created by houli on 2024/6/14.
//

#import <Foundation/Foundation.h>

@interface VCSKeyCenter : NSObject

/**
  声网 appid 访客端通过消息传过来
 */
@property (nonatomic, strong)  NSString * agoraAppid;

/**
 声网token 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * agoraToken;
/**
 声网channel 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * agoraChannel;
/**
 声网uid 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * agoraUid;
/**
 callid 访客端通过消息传过来
 */
@property (nonatomic, strong) NSString * callid;
/**
 屏幕分享id
 */
@property (nonatomic, strong) NSString * shareUid;
/**
 座席昵称
 */
@property (nonatomic, strong) NSString * agentNickName;
/**
 座席昵称
 */
@property (nonatomic, strong) NSString * agentUid;
/**
 访客昵称
 */
@property (nonatomic, strong) NSString * visitorNickName;
/**
 访客ID
 */
@property (nonatomic, strong) NSString                * visitorUid;
/**
  邀请座席昵称
 */
@property (nonatomic, strong) NSString *  invitationAgentNickName;

/**
  收到座席下发的消息 解析的值 后边访客给座席发消息要用到这个值
 */
@property (nonatomic, strong) NSString *  rtmChannel;
/**
 //当前通话设置的清晰度
//      1: '480p_1' 标清,
//      2: '720p_1' 高清,
//      3: '1080p_1 超高清'
 */
@property (nonatomic, assign) NSInteger  clarityType ;

//座席相关信息
@property (nonatomic, strong) NSDictionary *  agentTicket;
//共享相关信息
@property (nonatomic, strong) NSDictionary *  shareScreenTicket;

@end


