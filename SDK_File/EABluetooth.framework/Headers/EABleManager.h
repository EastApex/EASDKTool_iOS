//
//  EABleManager.h
//  Template
//
//  Created by Aye on 2021/3/15.
//  version: 2022.12.06 

/**

 Demo & SDK
 https://github.com/EastApex/EASDKTool_iOS.git
 
 SDK access documentation
 https://www.showdoc.com.cn/2042713679210858/0
 
 Date：2023-11-27
 Version：1.0.87.4
 
 1.Fix menstruation-prone digital display issues【修复经期易孕期数字显示问题】

  */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "EAPeripheralModel.h"
#import "EABleConfig.h"
#import <EABluetooth/EAEnum.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN


/// Connect status
/// MARK: -  绑定类型
typedef NS_ENUM(NSUInteger, EAConnectStatus) {
    
    /// Connect failed
    /// 连接失败
    EAConnectStatusFailed = 0,
    
    /// Connect succeed
    /// 连接成功
    EAConnectStatusSucceed = 1,
    
    /// Disconnect
    /// 断开连接
    EAConnectStatusDisconnect = 2,
    
    /// Bluetooth on
    /// 蓝牙开启
    EABlePoweredOn = 3,
    
    /// Bluetooth off
    /// 蓝牙关闭
    EABlePoweredOff = 4,
    
    /// Connect failed and need removed pairing
    /// 连接失败,需要忽略设备
    EAConnectStatusFailedWithRemovedPairing = 5,
    
    /// Connect failed time out
    /// 连接失败,超时
    EAConnectStatusFailedWithTimeOut = 6,
    
};

/// Notification Name:Connect failed
/// 连接失败
#define kNTF_EAConnectStatusFailed              @"EAConnectStatusFailed"

/// Notification Name:Connect succeed
/// 连接成功（已获取服务）
#define kNTF_EAConnectStatusSucceed             @"EAConnectStatusSucceed"

/// Notification Name: Disconnect
/// 断开连接
#define kNTF_EAConnectStatusDisconnect          @"EAConnectStatusDisconnect"

/// Notification Name:Connection attempt succeeded (service not obtained)
/// 尝试连接成功（未获取服务）
#define kNTF_EAConnectStatusSucceedUnGetServer  @"EAConnectStatusSucceedUnGetServer"

/// Connecting
/// 连接中
#define kNTF_EAConnectStatusConnecting          @"EAConnectStatusConnecting"

/// ANCS
#define kNTF_EAEADidUpdateANCSAuthorization     @"EADidUpdateANCSAuthorization"

/// Notification Name: Bluetooth on
/// 蓝牙开启
#define kNTF_EABlePoweredOn                 @"EABlePoweredOn"
/// Notification Name: Bluetooth off
/// 蓝牙关闭
#define kNTF_EABlePoweredOff                @"EABlePoweredOff"

/// Notification Name: Receive a mobile phone message from the watch
/// 收到手表发送的操作手机消息
#define kNTF_EAGetDeviceOpsPhoneMessage     @"EAGetDeviceOpsPhoneMessage"

/// Notification Name: OTA data transmission is complete
/// OTA数据传输完成
#define kNTF_EAOTAAGPSDataFinish            @"EAOTADataFinish"

/// Notification Name: OTA progress
/// OTA进度
#define kNTF_EAOTAAGPSDataing               @"EAOTADataing"


/// Notification Name: OTA progress fail
/// OTA失败
#define kNTF_EAOTAFail                      @"EAOTAFail"




/// 实时数据
/// Real time data
#define kNTF_EARealTimeData                 @"EARealTimeData"

/// App运动实时数据
/// App sport real time data
#define kNTF_EAAppSportRealTime             @"EAAppSportRealTime"

/// 上报启动手表测量结果【id = 48 测量结果）】
/// Report the measurement result of starting the watch [id = 48 measurement result]
#define kNTF_EAAppOpsData                   @"EAAppOpsData"


/// 回复信息
/// ReplayMessage
#define kNTF_EAReplayMessage                @"EAReplayMessage"



/// GPS bug
#define kNTF_EADebugGpsNmeaData             @"EADebugGpsNmeaData"



