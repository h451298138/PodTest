//
//  MainViewController.m
//  WeChatLibDemo
//
//  Created by mac on 16/4/6.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "MainViewController.h"
#import "WeChatApi.h"

@interface MainViewController ()

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"主页面";
    
    [[AsyncWeChatSimulationService stander] asyncWXInit:^(WX_INIT_RESULT initResult) {
    
        if (initResult == WIR_SUCCESS) {
            NSLog(@"加载成功!");
        }
        else if(initResult == WIR_GET_USER_INFO_FAIL){
            NSLog(@"获取用户信息失败！");
        }
        else if(initResult == WIR_INIT_FAIL){
            NSLog(@"初始化微信失败！");
        }
        else if(initResult == WIR_GET_CONTACT_FAIL){
            NSLog(@"获取联系人列表失败！");
        }
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
