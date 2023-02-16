//
//  EADBBloodOxygenModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/7.
//

#import "EADBBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface EADBBloodOxygenModel : EADBBaseModel

/// 平均血氧
@property NSInteger avgBloodOxygen;

/// 最小血氧
@property NSInteger minBloodOxygen;

/// 最大血氧
@property NSInteger maxBloodOxygen;

/// 血氧时间戳字符串（逗号隔开）
@property NSString *timestamps;

/// 血氧值字符串（逗号隔开）
@property NSString *bloodOxygenes;

///
@property (readonly) NSArray *timestampArray;

///
@property (readonly) NSArray *bloodOxygenArray;

@end

NS_ASSUME_NONNULL_END
