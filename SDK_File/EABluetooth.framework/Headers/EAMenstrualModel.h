//
//  EAMenstrualModel.h
//  EABluetooth
//
//  Created by Aye on 2021/6/21.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAMenstrualModel : EABaseModel

@property(nonatomic, assign) EAMenstruationType eType;

/// The time stamp
/// 时间戳
@property(nonatomic, assign) NSInteger timeStamp;

/// Days of prompt :(if e_type is a safe period, days>0, indicates the number of days of the next period. If you are menstruating, days>0 is the number of days you are menstruating.
/// 提示的天数：（如果e_type是安全期，days>0，则表示下一个经期的天数。如果是经期，days>0，则代表经期第几天)
@property(nonatomic, assign) NSInteger days;


@end


/// id = 32:Physiological cycle
/// id = 32:生理周期
@interface EAMenstruals : EABaseModel

/// Cycle data（A maximum of 45 are supported）
/// 生理周期数据（最多支持45个）
@property(nonatomic, strong) NSMutableArray<EAMenstrualModel*> *sDateArray;


/// Obtain period data
/// start: indicates the start date. eg. 2022-02-06 [yyyy-MM-dd]
/// keepDay: indicates the keepDay duration. eg.7
/// cycleDay: cycle . eg.28
+ (EAMenstruals *)eaAllocInitWithStartDate:(NSString *)start keepDay:(NSInteger)keepDay cycleDay:(NSInteger)cycleDay;


@end



NS_ASSUME_NONNULL_END
