//
//  SimulationService.h
//  WeChatStaticLib
//
//  Created by srulos on 16/3/7.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HttpResult;
@interface SimulationService : NSObject
{
    
}

-(NSData*)execute2Data:(NSMutableURLRequest*)request;
-(NSString*)execute2String:(NSMutableURLRequest*)request;
-(NSMutableDictionary*)execute2Dictionary:(NSMutableURLRequest*)request;
-(HttpResult*)execute2HttpResult:(NSMutableURLRequest*)request;
@end
