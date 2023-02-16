//
//  EADBGPSModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/6.
//

#import <Realm/Realm.h>
#import "EADBBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface EADBGPSModel : EADBBaseModel

/// 时间戳字符串（逗号隔开）
@property NSString *timestamps;

/// 纬度字符串（逗号隔开）
@property NSString *latitudes;

/// 经度字符串（逗号隔开）
@property NSString *longitudes;

///
@property (readonly) NSArray *timestampArray;

///
@property (readonly) NSArray *latitudeArray;

///
@property (readonly) NSArray *longitudeArray;



@end

NS_ASSUME_NONNULL_END
