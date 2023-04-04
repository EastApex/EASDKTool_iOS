//
//  Cmd_.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/14.
//

import Foundation
import UIKit
import EABluetooth

class Cmd_WatchInfo {

    class func setData() {

        Command.notSupportSetData()
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .watch) { baseModel in
            
            if baseModel.isKind(of: EAWatchModel.self) {
                let model = baseModel as! EAWatchModel;
                print(model.id_p)
            }
        }
    }
}

class Cmd_UserInfo {

    class func setData() {

        let model = EAUserModel.init();
        model.age = 32;
        model.height = 172 // unit:cm
        model.weight = 60000 // unit:g
        model.sexType = .female
        model.wearWayType = .leftHand
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .user) { baseModel in
            
            if baseModel.isKind(of: EAUserModel.self) {
                let model = baseModel as! EAUserModel;
                print(model.age)
            }
        }
    }
}

class Cmd_SyncTime {

    class func setData()  {
        
        let model = EASyncTime.getCurrent();
        model.timeZoneMinute = 30;
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .syncTime) { baseModel in
            
            if baseModel.isKind(of: EASyncTime.self) {
                let model = baseModel as! EASyncTime;
                print(model.year)
            }
        }
    }
}

class Cmd_Blacklight {

    class func setData()  {
        
        let model = EABlacklightModel.init();
        model.level = 50;
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .blacklight) { baseModel in
            
            if baseModel.isKind(of: EABlacklightModel.self) {
                let model = baseModel as! EABlacklightModel;
                print(model.level)
            }
        }
    }
}

class Cmd_BlacklightTimeout {

    class func setData()  {
        
        let model = EABlacklightTimeoutModel.init();
        model.timeOut = 10; // unit: second
        Command.setData(model: model);
    }
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .blacklightTimeout) { baseModel in
            
            if baseModel.isKind(of: EABlacklightTimeoutModel.self) {
                let model = baseModel as! EABlacklightTimeoutModel;
                print(model.timeOut)
            }
        }
    }
}

class Cmd_Battery{
    
    class func setData()  {
        
        Command.notSupportSetData()
    }
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .battery) { baseModel in
            
            if baseModel.isKind(of: EABatteryModel.self) {
                let model = baseModel as! EABatteryModel;
                print(model.level)
            }
        }
    }
}


class Cmd_Language {
    
    class func setData()  {
        
        let model = EALanguageModel.init();
        model.language = .english;
        Command.setData(model: model);
    }
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .language) { baseModel in
            
            if baseModel.isKind(of: EALanguageModel.self) {
                let model = baseModel as! EALanguageModel;
                print(model.language.rawValue)
            }
        }
    }
}

class Cmd_Unit {
    
    class func setData() {
        
        let model = EAUnifiedUnitModel.init();
        model.unit = .lengthUnitMetric;
        Command.setData(model: model);
    }
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .unifiedUnit) { baseModel in
            
            if baseModel.isKind(of: EAUnifiedUnitModel.self) {
                let model = baseModel as! EAUnifiedUnitModel;
                print(model.unit.rawValue)
            }
        }
    }
}

class Cmd_DeviceOps {
    
    class func setData()  {
        
