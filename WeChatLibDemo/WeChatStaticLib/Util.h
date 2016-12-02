//
//  Util.h
//  WeChatStaticLib
//
//  Created by srulos on 16/3/7.
//  Copyright © 2016年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Util : NSObject
+(NSString*)urlEncode:(NSString *)aUrlString;
+ (NSString *)flattenHTML:(NSString *)html trimWhiteSpace:(BOOL)trim;
+ (void)pushLocalNotification:(int)timeInterval badge:(int)badge content:(NSString *)content key:(NSString *)key;
@end
