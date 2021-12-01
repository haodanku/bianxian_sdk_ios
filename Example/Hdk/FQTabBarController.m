//
//  FQTabBarController.m
//  HDKDemo
//
//  Created by 陈威杰 on 2021/8/9.
//

#import "FQTabBarController.h"
#import "FQBaseViewController.h"
#import "FQNavigationController.h"
#import "FQHomeViewController.h"
#import "FQBrandViewController.h"
#import "FQPresentViewController.h"
#import "FQKingKongViewController.h"

@interface FQTabBarController ()

@end

@implementation FQTabBarController

#pragma mark -

- (BOOL)shouldAutorotate {
    return self.selectedViewController.shouldAutorotate;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return self.selectedViewController.supportedInterfaceOrientations;
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
    return [self.selectedViewController preferredInterfaceOrientationForPresentation];
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return self.selectedViewController.preferredStatusBarStyle;
}

- (BOOL)prefersStatusBarHidden{
    return self.selectedViewController.prefersStatusBarHidden;
    
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    FQHomeViewController *home = [[FQHomeViewController alloc] init];
    [self setUpChildController:home normalImage:@"" selectImage:@"" title:@"单页"];
    
    FQPresentViewController *material = [[FQPresentViewController alloc] init];
    [self setUpChildController:material normalImage:@"" selectImage:@"" title:@"弹出"];
    
    FQKingKongViewController *kingKong = [[FQKingKongViewController alloc] init];
    [self setUpChildController:kingKong normalImage:@"" selectImage:@"" title:@"金刚区"];
    
    self.tabBar.translucent = NO;

}


- (void)setUpChildController:(UIViewController *)controller normalImage:(NSString *)normalImage selectImage:(NSString *)selectImage title:(NSString *)title {

    controller.title = title;
    FQNavigationController *nav = [[FQNavigationController alloc] initWithRootViewController:controller];

    [self addChildViewController:nav];
}

@end
