//
//  EAPeripheralModel.h
//  Template
//
//  Created by Aye on 2021/3/15.
//

#import <Foundation/Foundation.h>

@class CBPeripheral;
NS_ASSUME_NONNULL_BEGIN

@interface EAPeripheralModel : NSObject<NSCopying>

@property(nonatomic,strong) CBPeripheral *peripheral;           // 设备
@property(nonatomic,strong) NSNumber *RSSI;                     // 设备 RSSI
@property(nonatomic,strong) NSDictionary *advertisementData;    //
@property(nonatomic,strong) NSString *SN;                       // sn号 或者 mac地址
@property(nonatomic,strong) NSString *clientCode;               // 客户编码


@end

NS_ASSUME_NONNULL_END
