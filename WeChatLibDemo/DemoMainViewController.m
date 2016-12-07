//
//  DemoMainViewController.m
//  WeChatLibDemo
//
//  Created by mac on 16/12/7.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "DemoMainViewController.h"
#import "WeChatStaticLib/WeChatApi.h"
#import "QRCodeLoginViewController.h"

@interface DemoMainViewController ()

@end

@implementation DemoMainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
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

- (IBAction)onTestQRCodeLoginCB:(id)sender {
    UIColor * color = [UIColor redColor];
    SHOW_QRCODE_LOGIN_VIEW_CONTROLLER(color);
    
    NSLog(@"这里是正常的流程");
}
@end
