//
//  Cmd_.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/14.
//

import Foundation
import UIKit
import EABluetooth

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
}

class Cmd_SyncTime {

    class func setData()  {
        
        let model = EASyncTime.getCurrent();
        Command.setData(model: model);
    }
    
}

class Cmd_Blacklight {

    class func setData()  {
        
        let model = EABlacklightModel.init();
        model.level = 50;
        Command.setData(model: model);
    }
}

class Cmd_BlacklightTimeout {

    class func setData()  {
        
        let model = EABlacklightTimeoutModel.init();
        model.timeOut = 10; // unit: second
        Command.setData(model: model);
    }
}

class Cmd_Language {
    
    class func setData()  {
        
        let model = EALanguageModel.init();
        model.language = .english;
        Command.setData(model: model);
    }
}

class Cmd_Unit {
    
    class func setData() {
        
        let model = EAUnifiedUnitModel.init();
        model.unit = .lengthUnitMetric;
        Command.setData(model: model);
    }
}

class Cmd_DeviceOps {
    
    class func setData()  {
        
        let model = EADeviceOps.init()
        model.deviceOpsType = .startSearchWatch
        model.deviceOpsStatus = .execute
        Command.setData(model: model);
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
}

class Cmd_DailyGoal {
    
    class func setData() {
        
        let model = EADailyGoalModel.eaInitWith(onOff: 1, stepGoal: 6000, calorieGoal: (500 * 1000), distanceGoal: (2 * 1000 * 100), durationGoal: (30 * 60), sleepGoal: (8 * 60 * 60))
        Command.setData(model: model);
    }
}

class Cmd_CheckSleep {
    
    class func setData() {
        
        let weekCycleBit = EADataValue.getWeekCycle(byWeekCycleBitString: "0111110")
        let model = EAAutoCheckSleepModel.eaInit(withWeekCycleBit: weekCycleBit, beginHour: 0, beginMinute: 0, endHour: 23, endMinute: 59)
        Command.setData(model: model);
    }
}

class Cmd_CheckHeartRate {
    
    class func setData() {
        
        let model = EAAutoCheckHeartRateModel.init()
        model.interval = 10 // unit:minute ,if value is 0 close this.
        Command.setData(model: model);
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
}
class Cmd_SocialSwitch {
    
    class func setData() {
        
        let model = EASocialSwitchModel.eaInit(with: .oneLongVibration, incomingcall: 1, missedcall: 1, sms: 1, social: 1, email: 1, schedule: 1);
        Command.setData(model: model);
    }
}

class Cmd_Reminder {
    
    class func getData(){
        
        EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in
            
            let reminderOps = baseModel as! EAReminderOps;
        }
    }
    
    
    class func add() {
        
        /// 0111110 ==>
        /// Sunday:Close
        /// Monday:Open
        /// Tuesday:Open
        /// Wednesday:Open
        /// Thursday:Open
        /// Friday:Open
        /// Saturday:Close
        
//        let weekCycleBit = EADataValue.getWeekCycle(byWeekCycleBitString: "0111110")
//        let reminderModel = EAReminderModel.eaInitCycleReminder(with: .alarm, weekCycleBit: weekCycleBit, hour: 8, minute: 0, onOff: 1, snooze: 1, snoozeDuration: 10, remindActionType: .longVibration, content: "");
        
        let reminderModel = EAReminderModel.eaInitSingleReminder(with: .alarm, year: 2023, month: 2, day: 15, hour: 13, minute: 14, onOff: 1, snooze: 0, snoozeDuration: 10, remindActionType: .longVibration, content: "")
        
        let model = EAReminderOps.eaInitAddOne(with: reminderModel)
        Command.setData(model: model);
    }
    
    class func edit() {
        
        EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in
            
            let reminderOps = baseModel as! EAReminderOps;
            
            if reminderOps.sIndexArray.count > 0 {
                
                let reminderModel = reminderOps.sIndexArray.firstObject as! EAReminderModel
                reminderModel.hour = 10
                reminderModel.minute = 20
                
                let model = EAReminderOps.eaInitEdit(with: reminderModel);
                Command.setData(model: model);
            }
        }
    }
    
    class func deleteOne() {
        
        EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in
            
            let reminderOps = baseModel as! EAReminderOps;
            
            if reminderOps.sIndexArray.count > 0 {
                
                let reminderModel = reminderOps.sIndexArray.firstObject as! EAReminderModel
                
                let model = EAReminderOps.eaInitDeleteOne(withReminderModelId: reminderModel.id_p);
                Command.setData(model: model);
            }
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
}

class Cmd_CaloriesSetting {
    
    class func setData() {
        
        let model = EACaloriesSettingModel.eaInit(withSwitch: 1)
        Command.setData(model: model);
    }
}

class Cmd_GesturesSetting {
    
    class func setData() {
        
        let model = EACaloriesSettingModel.eaInit(withSwitch: 1)
        Command.setData(model: model);
    }
}

class Cmd_HomePage {
    
    class func setData() {
        
        EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in
            
            let model = baseModel as! EAHomePageModel;
            
            
            if model.supportPageArray.count > 0 {
                
                model.sPageArray = NSMutableArray(array: model.supportPageArray)
                Command.setData(model: model);
            }else {
                
                Command.notSupportSetData();
            }
        }
    }
}

class Cmd_Menstrual {
    
    class func setData() {
        
        let model = EAMenstruals.eaAllocInit(withStartDate: "2023-02-15", keepDay: 7, cycleDay: 28, judgeCurrentTime: true)
        Command.setData(model: model);
    }
}

class Cmd_WatchFace {
    
    class func setData() {
        
        let model = EADialPlateModel.eaInitBuiltInWatchFace(withID: 1)
        Command.setData(model: model);
    }
}

class Cmd_AppMessage {
    
    class func setData() {
        
        let eaShowAppMessageModel = EAShowAppMessageModel.eaAllocInitWithAll(onOff: true)
        let model = eaShowAppMessageModel.getEAAppMessageSwitchData()
        Command.setData(model: model);
    }
}

class Cmd_HabitTracker {
    
    class func setData() {
        
        
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
}


class Cmd_MonitorReminder {
    
    class func getDrink() {
        
        let request = EARequestModel.init();
        request.requestId = Int(EADataInfoType.monitorReminder.rawValue)
        request.type = Int(EAMonitorReminderType.drink.rawValue)
        EABleSendManager.default().operationGetInfo(with: request) { baseModel in
            
            
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
}

class Cmd_SendRealTimeDataOnOff {
    
    class func setData() {
        
        let model = EASendRealTimeDataOnOff.eaInitWith(onOff: true)
        Command.setData(model: model);
    }
}

class Cmd_VibrateIntensity {
    
    class func setData() {
        
        let model = EAVibrateIntensity.eaInit(with: .strong)
        Command.setData(model: model);
    }
}