        /**【EAOperationWatchType】
         /// factory data reset
         /// 恢复出厂设置
         EADeviceOpsTypeRestoreFactory = 0,
         
         /// Restart the watch
         /// 重启手表
         EADeviceOpsTypeReset = 1,
         
         /// Watch to turn it off
         /// 手表关机
         EADeviceOpsTypePowerOff = 2,
         
         /// Disconnect the bluetooth
         /// 断开蓝牙
         EADeviceOpsTypeDisconnectBle = 3,
         
         /// Go into flight mode
         /// 进入飞行模式
         EADeviceOpsTypeEnteringFlightMode = 4,
         
         /// Light up the screen
         /// 点亮屏幕
         EADeviceOpsTypeLightUpTheScreen = 5,
         
         /// Put out the screen
         /// 熄灭屏幕
         EADeviceOpsTypeTurnOffTheScreen = 6,
         
         /// Stop Looking for your phone
         /// 停止寻找手机(上位机需求)
         EADeviceOpsTypeStopSearchPhone = 7,
         
         /// 工厂模式专用：进入工厂测试模式
         EADeviceOpsTypeEnterFactoryTestMode = 8,

         /// 工厂模式专用：退出工厂测试模式
         EADeviceOpsTypeExitFactoryTestMode = 9,
         
         /// Looking for a watch
         /// 寻找手表
         EADeviceOpsTypeStartSearchWatch = 10,
         
         /// Stop Looking for a Watch
         /// 停止寻找手表
         EADeviceOpsTypeStopSearchWatch = 11,
         
         /// Exit the photo
         /// 退出拍照
         EADeviceOpsTypeStopCamera = 12,
         
         /// Enable Watch operation The pairing box is displayed on the IOS phone
         /// 使能手表操作IOS手机弹出配对框
         EADeviceOpsTypeShowiPhonePairingAlert = 13,
         */
        
        // You will need to view the enumeration [EAOperationWatchType] to manipulate the watch to perform the corresponding action.
        // 你需要查看枚举【EAOperationWatchType】来操控手表做出对应的动作。
        let model = EADeviceOps.init()
        model.deviceOpsType = .lightUpTheScreen
        model.deviceOpsStatus = .execute
        Command.setData(model: model);
    }
    
    class func findWatch() {
        let model = EADeviceOps.init()
        model.deviceOpsType = .startSearchWatch
        model.deviceOpsStatus = .execute
        Command.setData(model: model);
    }
    class func stopFindWatch() {
        
        let model = EADeviceOps.init()
        model.deviceOpsType = .stopSearchWatch
        model.deviceOpsStatus = .execute
        Command.setData(model: model);
    }
    class func getData(){
        
        Command.notSupportGetData()
    }
}

class Cmd_DND {
    
    class func setData() {
        
        let model = EANotDisturbModel.init()
        model.sw = 1        // on-off =>  0:off 1:on
        model.beginHour = 8
        model.beginMinute = 0
        model.endHour = 22
        model.endMinute = 0
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .notDisturb) { baseModel in
            
            if baseModel.isKind(of: EANotDisturbModel.self) {
                let model = baseModel as! EANotDisturbModel;
            }
        }
    }
}

class Cmd_DailyGoal {
    
    class func setData() {
        
        let model = EADailyGoalModel.eaInitWith(onOff: 1, stepGoal: 6000, calorieGoal: (500 * 1000), distanceGoal: (2 * 1000 * 100), durationGoal: (30 * 60), sleepGoal: (8 * 60 * 60))
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .dailyGoal) { baseModel in
            
            if baseModel.isKind(of: EADailyGoalModel.self) {
                let model = baseModel as! EADailyGoalModel;
                print(model.sStep.goal)
            }
        }
    }
}

class Cmd_CheckSleep {
    
    class func setData() {
        
        let weekCycleBit = EADataValue.getWeekCycle(byWeekCycleBitString: "0111110")
        let model = EAAutoCheckSleepModel.eaInit(withWeekCycleBit: weekCycleBit, beginHour: 0, beginMinute: 0, endHour: 23, endMinute: 59)
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .autoCheckSleep) { baseModel in
            
            if baseModel.isKind(of: EAAutoCheckSleepModel.self) {
                let model = baseModel as! EAAutoCheckSleepModel;
                print(model.weekCycleBit)
            }
        }
    }
}

class Cmd_CheckHeartRate {
    
    class func setData() {
        
