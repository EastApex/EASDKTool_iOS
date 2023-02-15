//
//  EAHomeTimeZoneModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN


// disuse
// 弃用

/// id:14 家乡时区信息

@interface EAHomeTimeZoneItem : EABaseModel

/// 家乡时区: 0时区、东时区、西时区
@property(nonatomic, assign) EATimeZone timeZone;

/// 家乡时区: 时
@property(nonatomic, assign) NSInteger timeZoneHour;

/// 家乡时区: 分
@property(nonatomic, assign) NSInteger timeZoneMinute;

/// 家乡名称: 最多支持32字节的utf8，
@property(nonatomic, copy) NSString *place;




@end





/// 家乡时区
@interface EAHomeTimeZoneModel : EABaseModel

@property(nonatomic, strong) NSMutableArray<EAHomeTimeZoneItem*> *sHomeArray;








@end

NS_ASSUME_NONNULL_END
