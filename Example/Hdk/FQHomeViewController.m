//
//  FQHomeViewController.m
//  Hdk_Example
//
//  Created by 陈威杰 on 2021/8/30.
//  Copyright © 2021 WJCha. All rights reserved.
//

#import "FQHomeViewController.h"
#import <Hdk/Hdk.h>

@interface FQHomeViewController ()
//<HDKEntryPagePushDelegate>

@end

@implementation FQHomeViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    
    CGFloat top = 20;
    if (@available(iOS 11.0, *)) {
        top = [UIApplication sharedApplication].delegate.window.safeAreaInsets.top;
    }
    
    // 建议隐藏导航栏
    [[Hdk shareInstance] initWithAppKey:@"demo" onResult:^(int code, NSString * _Nonnull message) {
        if (code == 200) {
            HDKEntryPage *page = [[Hdk shareInstance] getSinglePage:HDKPageTypeMain];
//            page.pushDelegate = self;
            UIViewController *vc = page.viewController;
            vc.view.frame = CGRectMake(0, top/*获取状态栏的高度*/, self.view.frame.size.width, self.view.frame.size.height-top);
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