        let model = EAAutoCheckHeartRateModel.init()
        model.interval = 10 // unit:minute ,if value is 0 close this.
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .autoCheckHeartRate) { baseModel in
            
            if baseModel.isKind(of: EAAutoCheckHeartRateModel.self) {
                let model = baseModel as! EAAutoCheckHeartRateModel;
                print(model.interval)
            }
        }
    }
}

class Cmd_CheckSedentariness {
    
    class func setData()  {
        
        let model = EAAutoCheckSedentarinessModel.init()
        model.interval = 30 // unit:minute
        model.sw = 11        // on-off => 10:off  11:on
        model.weekCycleBit = 127
        model.beginHour = 8
        model.beginMinute = 0
        model.endHour = 22
        model.endMinute = 0
        model.stepThreshold = 10 // Step threshold: Below this threshold indicates sedentary behavior
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .autoCheckSedentariness) { baseModel in
            
            if baseModel.isKind(of: EAAutoCheckSedentarinessModel.self) {
                let model = baseModel as! EAAutoCheckSedentarinessModel;
                print(model.interval)
            }
        }
    }
}

class Cmd_Weather {
    
    class func setData() {
        
        let day1 = EADayWeatherModel.init();
        day1.eDayType = .clear;
        day1.eNightType = .cloudy;
        day1.eAir = .good;
//        ... 其他数据
        
        
        let model = EAWeatherModel.init();
        model.sDayArray = NSMutableArray.init(object: day1);
        model.place = "guangzhou"
        model.currentTemperature = 25;
        model.eFormat = .centigrade;
       
        Command.setData(model: model);
    }
    
    class func getData(){
        
        Command.notSupportGetData()
    }
}
class Cmd_SocialSwitch {
    
    class func setData() {
        
        let model = EASocialSwitchModel.eaInit(with: .oneLongVibration, incomingcall: 1, missedcall: 1, sms: 1, social: 1, email: 1, schedule: 1);
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .socialSwitch) { baseModel in
            
            if baseModel.isKind(of: EASocialSwitchModel.self) {
                
                let model = baseModel as! EASocialSwitchModel;
                print(model.sIncomingcall.sw)
                
            }
        }
    }
}

class Cmd_Reminder {
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in
            
            if baseModel.isKind(of: EAReminderOps.self) {
                let model = baseModel as! EAReminderOps;
                print(model.sIndexArray)
            }
        }
    }
    
    
    class func add() {
        
        /// 1011100 ==>
        /// Sunday:Open
        /// Monday:Close
        /// Tuesday:Open
        /// Wednesday:Open
        /// Thursday:Open
        /// Friday:Close
        /// Saturday:Close
        
        let weekCycleBit = EADataValue.getWeekCycle(byWeekCycleBitString: "1011100")
        let reminderModel = EAReminderModel.eaInitCycleReminder(with: .alarm, weekCycleBit: weekCycleBit, hour: 8, minute: 0, onOff: 1, snooze: 1, snoozeDuration: 10, remindActionType: .longVibration, content: "");
        
        
//        let reminderModel = EAReminderModel.eaInitSingleReminder(with: .alarm, year: 2023, month: 2, day: 15, hour: 13, minute: 14, onOff: 1, snooze: 0, snoozeDuration: 10, remindActionType: .longVibration, content: "")
//
//        let model = EAReminderOps.eaInitAddOne(with: reminderModel)
//        Command.setData(model: model);
//
//        let reminderModel1 = EAReminderModel.eaInitSingleReminder(with: .sleep, year: 2023, month: 2, day: 17, hour: 14, minute: 14, onOff: 1, snooze: 0, snoozeDuration: 10, remindActionType: .longVibration, content: "")
//
//        let model1 = EAReminderOps.eaInitAddOne(with: reminderModel1)
//        Command.setData(model: model1);
    }
    
    class func edit() {
        
        EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in
            
            if baseModel.isKind(of: EAReminderOps.self) {
                let reminderOps = baseModel as! EAReminderOps;
                
                if reminderOps.sIndexArray.count > 0 {
                    
                    let reminderModel = reminderOps.sIndexArray.object(at: 1) as! EAReminderModel
                    reminderModel.sw = 0
                    
                    let model = EAReminderOps.eaInitEdit(with: reminderModel);
                    Command.setData(model: model);
                }
            }
        }
    }
    
    class func deleteOne() {
        
        EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in
            
            if baseModel.isKind(of: EAReminderOps.self) {
                let reminderOps = baseModel as! EAReminderOps;
                
                if reminderOps.sIndexArray.count > 0 {
                    
                    let reminderModel = reminderOps.sIndexArray.firstObject as! EAReminderModel
                    
                    let model = EAReminderOps.eaInitDeleteOne(withReminderModelId: reminderModel.id_p);
                    Command.setData(model: model);
                }}
        }
    }
    
    class func deleteAll() {
        
        let model = EAReminderOps.eaInitDeleteAllReminder();
        Command.setData(model: model);
    }
}

