//
//  HDKEntryElement.h
//  Hdk
//
//  Created by YIC on 2021/11/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, HDKEntryElementType) {
    /// 今日值得买
    HDKEntryElementTypeTodayBuy = 0,
    /// 外卖瓷片区
    HDKEntryElementTypeTakeaway = 1
};



@protocol HDKEntryElementDelegate;

@interface HDKEntryElement : NSObject

/// 入口组件视图 entryElementSuccessToLoad 成功时获取
@property (nonatomic, strong, readonly, nullable) UIView *entryView;
/// 入口组件 size 大小 entryElementSuccessToLoad 成功时获取
@property (nonatomic, assign, readonly) CGSize entryExpectedSize;
/// 入口组件视图内边距 默认 padding 上下左右 为0，在 loadData之前配置
@property (nonatomic, assign) UIEdgeInsets entryPadding;
/// 入口组件默认为屏幕宽度，在 loadData之前配置
@property (nonatomic, assign) CGFloat expectedWidth;
/// 入口组件视图圆角 在 loadData之前配置
@property (nonatomic, assign) CGFloat entryCornerRadius;
/// 是否自动滚动,默认Yes 在 loadData之前配置
@property (nonatomic,assign) BOOL autoScroll;
/// 回调代理
@property (nonatomic, weak) id<HDKEntryElementDelegate> delegate;




/// 初始化设置组件类型
/// @param entryType 组件类型
- (HDKEntryElement *)initWithEntryType:(HDKEntryElementType)entryType NS_DESIGNATED_INITIALIZER;
- (HDKEntryElement *)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// 数据请求加载，通过代理回调
/// 1.连续多次调用,仅第一次生效
/// 2.回调成功或者失败后,外部自行选择合适时机可以再次调用,进行刷新或重试操作
- (void)loadData;

@end

@protocol HDKEntryElementDelegate <NSObject>

@required
/// 成功回调通知
/// 通过 entryView 获取具体的视图 entryExpectedSize 为期望的宽高
- (void)entryElementSuccessToLoad:(HDKEntryElement *)entryElement;


@optional
/// 失败回调
- (void)entryElement:(HDKEntryElement *)entryElement didFailWithError:(NSError *_Nullable)error;

/// 用来 Push 内容控制器的宿主控制器
- (nullable UIViewController *)hostControllerForEntryElement:(HDKEntryElement *)entryElement;

/// 内容控制器类型 (监听控制器生命周期 ,可用于导航栏的显示或隐藏)
- (nullable Class)contetnViewControllerClassForEntryElement:(HDKEntryElement *)entryElement;

/// 内容视图的内边距
- (UIEdgeInsets)edgeInsetsForEntryElement:(HDKEntryElement *)entryElement;


 
@end

NS_ASSUME_NONNULL_END
