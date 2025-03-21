//
//  HDLog.h
//  VCSClientLib
//
//  Created by houli on 2024/6/14.
//

#import <Foundation/Foundation.h>

/*!
 * Debug 调试
 */
#define HDLogD(desStr) [HDLog logD:[NSString stringWithFormat:@"【VCS-SDK】【Function】:%s 【Line】:【%d】 【Des】:\n%@",__func__,__LINE__,desStr],@""];
/*!
 * Info 信息
 */
#define HDLogI(desStr) [HDLog logI:[NSString stringWithFormat:@"【VCS-SDK】【Function】:%s 【Line】:%d 【Des】:\n%@",__func__,__LINE__,desStr],@""];
/*!
 * Warning 警告
 */
#define HDLogW(desStr) [HDLog logW:[NSString stringWithFormat:@"【VCS-SDK】【Function】:%s 【Line】:%d 【Des】:\n%@",__func__,__LINE__,desStr],@""];
/// Error
/*!
* Error 错误
*/
#define HDLogE(desStr) [HDLog logE:[NSString stringWithFormat:@"【VCS-SDK】【Function】:%s 【Line】:%d 【Des】:\n%@",__func__,__LINE__,desStr],@""];



/*!
 * 日志等级
 * Debug模式下：等级大于等于LOGLEVELD级别才会进行上报记录
 * Release模式下：等级大于等于LOGLEVELI级别才会进行上报记录
 */
typedef enum
{
    /// wend
    LOGLEVELV = 0,
    /// Debug 调试
    LOGLEVELD = 1,
    /// Info 信息
    LOGLEVELI = 2,
    /// Warning 警告
    LOGLEVELW = 3,
    /// Error 错误
    LOGLEVELE = 4,
} HDLogLevel;

/*!
 * 日志处理单例，用来记录重要节点的数据，并配合观测云进行数据上报
 */
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
