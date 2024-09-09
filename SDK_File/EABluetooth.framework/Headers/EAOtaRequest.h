//
//  EAOtaRequest.h
//  EABluetooth
//
//  Created by Aye on 2021/3/23.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAOtaRequest : EABaseModel

/// ota类型 
@property(nonatomic, assign) EAOtaRequestType eType;

/// 该类型版本号（大小详见对应OPTIONS文件） 
@property(nonatomic, copy) NSString *version;

/// 全部类型ota数据的总字节大小 
@property(nonatomic, assign) NSInteger totalSize;

/// 当前类型ota数据的字节大小 
@property(nonatomic, assign) NSInteger currentSize;

/// 如果当前类型是res，这个res_addr是从res的bin中截取前4个字节 
@property(nonatomic, assign) NSInteger resAddr;

/// 当前类型ota数据的16bit的crc码 
@property(nonatomic, assign) uint16_t crc;

/// 多少字节数据后等待设备数据包回应（影响ota速度: 根据手机性能调整，最高2048字节）
@property(nonatomic, assign) NSInteger waitBytes;

/// 是否弹出升级界面 1打开升级页面，0不打开
/// Check whether the upgrade page is displayed. 1 Open the upgrade page. 0 Do not open the upgrade page
@property(nonatomic, assign) NSInteger popUpInterface;


@property(nonatomic, assign) NSInteger isTestMode;

/// 自定义表盘控件位置由固件决定（0:不支持固件更改  1: 数字 2: 指针）
@property(nonatomic, assign) NSInteger WfOtaBefore;

/** 海思字库图库id (一对一对应后面发的bin，不能出错) */
@property(nonatomic, assign) NSInteger hisResId;
@property(nonatomic, assign) NSInteger hisFileNum;


/// MARK: - 
+ (EAOtaRequest *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
