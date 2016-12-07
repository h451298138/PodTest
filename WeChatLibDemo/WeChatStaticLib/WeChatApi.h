//
//  WeChatApi.h
//  WeChatStaticLib
//
//  Created by mac on 16/4/6.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WeChatLibHeader.h"
#import "Util.h"
#import "AsyncWeChatSimulationService.h"
#import "NotificationManager.h"
#import "WeChatMessageModel.h"
#import "WeChatContactModel.h"
#import "HttpResult.h"
#import "HttpRequest.h"
#import "DataCacheHelper.h"
#import "HttpHelper.h"

@interface WeChatApi : NSObject
@property BOOL m_shoudShowLogin;
@property NSString * m_shareContent;

- (id)init;
+ (void)initWeChatSdk;
+ (WeChatApi*)stander;
- (void)asyncGetAppInfo:(void(^)(HttpResult* httpResult))respBlock;
@end
