//
//  Hdk.h
//  HDK_SDK
//
//  Created by 陈威杰 on 2021/8/9.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface Hdk : NSObject

/// 是否打开 log, default is NO
@property (nonatomic, assign, getter=isDebug) BOOL debug;

/// 宿主控制器
@property (nonatomic, readonly, weak) UIViewController *hostController;


+ (Hdk *)shareInstance;

/// 注册 appKey
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
- (void)closePage;

/// 获取 SDK 版本
+ (NSString *)getSDKVersion;



/**
 该方法返回一个 UITabBarController 控制器，如果 SDK 初始化失败，方法返回 nil
 
 注意：该方法每调用一次都会返回一个全新的 UITabBarController。
 */
//- (nullable UITabBarController *)getMainController;

@end

NS_ASSUME_NONNULL_END
