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
We get 0110001, and we get 1000110 by little endian
Convert 1000110 binary to base 10, that is, weekCycleBit is 70 to enable the Monday, Tuesday, and Saturday detection

Eg2:
Sunday Monday Tuesday Wednesday Thursday Friday Saturday
0, 0, 0, 0, 1, 1
You get 0000011, and you get 1100000 by the little end
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
得到 0110001，按照小端排序得到 1000110
将 1000110 二进制转为 10进制 即此时 weekCycleBit 为 70 开启 周一二六 检测

eg2：
周日 周一 周二 周三 周四 周五 周六
0 0 0 0 0 1 1
得到 0000011，按照小端排序得到 1100000
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

@property(nonatomic, assign) NSInteger year;

@property(nonatomic, assign) NSInteger month;

@property(nonatomic, assign) NSInteger day;

/** 周期：位对应从bit0~bit6对应周日~周六
    The same of EAAutoCheckSleepModel.weekCycleBit
 */
@property(nonatomic, assign) NSInteger weekCycleBit;

/// on-off: 0 off 1 on
@property(nonatomic, assign) NSInteger sw;

/// Secondary reminder on-off: 0 off 1 on
@property(nonatomic, assign) NSInteger secSw;

/// Sleep duration
@property(nonatomic, assign) NSInteger sleepDuration;

@property(nonatomic, assign) EARemindActionType remindActionType;

/// if reminderEventType==.User [EAReminderEventTypeUser] needs to be set
@property(nonatomic, strong) NSString *content;

@end



/// id = 22 : 提醒（闹钟）
/// id = 22: Reminder (alarm clock)
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

+ (EAReminderOps *)getModelByData:(NSData *)data ;


- (NSData *)getModelData ;




@end



NS_ASSUME_NONNULL_END
