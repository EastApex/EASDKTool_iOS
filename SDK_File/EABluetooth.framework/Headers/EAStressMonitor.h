//
//  EAStressMonitor.h
//  EABluetooth
//
//  Created by Aye on 2023/2/3.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 51 ：自动压力监测
/// id = 51: Automatic pressure monitoring
@interface EAStressMonitor : EABaseModel

/// 0关，1开
/// Zero off, one on
@property(nonatomic, assign) BOOL sw;

/// 间隔时间，单位：分钟(最低不少于60分钟)
/// Interval time, unit: minutes (minimum 60 minutes)
@property(nonatomic, assign) NSInteger interval;

/// init【初始化】
/// - Parameters:
///   - sw: on-off Zero off, one on[0关，1开]
+ (instancetype )eaInitWithOnOff:(BOOL)sw;

+ (instancetype )eaInitWithOnOff:(BOOL)sw interval:(NSInteger)interval;

@end

NS_ASSUME_NONNULL_END
