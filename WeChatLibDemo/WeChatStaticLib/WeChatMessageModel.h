//
//  WeChatMessageModel.h
//  WeChatStaticLib
//
//  Created by srulos on 16/3/8.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WeChatMessageModel : NSObject
@property (nonatomic,retain) NSString * m_userName;
@property long m_createTime;

+(NSMutableArray*)sortMessage:(NSMutableArray *)messages;
@end