class Cmd_HeartRateWaringSetting {
    
    class func setData() {
        
        let model = EAHeartRateWaringSettingModel.eaInit(withSwitch: 1, maxHr: 180, minHr: 50)
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .heartRateWaringSetting) { baseModel in
            if baseModel.isKind(of: EAHeartRateWaringSettingModel.self) {
                let model = baseModel as! EAHeartRateWaringSettingModel;
                print(model.maxHr)
            }
        }
    }
}

class Cmd_CaloriesSetting {
    
    class func setData() {
        
        let model = EACaloriesSettingModel.eaInit(withSwitch: 1)
        Command.setData(model: model);
    }
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .caloriesSetting) { baseModel in
            
            if baseModel.isKind(of: EACaloriesSettingModel.self) {
                let model = baseModel as! EACaloriesSettingModel;
                print(model.sw)
            }
        }
    }
}

class Cmd_Combination {
    
    class func setData() {
        
        Command.notSupportSetData()
    }
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .combination) { baseModel in
            
            if baseModel.isKind(of: EACombinationModel.self) {
                let model = baseModel as! EACombinationModel;
                print(model.notDisturbSw)
            }
        }
    }
}

class Cmd_GesturesSetting {
    
    class func setData() {
        
        // open
        let model = EAGesturesSettingModel.eaInitAllDay();
        Command.setData(model: model);
        
        // close
//        let model2 = EAGesturesSettingModel.eaInitClose();
//        Command.setData(model: model2);
        
        // note：
        // Time range setting is not supported.
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .gesturesSetting) { baseModel in
            
            if baseModel.isKind(of: EAGesturesSettingModel.self) {
                let model = baseModel as! EAGesturesSettingModel;
                if (model.eBrightSrc == .close) {
                    print("gesturesSetting status : off");
                }else {
                   
                    print("gesturesSetting status : on");
                }
            }
        }
        
    }
}

class Cmd_HomePage {
    
    class func setData() {
        
        EABleSendManager.default().operationGetInfo(with: .homePage) { baseModel in
            
            if baseModel.isKind(of: EAHomePageModel.self) {
                let model = baseModel as! EAHomePageModel;
                
                
                if model.supportPageArray.count > 0 {
                    
                    let homePageModel = EAHomePageModel.init()
                    homePageModel.sPageArray = NSMutableArray(array: model.supportPageArray)
                    Command.setData(model: homePageModel);
                }else {
                    
                    Command.notSupportSetData();
                }
            }
        }
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .homePage) { baseModel in
            
            if baseModel.isKind(of: EAHomePageModel.self) {
                let model = baseModel as! EAHomePageModel;
                if model.supportPageArray.count > 0 {
                    
                    
                }else {
                    
                    Command.notSupportSetData();
                }
                
            }
        }
    }
}

class Cmd_Menstrual {
    
    class func setData() {
        
        let model = EAMenstruals.eaAllocInit(withStartDate: "2023-02-15", keepDay: 7, cycleDay: 28, judgeCurrentTime: true)
        Command.setData(model: model);
    }
    class func getData(){
        
