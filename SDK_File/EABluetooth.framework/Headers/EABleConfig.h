//
//  EABleConfig.h
//  Template
//
//  Created by Aye on 2021/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//自定义打印
#define EALog(format, ...) {\
if ([EABleConfig logEnable]) {\
NSLog(@"[EALog]:%s:%d " format, __func__, __LINE__, ##__VA_ARGS__);\
}\
}\


@interface EABleConfig : NSObject

/// Whether to print logs. This function is disabled by default
/// 是否打印日志，默认关闭
@property (nonatomic, assign) BOOL debug;

/// ignore：
/// 工具 ，默认关闭
@property (nonatomic, assign) BOOL tool;

/// ignore：
/// 显示信号量 ，默认关闭
@property (nonatomic, assign) BOOL showRSSI;

/// Search for the watch's Bluetooth name
/// 搜索手表的蓝牙名称
@property (nonatomic, copy) NSArray *deviceHeadNames;

/// ignore：
/// 检索通道设备
@property (nonatomic, assign) NSInteger scanchannel;

/// ignore：
/// 扫描所有设备 ，默认关闭
@property (nonatomic, assign) BOOL canScanAllDevices;

/// ignore：
/// 测试专用（请勿设置）
@property (nonatomic, assign) NSInteger isTest;




/// The singleton
+ (EABleConfig *)getDefaultConfig;


+ (BOOL)logEnable;

+ (BOOL)toolEnable;
@end

NS_ASSUME_NONNULL_END
