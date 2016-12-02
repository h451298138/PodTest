//
//  HttpRequest.h
//  QQLib
//
//  Created by srulos on 15/11/5.
//  Copyright © 2015年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HttpRequest : NSMutableURLRequest
@property (nonatomic,retain) NSString * _urlString;
- (id)initWithJsonString:(NSString *)jsonString;
- (id)initWithJsonStringAndData:(NSString *)jsonString data:(NSData*)data;
- (id)initWithUrlAndParam:(NSString*)url param:(NSString*)param;
- (void)postCookie;
@end
