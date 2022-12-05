//
//  EAWatchSupportModel.h
//  EABluetooth
//
//  Created by Aye on 2022/9/1.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// 手表支持设置的功能
/// The watch supports Settings
@interface EAWatchSupportModel : EABaseModel

/// 心率警告设置
/// Heart rate Warning Settings
@property(nonatomic, assign) BOOL hrWarning;

/// 心率监测
/// Heart rate monitor
@property(nonatomic, assign) BOOL hrMonitoring;

/// 静息心率监测
/// Resting heart rate monitoring
@property(nonatomic, assign) BOOL rhrMonitoring;

/// 血压监测
/// Blood pressure monitoring
@property(nonatomic, assign) BOOL bloodPressureMonitoring;

/// 压力监测
/// Pressure monitoring
@property(nonatomic, assign) BOOL pressureMonitoring;

/// 睡眠监测
/// Sleep monitoring
@property(nonatomic, assign) BOOL sleepMonitoring;

/// 天气设置
/// The weather is set
@property(nonatomic, assign) BOOL weatherSettings;

/// 抬手亮屏设置
/// Raise your hand to display the screen
@property(nonatomic, assign) BOOL gesturesWakeUpSettings;

/// 震动模式
/// Vibration mode
@property(nonatomic, assign) BOOL vibrationModeSettings;

/// 佩戴方式设置
/// Setting of Wearing Mode
@property(nonatomic, assign) BOOL wearingModeSettings;

/// 来电提醒设置
/// Call Reminder Settings
@property(nonatomic, assign) BOOL incomingCallReminder;

/// 未接来电提醒设置
@property(nonatomic, assign) BOOL missedCallReminder;

/// 短信提醒设置
/// Missed call notification setting
@property(nonatomic, assign) BOOL smsReminder;

/// 邮件提醒设置
/// Email Reminder Settings
@property(nonatomic, assign) BOOL mailReminder;

/// 目标达成提醒设置
/// Goal achievement reminder Settings
@property(nonatomic, assign) BOOL goalAchievementReminder;

/// 日程设置(吃饭喝水等)
/// Schedule (eating, drinking, etc.)
@property(nonatomic, assign) BOOL scheduleSetting;

/// 闹钟设置
/// The alarm clock Settings
@property(nonatomic, assign) BOOL alarmSettings;

/// App推送(开关)
/// App push (switch)
@property(nonatomic, assign) BOOL appPushSettings;

/// 久坐监测
/// Sedentary monitoring
@property(nonatomic, assign) BOOL sedentaryMonitoring;

/// 勿扰设置
/// Disturb setting
@property(nonatomic, assign) BOOL disturbSetting;

/// 一级菜单设置
/// Primary Menu Setting
@property(nonatomic, assign) BOOL menuSettings;

/// 习惯设置
/// Habit tracker settings
@property(nonatomic, assign) BOOL habitTrackerSettings;

/// 习惯颜色设置
/// Habit tracker color settings
@property(nonatomic, assign) BOOL habitTrackerColorSettings;

/// 单位设置（公制、英制）
/// Unit setting (Metric system, British system)
@property(nonatomic, assign) BOOL unitSettings;

/// 基础卡路里开关设置
/// Basic calorie switch setting
@property(nonatomic, assign) BOOL baseCaloriesSettings;

/// 经期设置
/// Menstrual period set
@property(nonatomic, assign) BOOL menstrualSetting;

/// 通讯录
/// Phone contact
@property(nonatomic, assign) BOOL phoneContact;

/// 支持铃声（有喇叭）
/// Support the bell
@property(nonatomic, assign) BOOL ringtoneSupport;

/** 有没GPS */
@property(nonatomic, assign) BOOL gpsSetting;

/** 体温测量 */
@property(nonatomic, assign) BOOL temperatureMonitoring;

/** 智慧运动 */
@property(nonatomic, assign) BOOL smartSportsSetting;

/** 提醒事件监测 */
@property(nonatomic, assign) BOOL monitorReminder;

/** 经典蓝牙一键连接功能 */
@property(nonatomic, assign) BOOL btOneKeyConnect;

/** 天气设置:空气质量 */
@property(nonatomic, assign) BOOL weatherAir;

/** 查找手表 */
@property(nonatomic, assign) BOOL findWatch;

+ (EAWatchSupportModel *)getModelByData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