        // 不支持读取手表的经期数据，可以使用 下面方法 获取 经期数据.
        // Menstrual data of the watch is not supported. You can use the following method to obtain menstrual data.
        let model = EAMenstruals.eaAllocInit(withStartDate: "2023-02-15", keepDay: 7, cycleDay: 28, judgeCurrentTime: true)

        Command.notSupportGetData();
    }
}

class Cmd_WatchFace {
    
    class func setData() {
        
        let model = EADialPlateModel.eaInitBuiltInWatchFace(withID: 1)
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .dialPlate) { baseModel in
            
            if baseModel.isKind(of: EADialPlateModel.self) {
                let model = baseModel as! EADialPlateModel;
                print(model.id_p)
                
            }
        }
    }
}

class Cmd_AppMessage {
    
    class func setData() {
        
        let eaShowAppMessageModel = EAShowAppMessageModel.eaAllocInitWithAll(onOff: true)
        let model = eaShowAppMessageModel.getEAAppMessageSwitchData()
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .appMessage) { baseModel in
            
            if baseModel.isKind(of: EAAppMessageSwitchData.self) {
                let model = baseModel as! EAAppMessageSwitchData;
                let showAppMessageModel = EAShowAppMessageModel.eaAllocInit(with: model)
                print(showAppMessageModel.facebook)
            }
        }
    }
}

class Cmd_HabitTracker {
    
    class func setData() {
        
        
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .habitTracker) { baseModel in
            
            if baseModel.isKind(of: EAHabitTrackers.self) {
                let model = baseModel as! EAHabitTrackers;
                print(model.sIndexArray)
            }
        }
    }
}

class Cmd_SportShowData {
    
    class func setData() {
        
        Command.notSupportSetData()
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .sportShowData) { baseModel in
            
            if baseModel.isKind(of: EASportShowDataModel.self) {
                let model = baseModel as! EASportShowDataModel;
                print(model.steps)
            }
        }
    }
}

class Cmd_BlePairState {
    
    class func setData() {
        
        Command.notSupportSetData()
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .blePairState) { baseModel in
            
            if baseModel.isKind(of: EABlePairStateModel.self) {
                let model = baseModel as! EABlePairStateModel;
                print(model.secState)
            }
        }
    }
}


class Cmd_TelephoneBook {
    
    class func setData() {
        
        // Method 1
  //        let book1 = EAContactModel.eaAllocInit(withName: "apple", telephoneNumber: "123456")
  //        let book2 = EAContactModel.eaAllocInit(withName: "Tomy", telephoneNumber: "128258")
  //        let eaTelephoneBookModel = EATelephoneBookModel.eaAllocInit(withList: [book1,book2])
  //        Command.setData(model: eaTelephoneBookModel);

          
          // Method 2
          let contacts = NSMutableArray.init();
          for i in 0..<12 {
              
              let contact = EAContactModel.eaAllocInit(withName: "apple" + String(i), telephoneNumber: "123456" + String(i))
              contacts.add(contact);
          }
          
          if contacts.count <= 10 {
              
              let eaTelephoneBookModel = EATelephoneBookModel.eaAllocInit(withList: contacts as! [EAContactModel])
              Command.setData(model: eaTelephoneBookModel);

          }else if contacts.count > 10 {
              
              let eaTelephoneBookModel1 = EATelephoneBookModel.eaAllocInit(withList: contacts.subarray(with: NSMakeRange(0, 10)) as! [EAContactModel])
              eaTelephoneBookModel1.eFlag = .begin
              Command.setData(model: eaTelephoneBookModel1);
              
              let eaTelephoneBookModel2 = EATelephoneBookModel.eaAllocInit(withList: contacts.subarray(with: NSMakeRange(10, contacts.count - 10)) as! [EAContactModel])
              eaTelephoneBookModel2.eFlag = .proceed
              Command.setData(model: eaTelephoneBookModel2);
          }
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .readTelephoneBook) { baseModel in
            
            if baseModel.isKind(of: EAReadTelephoneBookModel.self) {
                let model = baseModel as! EAReadTelephoneBookModel;
                print(model.sIndexArray)
            }
        }
    }
}


