//
//  EAMenstrualReminder.h
//  EABluetooth
//
//  Created by Aye on 2023/2/20.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 55 ：经期提醒
@interface EAMenstrualReminder : EABaseModel

/// 经期开始提醒开关，默认关闭
/// Menstrual start reminder switch, off by default
@property(nonatomic, assign) BOOL menstrualBeginSw;

/// 经期结束提醒开关，默认关闭
/// Menstrual end reminder switch, off by default
@property(nonatomic, assign) BOOL menstrualEndSw;

/// 易孕期开始提醒开关，默认关闭
/// Easy pregnancy start to remind switch, default off
@property(nonatomic, assign) BOOL easyPregnancyBeginSw;

/// 易孕期易孕期提醒开关，默认关闭
/// Easy pregnancy end to remind switch, default off
@property(nonatomic, assign) BOOL easyPregnancyEndSw;


/// 排卵日提醒开关，默认关闭
/// Ovulation day reminder switch, default off
@property(nonatomic, assign) BOOL ovulationDaySw;

/// Open or close with one key【一键开启或者关闭】
/// - Parameter onOff: on or Off
+ (instancetype )eaInitWithOnOff:(BOOL)onOff;

@end

NS_ASSUME_NONNULL_END
