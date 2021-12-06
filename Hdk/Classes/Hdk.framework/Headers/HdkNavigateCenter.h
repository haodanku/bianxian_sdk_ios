//
//  HdkNavigateCenter.h
//  Hdk
//
//  Created by YIC on 2021/11/30.
//

#import <Foundation/Foundation.h>
#import "HdkNavigate.h"

NS_ASSUME_NONNULL_BEGIN

@interface HdkNavigateCenter : NSObject

+ (HdkNavigateCenter *)shareInstance;

///注册 (通过注册跳转器来实现监听)
- (void)registerNavigate:(HdkNavigate *)navigate;
@end

NS_ASSUME_NONNULL_END

