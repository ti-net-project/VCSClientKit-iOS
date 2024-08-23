//
//  NSMutableDictionary+HDKit.h
//  VCSClientLib
//
//  Created by houli on 2024/6/14.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (HDKit)

/*
 判断字典赋值不为空
 
 @param value  字典value
 @param key    字典key
 @return 无
 */

- (void)hd_setValue:(id)value forKey:(NSString *)key;


@end
