//
//  FQNavigationController.m
//  HDKDemo
//
//  Created by 陈威杰 on 2021/8/9.
//

#import "FQNavigationController.h"

@interface FQNavigationController ()

@end

@implementation FQNavigationController

//- (void)viewDidLoad {
//    [super viewDidLoad];
//    // Do any additional setup after loading the view.
//}


#pragma mark -
- (BOOL)shouldAutorotate {
    return self.topViewController.shouldAutorotate;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return self.topViewController.supportedInterfaceOrientations;
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
    return [self.topViewController preferredInterfaceOrientationForPresentation];
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return self.topViewController.preferredStatusBarStyle;
}

- (BOOL)prefersStatusBarHidden{
    return self.topViewController.prefersStatusBarHidden;
    
}


#pragma mark -

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationBar.hidden = YES;
}



- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated {
    if (self.childViewControllers.count > 0) {
        viewController.hidesBottomBarWhenPushed = YES;
    }
    [super pushViewController:viewController animated:animated];
}


// iOS 14.0 Xcode 12.0 tabBar隐藏问题
- (NSArray<__kindof UIViewController *> *)popToRootViewControllerAnimated:(BOOL)animated {
    // fix  https://developer.apple.com/forums/thread/660750
    if (@available(iOS 14.0, *)) {
        if (self.viewControllers.count > 1) self.topViewController.hidesBottomBarWhenPushed = NO;
    }
   NSArray<__kindof UIViewController *> *viewControllers = [super popToRootViewControllerAnimated:animated];
   return viewControllers;
}

@end
