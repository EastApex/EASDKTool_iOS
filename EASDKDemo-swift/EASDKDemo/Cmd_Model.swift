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

    class func getModel() -> EAUserModel {

        let model = EAUserModel.init();
        model.age = 32;
        model.height = 172 // unit:cm
        model.weight = 60000 // unit:g
        model.sexType = .female
        model.wearWayType = .leftHand
        return model
    }
}

class Cmd_SyncTime {

    class func getModel() -> EASyncTime {
        
        let model = EASyncTime.getCurrent();
        return model;
    }
    
}

class Cmd_Blacklight {

    class func getModel() -> EABlacklightModel {
        
        let model = EABlacklightModel.init();
        model.level = 50;
        return model;
    }
}

class Cmd_BlacklightTimeout {

    class func getModel() -> EABlacklightTimeoutModel {
        
        let model = EABlacklightTimeoutModel.init();
        model.timeOut = 10; // unit: second
        return model;
    }
}

class Cmd_Language {
    
    class func getModel() -> EALanguageModel {
        
        let model = EALanguageModel.init();
        model.language = .english;
        return model;
    }
}

class Cmd_Unit {
    
    class func getModel() -> EAUnifiedUnitModel {
        
        let model = EAUnifiedUnitModel.init();
        model.unit = .lengthUnitMetric;
        return model;
    }
}

class Cmd_DeviceOps {
    
    class func getModel() -> EADeviceOps {
        
        let model = EADeviceOps.init()
        model.deviceOpsType = .startSearchWatch
        model.deviceOpsStatus = .execute
        return model;
    }
}

class Cmd_DND {
    
    class func getModel() -> EANotDisturbModel {
        
        let model = EANotDisturbModel.init()
        model.sw = 1        // on-off =>  0:off 1:on
        model.beginHour = 8
        model.beginMinute = 0
        model.endHour = 22
        model.endMinute = 0
        return model;
    }
}

class Cmd_DailyGoal {
    
    class func getModel() -> EADailyGoalModel {
        
        let model = EADailyGoalModel.eaInitWith(onOff: true, stepGoal: 6000, calorieGoal: (500 * 1000), distanceGoal: (2 * 1000 * 100), durationGoal: (30 * 60), sleepGoal: (8 * 60 * 60))
        return model;
    }
}

class Cmd_CheckSleep {
    
    class func getModel() -> EAAutoCheckSleepModel {
        
        let weekCycleBit = EADataValue.getWeekCycle(byWeekCycleBitString: "0111110")
        let model = EAAutoCheckSleepModel.eaInit(withWeekCycleBit: weekCycleBit, beginHour: 0, beginMinute: 0, endHour: 23, endMinute: 59)
        return model;
    }
}

class Cmd_CheckHeartRate {
    
    class func getModel() -> EAAutoCheckHeartRateModel {
        
        let model = EAAutoCheckHeartRateModel.init()
        model.interval = 10 // unit:minute ,if value is 0 close this.
        return model;
    }
}

class Cmd_CheckSedentariness {
    
    class func getModel() -> EAAutoCheckSedentarinessModel {
        
        let model = EAAutoCheckSedentarinessModel.init()
        model.interval = 30 // unit:minute
        model.sw = 11        // on-off => 10:off  11:on
        model.weekCycleBit = 127
        model.beginHour = 8
        model.beginMinute = 0
        model.endHour = 22
        model.endMinute = 0
        model.stepThreshold = 10 // Step threshold: Below this threshold indicates sedentary behavior
        return model;
    }
}

class Cmd_Weather {
    
    class func getModel() -> EAWeatherModel {
        
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
       
        return model;
    }
}
class Cmd_SocialSwitch {
    
    class func getModel() -> EASocialSwitchModel {
        
        let model = EASocialSwitchModel.eaInit(with: .oneLongVibration, incomingcall: true, missedcall: true, sms: true, social: true, email: true, schedule: true);
        return model;
    }
}

