//
//  HdkNavigateModel.h
//  Hdk
//
//  Created by YIC on 2021/11/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HdkNavigateModel : NSObject
/// sdk内部保留属性, 请勿改动
@property (nonatomic,assign) BOOL isSinglePage;
/// 打开模块需要的参数 (例如打开钱包的参数 model.params = @{@"token":@"token值"})
@property (nonatomic,copy) NSDictionary *params;
@end

NS_ASSUME_NONNULL_END
