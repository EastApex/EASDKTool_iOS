//
//  EASyncTime.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN


/// id = 5: 同步时间
/// id = 5: indicates the synchronization time
@interface EASyncTime : EABaseModel

/// year
/// 年
@property(nonatomic, assign) NSInteger year;

/// month
/// 月
@property(nonatomic, assign) NSInteger month;

/// day
/// 日
@property(nonatomic, assign) NSInteger day;

/// hour
/// 时
@property(nonatomic, assign) NSInteger hour;

/// minute
/// 分
@property(nonatomic, assign) NSInteger minute;

/// second
/// 秒
@property(nonatomic, assign) NSInteger second;

/// Time formats：12h or 24h
/// 小时制
@property(nonatomic, assign) EATimeHourType timeHourType;

/// time zone:Time zone 0, East Time zone, West time zone
/// 当前时区：0时区、东时区、西时区
@property(nonatomic, assign) EATimeZone timeZone;

/// The current time zone of hour
/// 当前时区:时
@property(nonatomic, assign) NSInteger timeZoneHour;

/// The current time zone of minute
/// 当前时区:分
@property(nonatomic, assign) NSInteger timeZoneMinute;

/// Synchronous mode:No setting required
/// 同步模式：
@property(nonatomic, assign) EASyncType syncType;

/// time zone city name
/// 时区城市名称
@property(nonatomic, strong) NSString *place;





/// Get the current time return class EASyncTime，cac used to set the watch time
/// note: If it's wrong, you need to fix it.
/// 获取当前时间
+ (EASyncTime *)getCurrentTime;




@end

NS_ASSUME_NONNULL_END
