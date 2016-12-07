//
//  QRCodeLoginViewController.h
//  WeChatRedBag
//
//  Created by srulos on 16/3/7.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface QRCodeLoginViewController : UIViewController
- (IBAction)onSaveQRCodeJump2WeChat:(id)sender;
@property (weak, nonatomic) IBOutlet UIImageView *m_imgQrcode;
@property (weak, nonatomic) IBOutlet UIImageView *m_imgAvatar;
@property (weak, nonatomic) IBOutlet UILabel *m_labelTips;
@property (weak, nonatomic) IBOutlet UIButton *m_btnSaveAndJump;
@property (weak, nonatomic) IBOutlet UIButton *m_btnScanFail;
@property (weak, nonatomic) IBOutlet UILabel *m_labelTips2;
@property (weak, nonatomic) IBOutlet UILabel *m_labelTips3;
- (IBAction)onOpenScanQRCodeHelp:(id)sender;
@property (weak, nonatomic) IBOutlet UIWebView *m_webView;

- (void)updateSaveBtnColor:(UIColor*)color;
@end
