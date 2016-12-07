//
//  WeChatLibHeader.h
//  WeChatStaticLib
//
//  Created by mac on 16/4/6.
//  Copyright © 2016年 srulos. All rights reserved.
//

#ifndef WeChatLibHeader_h
#define WeChatLibHeader_h

#pragma mark config
//notification
#define NOTIFICATION_USER_LOGIN_SUCCESS @"notification_user_login_success"
#define NOTIFICATION_NEW_SYNC_KEY @"notification_new_sync_key"
#define NOTIFICATION_OFFLINE @"notification_offline"
#define NOTIFICATION_WXINITED @"notification_wxinited"

//wechat init result
typedef enum WX_INIT_RESULT
{
    WIR_SUCCESS,
    WIR_GET_USER_INFO_FAIL,
    WIR_INIT_FAIL,
    WIR_GET_CONTACT_FAIL,
}WX_INIT_RESULT;


#pragma mark serialize
//notification
#define ADD_OBSERVER(_id,_sel,_notificationName,_object)\
[[NotificationManager standerNotificationManager]addObserver:_id selector:_sel name:_notificationName object:_object];

#define REMOVE_OBSERVER(_id,_notificationName,_object)\
//[[NSNotificationCenter defaultCenter]removeObserver:_id name:_notificationName object:_object];

#define POST_NOTIFICATION(_notificationName,_object)\
[[NotificationManager standerNotificationManager]postNotification:_notificationName object:_object];

//http
#define DECLEAR_POST_CB_FUNC(_func_name)\
-(void)_func_name:(HttpResult *)result backCode:(id)backCode;

#define DECLEAR_GETDATA_CB_FUNC(_func_name)\
-(void)_func_name:(NSData *)data backCode:(id)backCode;

#define POST_STRING(_url,_param,_delegate,_selector,_backCode)\
[[HttpHelper standard]post:[NSString stringWithFormat:@"%@",_url] param:_param delegate:_delegate selector:_selector backCode:_backCode];

#define GET_CACHE_IMAGE_HTTP(_httpUrl,_imageView)\
[[DataCacheHelper standard] getImage:_httpUrl imageView:_imageView scale:1.0];

#define Nil2EmptyString(condition)\
if (condition == nil) {\
condition = @"";\
}

#define SHOW_QRCODE_LOGIN_VIEW_CONTROLLER(_color)\
if([WeChatApi stander].m_shoudShowLogin){\
QRCodeLoginViewController * qrcodeLoginViewController = [[QRCodeLoginViewController alloc]initWithNibName:@"QRCodeLoginViewController" bundle:nil];\
[qrcodeLoginViewController updateSaveBtnColor:_color];\
UINavigationController * navigationController = [[UINavigationController alloc]initWithRootViewController:qrcodeLoginViewController];\
[self presentViewController:navigationController animated:YES completion:nil];\
return;\
}

#endif /* WeChatLibHeader_h */
