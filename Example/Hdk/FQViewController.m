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

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = [UIColor redColor];
}


- (IBAction)click:(id)sender {
    [[Hdk shareInstance] openPageFromViewController:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