#define kKeychainService                    @"com.eastapex.bluetooth"
#define kKeychainDataAccount                @"data_apexwear"


@protocol EABleManagerDelegate <NSObject>


/// Scanning Discovered watch (in real time)
/// 扫描发现的设备 （实时）
/// @param peripheralModel peripheral 设备
- (void)didDiscoverPeripheral:(EAPeripheralModel *)peripheralModel;

@end

/// Bluetooth data Broker
/// 蓝牙数据代理
@protocol EABleManagerDataDelegate <NSObject>

/// Bluetooth data 蓝牙数据
/// @param characteristic characteristic 通道
/// @param error error 错误信息
- (void)updateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

@end





/// Bluetooth data
/// 蓝牙数据
typedef void(^UpdateValueBlock)(CBCharacteristic *characteristic,NSError *error);

@interface EABleManager : NSObject

/// The bluetooth Settings
/// 蓝牙设置
@property (nonatomic,strong) EABleConfig *bleConfig;

/// Searching for watch Agents
/// 搜索设备代理
@property(nonatomic,assign) id<EABleManagerDelegate> delegate;

/// ignore：Bluetooth data Broker
/// 忽略：蓝牙数据代理
@property(nonatomic,weak) id<EABleManagerDataDelegate> dataDelegate;

/// Watch connection status
/// 连接设备状态
@property(nonatomic,assign) EAConnectStateType connectState;

/// 当前连接的设备
/// Currently connected device
@property (nonatomic, strong) EAPeripheralModel *eaPeripheralModel;

/// 蓝牙状态
/// Bluetooth status
@property(nonatomic,assign) EABleState bleState;

/// The singleton
/// 单例
+ (instancetype)defaultManager;


#pragma mark - Equipment related Methods 设备相关方法

/// scan watch
/// 扫描
- (void)scanPeripherals;

/// stop scan watch
/// 停止扫描设备
- (void)stopScanPeripherals;

/// connect watch
/// 连接设备
- (void)connectToPeripheral:(EAPeripheralModel *)peripheralModel;

/// reconnection
/// 重连设备
- (void)reConnectToPeripheral;

/// reconnection（Need the SN number or mac address of the watch）
/// 重连设备（传手表的SN号或者mac address）
- (void)reConnectToPeripheral:(NSString *)sn;

/// reconnection（Need the uuidString of the watch）
/// 重连设备（传手表的uuidString）
- (void)reConnectToPeripheralWithUUIDString:(NSString *)uuidString;

/// Cancel connection
/// 取消连接（连接时可用）
- (void)cancelConnectingPeripheral;

/// Disconnect the watch. Restart the App, and EASDK will automatically connect the watch.
/// 断开手表连接。重启App，EASDK自动连接。
- (void)disconnectPeripheral;


/// Disconnect the watch. Restart the App, EASDK will not automatically connect to the watch.
/// 断开手表连接。重启App，EASDK不会自动连接。
- (void)disconnectAndNotReConnectPeripheral;

/// Disconnect the watch. Restart the App, EASDK will not automatically connect to the watch.
/// 断开手表连接。重启App，EASDK不会自动连接。
- (void)unbindPeripheral DEPRECATED_MSG_ATTRIBUTE("Please use \"disconnectAndNotReConnectPeripheral\"");


/// Disconnect from the watch and reset and clear the watch data.
/// 断开与手表的连接，重置并清除手表数据。
- (void)unbindAndResetPeripheral;



/// Check whether to enable Bluetooth
/// 是否开启蓝牙
- (BOOL)isBleOn;

/// Check whether the watch is connected
/// 是否已连接设备
- (BOOL)isConnected;

/// Gets the connected watch
/// 获取连接的设备信息
- (EAPeripheralModel *)getPeripheralModel;

#pragma mark 分析广播包
- (EAPeripheralModel *)analyseAdvertisementData:(NSDictionary *)advertisementData peripheral:(CBPeripheral *)peripheral  RSSI:( NSNumber *)RSSI;

/// ignore：
- (void)writeValue:(NSData *)Data forCharacteristic:(EACharacteristicType )characteristicType;

- (BOOL)isScanning;


@end

NS_ASSUME_NONNULL_END
