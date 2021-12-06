//
//  HdkNavigate.h
//  Hdk
//
//  Created by YIC on 2021/11/30.
//

#import <Foundation/Foundation.h>
#import "HdkNavigateModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface HdkNavigate : NSObject

/// 监听页面点击事件 (接入方继承HdkNavigate , 重写该方法, 在这里根据实现点击返回的类型进行相关操作，例如跳转钱包页面等..)
/// @param keyword 关键字 (目前支持钱包按钮关键字：wallet )
/// @param model 页面数据 (接入方在此将构建的数据赋值给model.params 例如钱包 model.params = @{@"token":@"token值"})
- (void)navigate:(NSString *)keyword model:(HdkNavigateModel *)model;

@end

NS_ASSUME_NONNULL_END
