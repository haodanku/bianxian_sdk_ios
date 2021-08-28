//
//  HDKEntryPage.h
//  Hdk
//
//  Created by 陈威杰 on 2021/8/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HDKEntryPage : NSObject

- (instancetype)initWithViewController:(UIViewController *)viewController;

@property (nonatomic, strong, readonly) UIViewController *viewController;

@end

NS_ASSUME_NONNULL_END
