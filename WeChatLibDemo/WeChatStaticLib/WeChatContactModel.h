//
//  WeChatContactModel.h
//  WeChatStaticLib
//
//  Created by srulos on 16/3/7.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WeChatContactModel : NSObject
{
    
}

enum CONTACT_TYPE
{
    CT_CHATROOM,
    CT_USER,
    CT_MP,
    CT_WEIXIN
};

@property (nonatomic,retain) NSString * m_uin;
@property (nonatomic,retain) NSString * m_userName;
@property (nonatomic,retain) NSString * m_nickName;
@property (nonatomic,retain) NSString * m_headImgUrl;
@property (nonatomic,retain) NSString * m_remarkName;
@property int m_sex;
@property (nonatomic,retain) NSString * m_signature;
@property (nonatomic,retain) NSString * m_province;
@property (nonatomic,retain) NSString * m_city;
@property (nonatomic,retain) NSString * m_alias;
@property (nonatomic,retain) NSString * m_avatar;
@property enum CONTACT_TYPE m_contactType;
@property (nonatomic,retain) NSString * m_pinYin;

-(id)initWithDic:(NSMutableDictionary*)dic;
-(NSString*)toJsonString;
+(NSMutableArray*)sortByPinYin:(NSMutableArray*)array;
+(WeChatContactModel*)getContactModelByUserName:(NSString*)userName;
+(WeChatContactModel*)getContactModelByAlias:(NSString*)alias;
@end
