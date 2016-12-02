//
//  HttpHelper.h
//  QQLib
//
//  Created by srulos on 15/11/4.
//  Copyright © 2015年 srulos. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HttpRequest;
@interface HttpHelper : NSObject
{
    NSOperationQueue * _queue;
}
//
+ (HttpHelper *)standard;
//
- (void)post:(NSString *)url param:(NSString *)param delegate:(id)delegate selector:(SEL)selector backCode:(id)backCode;
- (void)downLoadData:(NSString *)httpUrl delegate:(id)delegate selector:(SEL)selector backCode:(id)backCode;
- (void)post:(HttpRequest*)request delegate:(id)delegate selector:(SEL)selector backCode:(id)backCode;
- (NSHTTPCookie *)getCookie:(NSString*)name;
- (void)clearCookie:(NSString*)domain;
- (void)clearAllCookie;
@end
