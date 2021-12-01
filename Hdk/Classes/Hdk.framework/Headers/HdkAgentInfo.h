//
//  HdkAgentInfo.h
//  Hdk
//
//  Created by Jie on 2021/11/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HdkAgentInfo : NSObject

+ (HdkAgentInfo *)infoWithUserId:(NSString *)userId;
+ (HdkAgentInfo *)infoWithUserId:(NSString *)userId nickname:(nullable NSString *)nickname;

/// 用户唯一标识，用于跟踪佣金，请确保唯一性！
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString * _Nullable nickname;

@end



NS_ASSUME_NONNULL_END