class Cmd_WatchSupport {
    
    class func setData() {
        
        Command.notSupportSetData()
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .watchSupport) { baseModel in
            
            if baseModel.isKind(of: EAWatchSupportModel.self) {
                
                let model = baseModel as! EAWatchSupportModel;
                print(model.scheduleSetting)
            }
        }
    }
}

class Cmd_MonitorReminder {
    
    class func getDrink() {
        
        let request = EARequestModel.init();
        request.requestId = Int(EADataInfoType.monitorReminder.rawValue)
        request.type = Int(EAMonitorReminderType.drink.rawValue)
        EABleSendManager.default().operationGetInfo(with: request) { baseModel in
            
            if baseModel.isKind(of: EAMonitorReminder.self) {
                
                
            }
        }
    }
    
    class func drink() {
        
        let model = EAMonitorReminder.eaInitDrinkMonitorWith(onOff: true, interval: 60, weekCycleBit: 127, beginHour: 8, beginMinute: 0, endHour: 22, endMinute: 0, cup: 1);
        Command.setData(model: model);
    }
    
    class func getWashHands() {
        
        let request = EARequestModel.init();
        request.requestId = Int(EADataInfoType.monitorReminder.rawValue)
        request.type = Int(EAMonitorReminderType.washHands.rawValue)
        EABleSendManager.default().operationGetInfo(with: request) { baseModel in
            
            if baseModel.isKind(of: EAMonitorReminder.self) {
                
                
            }
        }
    }
    
    class func washHands() {
        
        let model = EAMonitorReminder.eaInitWashHandsMonitorWith(onOff: true, interval: 60, weekCycleBit: 127, beginHour: 8, beginMinute: 0, endHour: 22, endMinute: 0)
        Command.setData(model: model);
    }
}

class Cmd_AppLaunchMapSport {
    
    
}

class Cmd_StressMonitor {
    
    class func setData() {
        
        let model = EAStressMonitor.eaInitWith(onOff: true);
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .stressMonitor) { baseModel in
            
            if baseModel.isKind(of: EAStressMonitor.self) {
                
                let model = baseModel as! EAStressMonitor;
                print(model.sw)
                
            }else if baseModel.isKind(of: EARespondModel.self) {
                
                print(baseModel.modelToJSONObject()!);
            }
        }
    }
}

class Cmd_SendRealTimeDataOnOff {
    
    class func setData() {
        
        let model = EASendRealTimeDataOnOff.eaInitWith(onOff: true)
        Command.setData(model: model);
    }
    class func getData(){
                
        EABleSendManager.default().operationGetInfo(with: .sendRealTimeDataOnOff) { baseModel in
            
            if baseModel.isKind(of: EASendRealTimeDataOnOff.self) {
                
                let model = baseModel as! EASendRealTimeDataOnOff;
                print(model.sw)
            }else if baseModel.isKind(of: EARespondModel.self) {
                
                print(baseModel.modelToJSONObject()!);
            }
        }
    }
}

class Cmd_VibrateIntensity {
    
    class func setData() {
        
        let model = EAVibrateIntensity.eaInit(with: .strong)
        Command.setData(model: model);
    }
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .vibrateIntensity) { baseModel in
            
            if baseModel.isKind(of: EAVibrateIntensity.self) {
                let model = baseModel as! EAVibrateIntensity;
                print(model.eVibrateIntensity.rawValue)
            }else if baseModel.isKind(of: EARespondModel.self) {
                
                print(baseModel.modelToJSONObject()!);
            }
        }
    }
}
