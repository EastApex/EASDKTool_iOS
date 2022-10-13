//
//  EACombination.h
//  EABluetooth
//
//  Created by Aye on 2021/5/8.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// Basic Device Information
/// 设备基本信息
@interface EACombinationModel : EABaseModel

/// charging state [cannot be modified]
/// 充电状态 【不支持修改】
@property(nonatomic, assign) EABatteryStatus eBatStatus;

/// electric quantity value [cannot be modified]
/// 电量值 【不支持修改】
@property(nonatomic, assign) NSInteger batLevel;

/// Automatic pressure monitoring switch
/// 自动压力监测开关
@property(nonatomic, assign) NSInteger autoPressureSw;

/// Automatic sedentary monitoring switch [cannot be modified]
/// 自动久坐监测开关【不支持修改】
@property(nonatomic, assign) NSInteger autoSedentarinessSw;

/// Raise the screen setting switch
/// 抬手亮屏设置开关
@property(nonatomic, assign) NSInteger gesturesSw;

/// vibrational mode
/// 振动模式
@property(nonatomic, assign) EAVibrateIntensityType eVibrateIntensity;

/// way of wearing
/// 佩戴方式
@property(nonatomic, assign) EAWearWayType eHandInfo;

/// Setting Units
/// 单位设置
@property(nonatomic, assign) EAUnifiedUnit eUnitFormat;

/// Heart rate monitoring switch [cannot be modified]
/// 心率监测开关【不支持修改】
@property(nonatomic, assign) NSInteger autoCheckHrSw;

/// Do not disturb the mode switch
/// 勿扰模式开关
@property(nonatomic, assign) NSInteger notDisturbSw;

/// Whether the vibration mode is set separately 0: not set separately 1: Set separately
/// 是否单独设定振动模式 0:不单独设置 1:单独设置
@property(nonatomic, assign) NSInteger setVibrateIntensity;

/// Dial ID, (0 indicates online custom dial, 1~n, internal dial number)  [cannot be modified]
/// 表盘id, (0代表在线自定义表盘，1~n，内置表盘编号) 【不支持修改】
@property(nonatomic, assign) NSInteger wfId;

///  Online custom dial ID [cannot be modified]
/// 在线自定义表盘id 【不支持修改】
@property(nonatomic, copy,readonly) NSString *userWfId;

+ (EACombinationModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
