//
//  EADBStressModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/7.
//

#import "EADBBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface EADBStressModel : EADBBaseModel

/// 平均压力
@property NSInteger avgStress;

/// 最小压力
@property NSInteger minStress;

/// 最大压力
@property NSInteger maxStress;

/// 压力时间戳字符串（逗号隔开）
@property NSString *timestamps;

/// 压力值字符串（逗号隔开）
@property NSString *stresses;

///
@property (readonly) NSArray *timestampArray;

///
@property (readonly) NSArray *stressArray;

@end

NS_ASSUME_NONNULL_END
