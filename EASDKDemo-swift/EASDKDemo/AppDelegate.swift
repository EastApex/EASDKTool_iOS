//
//  AppDelegate.swift
//  EASDKDemo
//
//  Created by Aye on 2022/8/4.
//

import UIKit

import EABluetooth

@main
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        /**
         必须 添加 权限
         NSBluetoothAlwaysUsageDescription
         NSBluetoothPeripheralUsageDescription
         打包时 报错请设置
         bitcode 设为 NO
         excluded architectures 添加 armv7
         */
        
        let config = EABleConfig.getDefault();
        config.debug = true;
        
        config.saveLog = true;// Whether to save logs. This parameter is disabled by default.This function takes effect only when 'config.debug' is set to YES
//        config.deviceHeadNames = ["PRIMIA ACE"] //["APEX G02"];
        
        config.isTest = 1;// Test special (please set use in the debugging stage => 0: delete big data, 1: do not delete big data)
        
        let bleManager = EABleManager.default()
        bleManager.bleConfig = config;
        bleManager.setEASdkKey("EASDKDemo");
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

