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
@property(nonatomic,strong) NSString *SN;                       //
@end

NS_ASSUME_NONNULL_END
