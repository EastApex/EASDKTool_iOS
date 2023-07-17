//
//  EABleConfig.h
//  Template
//
//  Created by Aye on 2021/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#define EALog(format, ...) {\
if ([EABleConfig logEnable]) {\
NSLog(@"[EASDKLog]%s-%d " format, __func__,__LINE__, ##__VA_ARGS__);\
if ([EABleConfig saveLogEnable]) {\
NSString *logFirstString = [NSString stringWithFormat:@"【%s:%d】** ",__func__,__LINE__];\
NSString *logString = [NSString stringWithFormat:@""format,##__VA_ARGS__];\
[EABleConfig writeLog:[logFirstString stringByAppendingString:logString]];\
}\
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
@property (nonatomic, assign) NSInteger scanchannel __attribute__((deprecated));

/// 测试专用（请在调试阶段设置使用=》0:删除大数据，1:不删除大数据）
/// Test special (please set use in the debugging stage => 0: delete big data, 1: do not delete big data)
@property (nonatomic, assign) NSInteger isTest;

/// Whether to save logs. This parameter is disabled by default.This function takes effect only when debug is set to YES
/// 是否保存日志，默认关闭,需要 debug 为YES才能起作用
@property (nonatomic, assign) BOOL saveLog;

/// SDK不开启重连手表，默认关闭
@property (nonatomic, assign) BOOL sdkNotOpenReconnectWatch;

/// 默认 ”8800“
@property (nonatomic, copy) NSArray *uuids;

/// Enable command timeout response.  Defalut NO,
@property (nonatomic, assign) BOOL openCmdTimeOut;

/// ignore：
/// 工具 ，默认关闭
@property (nonatomic, assign) BOOL tool;

/// ignore：
/// 工厂
@property (nonatomic, assign) BOOL factory;

/// ignore：
/// 扫描所有设备 ，默认关闭
@property (nonatomic, assign) BOOL canScanAllDevices;



/// 初始化默认配置,不是单例（debug:NO,scanchannel:8800,canScanAllDevices:NO,isTest:NO,saveLog:NO）
+ (EABleConfig *)getDefaultConfig;


+ (BOOL)logEnable;

+ (BOOL)toolEnable;

+ (BOOL)saveLogEnable;


+ (void)writeLog:(NSString *)logLastString;
@end

NS_ASSUME_NONNULL_END
