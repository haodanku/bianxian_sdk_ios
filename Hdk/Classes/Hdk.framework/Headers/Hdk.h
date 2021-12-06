//
//  Hdk.h
//  Hdk
//
//  Created by 陈威杰 on 2021/8/9.
//

#import <UIKit/UIKit.h>
#import "HDKEntryPage.h"
#import "HDKEntryElement.h"
#import "HdkAgentInfo.h"
#import "HdkNavigateModel.h"
#import "HdkNavigate.h"
#import "HdkNavigateCenter.h"

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

typedef NS_ENUM(NSUInteger, HDKModulePage) {
    /// 钱包模块
    HDKModulePageWallet
};

NS_ASSUME_NONNULL_BEGIN

@interface Hdk : NSObject

/// 宿主控制器
@property (nonatomic, readonly, weak) UIViewController * _Nullable hostController;

/// 是否打开 log, default is NO
@property (nonatomic, assign, getter=isDebug) BOOL debug;

/// 设置用户标识符（用户归因）
@property (nonatomic, copy) HdkAgentInfo * _Nullable userInfo;


+ (Hdk *)shareInstance;

/// 注册 appKey， 异步
/// @param appKey 后台申请的 appKey
/// @param onResult 结果回调
- (void)initWithAppKey:(NSString *)appKey
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


#pragma mark - 根据服务端返回的 jump 字段内容打开页面

/// 根据服务端返回的字段 jump 编码内容打开相应的页面
/// @param link 需要打开的链接
/// @param contentInsets 内容视图的内边距
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param viewController 用于 push 的控制器
- (void)openSinglePage:(NSString *)link
         contentInsets:(UIEdgeInsets)contentInsets
 contentViewController:(nullable Class)viewControllerClass
    fromViewController:(nullable UIViewController *)viewController;

/// 根据服务端返回的字段 jump 编码内容打开相应的页面
/// @param link 需要打开的链接
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param viewController 用于 push 的控制器
- (void)openSinglePage:(NSString *)link
 contentViewController:(nullable Class)viewControllerClass
    fromViewController:(nullable UIViewController *)viewController;

/// 根据服务端返回的字段 jump 编码内容打开相应的页面
/// @param link 需要打开的链接
/// @param viewController 用于 push 的控制器
- (void)openSinglePage:(NSString *)link fromViewController:(nullable UIViewController *)viewController;

/// 根据服务端返回的字段 jump 编码内容打开相应的页面
/// @param link 需要打开的链接
- (void)openSinglePage:(NSString *)link;


#pragma mark - 打开金刚区某个模块

/// 打开金刚区某个模块
/// @param navType 模块类型
/// @param contentInsets 内容视图的内边距
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param viewController 用于 push 的控制器
- (void)jumpNav:(HDKJumpNavType)navType contentInsets:(UIEdgeInsets)contentInsets contentViewController:(nullable Class)viewControllerClass fromViewController:(nullable UIViewController *)viewController;

/// 打开金刚区某个模块
/// @param navType 模块类型
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param viewController 用于 push 的控制器
- (void)jumpNav:(HDKJumpNavType)navType contentViewController:(nullable Class)viewControllerClass fromViewController:(nullable UIViewController *)viewController;

/// 打开金刚区某个模块
/// @param navType 模块类型
/// @param viewController 用于 push 的控制器
- (void)jumpNav:(HDKJumpNavType)navType fromViewController:(nullable UIViewController *)viewController;

/// 打开金刚区某个模块
/// @param navType 模块类型
- (void)jumpNav:(HDKJumpNavType)navType;


#pragma mark - 通过一些参数打开模块页面

/// 打开模块页面
/// @param modulePage 模块类型
/// @param parameters 打开模块需要的参数（钱包模块需要 token 如 @{ @"token" : "..."}, 详见接入文档）
- (void)openModule:(HDKModulePage)modulePage parameters:(NSDictionary *)parameters;

/// 打开模块页面
/// @param modulePage 模块类型
/// @param parameters 打开模块需要的参数（钱包模块需要 token 如 @{ @"token" : "..."}, 详见接入文档）
/// @param requestState 加载状态，isLoading 为 YES 表示正在加载，反之加载完毕
- (void)openModule:(HDKModulePage)modulePage
        parameters:(NSDictionary *)parameters
      requestState:(nullable void(^)(BOOL isLoading))requestState;


/// 打开模块页面
/// @param modulePage 模块类型
/// @param parameters 打开模块需要的参数（钱包模块需要 token 如 @{ @"token" : "..."}, 详见接入文档）
/// @param contentInsets 内容内边距
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param requestState 加载状态，isLoading 为 YES 表示正在加载，反之加载完毕
- (void)openModule:(HDKModulePage)modulePage parameters:(NSDictionary *)parameters
                                          contentInsets:(UIEdgeInsets)contentInsets
                                  contentViewController:(nullable Class)viewControllerClass
                                           requestState:(nullable void(^)(BOOL isLoading))requestState;

/// 打开模块页面
/// @param modulePage 模块类型
/// @param parameters 打开模块需要的参数（钱包模块需要 token 如 @{ @"token" : "..."}, 详见接入文档）
/// @param contentInsets 内容内边距
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param fromViewController 用于 push 的控制器
/// @param requestState 加载状态，isLoading 为 YES 表示正在加载，反之加载完毕
- (void)openModule:(HDKModulePage)modulePage parameters:(NSDictionary *)parameters
                                          contentInsets:(UIEdgeInsets)contentInsets
                                  contentViewController:(nullable Class)viewControllerClass
                                     fromViewController:(nullable UIViewController *)fromViewController
                                           requestState:(nullable void(^)(BOOL isLoading))requestState;

/// 页面点击事件 (通过该方法打开页面)
/// @param modulePage 模块类型
/// @param model 打开模块需要的参数（钱包模块需要 token 如 @{ @"token" : "..."}, 详见接入文档）
/// @param contentInsets 内容内边距（只对接入的单页有效）
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param fromViewController 用于 push 的控制器
- (void)eventClick:(HDKModulePage)modulePage model:(HdkNavigateModel *)model
                                     contentInsets:(UIEdgeInsets)contentInsets
                             contentViewController:(nullable Class)viewControllerClass
                                fromViewController:(nullable UIViewController *)fromViewController;

/// 页面点击事件 (通过该方法打开页面)
/// @param modulePage 模块类型
/// @param model 打开模块需要的参数（钱包模块需要 token 如 @{ @"token" : "..."}, 详见接入文档）
/// @param viewControllerClass 内容控制器类型（监听控制器生命周期、可用于导航栏的显隐藏），默认隐藏导航栏，消失显示导航栏
/// @param fromViewController 用于 push 的控制器
- (void)eventClick:(HDKModulePage)modulePage model:(HdkNavigateModel *)model
                             contentViewController:(nullable Class)viewControllerClass
                                fromViewController:(nullable UIViewController *)fromViewController;

#pragma mark - 版本号获取

/// 获取 SDK 版本名
+ (NSString *)getVersionName;
/// 获取 SDK Build 版本号
+ (NSInteger)getBuildCode;



@end

NS_ASSUME_NONNULL_END
