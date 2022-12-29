//
//  EAAppOps.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// App操作设备
@interface EAAppOps : EABaseModel

/** 操作类型 */
@property(nonatomic, assign) EAAppOpsType eAppOpsType;

/** 0停止，1开启 */
@property(nonatomic, assign) BOOL sw;

+ (instancetype )eaInitWithAppOpsType:(EAAppOpsType )appOpsType sw:(BOOL)sw;

@end

NS_ASSUME_NONNULL_END
