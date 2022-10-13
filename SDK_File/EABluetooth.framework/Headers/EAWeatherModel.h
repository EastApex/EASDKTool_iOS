//
//  EAWeatherModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// Weather
/// 天气信息
@interface EADayWeatherModel : EABaseModel

/// Weather Conditions (Day)
/// 天气状况 （日间）
@property(nonatomic, assign) EAWeatherType eDayType;

/// Weather Conditions (night)
/// 天气状况 （夜间）
@property(nonatomic, assign) EAWeatherType eNightType;

/// The lowest temperature
/// 最低温度
@property(nonatomic, assign) NSInteger minTemperature;

/// The highest temperature
/// 最高温度
@property(nonatomic, assign) NSInteger maxTemperature;

/// Sunrise time (timestamp)
/// 日出时间 (时间戳)
@property(nonatomic, assign) NSInteger sunriseTimestamp;

/// Sunset time (timestamp)
/// 日落时间 (时间戳)
@property(nonatomic, assign) NSInteger sunsetTimestamp;

/// Air quality
/// 空气质量
@property(nonatomic, readwrite) EAWeatherAirType eAir;

/// Minimum wind rating
/// 最低风力等级
@property(nonatomic, assign) NSInteger minWindPower;

/// Maximum wind rating
/// 最高风力等级
@property(nonatomic, assign) NSInteger maxWindPower;

/// ultraviolet intensity
/// 紫外线强度
@property(nonatomic, assign) EAWeatherRaysType eRays;

/// Air humidity (1~100)%
/// 空气湿度(1~100)%
@property(nonatomic, assign) NSInteger airHumidity;

/// phase of the moon
/// 月相
@property(nonatomic, assign) EAWeatherMoonType eMoon;

/// Cloud cover (1-100) %
/// 云量(1~100)%
@property(nonatomic, assign) NSInteger cloudiness;

/// Air quality fraction == AQI
/// 空气质量分数 == AQI
@property(nonatomic, assign) NSInteger airGrade;
@end



@interface EAWeatherModel : EABaseModel


/// temperature unit
/// 温度单位
@property(nonatomic, assign) EAWeatherUnit eFormat;

/// current temperature
/// 当前温度
@property(nonatomic, assign) NSInteger currentTemperature;

/// A maximum of 8 days is supported
/// 最多支持8天
@property(nonatomic, strong) NSMutableArray<EADayWeatherModel*> *sDayArray;

/// place or address
/// 位置
@property(nonatomic, strong) NSString *place;


+ (EAWeatherModel *)getModelByData:(NSData *)data;





@end


NS_ASSUME_NONNULL_END
