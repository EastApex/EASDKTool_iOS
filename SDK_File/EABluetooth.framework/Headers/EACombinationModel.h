//
//  EACombination.h
//  EABluetooth
//
//  Created by Aye on 2021/5/8.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 30: Basic Device Information[cannot be modified]
/// id = 30: 设备基本信息【不支持修改】
@interface EACombinationModel : EABaseModel

/// charging state [cannot be modified]
/// 充电状态【不支持修改】
@property(nonatomic, assign) EABatteryStatus eBatStatus;

/// electric quantity value [cannot be modified]
/// 电量值 【不支持修改】
@property(nonatomic, assign) NSInteger batLevel;

/// Automatic pressure monitoring switch[cannot be modified]
/// 自动压力监测开关【不支持修改】
@property(nonatomic, assign) NSInteger autoPressureSw;

/// Automatic sedentary monitoring switch [cannot be modified]
/// 自动久坐监测开关【不支持修改】
@property(nonatomic, assign) NSInteger autoSedentarinessSw;

/// Raise the screen setting switch[cannot be modified]
/// 抬手亮屏设置开关【不支持修改】
@property(nonatomic, assign) NSInteger gesturesSw;

/// vibrational mode[cannot be modified]
/// 振动模式【不支持修改】
@property(nonatomic, assign) EAVibrateIntensityType eVibrateIntensity;

/// way of wearing[cannot be modified]
/// 佩戴方式【不支持修改】
@property(nonatomic, assign) EAWearWayType eHandInfo;

/// Setting Units[cannot be modified]
/// 单位设置【不支持修改】
@property(nonatomic, assign) EAUnifiedUnit eUnitFormat;

/// Heart rate monitoring switch [cannot be modified]
/// 心率监测开关【不支持修改】
@property(nonatomic, assign) NSInteger autoCheckHrSw;

/// Do not disturb the mode switch[cannot be modified]
/// 勿扰模式开关【不支持修改】
@property(nonatomic, assign) NSInteger notDisturbSw;

@property(nonatomic, assign) NSInteger setVibrateIntensity;

/// Dial ID, (0 indicates online custom dial, 1~n, internal dial number)  [cannot be modified]
/// 表盘id, (0代表在线自定义表盘，1~n，内置表盘编号) 【不支持修改】
@property(nonatomic, assign) NSInteger wfId;

///  Online custom dial ID [cannot be modified]
/// 在线自定义表盘id 【不支持修改】
//@property(nonatomic, copy) NSString *userWfId;

/// 睡眠血氧监测开关 【不支持修改】
@property(nonatomic, assign) NSInteger sleepBloodOxygenSw;

/////  压力监测开关 【不支持修改】
//@property(nonatomic, assign) NSInteger stressSw;





@end

NS_ASSUME_NONNULL_END
