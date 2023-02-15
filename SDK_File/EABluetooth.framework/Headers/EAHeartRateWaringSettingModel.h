//
//  EAHeartRateWaringSettingModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 26: Heart rate alarm setting
/// id = 26: 心率报警门限设置
@interface EAHeartRateWaringSettingModel : EABaseModel

/// Switch: 0 Off 1 on
/// 开关： 0关闭 1打开
@property(nonatomic, assign) NSInteger sw;

/// Heart rate upper limit
/// 心率上限值
@property(nonatomic, assign) NSInteger maxHr;

/// Lower heart rate
/// 心率下限值
@property(nonatomic, assign) NSInteger minHr;





+ (instancetype)eaInitWithSwitch:(NSInteger)sw maxHr:(NSInteger)maxHr minHr:(NSInteger)minHr;



@end

NS_ASSUME_NONNULL_END
