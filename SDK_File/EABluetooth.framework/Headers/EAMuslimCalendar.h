//
//  EAMuslimCalendar.h
//  EABluetooth
//
//  Created by Aye on 2024/11/13.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAMuslimCalendar : EABaseModel

/** 当前回历年份 */
@property(nonatomic,  assign) NSInteger mYear;

/** 当前回历月份 */
@property(nonatomic,  assign) NSInteger mMonth;

/** 当前回历日期 */
@property(nonatomic,  assign) NSInteger mDay;


- (instancetype)eaInitMuslimCalendarWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;

@end

NS_ASSUME_NONNULL_END
