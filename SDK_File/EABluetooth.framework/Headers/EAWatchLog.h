//
//  EAWatchLog.h
//  EABluetooth
//
//  Created by Aye on 2023/8/24.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 61 ：固件log的bin
@interface EAWatchLog : EABaseModel

/** 死机信息 */
@property(nonatomic, strong) NSData *logData;
@end

NS_ASSUME_NONNULL_END
