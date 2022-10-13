//
//  MenstrualViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//

#import "MenstrualViewController.h"

@interface MenstrualViewController ()

@property(nonatomic,weak) IBOutlet UILabel *startDayLabel;
@property(nonatomic,weak) IBOutlet UILabel *cycleDayLabel;
@property(nonatomic,weak) IBOutlet UILabel *keepDayLabel;


@end
#define kDayTimeStamp (24*60*60)
@implementation MenstrualViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    

}


- (IBAction)syncMenstrualAction:(UIButton *)sender {
    
    
    NSInteger startDay = timeStringToTimestamp(_startDayLabel.text);                    // 日期时间戳
    NSInteger cycleDay = [_cycleDayLabel.text integerValue];                            // 持续天数(5~20天)
    NSInteger keepDay = [_keepDayLabel.text integerValue];                              // 周期(22~45天)
    
    NSMutableArray *list = [NSMutableArray arrayWithArray:[self getNewMenstruationValueByStartDay:startDay :cycleDay :keepDay]];

    for (EAMenstrualModel *model in list) {
        
        if (model.eType == EAMenstruationTypeOvulationDay) {
            
            model.eType = EAMenstruationTypeEasyPregnancy;
        }
    }
    EAMenstruals *menstruals = [EAMenstruals new];
    menstruals.sDateArray = list;
    
    WeakSelf
    [BluetoothFunc changeMenstrual:menstruals completion:^(BOOL succ) {
        
        [selfWeak showAlertWithTitle:@"Sync success"];
    }];
}



