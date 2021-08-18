//
//  FQViewController.m
//  Hdk
//
//  Created by WJCha on 08/16/2021.
//  Copyright (c) 2021 WJCha. All rights reserved.
//

#import "FQViewController.h"
#import <Hdk/Hdk.h>

@interface FQViewController ()

@end

@implementation FQViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}


- (IBAction)click:(id)sender {
    [[Hdk shareInstance] openIndexPageFromViewController:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
