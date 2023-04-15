//
//  EAAutoCheckHeartRateModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 17 : Automatic heart rate monitoring
/// id = 17 : 自动心率监测
@interface EAAutoCheckHeartRateModel : EABaseModel

/// Interval: Unit: minute. 0 indicates that the monitoring function is disabled
/// 间隔时长：单位分钟，0为关闭监测功能
@property(nonatomic, assign) NSInteger interval;


+ (instancetype )eaInitAutoCheckHeartRateModelWithInterval:(NSInteger )interval;






@end

NS_ASSUME_NONNULL_END
