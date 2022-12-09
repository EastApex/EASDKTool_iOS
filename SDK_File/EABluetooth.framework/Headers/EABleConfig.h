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
NSLog(@"[EALog]:%s:%d 👻 " format, __func__,__LINE__, ##__VA_ARGS__);\
}\
}\


@interface EABleConfig : NSObject

/// Whether to print logs. This function is disabled by default
/// 是否打印日志，默认关闭
@property (nonatomic, assign) BOOL debug;

/// Search for the watch's Bluetooth name
/// 搜索手表的蓝牙名称
@property (nonatomic, copy) NSArray *deviceHeadNames;

/// 检索通道设备：默认8800
@property (nonatomic, assign) NSInteger scanchannel;

/// 测试专用（请在调试阶段设置使用=》0:删除大数据，1:不删除大数据）
@property (nonatomic, assign) NSInteger isTest;

/// ignore：
/// 工具 ，默认关闭
@property (nonatomic, assign) BOOL tool;

/// ignore：
/// 扫描所有设备 ，默认关闭
@property (nonatomic, assign) BOOL canScanAllDevices;

/// ignore：
/// 显示信号量 ，默认关闭
//@property (nonatomic, assign) BOOL showRSSI;


/// 初始化默认配置,不是单例（debug:NO,scanchannel:8800,canScanAllDevices:NO,isTest:0）
+ (EABleConfig *)getDefaultConfig;


+ (BOOL)logEnable;

+ (BOOL)toolEnable;
@end

NS_ASSUME_NONNULL_END
