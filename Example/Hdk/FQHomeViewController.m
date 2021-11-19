//
//  FQHomeViewController.m
//  Hdk_Example
//
//  Created by 陈威杰 on 2021/8/30.
//  Copyright © 2021 WJCha. All rights reserved.
//

#import "FQHomeViewController.h"
#import <Hdk/Hdk.h>

@interface FQHomeViewController ()<HDKEntryPageDelegate>

@end

@implementation FQHomeViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    [[Hdk shareInstance] initWithAppKey:@"demo" onResult:^(int code, NSString * _Nonnull message) {
        if (code == 200) {
            HDKEntryPage *page = [[Hdk shareInstance] getSinglePage:HDKPageTypeMain];
            page.delegate = self;
            UIViewController *vc = page.viewController;
            vc.view.frame = CGRectMake(0, 20/*获取状态栏的高度*/, self.view.frame.size.width, self.view.frame.size.height-20);
            [self addChildViewController:vc];
            [self.view addSubview:vc.view];
        }
    }];
    
}

#pragma mark - HDKEntryPageDelegate

- (BOOL)shouldCustomPushViewContrller {
    return YES;
}

- (void)entryPage:(HDKEntryPage *)entryPage didPushViewController:(UIViewController *)controller {
    
    // 通过一个控制器添加父子控制器，
    UIViewController *superController = [[UIViewController alloc] init];
    superController.view.backgroundColor = [UIColor whiteColor];
    
    // 布局控制器的view
    controller.view.frame = CGRectMake(0, 20/*获取状态栏的高度*/, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height - 20);
    
    [superController addChildViewController:controller];
    [superController.view addSubview:controller.view];
    
    
    [self.navigationController pushViewController:superController animated:YES];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
