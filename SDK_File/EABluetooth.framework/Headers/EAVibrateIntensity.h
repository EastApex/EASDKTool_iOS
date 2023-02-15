//
//  EAVibrateIntensity.h
//  EABluetooth
//
//  Created by Aye on 2023/2/3.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 53 ：震动模式
/// id = 53: vibrate mode
@interface EAVibrateIntensity : EABaseModel

/// MARK: - 震动类型
/// Vibration type
@property(nonatomic, assign) EAVibrateIntensityType eVibrateIntensity;

/// init【初始化】
/// - Parameters:
///   - eaVibrateIntensityType: Vibration type【震动类型】
+ (instancetype )eaInitWithVibrateIntensityType:(EAVibrateIntensityType )eaVibrateIntensityType;



@end

NS_ASSUME_NONNULL_END
