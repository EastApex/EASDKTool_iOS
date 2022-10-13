//
//  EAWatchDebug.h
//  EAProductDemo
//
//  Created by Aye on 2021/7/7.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAWatchDebug : EABaseModel

/** 操作 0设备的死机信息 1设备的内存信息*/
@property(nonatomic, assign) NSInteger eOps;

/** 内存地址 */
@property(nonatomic, assign) NSInteger memAddr;

/** 内存数据长度 */
@property(nonatomic, assign) NSInteger memDataLen;

/** 设备返回值，当ops=error_log时string显示此项，当ops=mem_log时16进制显示此项 */
@property(nonatomic,strong) NSString *log;


/// MARK: - 获取设备表盘信息
+ (EAWatchDebug *)getModelByData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
