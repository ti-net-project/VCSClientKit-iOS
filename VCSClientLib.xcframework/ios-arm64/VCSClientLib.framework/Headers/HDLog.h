//
//  HDLog.h
//  VCSClientLib
//
//  Created by houli on 2024/6/14.
//

#import <Foundation/Foundation.h>

//Debug
#define HDLogD(desStr) [HDLog logD:[NSString stringWithFormat:@"【HelpDesk-SDK】【Function】:%s 【Line】:【%d】 【Des】:\n%@",__func__,__LINE__,desStr],@""];
//Info
#define HDLogI(desStr) [HDLog logI:[NSString stringWithFormat:@"【HelpDesk-SDK】【Function】:%s 【Line】:%d 【Des】:\n%@",__func__,__LINE__,desStr],@""];
//Warning
#define HDLogW(desStr) [HDLog logW:[NSString stringWithFormat:@"【HelpDesk-SDK】【Function】:%s 【Line】:%d 【Des】:\n%@",__func__,__LINE__,desStr],@""];
//Error
#define HDLogE(desStr) [HDLog logE:[NSString stringWithFormat:@"【HelpDesk-SDK】【Function】:%s 【Line】:%d 【Des】:\n%@",__func__,__LINE__,desStr],@""];



//日志等级
typedef enum
{
    LOGLEVELV = 0,  //wend
    LOGLEVELD = 1,  //Debug
    LOGLEVELI = 2,  //Info
    LOGLEVELW = 3,  //Warning
    LOGLEVELE = 4,  //Error
} HDLogLevel;

@interface HDLog : NSObject

/**
 *  log初始化函数，在系统启动时调用
 */
+ (void)logIntial;

/**
 *  设置要记录的log级别
 *
 *  @param level level 要设置的log级别
 */
+ (void)setLogLevel:(HDLogLevel)level;

/**
 *  记录系统crash的Log函数
 *
 *  @param exception 系统异常
 */
+ (void)logCrash:(NSException*)exception;

/**
 *  log记录函数
 *
 *  @param level  log所属的等级
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logLevel:(HDLogLevel)level LogInfo:(NSString*)format,... NS_FORMAT_FUNCTION(2,3);

/**
 *  LOGLEVELV级Log记录函数
 *
 *  @param format format 具体记录log的格式以及内容
 */
+ (void)logV:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELD级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logD:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELI级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logI:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELW级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logW:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELE级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logE:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

@end
