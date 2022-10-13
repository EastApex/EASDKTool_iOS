//
//  EAOTAModel.h
//  EABluetooth
//
//  Created by Aye on 2021/6/30.
//


#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN



@interface EAFileModel : EABaseModel

/// Ota type
///ota类型
@property(nonatomic,assign) EAOtaRequestType otaType;

/// Bin Indicates the path where the package is stored
/// bin包所在路径
@property(nonatomic,strong) NSString *binPath;

/// The version number
/// 版本号
@property(nonatomic,copy) NSString *version;


/// init
+ (EAFileModel *)allocInitWithPath:(NSString *)binPath otaType:(EAOtaRequestType )otaType version:(NSString *)version;

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
