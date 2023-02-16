//
//  EADBFrequencyModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/6.
//

#import <Realm/Realm.h>
#import "EADBBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface EADBFrequencyModel : EADBBaseModel

/// 时间戳字符串（逗号隔开）
@property NSString *timestamps;

/// 步频值字符串（逗号隔开）
@property NSString *fequencyValues;

///
@property (readonly) NSArray *timestampArray;

///
@property (readonly) NSArray *fequencyArray;

@end

NS_ASSUME_NONNULL_END
