//
//  EAHabitTrackerModel.h
//  EABluetooth
//
//  Created by Aye on 2022/3/9.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 38: 习惯追踪
/// id = 38: Habit Tracker
@interface EAHabitTrackerModel : EABaseModel

@property(nonatomic, assign) EAHabitTrackerIconType eIconId;

@property(nonatomic, assign) NSInteger id_p;

@property(nonatomic, assign) NSInteger beginHour;

@property(nonatomic, assign) NSInteger beginMinute;

@property(nonatomic, assign) NSInteger endHour;

@property(nonatomic, assign) NSInteger endMinute;

@property(nonatomic, assign) NSInteger r;

@property(nonatomic, assign) NSInteger g;

@property(nonatomic, assign) NSInteger b;


/// Snooze time (Unit: minute)
/// 贪睡时间（单位：分钟）写死30分钟 */
@property(nonatomic, assign) NSInteger duration;


@property(nonatomic, assign) EARemindActionType eAction;

@property(nonatomic, copy,) NSString *content;

/// 周期：
@property(nonatomic, assign) NSInteger weekCycleBit;

/** 标志  （read respond有效，write request set 0） */
@property(nonatomic, assign) EAHabitTrackerFlag eFlag;


@end

/**
 * id = 38 : 习惯追踪
 * write request：   (上位机--->固件 id：38)       respond：（固件--->上位机 id：39）
 * read  request:    (上位机--->固件 id：2)        respond：（固件--->上位机 id：38）
 **/
@interface EAHabitTrackers : EABaseModel

@property(nonatomic, assign) EAHabitTrackerOps eOps;

@property(nonatomic, assign) NSInteger id_p;

/**  Up to 12 最多12个 */
@property(nonatomic, strong) NSMutableArray<EAHabitTrackerModel*> *sIndexArray;

/// will delete id_ps  要删除的id_p
@property(nonatomic,strong)NSMutableArray<NSNumber*> *sDelIndexArray;




@end

/**
 * id = 39 ：习惯追踪回应
 *     write request：   (上位机--->固件 id：38)        respond：（固件--->上位机 id：39）
 *     read  request:     不支持            respond：不支持
 **/
NS_CLASS_DEPRECATED_IOS(9_0, 9_0, "No longer supported; please adopt EARespondModel") __TVOS_PROHIBITED
@interface EAHabitTrackerRespondModel : EABaseModel

/** 操作状态 */
@property(nonatomic, assign) EAHabitTrackerRespondType eOpsStatus;

/** 提醒id: 在write request的ops为新增 编辑回应中赋值，其他情况为0 */
@property(nonatomic, assign) NSInteger id_p;

+ (EAHabitTrackerRespondModel *)getModelByData:(NSData *)data;


@end





NS_ASSUME_NONNULL_END
