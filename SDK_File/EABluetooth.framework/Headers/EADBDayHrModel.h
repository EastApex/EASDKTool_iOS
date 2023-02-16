//
//  EABDDayHrModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/13.
//

#import "EADBBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface EADBDayHrModel : EADBBaseModel

/// 平均心率
@property NSInteger avgHr;

/// 最小心率
@property NSInteger minHr;

/// 最大心率
@property NSInteger maxHr;

/// 心率时间戳字符串（逗号隔开）
@property NSString *timestamps;

/// 心率值字符串（逗号隔开）
@property NSString *hrs;

///
//@property (readonly) NSArray *timestampArray;

/// 心率数据（10分钟一个点，当天00:00开始）
@property (readonly) NSArray *hrArray;

@end

NS_ASSUME_NONNULL_END
