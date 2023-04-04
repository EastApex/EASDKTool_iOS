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

/// CBPeripheral
@property(nonatomic,strong) CBPeripheral *peripheral;
@property(nonatomic,strong) NSNumber *RSSI;
/// Broadcast packet
@property(nonatomic,strong) NSDictionary *advertisementData;
/// sn号 或者 mac地址
@property(nonatomic,strong) NSString *SN;
@property(nonatomic,strong) NSString *clientCode;

/// Bluetooth watch name
@property(nonatomic,strong) NSString *localName;

/// ignore
@property(nonatomic,strong) NSString *kehuhao;
@property(nonatomic,strong) NSString *banben;
@property(nonatomic,assign) NSInteger number;
@end

NS_ASSUME_NONNULL_END
