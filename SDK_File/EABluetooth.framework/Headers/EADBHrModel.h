//
//  EADBHrModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/6.
//

#import <Realm/Realm.h>
#import "EADBBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface EADBHrModel : EADBBaseModel

/// 心率时间戳字符串（逗号隔开）
@property NSString *timestamps;

/// 心率值字符串（逗号隔开）
@property NSString *hrs;

///
@property (readonly) NSArray *timestampArray;

///
@property (readonly) NSArray *hrArray;




@end

NS_ASSUME_NONNULL_END
