//
//  AppDelegate.m
//  SDKDemo
//
//  Created by Aye on 2021/12/6.
//

#import "AppDelegate.h"

#import <EABluetooth/EABluetooth.h>


@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        
    /**
     必须 添加 权限
     NSBluetoothAlwaysUsageDescription
     NSBluetoothPeripheralUsageDescription
     
     打包时 报错请设置
     bitcode 设为 NO
     excluded architectures 添加 armv7
     */
    
    // 初始化SDK
    EABleConfig *config = [EABleConfig getDefaultConfig];
    config.debug = YES;
    [[EABleManager defaultManager] setBleConfig:config];
    
    
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
