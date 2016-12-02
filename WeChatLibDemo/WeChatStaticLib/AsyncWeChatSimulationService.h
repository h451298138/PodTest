//
//  AsyncWeChatSimulationService.h
//  WeChatStaticLib
//
//  Created by mac on 16/4/5.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import "WeChatSimulationService.h"
#import <UIKit/UIKit.h>
#import "WeChatLibHeader.h"

@interface AsyncWeChatSimulationService : WeChatSimulationService
+(AsyncWeChatSimulationService*)stander;
- (void)asyncGetUUID:(void(^)(NSString* uuid))respBlock;
- (void)asyncGetQRCode:(NSString*)uuid respBlock:(void(^)(NSData* data))respBlock;
- (void)asyncGetUUIDAndQRCode:(void(^)(NSString * uuid,NSData * data))respBlock;
- (void)asyncCheckQRCode:(NSString*)uuid loginSuccessBlock:(void(^)())loginSuccessBlock setAvatarImage:(void(^)(UIImage * headImage))setAvatarBlock continueBlock:(void(^)())continueBlock;
//初始化微信，获取自己的信息，获取好友列表
- (void)asyncWXInit:(void(^)(WX_INIT_RESULT initResult))initResultBlock;
- (void)asyncSendMsg:(NSString*)userName msgContent:(NSString*)msgContent;
- (void)asyncGetHeadImg:(NSString*)userName respBlock:(void(^)(UIImage * headImage))respBlock;
- (void)releaseWeChat;
@end
