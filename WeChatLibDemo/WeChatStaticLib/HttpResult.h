//
//  HttpResult.h
//  QQLib
//
//  Created by srulos on 15/11/4.
//  Copyright © 2015年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HttpResult : NSObject
@property int ret;
@property (nonatomic,retain) NSString * msg;
@property (nonatomic,retain) NSString * url;
@property (nonatomic,retain) NSMutableDictionary * dic;
@property int responseCode;
@property (nonatomic,retain) NSString * responseString;

- (id)initWithResponseString:(int)_responseCode responseString:(NSString *)_responseString;
- (id)initWithJsonString:(NSString *)jsonString;
- (id)objectForKey:(NSString*)key;
- (int)toInt:(NSString*)key;
@end
