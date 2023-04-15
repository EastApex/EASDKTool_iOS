//
//  EADeviceOps.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN


/// id = 12 : Operating the watch
/// id = 12 : 操作设备
@interface EADeviceOps : EABaseModel


/// Operating Device Type
@property(nonatomic, assign) EADeviceOpsType deviceOpsType;

/// need set EADeviceOpsStatusExecute to Operating the watch
@property(nonatomic, assign) EADeviceOpsStatus deviceOpsStatus;


+ (instancetype)eaInitDeviceOpsType:(EADeviceOpsType )deviceOpsType;



@end

NS_ASSUME_NONNULL_END
