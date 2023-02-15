//
//  EABatteryModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN


/// id = 9 : Watch power information
/// id = 9 : 设备电量信息
@interface EABatteryModel : EABaseModel

/// battery status
/// 电池状态 : 正常、充电中
@property(nonatomic, assign) EABatteryStatus batteryStatus;

/// Battery value
/// 电量值  0 ~ 100
@property(nonatomic, assign) NSInteger level;





@end

NS_ASSUME_NONNULL_END
