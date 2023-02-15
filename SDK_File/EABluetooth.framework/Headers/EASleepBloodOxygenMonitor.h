//
//  EASleepBloodOxygenMonitor.h
//  EABluetooth
//
//  Created by Aye on 2023/2/2.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 50 ：自动睡眠血氧监测（夜间血氧监测）
/// id = 50: Automatic sleep oxygen monitoring (night oxygen monitoring)
@interface EASleepBloodOxygenMonitor : EABaseModel

/// 0关，1开
/// Zero off, one on
@property(nonatomic, assign) BOOL sw;

/// 间隔时间，默认半小时：30（单位：分钟），范围（30、45、60、90、120）
/// Interval: 30 (unit: minute), range: 30, 45, 60, 90, and 120
@property(nonatomic, assign) NSInteger interval;




/// init【初始化】
/// - Parameters:
///   - sw: on-off Zero off, one on[0关，1开]
///   - interval: Interval[间隔时间]
+ (instancetype )eaInitWithOnOff:(BOOL)sw interval:(NSInteger)interval;




@end

NS_ASSUME_NONNULL_END
