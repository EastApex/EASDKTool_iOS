//
//  EAReminderModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/*
Cycle: == "Sunday ~ Saturday,
0: off 1: on
Eg1:

Sunday Monday Tuesday Wednesday Thursday Friday Saturday
0, 1, 1, 0, 0, 1
We get 0110001, flashback get 1000110
Convert 1000110 binary to base 10, that is, weekCycleBit is 70 to enable the Monday, Tuesday, and Saturday detection

 Or use the Class EADataValue.getWeekCycleByWeekCycleBitString() to get weekCycleBit
 
 
Eg2:
Sunday Monday Tuesday Wednesday Thursday Friday Saturday
0, 0, 0, 0, 1, 1
You get 0000011, flashback get 1100000
Convert 1100000 binary to base 10. At this time, weekCycleBit is 96

If weekCycleBit is 0, the monitoring function is disabled
If weekCycleBit is set to 127, the daily monitoring function is enabled
*/
 
/*
周期：==》周日~周六，
0：关闭 1：开启
eg1：

周日 周一 周二 周三 周四 周五 周六
0 1 1 0 0 0 1
得到 0110001，倒叙获取 1000110
将 1000110 二进制转为 10进制 即此时 weekCycleBit 为 70 开启 周一二六 检测

或者使用 Class EADataValue.getWeekCycleByWeekCycleBitString() 获取 weekCycleBit
 
 
eg2：
周日 周一 周二 周三 周四 周五 周六
0 0 0 0 0 1 1
得到 0000011，倒叙获取 1100000
将 1100000二进制转为 10进制 即此时 weekCycleBit 为 96 开启 周五六 检测

weekCycleBit 为0 即 关闭监测功能
weekCycleBit 为127 即 开启每天监测功能
*/

/// 提醒事件
@interface EAReminderModel : EABaseModel


/// Reminder Event Type
/// 提醒事件类型
@property(nonatomic, assign) EAReminderEventType reminderEventType;

/// This parameter does not need to be set. If the parameter is modified, the ID needs to be set
/// 新增不需要设置，修改需要设置id
@property(nonatomic, assign) NSInteger id_p;

@property(nonatomic, assign) NSInteger hour;

@property(nonatomic, assign) NSInteger minute;
//
//@property(nonatomic, assign) NSInteger year;

//@property(nonatomic, assign) NSInteger month;
//
//@property(nonatomic, assign) NSInteger day;

/** 周期：位对应从bit0~bit6对应周日~周六
    The same of EAAutoCheckSleepModel.weekCycleBit
 */
@property(nonatomic, assign) NSInteger weekCycleBit;

/// on-off: 0 off 1 on
@property(nonatomic, assign) NSInteger sw;

/// Secondary reminder on-off(Snooze on-off): 0 off 1 on
@property(nonatomic, assign) NSInteger secSw;

/// Sleep duration(Snooze Duration)
@property(nonatomic, assign) NSInteger sleepDuration;

@property(nonatomic, assign) EARemindActionType remindActionType;

/// if reminderEventType==.User [EAReminderEventTypeUser] needs to be set
@property(nonatomic, strong) NSString *content;






/// Cycle Reminder【周期提醒】
/// - Parameters:
///   - reminderEventType: Reminder Event Type
///   - weekCycleBit: weekCycleBit
///   - hour:   hour
///   - minute: minute
///   - onOff: onOff
///   - snooze: Secondary reminder on-off(Snooze on-off)
///   - snoozeDuration: Sleep duration(Snooze Duration)
///   - remindActionType: Remind action type
///   - content: if reminderEventType==.User [EAReminderEventTypeUser] needs to be set
+ (instancetype)eaInitCycleReminderWithReminderEventType:(EAReminderEventType)reminderEventType
                                            weekCycleBit:(NSInteger)weekCycleBit
                                                    hour:(NSInteger)hour
                                                  minute:(NSInteger)minute
                                                   onOff:(NSInteger)onOff
                                                  snooze:(NSInteger)snooze
                                          snoozeDuration:(NSInteger)snoozeDuration
                                        remindActionType:(EARemindActionType )remindActionType
                                                 content:(NSString *)content;


