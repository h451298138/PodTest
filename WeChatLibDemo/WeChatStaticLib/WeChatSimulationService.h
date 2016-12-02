//
//  WeChatSimulationService.h
//  WeChatStaticLib
//
//  Created by srulos on 16/3/7.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SimulationService.h"

@class WeChatContactModel;
@interface WeChatSimulationService : SimulationService
{
}

@property (nonatomic,retain) NSString * m_weChatDns;
@property (nonatomic,retain) NSString * m_checkSyncKeyDns;
@property (nonatomic,retain) NSString * m_fileDns;
@property (nonatomic,retain) NSString * m_deviceId;
@property (nonatomic,retain) NSMutableDictionary * m_weChatUserJsonObject;
@property (nonatomic,retain) NSMutableDictionary * m_weChatUserData;
@property (nonatomic,retain) WeChatContactModel * m_selfContactModel;
@property (nonatomic,retain) NSString * m_avatar;
@property (nonatomic,retain) NSString * m_redirectUri;
@property (nonatomic,retain) NSString * m_vcdataticket;
@property (nonatomic,retain) NSMutableArray * m_contacts;
@property (nonatomic,retain) NSMutableArray * m_chatRooms;
@property (nonatomic,retain) NSMutableArray * m_otherContacts;
//
//+(WeChatSimulationService*)stander;
-(NSString*)getWeChatDns;
-(NSString*)getHost;
-(NSString*)getSyncHost;
-(NSString*)getUserSid;
-(NSString*)getUserSKey;
-(NSString*)getUserPassTicket;
-(NSString*)getUserUin;
-(NSMutableDictionary*)getUserSyncKey;
//
-(long)getRandom;
-(NSData*)getPostDataByPostDictionary:(NSMutableDictionary*)postDictionary;
//
-(NSString*)getUUID;
-(NSData*)getQRCode:(NSString*)uuid;
-(NSString*)checkQRCode:(NSString*)uuid loginIcon:(int)loginIcon;
-(NSData*)getHeadImg:(NSString *)userName;
-(NSMutableDictionary*)getUserInfo;
-(NSMutableDictionary*)wxInit;
-(NSMutableDictionary*)getContact;
-(NSMutableDictionary*)addContact:(NSString*)wxId type:(int)type;
-(NSMutableDictionary*)sendMsg:(NSString*)userName msgContent:(NSString*)msgContent;
-(NSMutableDictionary*)getSyncKey;
-(NSString*)checkSyncKey;
//-(void)releaseWeChat;
@end
