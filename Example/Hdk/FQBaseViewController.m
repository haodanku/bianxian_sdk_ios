//
//  FQBaseViewController.m
//  HDKDemo
//
//  Created by 陈威杰 on 2021/8/9.
//

#import "FQBaseViewController.h"

@interface FQBaseViewController ()

@end

@implementation FQBaseViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.hidden = YES;
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];

    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"点我" forState:UIControlStateNormal];
    [button sizeToFit];
    button.frame = CGRectMake(20, 100, 90, 50);
    [button addTarget:self action:@selector(_onButton) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    


    
}



- (void)_onButton {
//    FQInsertViewController *view = [[FQInsertViewController alloc] init];
    
//    [self.navigationController pushViewController:view animated:YES];
}

#pragma mark - 横竖屏

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {

//    HDKEntryPage *page = [[Hdk shareInstance] getPageWithType:HDKPageTypeMain];
//    UIViewController *vc = page.viewController;
//    vc.view.frame = self.view.bounds;
//    [self addChildViewController:vc];
//    [self.view addSubview:vc.view];
//    [[Hdk shareInstance] openIndexPageFromViewController:self];
    
//    HDKEntryPage *page = [[Hdk shareInstance] getPageWithType:HDKPageTypeRanking];
//    UIViewController *vc = page.viewController;
//    vc.view.frame = self.view.bounds;
//    [self addChildViewController:vc];
//    [self.view addSubview:vc.view];
    
    
//    [Hdk shareInstance] ;
//    UIView *baba = [[UIView alloc] initWithFrame:self.view.bounds];
//    [self.view addSubview:baba];
//
//
//
//
//    UITabBarController *view =  [Hdk shareInstance].getMainController;
////    view.frame = [UIScreen mainScreen].bounds;
//    view.view.frame = self.view.bounds;
//    [self.view addSubview:view.view];
//    [self addChildViewController:view];
}

/// 只支持所有方向
- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAll;
}

- (BOOL)prefersStatusBarHidden{
    return NO;
    
}





@end
