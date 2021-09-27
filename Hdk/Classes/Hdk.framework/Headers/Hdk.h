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

/// 金刚区模块
typedef NS_ENUM(NSUInteger, HDKJumpNavType) {
    /// 京东模块
    HDKJumpNavTypeJD = 1,
    /// 拼多多模块
    HDKJumpNavTypePDD,
    /// 唯品会模块
    HDKJumpNavTypeVIP,
    /// 美团外卖模块
    HDKJumpNavTypeMeiTuan,
    /// 话费充值模块
    HDKJumpNavTypePhoneBill,
    /// 线报模块
    HDKJumpNavTypeXianBao,
    /// 防疫专区模块
    HDKJumpNavTypeEpidemic,
    /// 肯德基模块
    HDKJumpNavTypeKFC,
    /// 电影票模块
    HDKJumpNavTypeMovie,
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

/// 打开完整页面
/// @param controller 控制器
- (BOOL)openIndexPageFromViewController:(UIViewController *)controller;

/// 关闭页面
/// 针对 -openIndexPageFromViewController: 方法弹出的页面
- (void)closePage;

/// 获取单页 
/// @param pageType 单页类型
- (nullable HDKEntryPage *)getSinglePage:(HDKPageType)pageType;


/// 根据服务端返回的字段 jump 编码内容打开相应的页面
/// @param link 需要打开的链接
/// @param contentInsets 内容视图的内边距
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏）
/// @param viewController 用于 push 的控制器
- (void)openSinglePage:(NSString *)link
         contentInsets:(UIEdgeInsets)contentInsets
 contentViewController:(nullable Class)viewControllerClass
    fromViewController:(UIViewController *)viewController;

/// 根据服务端返回的字段 jump 编码内容打开相应的页面
/// @param link 需要打开的链接
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏）
/// @param viewController 用于 push 的控制器
- (void)openSinglePage:(NSString *)link
 contentViewController:(nullable Class)viewControllerClass
    fromViewController:(UIViewController *)viewController;

/// 根据服务端返回的字段 jump 编码内容打开相应的页面
/// @param link 需要打开的链接
/// @param viewController 用于 push 的控制器
- (void)openSinglePage:(NSString *)link fromViewController:(UIViewController *)viewController;





/// 打开金刚区某个模块
/// @param navType 模块类型
/// @param contentInsets 内容视图的内边距
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏）
/// @param viewController 用于 push 的控制器
- (void)jumpNav:(HDKJumpNavType)navType contentInsets:(UIEdgeInsets)contentInsets contentViewController:(nullable Class)viewControllerClass fromViewController:(UIViewController *)viewController;

/// 打开金刚区某个模块
/// @param navType 模块类型
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏）
/// @param viewController 用于 push 的控制器
- (void)jumpNav:(HDKJumpNavType)navType contentViewController:(nullable Class)viewControllerClass fromViewController:(UIViewController *)viewController;

/// 打开金刚区某个模块
/// @param navType 模块类型
/// @param viewController 用于 push 的控制器
- (void)jumpNav:(HDKJumpNavType)navType fromViewController:(UIViewController *)viewController;




/// 获取 SDK 版本名
+ (NSString *)getVersionName;
/// 获取 SDK Build 版本号
+ (NSInteger)getBuildCode;



@end

NS_ASSUME_NONNULL_END
