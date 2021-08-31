//
//  FQBrandViewController.m
//  Hdk_Example
//
//  Created by 陈威杰 on 2021/8/30.
//  Copyright © 2021 WJCha. All rights reserved.
//

#import "FQBrandViewController.h"
#import <Hdk/Hdk.h>

@interface FQBrandViewController ()

@end

@implementation FQBrandViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [[Hdk shareInstance] initWithAppKey:@"demo" appSecret:@"demo" onResult:^(int code, NSString * _Nonnull message) {
        if (code == 200) {
            HDKEntryPage *page = [[Hdk shareInstance] getSinglePage:HDKPageTypeMain];
            UIViewController *vc = page.viewController;
            vc.view.frame = CGRectMake(0, 20/*获取状态栏的高度*/, self.view.frame.size.width, self.view.frame.size.height-20);
            [self addChildViewController:vc];
            [self.view addSubview:vc.view];
        }
    }];
    
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
