//
//  EADBSportModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/6.
//

#import <Realm/Realm.h>
#import "EADBBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface EADBSportModel : EADBBaseModel

/// 运动类型
@property NSInteger sportType;

/// 猎声运动类型
@property NSInteger hlSportType;

/// 起始时间戳
@property NSInteger  beginTimeStamp;

/// 停止时间戳
@property NSInteger  endTimeStamp;

/// 步数
@property NSInteger  steps;

/// 卡路里（单位:小卡)
@property NSInteger  calorie;

/// 距离 （单位:厘米）
@property NSInteger  distance;

/// 次数 （跳绳）
@property NSInteger  count;

/// 运动时长(单位:秒)
@property NSInteger  duration;

/// 平均心率
@property NSInteger  averageHeartRate;

/// 最小心率
@property NSInteger  minHeartRate;

/// 最大心率
@property NSInteger  maxHeartRate;

/// 平均体温（单位：摄氏度）
@property CGFloat  averageTemperature;

/// 平均速度（单位: KM/H *100倍）
@property NSInteger averageSpeed;

/// 平均配速（单位: S/KM）
@property NSInteger averagePace;

/// 平均步频（单位: SPM 步每分钟）
@property NSInteger averageStepFreq;

/// 平均步距（单位:厘米）
@property NSInteger averageStride;

/// 平均海拔（单位:厘米）
@property NSInteger averageAltitude;

/// 训练效果 正常心率 时长(单位:秒)
@property NSInteger  trainingEffectNormal;

/// 训练效果 热身心率 时长(单位:秒)
@property NSInteger  trainingEffectWarmUp;

/// 训练效果 消耗脂肪 时长(单位:秒)
@property NSInteger  trainingEffectFatconsumption;

/// 训练效果 有氧心率 时长(单位:秒)
@property NSInteger  trainingEffectAerobic;

/// 训练效果 无氧心率 时长(单位:秒)
@property NSInteger  trainingEffectAnaerobic;

/// 训练效果 极限心率 时长(单位:秒)
@property NSInteger  trainingEffectLimit;

/// 心率时间戳字符串（逗号隔开）
@property NSString *hrTimestamps;

/// 心率值字符串（逗号隔开）
@property NSString *hrs;

/// gps时间戳字符串（逗号隔开）
@property NSString *gpsTimestamps;

/// gps纬度字符串（逗号隔开）
@property NSString *gpsLatitudes;

/// gps经度字符串（逗号隔开）
@property NSString *gpsLongitudes;

/// 配速时间戳字符串（逗号隔开）
@property NSString *paceTimestamps;

/// 配速值字符串（逗号隔开）
@property NSString *paces;

/// 步频时间戳字符串（逗号隔开）
@property NSString *frequencyTimestamps;

/// 步频值字符串（逗号隔开）
@property NSString *frequencys;


@end

NS_ASSUME_NONNULL_END
