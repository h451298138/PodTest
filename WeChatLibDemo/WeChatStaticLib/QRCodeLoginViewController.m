//
//  QRCodeLoginViewController.m
//  WeChatRedBag
//
//  Created by srulos on 16/3/7.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import "QRCodeLoginViewController.h"
#import "WeChatApi.h"

#define SCAN_QRCODE_HELP_URL @"https://redbag.ererer222.com/help"

@interface QRCodeLoginViewController ()<UIWebViewDelegate>
{
    NSString * m_uuid;
    BOOL m_isQuite;
    UIColor * m_color;
}
@end

@implementation QRCodeLoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"微信登陆";
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"返回" style:UIBarButtonItemStyleDone target:self action:@selector(backBtnAction)];
    m_isQuite = NO;
    
    self.m_webView.delegate = self;
    self.m_webView.hidden = YES;
    
    [self.m_btnSaveAndJump setBackgroundColor:m_color];
    
    [self loadQRCode];
}

- (void)backBtnAction
{
    if (self.m_webView.hidden == NO) {
        self.m_webView.hidden = YES;
        self.title = @"微信登陆";
    }
    else{
        [self dismissViewControllerAnimated:YES completion:nil];
    }
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    m_isQuite = YES;
}

- (IBAction)onSaveQRCodeJump2WeChat:(id)sender {
    UIImage * image = self.m_imgQrcode.image;
    if (image) {
        [self saveImageToPhotos:image];
    }
}

- (void)loadQRCode
{
    NSLog(@"二维码加载中...");
    [[AsyncWeChatSimulationService stander]asyncGetUUIDAndQRCode:^(NSString *uuid, NSData *data) {
        m_uuid = uuid;
        
        if (data != nil) {
            UIImage * qrcode = [UIImage imageWithData:data];
            [self.m_imgQrcode setImage:qrcode];

            [self checkQRCode];
            
            NSLog(@"加载二维码成功！");
        }
        else{
            NSLog(@"加载二维码失败！");
        }
    }];
}

-(void)checkQRCode
{
    if (m_isQuite) {
        return;
    }

    [[AsyncWeChatSimulationService stander]asyncCheckQRCode:m_uuid loginSuccessBlock:^{
        NSLog(@"登录成功！");
        [self dismissViewControllerAnimated:YES completion:nil];
    } setAvatarImage:^(UIImage *headImage) {
        if (headImage != nil) {
            self.m_labelTips.hidden = YES;
            self.m_btnSaveAndJump.hidden = YES;
            self.m_imgQrcode.hidden = YES;
            self.m_btnScanFail.hidden = YES;
            
            self.m_labelTips2.hidden = NO;
            self.m_labelTips3.hidden = NO;
            self.m_imgAvatar.hidden = NO;
            
            [self.m_imgAvatar setImage:headImage];
        }
        [self checkQRCode];
    } continueBlock:^{
        [self checkQRCode];
        NSLog(@"请扫描!!!");
    }];
}

- (void)saveImageToPhotos:(UIImage*)savedImage
{
    UIImageWriteToSavedPhotosAlbum(savedImage, self, @selector(image:didFinishSavingWithError:contextInfo:), NULL);
}

- (void)image: (UIImage *) image didFinishSavingWithError: (NSError *) error contextInfo: (void *) contextInfo
{
    NSString *msg = nil ;
    if(error != NULL){
        msg = @"保存失败!";
        NSLog(@"%@",msg);
        return;
    } else {
        if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"weixin://"]]){
            NSURL * url = [[NSURL alloc]initWithString:@"weixin://scanqrcode/"];
            [[UIApplication sharedApplication ]openURL:url];
        }
        else if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"wechat://"]]){
            NSURL * url = [[NSURL alloc]initWithString:@"weixin://scanqrcode/"];
            [[UIApplication sharedApplication ]openURL:url];
        }
        else{
            NSLog(@"保存成功!但本机没有安装微信!");
        }
    }
}

- (IBAction)onOpenScanQRCodeHelp:(id)sender {
    NSURLRequest * request = [[NSURLRequest alloc]initWithURL:[NSURL URLWithString:SCAN_QRCODE_HELP_URL]];
    [self.m_webView loadRequest:request];
    [self.view bringSubviewToFront:self.m_webView];
    self.m_webView.hidden = NO;
}

#pragma mark delegate
- (void)webViewDidStartLoad:(UIWebView *)webView{
    [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:YES];
}

- (void)webViewDidFinishLoad:(UIWebView *)webView{
    [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:NO];
    
    self.title = [webView stringByEvaluatingJavaScriptFromString:@"document.title"];
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error{
}

- (void)updateSaveBtnColor:(UIColor *)color{
    m_color = color;
}
@end
