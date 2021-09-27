//
//  FQPresentViewController.m
//  Hdk_Example
//
//  Created by 陈威杰 on 2021/8/31.
//  Copyright © 2021 WJCha. All rights reserved.
//

#import "FQPresentViewController.h"
#import <Hdk/Hdk.h>

@interface FQPresentViewController ()

@end

@implementation FQPresentViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"点我" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor darkTextColor] forState:UIControlStateNormal];
    [button sizeToFit];
    [button addTarget:self action:@selector(onClickButton) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    button.center = self.view.center;
    
}

- (void)onClickButton {
    [[Hdk shareInstance] initWithAppKey:@"143ea247f2" appSecret:@"24fc3a2123f7a59514467f5e4ca5503f" onResult:^(int code, NSString * _Nonnull message) {
        if (code == 200) {
            [[Hdk shareInstance] openIndexPageFromViewController:self];
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
