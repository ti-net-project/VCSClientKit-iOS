//
//  VCSCallModel.h
//  VCSClientKit
//
//  Created by houli on 2024/6/14.
//

#import <Foundation/Foundation.h>
#import <VCSClientLib/VCSClientLib.h>
NS_ASSUME_NONNULL_BEGIN

@interface VCSCallModel : NSObject
//访客id 必传字段
@property (nonatomic, strong) NSString *visitorId;
//访客信息
@property (nonatomic, strong) VCSVisitorInfo *visitorInfo;
//业务标识
@property (nonatomic, strong) NSDictionary *serviceIdentification;
//访客vip 标签
@property (nonatomic, strong) NSDictionary *vipTags;
//扩展字段
@property (nonatomic, strong) NSDictionary *parameters;
//透传消息内容
@property (nonatomic, strong) NSString *text;
@end

NS_ASSUME_NONNULL_END
