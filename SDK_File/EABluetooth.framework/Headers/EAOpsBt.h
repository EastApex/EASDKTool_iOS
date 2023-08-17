//
//  EAOpsBt.h
//  EABluetooth
//
//  Created by Aye on 2023/7/21.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// Classic Bluetooth BT Control
@interface EAOpsBt : EABaseModel

@property(nonatomic, assign) EABtType eBtStatusType;

+ (instancetype )eaInitOnOff:(EABtType)eaBtType;

@end

NS_ASSUME_NONNULL_END
