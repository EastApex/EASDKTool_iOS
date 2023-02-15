//
//  EAWatchSupportModel.h
//  EABluetooth
//
//  Created by Aye on 2022/9/1.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN



/*
 #pragma  【id的值 == EADataInfoType的值】
 #pragma  【Value of id == Value of EADataInfoType】
 */



/// id = 44: 手表支持设置的功能
/// id = 44: The watch supports Settings
@interface EAWatchSupportModel : EABaseModel

/// 功能与协议：心率警告设置（id = 26）
/// Heart rate Warning Settings
@property(nonatomic, assign) BOOL hrWarning;

/// 功能与协议：心率监测（id = 17）
/// Heart rate monitor
@property(nonatomic, assign) BOOL hrMonitoring;

/// 功能：静息心率监测
/// Resting heart rate monitoring
@property(nonatomic, assign) BOOL rhrMonitoring;

/// 功能：血压监测
/// Blood pressure monitoring
@property(nonatomic, assign) BOOL bloodPressureMonitoring;

/// 功能：压力监测
/// Pressure monitoring
@property(nonatomic, assign) BOOL pressureMonitoring;

/// 功能：睡眠监测
/// Sleep monitoring
@property(nonatomic, assign) BOOL sleepMonitoring;

/// 功能与协议：天气设置（id = 20）
/// The weather is set
@property(nonatomic, assign) BOOL weatherSettings;

/// 功能与协议：抬手亮屏设置（id = 28）
/// Raise your hand to display the screen
@property(nonatomic, assign) BOOL gesturesWakeUpSettings;

/// 功能与协议：支持震动模式(id = 30弃用设置，id =53启用）
/// Vibration mode
@property(nonatomic, assign) BOOL vibrationModeSettings;

/// 功能与协议：佩戴方式设置(id = 30弃用设置)（id = 4设置）
/// Setting of Wearing Mode
@property(nonatomic, assign) BOOL wearingModeSettings;

/// 功能与协议：来电提醒设置（id = 21）
/// Call Reminder Settings
@property(nonatomic, assign) BOOL incomingCallReminder;

/// 功能与协议：来电提醒设置（id = 21）
@property(nonatomic, assign) BOOL missedCallReminder;

/// 功能与协议：来电提醒设置（id = 21）
/// Missed call notification setting
@property(nonatomic, assign) BOOL smsReminder;

/// 功能与协议：来电提醒设置（id = 21）
/// Email Reminder Settings
@property(nonatomic, assign) BOOL mailReminder;

/// 功能与协议：目标达成提醒设置（id = 15）
/// Goal achievement reminder Settings
@property(nonatomic, assign) BOOL goalAchievementReminder;

/// 功能与协议：日程设置(吃饭喝水等)（id = 22）
/// Schedule (eating, drinking, etc.)
@property(nonatomic, assign) BOOL scheduleSetting;

/// 功能与协议：闹钟设置（id = 22）
/// The alarm clock Settings
@property(nonatomic, assign) BOOL alarmSettings;

/// 功能与协议：App推送(开关)（id = 34 ）
/// App push (switch)
@property(nonatomic, assign) BOOL appPushSettings;

/// 功能与协议：久坐监测（id = 18）
/// Sedentary monitoring
@property(nonatomic, assign) BOOL sedentaryMonitoring;

/// 功能与协议：勿扰设置（id = 13）
/// Disturb setting
@property(nonatomic, assign) BOOL disturbSetting;

/// 功能与协议：一级菜单设置（id = 31）
/// Primary Menu Setting
@property(nonatomic, assign) BOOL menuSettings;

/// 功能与协议：习惯设置（id = 38）
/// Habit tracker settings
@property(nonatomic, assign) BOOL habitTrackerSettings;

/// 功能与协议：习惯颜色设置（id = 38）
/// Habit tracker color settings
@property(nonatomic, assign) BOOL habitTrackerColorSettings;

/// 功能与协议：单位设置（公制、英制）（id = 11）
/// Unit setting (Metric system, British system)
@property(nonatomic, assign) BOOL unitSettings;

/// 功能与协议：基础卡路里开关设置 (id = 27)
/// Basic calorie switch setting
@property(nonatomic, assign) BOOL baseCaloriesSettings;

/// 功能与协议：经期设置    (id = 32)
/// Menstrual period set
@property(nonatomic, assign) BOOL menstrualSetting;

/// 功能与协议：通讯录(id = 42、id = 43)
/// Phone contact
@property(nonatomic, assign) BOOL phoneContact;

/// 功能与协议：支持铃声（有喇叭）
/// Support the bell
@property(nonatomic, assign) BOOL ringtoneSupport;

/// 功能与协议：有没GPS
@property(nonatomic, assign) BOOL gpsSetting;

/// 功能：体温测量
@property(nonatomic, assign) BOOL temperatureMonitoring;

/// 功能：智慧运动
@property(nonatomic, assign) BOOL smartSportsSetting;

/// 功能与协议：提醒事件监测（id = 45）
@property(nonatomic, assign) BOOL monitorReminder;

/// 功能：经典蓝牙一键连接功能
@property(nonatomic, assign) BOOL btOneKeyConnect;

/// 功能与协议:天气支持空气质量（id = 20）
@property(nonatomic, assign) BOOL weatherAir;

/// 功能与协议：查找手表（id = 20）
@property(nonatomic, assign) BOOL findWatch;

/// 功能与协议：支持app地图运动（id = 46）
@property(nonatomic, assign) BOOL supportAppMapSport;

/// 功能与协议：支持app启动检测（心率、血氧、压力、呼吸等功能）（id = 48）
@property(nonatomic, assign) BOOL supportAppDetection;

/// 功能与协议：支持大数据单独按类型获取（id = 49）
@property(nonatomic, assign) BOOL supportOnlyGetBigData;

/** 功能与协议：支持睡眠血氧监测开关协议（id = 50） */
@property(nonatomic, assign) BOOL sleepBloodOxygenMonitorSetting;

/** 功能与协议：支持压力监测开关协议（id = 51） */
@property(nonatomic, assign) BOOL stressMonitorSetting;

/** 功能与协议：支持实时数据开关协议（id = 52） */
@property(nonatomic, assign) BOOL sendRealTimeDataSetting;

/** 功能与协议：支持提醒协议全部写入操作、支持提醒协议根据类型全部替换操作（id = 22） */
@property(nonatomic, assign) BOOL reminderAllInAndReplaceTypeSetting;

/** 功能与协议：支持震动模式设置协议（id = 53） */
@property(nonatomic, assign) BOOL vibrateIntensitySetting;

/** 功能与协议：支持App启动运动协议（投屏运动）（id = 54） */
@property(nonatomic, assign) BOOL appLaunchScreenSport;





@end

NS_ASSUME_NONNULL_END
