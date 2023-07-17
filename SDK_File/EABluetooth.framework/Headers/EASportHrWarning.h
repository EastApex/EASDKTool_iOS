//
//  EASportHrWarning.h
//  EABluetooth
//
//  Created by Aye on 2023/6/29.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 57
/// 运动心率报警
/// Exercise heart rate warning
@interface EASportHrWarning : EABaseModel

/// Switch: 0 Off 1 on
/// 开关： 0关闭 1打开
@property(nonatomic, assign) NSInteger sw;

/// Heart rate upper limit
/// 心率上限值
@property(nonatomic, assign) NSInteger maxHr;

/// Lower heart rate
/// 心率下限值
@property(nonatomic, assign) NSInteger minHr;

+ (instancetype )eaInitWithSwitch:(NSInteger )sw maxHr:(NSInteger )maxHr minHr:(NSInteger )minHr;


@end

NS_ASSUME_NONNULL_END
