//
//  AppDelegate.m
//  WeChatLibDemo
//
//  Created by mac on 16/4/6.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "AppDelegate.h"
#import "WeChatStaticLib/WeChatApi.h"
#import "DemoMainViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [WeChatApi initWeChatSdk];
    
    DemoMainViewController * demoMainViewController = [[DemoMainViewController alloc]initWithNibName:@"DemoMainViewController" bundle:nil];
    [self.window setRootViewController:demoMainViewController];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    self.backgroundTaskIdentifier =[application beginBackgroundTaskWithExpirationHandler:^(void) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [application endBackgroundTask:self.backgroundTaskIdentifier];
            self.backgroundTaskIdentifier = UIBackgroundTaskInvalid;
        });
    }];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [application endBackgroundTask:self.backgroundTaskIdentifier];
    self.backgroundTaskIdentifier = UIBackgroundTaskInvalid;
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
}

- (void)applicationWillTerminate:(UIApplication *)application {
}

@end
