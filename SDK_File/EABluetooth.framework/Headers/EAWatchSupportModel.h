//
//  EAWatchSupportModel.h
//  EABluetooth
//
//  Created by Aye on 2022/9/1.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN



/**
 #pragma  【id的值 == EADataInfoType的值】
 #pragma  【Value of id == Value of EADataInfoType】
 */



/// id = 44: 手表支持设置的功能
/// id = 44: The watch supports Settings
@interface EAWatchSupportModel : EABaseModel

/// 心率警告设置（id = 26）
/// Heart rate Warning Settings
@property(nonatomic, assign) BOOL hrWarning;

/// 心率监测（id = 17）
/// Heart rate monitor
@property(nonatomic, assign) BOOL hrMonitoring;

/// 静息心率监测
/// Resting heart rate monitoring
@property(nonatomic, assign) BOOL rhrMonitoring;

///
/// 功能：血压监测
/// Blood pressure monitoring
@property(nonatomic, assign) BOOL bloodPressureMonitoring;

/// （id = 51）
/// 压力监测
/// Pressure monitoring
@property(nonatomic, assign) BOOL pressureMonitoring;

/// 功能：睡眠监测
/// Sleep monitoring
@property(nonatomic, assign) BOOL sleepMonitoring;

///（id = 20）
/// 天气设置
/// The weather is set
@property(nonatomic, assign) BOOL weatherSettings;

/// （id = 28）
/// 抬手亮屏设置
/// Raise your hand to display the screen
@property(nonatomic, assign) BOOL gesturesWakeUpSettings;

/// (id = 30弃用设置，id =53启用）
/// 支持震动模式
/// Vibration mode
@property(nonatomic, assign) BOOL vibrationModeSettings;

/// (id = 30弃用设置)（id = 4设置）
/// 佩戴方式设置
/// Setting of Wearing Mode
@property(nonatomic, assign) BOOL wearingModeSettings;

/// （id = 21）
/// 来电提醒设置
/// Call Reminder Settings
@property(nonatomic, assign) BOOL incomingCallReminder;

///（id = 21）
/// 来电提醒设置
@property(nonatomic, assign) BOOL missedCallReminder;

///（id = 21）
/// 来电提醒设置
/// Missed call notification setting
@property(nonatomic, assign) BOOL smsReminder;

/// （id = 21）
/// 来电提醒设置
/// Email Reminder Settings
@property(nonatomic, assign) BOOL mailReminder;

///（id = 15）
/// 目标达成提醒设置
/// Goal achievement reminder Settings
@property(nonatomic, assign) BOOL goalAchievementReminder;

///（id = 22）
/// 日程设置(吃饭喝水等)
/// Schedule (eating, drinking, etc.)
@property(nonatomic, assign) BOOL scheduleSetting;

///（id = 22）
/// 闹钟设置
/// The alarm clock Settings
@property(nonatomic, assign) BOOL alarmSettings;

/// （id = 34 ）
/// App推送(开关)
/// App push (switch)
@property(nonatomic, assign) BOOL appPushSettings;

///（id = 18）
/// 久坐监测
/// Sedentary monitoring
@property(nonatomic, assign) BOOL sedentaryMonitoring;

///（id = 13）
/// 勿扰设置
/// Disturb setting
@property(nonatomic, assign) BOOL disturbSetting;

/// （id = 31）
/// 一级菜单设置
/// Primary Menu Setting
@property(nonatomic, assign) BOOL menuSettings;

///（id = 38）
/// 习惯设置
/// Habit tracker settings
@property(nonatomic, assign) BOOL habitTrackerSettings;

///（id = 38）
/// 习惯颜色设置
/// Habit tracker color settings
@property(nonatomic, assign) BOOL habitTrackerColorSettings;

///（id = 11）
/// 单位设置（公制、英制）
/// Unit setting (Metric system, British system)
@property(nonatomic, assign) BOOL unitSettings;

///  (id = 27)
/// 基础卡路里开关设置
/// Basic calorie switch setting
@property(nonatomic, assign) BOOL baseCaloriesSettings;

/// (id = 32)
/// 经期设置
/// Menstrual period set
@property(nonatomic, assign) BOOL menstrualSetting;

/// (id = 42、id = 43)
/// 通讯录
/// Phone contact
@property(nonatomic, assign) BOOL phoneContact;

/// 支持铃声（有喇叭）
/// Support the bell
@property(nonatomic, assign) BOOL ringtoneSupport;

/// 有没GPS
@property(nonatomic, assign) BOOL gpsSetting;

/// 功能：体温测量
@property(nonatomic, assign) BOOL temperatureMonitoring;

/// 智慧运动
@property(nonatomic, assign) BOOL smartSportsSetting;

/// （id = 45）
/// 提醒事件监测
/// Alert event monitoring
@property(nonatomic, assign) BOOL monitorReminder;

/// 经典蓝牙一键连接功能
/// Classic Bluetooth one-button connection
@property(nonatomic, assign) BOOL btOneKeyConnect;

/// （id = 20）
/// 天气支持空气质量
/// Weather supports air quality
@property(nonatomic, assign) BOOL weatherAir;

///（id = 12）
/// 查找手表
/// findWatch
@property(nonatomic, assign) BOOL findWatch;

/// （id = 46）
@property(nonatomic, assign) BOOL supportAppMapSport;

///（id = 48）
/// 支持app启动检测（心率、血氧、压力、呼吸等功能）
/// Support app startup detection (heart rate, blood oxygen, pressure, breathing and other functions)
@property(nonatomic, assign) BOOL supportAppDetection;

/// （id = 49）
/// 支持大数据单独按类型获取
/// Big data can be obtained separately by type
@property(nonatomic, assign) BOOL supportOnlyGetBigData;

///（id = 50）
/// 支持睡眠血氧监测开关协议
/// Support sleep blood oxygen monitoring switch protocol
@property(nonatomic, assign) BOOL sleepBloodOxygenMonitorSetting;

/// （id = 51）
/// 支持压力监测开关协议
/// Support for pressure monitoring switch protocol
@property(nonatomic, assign) BOOL stressMonitorSetting;

/// （id = 52）
/// 支持实时数据开关协议
/// Supports real-time data switching protocol
@property(nonatomic, assign) BOOL sendRealTimeDataSetting;

/// （id = 22）
/// 支持提醒协议全部写入操作、支持提醒协议根据类型全部替换操作
/// Supports all write operations of reminding protocols and all replace operations of reminding protocols based on types
@property(nonatomic, assign) BOOL reminderAllInAndReplaceTypeSetting;

/// （id = 53）
/// Support for vibration mode setting protocol
/// 支持震动模式设置协议
@property(nonatomic, assign) BOOL vibrateIntensitySetting;

/// （id = 54）
/// Support App startup motion protocol (screen motion)
/// 支持App启动运动协议（投屏运动
@property(nonatomic, assign) BOOL appLaunchScreenSport;


/// （id = 55）
/// Menstrual reminder
/// 经期提醒
@property(nonatomic, assign) BOOL menstrualReminder;


@end

NS_ASSUME_NONNULL_END
