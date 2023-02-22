//
//  EASportDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN



/// Daily steps
/// 日常步数
@interface EAStepModel : EABigDataModel


/// steps
///运动数据：步数
@property(nonatomic, assign) NSInteger steps;

/// calorie (cal)
/// 运动数据：卡路里（单位:小卡)
@property(nonatomic, assign) NSInteger calorie;

/// distance (cm)
///运动数据：距离 （单位:厘米）
@property(nonatomic, assign) NSInteger distance;

/// duration (s)
///运动数据：运动时长(单位:秒)
@property(nonatomic, assign) NSInteger duration;

/// average heart rate
/// 运动数据：平均心率
@property(nonatomic, assign) NSInteger averageHeartRate;


@end


/// 手机端获取设备上传运动数据
@interface EAStepData : EABaseBigDataModel

/// list of EAStepModel
///运动包（大小详见对应OPTIONS文件）
@property(nonatomic, strong) NSMutableArray<EAStepModel*> *sIndexArray;

+ (EAStepData *)getSportData:(NSData *)data;

@end



NS_ASSUME_NONNULL_END
