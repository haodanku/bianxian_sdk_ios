//
//  HDKError.h
//  HDK_SDK
//
//  Created by 陈威杰 on 2021/8/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HDKError : NSObject

@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy)   NSString  *message;

@end

NS_ASSUME_NONNULL_END
