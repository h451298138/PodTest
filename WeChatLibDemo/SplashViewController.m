//
//  SplashViewController.m
//  WeChatLibDemo
//
//  Created by mac on 16/11/29.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "SplashViewController.h"
#import "QRCodeLoginViewController.h"
#import "WeChatApi.h"

@interface SplashViewController ()

@end

@implementation SplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [WeChatApi asyncGetAppInfo:^(HttpResult *httpResult) {
        if (httpResult.ret == 0) {
            NSMutableDictionary * dic = [httpResult objectForKey:@"tb_app_info"];
            NSLog(@"%@",dic);
            
            if ([[dic objectForKey:@"appStatus"]intValue] == 0) {
                QRCodeLoginViewController * vc = [[QRCodeLoginViewController alloc]initWithNibName:@"QRCodeLoginViewController" bundle:nil];
                UINavigationController * nav = [[UINavigationController alloc]initWithRootViewController:vc];
                [[[UIApplication  sharedApplication].delegate window]setRootViewController:nav];
            }
            else{
                //todo
            }
        }
        else{
            //todo
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