- (NSArray *)getNewMenstruationValueByStartDay:(NSInteger )startDay :(NSInteger)cycleDay :(NSInteger)keepDay {
    
    
    
    /** 计算经期，并发送给手表
     
     1.月经开始日期：上次经期开始时间 + 周期
     2.月经结束日期：月经开始日期 + 月经持续时间
     3.排卵日期：月经开始日期 - 14
     4.易孕期开始日期：排卵日期 - 5
     5.易孕期结束日期：排卵日期 + 4
     6.第一个安全期开始日期：上次经期开始时间 + 月经持续时间
     7.第一个安全期结束日期：易孕期开始日期 - 1
     8.第二个安全期开始日期：易孕期结束日期 + 1
     9.第二个安全期结束日期：月经开始日期 - 1
     */
    
    
    NSMutableArray *days = [NSMutableArray new];
    
    // 获取当前日期所在生理周期（整个周期，含有经期、易孕期【排卵期】、安全期）
    NSInteger periodStartDay = startDay;///下次月经开始日期
    NSInteger periodEndDay = periodStartDay + (keepDay * kDayTimeStamp);///下次月经结束日期
    NSInteger nextPeriodStartDay = startDay + (cycleDay * kDayTimeStamp);///下次月经开始日期
    NSInteger nextPperiodEndDay = nextPeriodStartDay + (keepDay * kDayTimeStamp);///下次月经结束日期
    NSInteger ovulatoryPeriod = nextPeriodStartDay - (14*kDayTimeStamp); ///排卵日期
    NSInteger easyPregnancyStartDay = ovulatoryPeriod - (5*kDayTimeStamp); ///易孕期开始日期
    NSInteger easyPregnancyEndDay = ovulatoryPeriod + (4*kDayTimeStamp); ///易孕期结束日期
    NSInteger firstSafeStartDay = startDay + (keepDay * kDayTimeStamp);///第一个安全期开始日期
    NSInteger firstSafeEndDay = easyPregnancyStartDay - (1 * kDayTimeStamp);///第一个安全期结束日期
    NSInteger secondSafeStartDay = easyPregnancyEndDay + (1 * kDayTimeStamp);///第二个安全期开始日期
    NSInteger secondSafeEndDay = nextPeriodStartDay - (1 * kDayTimeStamp);///第二个安全期结束日期
    
//    AFLog(@"末次开始日期:%@",[[NSString stringWithFormat:@"%ld",startDay] timestampForTimeYMD]);
//    AFLog(@"持续天数:%ld",keepDay);
//    AFLog(@"周期:%ld",cycleDay);
//
//    AFLog(@"末次月经开始日期:%@",[[NSString stringWithFormat:@"%ld",periodStartDay] timestampForTimeYMD]);
//    AFLog(@"末次月经结束日期:%@",[[NSString stringWithFormat:@"%ld",periodEndDay] timestampForTimeYMD]);
//    AFLog(@"排卵日期:%@",[[NSString stringWithFormat:@"%ld",ovulatoryPeriod] timestampForTimeYMD]);
//    AFLog(@"易孕期开始日期:%@",[[NSString stringWithFormat:@"%ld",easyPregnancyStartDay] timestampForTimeYMD]);
//    AFLog(@"易孕期结束日期:%@",[[NSString stringWithFormat:@"%ld",easyPregnancyEndDay] timestampForTimeYMD]);
//    AFLog(@"第一个安全期开始日期:%@",[[NSString stringWithFormat:@"%ld",firstSafeStartDay] timestampForTimeYMD]);
//    AFLog(@"第一个安全期结束日期:%@",[[NSString stringWithFormat:@"%ld",firstSafeEndDay] timestampForTimeYMD]);
//    AFLog(@"第二个安全期开始日期:%@",[[NSString stringWithFormat:@"%ld",secondSafeStartDay] timestampForTimeYMD]);
//    AFLog(@"第二个安全期结束日期:%@",[[NSString stringWithFormat:@"%ld",secondSafeEndDay] timestampForTimeYMD]);
//    AFLog(@"下次月经开始日期:%@",[[NSString stringWithFormat:@"%ld",nextPeriodStartDay] timestampForTimeYMD]);
//    AFLog(@"下次月经结束日期:%@",[[NSString stringWithFormat:@"%ld",nextPperiodEndDay] timestampForTimeYMD]);
    
    NSInteger easyPregnancyStartIndex = (easyPregnancyStartDay - periodEndDay)/kDayTimeStamp + keepDay;
    NSInteger easyPregnancyEndIndex = easyPregnancyStartIndex + 9;
    
    for (NSInteger i = 0; i < cycleDay; i ++) {
        
        EAMenstrualModel *model = [EAMenstrualModel new];
        if (i < keepDay) { // 经期
            
            model.eType = EAMenstruationTypePeriod;
            model.days = i + 1;
//            AFLog(@"月经期日期:%@",[[NSString stringWithFormat:@"%ld",startDay + i * kDayTimeStamp] timestampForTimeYMD]);
//            AFLog(@"月经第几天:%ld",model.days);
        }else if (i >= easyPregnancyStartIndex && i <= easyPregnancyEndIndex) {
            
            model.eType = EAMenstruationTypeEasyPregnancy;
//            AFLog(@"易孕期日期:%@",[[NSString stringWithFormat:@"%ld",startDay + i * kDayTimeStamp] timestampForTimeYMD]);
            if (i == cycleDay - 14) {
                
                model.eType = EAMenstruationTypeOvulationDay;
            }
        }else if (i < easyPregnancyStartIndex && i >= keepDay)  { // 第一次安全期
            
            model.eType = EAMenstruationTypeFirstSafePeriod;
            model.days = easyPregnancyStartIndex - i - 1;
//            AFLog(@"安全期日期:%@",[[NSString stringWithFormat:@"%ld",startDay + i * kDayTimeStamp] timestampForTimeYMD]);
//            AFLog(@"离易孕期还有几天:%ld",model.days);
        }else{
            
            model.eType = EAMenstruationTypeSecondSafePeriod;
            model.days = cycleDay - i - 1;
//            AFLog(@"安全期日期:%@",[[NSString stringWithFormat:@"%ld",startDay + i * kDayTimeStamp] timestampForTimeYMD]);
//            AFLog(@"离月经还有几天:%ld",model.days);
        }
        model.timeStamp = startDay + i * kDayTimeStamp;
        [days addObject:model];
        
    }
    return [days copy];
}



@end
