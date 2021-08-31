//
//  HDKEntryPage.h
//  Hdk
//
//  Created by 陈威杰 on 2021/8/20.
//

#import <UIKit/UIKit.h>
@class HDKEntryPage;

NS_ASSUME_NONNULL_BEGIN

typedef void(^HDKDidPushViewControllerHandle)(UIViewController *viewController);

@protocol HDKEntryPageDelegate <NSObject>

/// 是否自己处理控制器页面跳转
- (BOOL)shouldCustomPushViewContrller;
/// push 需要的 控制器
- (void)entryPage:(HDKEntryPage *)entryPage didPushViewController:(UIViewController *)controller;

@end

@interface HDKEntryPage : NSObject

- (instancetype)initWithViewController:(UIViewController *)viewController;

@property (nonatomic, weak) id<HDKEntryPageDelegate> delegate;
@property (nonatomic, strong, readonly) UIViewController *viewController;

@end

NS_ASSUME_NONNULL_END
