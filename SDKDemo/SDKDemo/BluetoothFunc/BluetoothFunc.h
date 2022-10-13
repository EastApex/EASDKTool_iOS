//
//  BluetoothFunc.h
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//


/**
 
 EABluetooth.framework
 主要分为 蓝牙连接类《EABleManager》、蓝牙数据类《EABleSendManager》、配置类《EABleConfig》、各种通知以及手表各种数据模型。
 1.蓝牙连接类《EABleManager》负责手机和手表的搜索、连接等操作。
 2.蓝牙数据类《EABleSendManager》负责与手表的通讯，数据传输。
 3.配置类型《EABleConfig》配置一些设置，EABleManager初始化时被使用
 4.手表各种数据模型，与EABleSendManager配合使用。
 
 《EABleManager》《EABleConfig》
 1.初始化SDK
 EABleConfig *config = [EABleConfig getDefaultConfig];
 config.debug = YES;
 config.deviceHeadNames = @[@"APEX A02",@"APEX M02"]; // 需要支持的蓝牙设备名称
 [[EABleManager defaultManager] setBleConfig:config];
 
 2.搜索设备
 [[EABleManager defaultManager] scanPeripherals];
 [EABleManager defaultManager].delegate = self;  // 协议
 
 3.发现设备 <协议>
 - (void)didDiscoverPeripheral:(EAPeripheralModel *)peripheralModel;
 
 4.连接设备
 [[EABleManager defaultManager] connectToPeripheral:<需要连接的设备>];
 
 5.重连设备
 [[EABleManager defaultManager] reConnectToPeripheral]; // 重连当前已断连的手表
 [[EABleManager defaultManager] reConnectToPeripheral:<sn>];// 重连知道sn号的手表
 
 6.断开设备连接（物理层的断开连接，App不持有手表）
 [[EABleManager defaultManager] disconnectPeripheral];

 7.解绑设备（手表会重置,重启，清空手表所有数据）
 [[EABleManager defaultManager] unbindPeripheral];
 
 
 《EABleSendManager》
 1.获取手表的相关数据  [[EABleSendManager defaultManager] changeInfo:<> respond:^(EABaseModel * _Nonnull baseModel) {}];
   参数说明：EADataInfoType 是手表所支持的数据类型枚举，Eg：EADataInfoTypeWatch 是手表信息，返回 EAWatchModel数据类型
 2.修改手表相关数据     [[EABleSendManager defaultManager] changeInfo:<> respond:^(EARespondModel * _Nonnull respondModel) {}];
 3.OTA升级            [[EABleSendManager defaultManager] upgrade:<>];
   OTA注意事项
   1.OTA类型为 字库Res或者自定义表盘时
 
 4.获取大数据          [[EABleSendManager defaultManager] getBigDataWithBigDataType:(EADataInfoTypeSportsData)];
 
 
 手表各种数据模型
 1.《EARequestModel》请求模型，用于请求手表各种数据，requestId 与 枚举《EADataInfoType》 一致
 2.《EARespondModel》手表收到请求后的回应，成功与失败
 3. 其他各种数据模型明细请到具体的头文件查看。
 
 
 《各种通知》
 手表的状态
 1.连接失败：连接手表失败
 kNTF_EAConnectStatusFailed
 2. 连接成功：连接手表成功
 kNTF_EAConnectStatusSucceed
 3. 断开连接：手表断开连接
 kNTF_EAConnectStatusDisconnect
 
 蓝牙的状态
 4.蓝牙开启
 kNTF_EABlePoweredOn
 5. 蓝牙关闭
 kNTF_EABlePoweredOff
 
 手表操作手机
 6. 收到手表发送的操作手机消息
 kNTF_EAGetDeviceOpsPhoneMessage

 数据传输
 7. OTA数据传输完成
 kNTF_EAOTAAGPSDataFinish
 8.OTA进度
 kNTF_EAOTAAGPSDataing
 
 
 注意事项：
    所有通讯都是单线程。
 
 
*/



#import <Foundation/Foundation.h>
#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface BluetoothFunc : NSObject


/// 绑定操作
+ (void)bingdingWatch:(EABingingOps *)bingdingOps completion:(void (^)(BOOL succ))completion;


/// 获取手表信息
+ (void)getWatchInfo:(void (^)(EAWatchModel *watchModel))completion;

#pragma mark - 用户信息
/// 获取用户相关信息
+ (void)getUserInfo:(void (^)(EAUserModel *userModel))completion;
/// 修改用户信息
+ (void)changeUserInfo:(EAUserModel *)userModel completion:(void (^)(BOOL succ))completion;

#pragma mark - 同步时间
/// 获取手表的时间
+ (void)getWatchTime:(void (^)(EASyncTime *syncTime))completion;
/// 同步手机时间到手表
+ (void)changeSyncTime:(EASyncTime *)syncTime completion:(void (^)(BOOL succ))completion;


#pragma mark - 天气
/// 同步天气
+ (void)changeWeather:(EAWeatherModel *)weatherModel completion:(void (^)(BOOL succ))completion;


#pragma mark - 经期
/// 同步经期数据
+ (void)changeMenstrual:(EAMenstruals *)menstruals completion:(void (^)(BOOL succ))completion;

#pragma mark - 系统表盘
/// 系统表盘
+ (void)changeWatchFaces:(EADialPlateModel *)dialPlateModel completion:(void (^)(BOOL succ))completion ;
@end

NS_ASSUME_NONNULL_END
