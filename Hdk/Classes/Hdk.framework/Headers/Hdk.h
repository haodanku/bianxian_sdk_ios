//
//  Hdk.h
//  Hdk
//
//  Created by 陈威杰 on 2021/8/9.
//

#import <UIKit/UIKit.h>
#import "HDKEntryPage.h"

typedef NS_ENUM(NSUInteger, HDKPageType) {
    /// 主页
    HDKPageTypeMain = 0,
};

NS_ASSUME_NONNULL_BEGIN

@interface Hdk : NSObject

/// 是否打开 log, default is NO
@property (nonatomic, assign, getter=isDebug) BOOL debug;

/// 宿主控制器
@property (nonatomic, readonly, weak) UIViewController * _Nullable hostController;


+ (Hdk *)shareInstance;

/// 注册 appKey， 异步
/// @param appKey 后台申请的 appKey
/// @param appSecret 后台申请的 appSecret
/// @param onResult 结果回调
- (void)initWithAppKey:(NSString *)appKey
             appSecret:(NSString *)appSecret
              onResult:(nullable void(^)(int code , NSString *message))onResult;

/// 打开页面
/// @param controller 控制器
- (BOOL)openIndexPageFromViewController:(UIViewController *)controller;

/// 关闭页面
/// 针对 -openIndexPageFromViewController: 方法弹出的页面
- (void)closePage;

/// 获取单页 
/// @param pageType 单页类型
- (nullable HDKEntryPage *)getSinglePage:(HDKPageType)pageType;

/// 获取 SDK 版本名
+ (NSString *)getVersionName;
/// 获取 SDK Build 版本号
+ (NSInteger)getBuildCode;



@end

NS_ASSUME_NONNULL_END