/// Single Reminder【单次提醒】
/// - Parameters:
///   - reminderEventType: Reminder Event Type
///   - year: year
///   - month: month
///   - day: day
///   - hour: hour
///   - minute: minute
///   - onOff: onOff
///   - snooze:  Secondary reminder on-off(Snooze on-off)
///   - snoozeDuration: Sleep duration(Snooze Duration)
///   - remindActionType: Remind action type
///   - content: if reminderEventType==.User [EAReminderEventTypeUser] needs to be set
//+ (instancetype)eaInitSingleReminderWithReminderEventType:(EAReminderEventType)reminderEventType
//                                                     year:(NSInteger)year
//                                                    month:(NSInteger)month
//                                                      day:(NSInteger)day
//                                                     hour:(NSInteger)hour
//                                                   minute:(NSInteger)minute
//                                                    onOff:(NSInteger)onOff
//                                                   snooze:(NSInteger)snooze
//                                           snoozeDuration:(NSInteger)snoozeDuration
//                                         remindActionType:(EARemindActionType )remindActionType
//                                                  content:(NSString *)content DEPRECATED_MSG_ATTRIBUTE("Not Sopport this");

@end



/// id = 22 : 提醒（闹钟、日程）
/// id = 22: Reminder (alarm clock 、 schedule)
@interface EAReminderOps : EABaseModel

/// Reminder event operations
/// 提醒事件操作
@property(nonatomic, assign) EAReminderEventOps eOps;

/// This parameter does not need to be set. If the parameter is modified, the ID needs to be set
/// 新增不需要设置，修改需要设置id
@property(nonatomic, assign) NSInteger id_p;

@property(nonatomic,strong) NSMutableArray<EAReminderModel*> *sIndexArray;

/** 类型：当ops = replace_type时需要填入 */
@property(nonatomic, assign) EAReminderEventType eType;




/// Add one reminder【新增提醒】
/// - Parameter eaReminderModel: Class EAReminderModel Object
+ (instancetype)eaInitAddOneWithReminderModel:(EAReminderModel *)eaReminderModel;


/// Edit reminder【修改提醒】
/// The method "EABleSendManager.default().operationGetInfo(with:.reminder) {baseModel in}" needs to be called to get an object of "EAReminderModel"
/// 【需要调用此方法"EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in }"获取"EAReminderModel"的对象】
+ (instancetype)eaInitEditWithReminderModel:(EAReminderModel *)eaReminderModel;


/// Delete One reminder【删除提醒】
/// The method "EABleSendManager.default().operationGetInfo(with:.reminder) {baseModel in}" needs to be called to get the value of id_p for "EAReminderModel"
/// 【需要调用此方法"EABleSendManager.default().operationGetInfo(with: .reminder) { baseModel in }"获取"EAReminderModel"的id_p的值】
+ (instancetype)eaInitDeleteOneWithReminderModelId:(NSInteger )id_p;


/// Delete all alarm 【删除所有的闹钟】
+ (instancetype)eaInitDeleteAllAlarm;


/// Delete all schedule(All reminders except the alarm clock) 【删除所有的日程（除闹钟之外的所有提醒）】
+ (instancetype)eaInitDeleteAllSchedule;


/// Delete all reminder【删除所有提醒】
+ (instancetype)eaInitDeleteAllReminder;


/// Replace all reminder data of the same type for the watch according to the reminder type【根据提醒类型替换手表的所有相同类型的提醒数据】
/// (Supported only when id=44: reminder_all_in_and_replace_type_setting is true)【需要id=44：reminder_all_in_and_replace_type_setting为true才支持)】
+ (instancetype)eaInitReplaceAllWithReminderEventType:(EAReminderEventType )type list:(NSMutableArray<EAReminderModel *> *)list;


/// Replace all reminder data【替换手表的提醒数据】
/// (Supported only when id=44: reminder_all_in_and_replace_type_setting is true)【需要id=44：reminder_all_in_and_replace_type_setting为true才支持)】
+ (instancetype)eaInitReplaceAllWithList:(NSMutableArray<EAReminderModel *> *)list;

@end



NS_ASSUME_NONNULL_END
