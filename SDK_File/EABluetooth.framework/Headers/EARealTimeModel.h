//
//  EARealTimeModel.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EARealTimeModel : EABaseModel

/// 当前总步数
@property(nonatomic, assign) NSInteger steps;

/// 当前总卡路里（单位:小卡)
@property(nonatomic, assign) NSInteger calorie;

/// 当前总距离（单位:厘米）
@property(nonatomic, assign) NSInteger distance;

/// 当前总运动时长(单位:秒)
@property(nonatomic, assign) NSInteger duration;

/// 当前心率
@property(nonatomic, assign) NSInteger hr;

/// 当前压力
@property(nonatomic, assign) NSInteger pressure;

/// 当前血氧
@property(nonatomic, assign) NSInteger bloodOxygen;

/// 当前电量
@property(nonatomic, assign) NSInteger batLev;



@end

NS_ASSUME_NONNULL_END
