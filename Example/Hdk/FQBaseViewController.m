//
//  FQBaseViewController.m
//  HDKDemo
//
//  Created by 陈威杰 on 2021/8/9.
//

#import "FQBaseViewController.h"
#import <Hdk/Hdk.h>

@interface FQBaseViewController ()

@end

@implementation FQBaseViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.hidden = YES;
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
}



- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAll;
}

- (BOOL)prefersStatusBarHidden{
    return NO;
    
}





@end
