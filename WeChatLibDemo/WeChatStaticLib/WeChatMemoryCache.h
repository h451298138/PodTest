//
//  WeChatMemoryCache.h
//  WeChatStaticLib
//
//  Created by srulos on 16/3/8.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WeChatMemoryCache : NSObject
{
    NSMutableDictionary * m_cacheDic;
}

+(WeChatMemoryCache*)stander;
-(void)addData:(NSData*)value key:(NSString*)key;
-(NSData*)getData:(NSString*)key;
@end
