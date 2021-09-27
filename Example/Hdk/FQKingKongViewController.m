//
//  FQKingKongViewController.m
//  Hdk_Example
//
//  Created by 陈威杰 on 2021/9/27.
//  Copyright © 2021 WJCha. All rights reserved.
//

#import "FQKingKongViewController.h"
#import "FQContentViewController.h"
#import <Hdk/Hdk.h>

@interface FQKingKongViewController ()<UITableViewDelegate, UITableViewDataSource>
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (nonatomic, copy) NSArray<NSString *> *titles;
@end

@implementation FQKingKongViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.hidden = NO;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.view.backgroundColor = [UIColor whiteColor];
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.titles.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    }
    
    cell.textLabel.text = self.titles[indexPath.row];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [[Hdk shareInstance] jumpNav:indexPath.row + 1 fromViewController:self];
//    [[Hdk shareInstance] jumpNav:indexPath.row + 1 contentViewController:UIViewController.class fromViewController:self];
//    [[Hdk shareInstance] jumpNav:indexPath.row + 1 contentInsets:UIEdgeInsetsMake(0, 0, 0, 0) contentViewController:FQContentViewController.class fromViewController:self];
}



- (NSArray<NSString *> *)titles {
    if (!_titles) {
        _titles = @[@"京东", @"拼多多",@"唯品会",@"美团外卖",@"话费充值",@"福袋线报",@"防疫专区",@"肯德基",@"电影票"];
    }
    return _titles;
}
@end
