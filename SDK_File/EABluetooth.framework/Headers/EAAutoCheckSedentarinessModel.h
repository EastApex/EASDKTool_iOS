//
//  EAAutoCheckSedentarinessModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN

/// id = 18 : Sedentary monitoring
/// id = 18 : 久坐监测
@interface EAAutoCheckSedentarinessModel : EABaseModel

///  Interval: The unit is minute.
/// 间隔时长：单位分钟，
@property(nonatomic, assign) NSInteger  interval;

/** 周期：位对应从bit0~bit6对应周日~周六
    The same of EAAutoCheckSleepModel.weekCycleBit
 */
@property(nonatomic, assign) NSInteger  weekCycleBit;


@property(nonatomic, assign) NSInteger  beginHour;


@property(nonatomic, assign) NSInteger  beginMinute;


@property(nonatomic, assign) NSInteger  endHour;

@property(nonatomic, assign) NSInteger  endMinute;

/// Step threshold: Below this threshold indicates sedentary behavior
/// 步数阈值 ：低于此步数则提醒久坐
@property(nonatomic, assign) NSInteger  stepThreshold;


/// 久坐开关 (10:关闭，11:打开)
@property(nonatomic, assign) NSInteger sw;


/** 午休开关 */
@property(nonatomic, assign) NSInteger noonSw;

/** 午休开始时间 ：小时 */
@property(nonatomic, assign) NSInteger noonBeginHour;

/** 午休开始时间 ：分钟 */
@property(nonatomic, assign) NSInteger noonBeginMinute;

/** 午休结束时间 ：小时 */
@property(nonatomic, assign) NSInteger noonEndHour;

/** 午休结束时间 ：分钟 */
@property(nonatomic, assign) NSInteger noonEndMinute;








@end

NS_ASSUME_NONNULL_END
