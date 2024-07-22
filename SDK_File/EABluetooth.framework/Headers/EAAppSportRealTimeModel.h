//
//  EAAppSportRealTimeModel.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAAppSportRealTimeModel : EABaseModel

/// 当前运动的总步数
/// The total number of steps currently in motion
@property(nonatomic, assign) NSInteger steps;

/// 当前运动的总卡路里（单位:小卡)
/// Total calories from current exercise (in calories)
@property(nonatomic, assign) NSInteger calorie;

/// 当前运动的心率
/// Heart rate of current exercise
@property(nonatomic, assign) NSInteger hr;

/// 当前总距离（单位:厘米）
/// Current total distance (unit: cm)
@property(nonatomic, assign) NSInteger distance;

/// 配速（单位:秒/KM）
/// Pace (unit: second /KM)
@property(nonatomic, assign) NSInteger pace;

/// 步频（单位:步/分钟）
/// Stride frequency (unit: steps per minute)
@property(nonatomic, assign) NSInteger strideFrequency;

/// 当前总次数（跳绳当前跳了多少下）
/// Current total number (how many jumps the rope is currently taking)
@property(nonatomic, assign) NSInteger count;

/// 当前海拔高度（单位:厘米）
/// Current altitude (unit: cm)
@property(nonatomic, assign) NSInteger altitude;

/// 时间戳
/// Time stamp
@property(nonatomic, assign) NSInteger timestamp;

/** 当前速度（单位: M/H） */
@property(nonatomic, assign) NSInteger speed;


@end

NS_ASSUME_NONNULL_END
