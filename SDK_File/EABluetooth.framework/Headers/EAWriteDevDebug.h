//
//  EAWirteDevDebug.h
//  EABluetooth
//
//  Created by Aye on 2023/10/31.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger,EAWirteDevDebugOps) {
    
    EAWirteDevDebugOpsGpsLog = 0,
};


@interface EAWriteDevDebug : EABaseModel

/** 操作 */
@property(nonatomic, assign) EAWirteDevDebugOps eOps;

/** log信息 */
@property(nonatomic, strong) NSString *log;

@end

NS_ASSUME_NONNULL_END
