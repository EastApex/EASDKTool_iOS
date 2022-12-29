//
//  EAAppLaunchSport.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


@interface EAAppLaunchSport : EABaseModel

/// 运动状态：0关闭 1开启 2暂停
@property(nonatomic, assign) EAAppLaunchSportStatus status;

/// 运动类型(仅支持运动类型序号为 1~6)
@property(nonatomic, assign) EASportType eSportType;

/** 手表上报数据间隔时长(默认5秒)：（单位：秒） */
@property(nonatomic, assign) NSInteger interval;

+ (instancetype )eaInitWithStatus:(EAAppLaunchSportStatus)status sportType:(EASportType)eSportType interval:(NSInteger)interval;


@end

NS_ASSUME_NONNULL_END
