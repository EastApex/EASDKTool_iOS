//
//  WeatherViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//

#import "WeatherViewController.h"

@interface WeatherViewController ()

@end

@implementation WeatherViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)synceWeatherAction {
    
    /**
     
     天气 
     
     */
    
    //读取本地json文件
    NSError *error;
    NSString *path = [[NSBundle mainBundle] pathForResource:@"Weather" ofType:@"json"];
    NSData *data = [[NSData alloc] initWithContentsOfFile:path];
    NSDictionary *weatherInfo = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];

    NSArray *locDaily = weatherInfo[@"weatherJson"];
    
    NSMutableArray *dayModels = [[NSMutableArray alloc] init];
    for (NSDictionary *item in locDaily) {
        
        EADayWeatherModel *dayModel = [EADayWeatherModel new];
        dayModel.eDayType = [self getWeatherTypeByNumber:[item[@"iconDay"] integerValue]];
        dayModel.eNightType = [self getWeatherTypeByNumber:[item[@"iconNight"] integerValue]];
        
        dayModel.minTemperature = [item[@"tempMin"] integerValue];
        dayModel.maxTemperature = [item[@"tempMax"] integerValue];
        
        dayModel.sunriseTimestamp = [item[@"sunrise"] integerValue];
        dayModel.sunsetTimestamp = [item[@"sunset"] integerValue];
        
        dayModel.eAir = EAWeatherAirTypeGood;
        
        NSString *windScaleDay = item[@"windScaleDay"];
        NSArray *windScaleDays = [windScaleDay componentsSeparatedByString:@"-"];
        dayModel.minWindPower = [[windScaleDays firstObject] integerValue];
        dayModel.maxWindPower = [[windScaleDays lastObject] integerValue];
        
        dayModel.eRays = [self getEAWeatherRaysTypeByNumber:[item[@"uvIndex"] integerValue]];
        
        dayModel.airHumidity = [item[@"humidity"] integerValue] *100;
        
        dayModel.eMoon = [item[@"moonPhase"] integerValue];
        
        dayModel.cloudiness = [item[@"cloud"] integerValue];
        
        switch ([weatherInfo[@"airLever"] integerValue]) {
            case 1:
                dayModel.eAir = EAWeatherAirTypeExcellent;
                break;
            case 2:
                dayModel.eAir = EAWeatherAirTypeGood;
                break;
            default:
                dayModel.eAir = EAWeatherAirTypeBad;
                break;
        }
        
        [dayModels addObject:dayModel];
    }
    
    EAWeatherModel *weatherModel = [EAWeatherModel new];
    
    weatherModel.currentTemperature = [weatherInfo[@"currentTemperature"] intValue];
    weatherModel.eFormat = [weatherInfo[@"unit"] intValue];
    weatherModel.sDayArray = [dayModels copy];
    weatherModel.place = weatherInfo[@"place"];
    
    WeakSelf
    [BluetoothFunc changeWeather:weatherModel completion:^(BOOL succ) {
        
        [selfWeak showAlertWithTitle:@"Sync success"];
    }];
}


- (EAWeatherType)getWeatherTypeByNumber:(NSInteger )number {
    
    NSDictionary *typeInfo = @{
        @"0":@[@(100),@(102),@(150)],
        @"1":@[@(101),@(103),@(153),@(502),@(503),@(504),@(505),@(506),@(507),@(508),@(509),@(510),@(511),@(512),@(513),@(514),@(515)],
        @"2":@[@(104),@(154),@(500),@(501),@(999)],
        @"3":@[@(300),@(305),@(309),@(350)],
        @"4":@[@(301),@(306),@(314),@(399),@(351)],
        @"5":@[@(302),@(303),@(304)],
        @"6":@[@(307),@(308),@(310),@(311),@(312),@(315),@(316),@(317),@(318)],
        @"7":@[@(313),@(404),@(405),@(406),@(456)],
        @"8":@[@(400),@(407),@(457)],
        @"9":@[@(401),@(408),@(499)],
        @"10":@[@(402),@(403),@(410)],
    };
    for (NSString *key in typeInfo.allKeys) {
        
        NSArray *list = [NSArray arrayWithArray:typeInfo[key]];
        if ([list containsObject:@(number)]) {
            
            return [key integerValue];
        }
    }
    return EAWeatherTypeGloomy;
}
- (EAWeatherMoonType)getWeatherMoonTypeByNumber:(NSString *)moonPhase {
    
    NSDictionary *typeInfo = @{
        
        @"新月"   : @(0),
        @"峨眉月" : @(1),
        @"上弦月" : @(2),
        @"盈半月" : @(3),
        @"盈凸月" : @(4),
        @"满月"   : @(5),
        @"亏凸月" : @(6),
        @"亏半月" : @(7),
        @"下弦月" : @(8),
        @"残月"   : @(9),
    };
    return [[typeInfo objectForKey:moonPhase] integerValue];
}

- (EAWeatherRaysType)getEAWeatherRaysTypeByNumber:(NSInteger )number {
    
    if (number > 0 && number <=2) {
        
        return EAWeatherRaysTypeWeak;
        
    }else if (number > 3 && number <=4) {
        
        return EAWeatherRaysTypeMedium;
        
    }else if (number > 5 && number <=6) {
        
        return EAWeatherRaysTypeStrong;
        
    }else if (number > 7 && number <=8) {
        
        return EAWeatherRaysTypeVeryStrong;
        
    }else {
        
        return EAWeatherRaysTypeSuperStrong;
    }
}

@end
