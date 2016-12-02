//
//  QQNotificationManager.h
//  MicroMessage
//
//  Created by mac on 15/5/18.
//  Copyright (c) 2015年 zk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificationObserver : NSObject
@property id _observer;
@property SEL _selector;
@property NSString * _name;
@property id _object;
@end

@interface NotificationManager : NSObject
{
    NSMutableArray * _arrayObservers;
}

+(NotificationManager*)standerNotificationManager;

-(void)addObserver:(id)_observer selector:(SEL)_selector name:(NSString *)_name object:(id)_object;
-(void)clearObserver;
-(void)postNotification:(NSString*)_name object:(id)_object;

@end
