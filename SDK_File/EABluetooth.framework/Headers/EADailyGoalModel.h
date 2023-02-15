//
//  EADailyGoalModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN

/// 日常目标值明细
@interface EADailyGoalItem : EABaseModel

/// on-off :0 off 1 on
/// 开关： 0关闭 1打开
@property(nonatomic, assign) NSInteger sw;

/// goal
/// 目标值
@property(nonatomic, assign) NSInteger goal;


+ (instancetype)eaInitWithOnOff:(NSInteger)onOff
                           goal:(NSInteger)goal;

@end



/// id = 15 : Daily target value setting
/// id = 15 : 日常目标值设置
@interface EADailyGoalModel : EABaseModel


/// Step (Unit: steps)
/// 步数，目标值单位: 步
@property(nonatomic, strong) EADailyGoalItem *sStep;


/// Calorie (Unit: cal)
/// 卡路里，目标值单位: 卡
@property(nonatomic, strong) EADailyGoalItem *sCalorie;

/// Distance (Unit: meter)
/// 距离，目标值单位: 米
@property(nonatomic, strong) EADailyGoalItem *sDistance;

/// Duration (Unit: second)
/// 运动时长，目标值单位: 秒
@property(nonatomic, strong) EADailyGoalItem *sDuration;


/// Sleep time (Unit: second)
/// 睡眠时长，目标值单位: 秒
@property(nonatomic, strong) EADailyGoalItem *sSleep;




+ (instancetype)eaInitWithOnOff:(NSInteger)onOff
                       stepGoal:(NSInteger)stepGoal
                    calorieGoal:(NSInteger)calorieGoal
                   distanceGoal:(NSInteger)distanceGoal
                   durationGoal:(NSInteger)durationGoal
                      sleepGoal:(NSInteger)sleepGoal;




@end

NS_ASSUME_NONNULL_END
