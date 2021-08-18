//
//  FQAppDelegate.m
//  Hdk
//
//  Created by WJCha on 08/16/2021.
//  Copyright (c) 2021 WJCha. All rights reserved.
//

#import "FQAppDelegate.h"
#import <Hdk/Hdk.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>

@implementation FQAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    
    [self requestIDFA];
    
    [[Hdk shareInstance] setDebug:YES];
    
    // 方法异步，请保证初始化前已经取得网络访问权限
    [[Hdk shareInstance] initWithAppKey:@"demo" appSecret:@"demo" onResult:^(int code, NSString * _Nonnull message) {
        if (code == 200) {
            NSLog(@"初始化成功");
        } else {
            NSLog(@"初始化失败");
        }
    }];
    
    return YES;
}


- (void)requestIDFA {
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            // Tracking authorization completed. Start loading ads here.
        }];
    } else {
        // Fallback on earlier versions
    }
}

@end
