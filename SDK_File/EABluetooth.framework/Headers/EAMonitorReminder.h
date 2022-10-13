//
//  EAMonitorReminder.h
//  EABluetooth
//
//  Created by Aye on 2022/9/27.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// 提醒事件监测
/// Monitor reminder event
@interface EAMonitorReminder : EABaseModel

/** 提醒事件类型 */
@property(nonatomic, assign) EAMonitorReminderType eReminderType;

/** 开关 */
@property(nonatomic, assign) NSInteger sw;

/** 间隔时长：单位分钟 */
@property(nonatomic, assign) NSInteger interval;

/** 周期：位对应从bit0~bit6对应周日~周六,0仅一次提醒 */
@property(nonatomic, assign) NSInteger weekCycleBit;

/** 开始时间 ：小时 */
@property(nonatomic, assign) NSInteger beginHour;

/** 开始时间 ：分钟 */
@property(nonatomic, assign) NSInteger beginMinute;

/** 结束时间 ：小时 */
@property(nonatomic, assign) NSInteger endHour;

/** 结束时间 ：分钟 */
@property(nonatomic, assign) NSInteger endMinute;

/** 步数阈值 ：低于此步数则提醒久坐（reminder_type = Sedentary） */
@property(nonatomic, assign) NSInteger stepThreshold;

/** 杯：喝多少杯水，一杯水 = 200ml（reminder_type = Drink） */
@property(nonatomic, assign) NSInteger cup;

+ (EAMonitorReminder *)initDrinkMonitorWithOnOff:(BOOL)sw
                                        interval:(NSInteger)interval
                                    weekCycleBit:(NSInteger)weekCycleBit
                                       beginHour:(NSInteger)beginHour
                                     beginMinute:(NSInteger)beginMinute
                                         endHour:(NSInteger)endHour
                                       endMinute:(NSInteger)endMinute
                                             cup:(NSInteger)cup;


+ (EAMonitorReminder *)initWashHandsMonitorWithOnOff:(BOOL)sw
                                            interval:(NSInteger)interval
                                        weekCycleBit:(NSInteger)weekCycleBit
                                           beginHour:(NSInteger)beginHour
                                         beginMinute:(NSInteger)beginMinute
                                             endHour:(NSInteger)endHour
                                           endMinute:(NSInteger)endMinute;

+ (EAMonitorReminder *)initSedentaryMonitorWithOnOff:(BOOL)sw
                                            interval:(NSInteger)interval
                                        weekCycleBit:(NSInteger)weekCycleBit
                                           beginHour:(NSInteger)beginHour
                                         beginMinute:(NSInteger)beginMinute
                                             endHour:(NSInteger)endHour
                                           endMinute:(NSInteger)endMinute
                                       stepThreshold:(NSInteger)stepThreshold;

@end

/// 提醒事件监测（读取）
/// read monitor reminder event
@interface EAMonitorReminderRead : EABaseModel

@property(nonatomic, strong) NSArray<EAMonitorReminder *> *sIndexArray;

+ (EAMonitorReminderRead *)getModelByData:(NSData *)data;
@end


NS_ASSUME_NONNULL_END
