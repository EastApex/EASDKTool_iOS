//
//  EAReminderModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


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



@interface EAReminderOps : EABaseModel

/// Reminder event operations
/// 提醒事件操作
@property(nonatomic, assign) EAReminderEventOps eOps;

/// This parameter does not need to be set. If the parameter is modified, the ID needs to be set
/// 新增不需要设置，修改需要设置id
@property(nonatomic, assign) NSInteger id_p;

@property(nonatomic,strong) NSMutableArray<EAReminderModel*> *sIndexArray;


+ (EAReminderOps *)getModelByData:(NSData *)data ;


- (NSData *)getModelData ;




@end



NS_ASSUME_NONNULL_END
