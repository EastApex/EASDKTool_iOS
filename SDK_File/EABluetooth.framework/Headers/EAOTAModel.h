//
//  EAOTAModel.h
//  EABluetooth
//
//  Created by Aye on 2021/6/30.
//


#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


 /**
 
  * 手表固件版本显示形式：AP0.1B1.2R0.1T0.1H0.1
  * OTA文件名称规则：
 
  * 手表固件名称：001001_AP0.1B1.2.bin
  * AP是大版本，B后面是小版本
  * 大版本指的是测试确认版本，假如某个版本确认了，那就这个版本+1
  * B是在这个版本下的小版本，用于修改各种bug，增加需求
 
  * 字库名称：001001_R0.1.bin
  * 屏幕名称：001001_T0.1.bin
  * 心率名称：001001_H0.1.bin
 
  * 001001 是手表的特定标识
  *
  */

 /**
  * 假设 当前手表 firmwareVersion => AP0.1B0.9R0.3T0.1G0.1
  * AP0.1B0.9 => 固件版本号是0.1 build 0.9
  * R0.3=>字库版本号是0.3
  * T0.1=>屏幕版本号0.1
  * H0.1=>心率版本号0.1
  *
  * 有新的 固件版本号 是 AP0.1B1.0 和 AP0.1B1.1
  * 有新的 字库版本号是 R0.4 和 R0.5
  *
  * 固件版本升级 升级 最大版本号就可以了，即升级 AP0.1B1.1，不需要升级 AP0.1B1.0
  * 字库版本升级 需要升级所有比当前字库版本大的版本，即 R0.4 和 R0.5都要升级
  * 屏幕和心率同固件一样逻辑，升级最大版本的就行
  */






@interface EAFileModel : EABaseModel

/// Ota type
///ota类型
@property(nonatomic,assign) EAOtaRequestType otaType;

/// Bin Indicates the path where the package is stored(binPath or binData just pass one of these values.)
/// bin包所在路径（binPath 或者 binData 2传一即可）
@property(nonatomic,strong) NSString *binPath;

/// The version number
/// 版本号
@property(nonatomic,copy) NSString *version;

/// Data flow of the bin file(binPath or binData just pass one of these values.)
/// bin文件的数据流（binPath 或者 binData 2传一即可）
@property(nonatomic,strong) NSData *binData;


/// set watch face id,max 32.   ==> watchFaceId.lenght <= 32
/// 设置表盘id，最长32
@property(nonatomic,strong) NSString *watchFaceId;



/// init
+ (EAFileModel *)eaInitWithPath:(NSString *)binPath otaType:(EAOtaRequestType )otaType version:(NSString *)version;
+ (EAFileModel *)eaInitWithData:(NSData *)binData otaType:(EAOtaRequestType )otaType version:(NSString *)version;


/// init watch face file
+ (EAFileModel *)eaInitWatchFaceFileWithPath:(NSString *)binPath version:(NSString *)version watchFaceId:(NSString *)watchFaceId;
+ (EAFileModel *)eaInitWatchFaceFileWithData:(NSData *)binData version:(NSString *)version watchFaceId:(NSString *)watchFaceId;


- (BOOL)checkCanOTAWatchFace;

/// Deprecated
/// 弃用
+ (EAFileModel *)allocInitWithPath:(NSString *)binPath otaType:(EAOtaRequestType )otaType version:(NSString *)version DEPRECATED_MSG_ATTRIBUTE("Please use \"eaInitWithPath: otaType: version:\"");
@end




@interface EAOTAModel : EAFileModel


 ///当前ota Bin 包大小 单位 bytes）
@property(nonatomic,assign) NSInteger currentSize;

 ///当前 crc
@property(nonatomic,assign) uint16_t crc;

 ///当前 AGPS Data
@property(nonatomic,assign) NSData *agpsData;

 ///序号
@property(nonatomic,assign) NSInteger number;



- (NSData *)getOtaData;

- (uint16_t)getCrcValue:(BOOL)isRes;

- (uint16_t)getCrcValue:(BOOL)isRes andBinPath:(NSString *)binPath;

/// 初始化OTA更新
/// @param binPath binPath
/// @param otaType EAOtaRequestType
- (EAOTAModel *)initWithPath:(NSString *)binPath otaType:(EAOtaRequestType )otaType version:(NSString *)version;




@end


@interface EAOTA : EABaseModel

 ///ota的所有数据包
@property(nonatomic,strong) NSMutableArray <EAOTAModel *> *otaModels;

 ///当前ota Bin 包大小 （单位 bytes）
@property(nonatomic,assign) float totalSize;

 ///是否弹出升级界面 1打开升级页面，0不打开
@property(nonatomic, assign) NSInteger popUpInterface;

 ///测试专用：强制升级
@property(nonatomic, assign) NSInteger isTestMode;

@end

NS_ASSUME_NONNULL_END
