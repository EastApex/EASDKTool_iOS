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
@property(nonatomic, assign) NSInteger steps;

/// 当前运动的总卡路里（单位:小卡)
@property(nonatomic, assign) NSInteger calorie;

/// 当前运动的心率
@property(nonatomic, assign) NSInteger hr;

/// 当前总距离（单位:厘米）
@property(nonatomic, assign) NSInteger distance;

/// 当前总次数（跳绳当前跳了多少下）
@property(nonatomic, assign) NSInteger count;

/// 当前海拔高度（单位:厘米）
@property(nonatomic, assign) NSInteger altitude;

/// 当前时间戳
@property(nonatomic, assign) NSInteger timestamp;

+ (EAAppSportRealTimeModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
