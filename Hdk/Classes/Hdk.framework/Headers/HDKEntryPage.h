//
//  HDKEntryPage.h
//  Hdk
//
//  Created by 陈威杰 on 2021/8/20.
//

#import <UIKit/UIKit.h>
@class HDKEntryPage;

NS_ASSUME_NONNULL_BEGIN

@protocol HDKEntryPagePushDelegate <NSObject>


@optional
/// 用来 Push 内容控制器的宿主控制器
- (nullable UIViewController *)hostControllerForEntryPage:(HDKEntryPage *)entryPage;
/// 返回自定义内容控制器（可在此控制器监听控制器生命周期、用于导航栏的显隐藏，添加自定义视图）
- (nullable Class)contentViewControllerClassEntryPage:(HDKEntryPage *)entryPage;
/// 返回内容视图的内边距，默认布局在安全区域内
- (UIEdgeInsets)edgeInsetsForEntryPage:(HDKEntryPage *)entryPage;

@end


@protocol HDKEntryPageDelegate <NSObject>

/// 是否自己处理控制器页面跳转
- (BOOL)shouldCustomPushViewContrller;

/// Push 控制器
- (void)entryPage:(HDKEntryPage *)entryPage didPushViewController:(UIViewController *)controller;

@end

@interface HDKEntryPage : NSObject

- (instancetype)initWithViewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, weak) id<HDKEntryPageDelegate> delegate DEPRECATED_MSG_ATTRIBUTE("推荐使用 -setPushDelegate:");
@property (nonatomic, weak) id<HDKEntryPagePushDelegate> pushDelegate;
@property (nonatomic, strong, readonly) UIViewController *viewController;

@end

NS_ASSUME_NONNULL_END
