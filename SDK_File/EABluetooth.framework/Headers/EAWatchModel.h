//
//  EAWatchModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/18.
//

#import <EABluetooth/EABaseModel.h>
#import <EABluetooth/EARespondModel.h>
#import <EABluetooth/EARequestModel.h>
NS_ASSUME_NONNULL_BEGIN



/// id = 3: Watch the information
/// id = 3: 手表信息
@interface EAWatchModel : EABaseModel

/// Watch SN no.
/// 手表SN号：
@property(nonatomic, copy) NSString *id_p;

/// Watch models
/// 手表型号
@property(nonatomic, copy) NSString *type;

/// firmware version
/// 固件版本：
@property(nonatomic, copy) NSString *firmwareVersion;

/// Whether the binding
/// 是否绑定
@property(nonatomic, assign) EABindingType bindingType;

/// userId
/// 用户id
@property(nonatomic, strong) NSString *userId;


/// The last update timestamp of the watch AGPS. 0 indicates that it has not been updated
/// 手表agps的最后更新时间戳，0为没更新过
@property(nonatomic, assign) NSInteger agpsUpdateTimestamp;

/// watch MAC Address
/// 手表MAC地址
@property(nonatomic, strong) NSString *bleMacAddr;

/// Whether to wait for the device to confirm the binding
/// 是否需要等待设备确认绑定
@property(nonatomic,assign) NSInteger isWaitForBinding;

/// 手表功能列表: 0 不支持 1:支持
/// Watch function list: 0 Not supported 1: supported
/// see class EAWatchSupportModel
@property(nonatomic, assign) BOOL projSettings;

/// 手表尺寸-宽度
/// Watch size - width
@property(nonatomic, assign) NSInteger width;

/// 手表尺寸-高度
/// Watch size - height
@property(nonatomic, assign) NSInteger height;

/// 手表缩略图尺寸-宽度
/// Watch thumbnail size - width
@property(nonatomic, assign) NSInteger thumbnailWidth;

/// 手表缩略图尺寸-高度
/// Watch thumbnail size - height
@property(nonatomic, assign) NSInteger thumbnailHeight;

/// 手表缩略图-圆角
/// Watch thumbnail - Rounded corners
@property(nonatomic, assign) NSInteger thumbnailRadius;

/// 手表屏幕类型: 0:方屏 1:圆屏
/// Screen type: 0: square screen 1: round screen
@property(nonatomic, assign) EAScreenType screenType;

/// 不支持sn号绑定手表: 0:支持 1:不支持
/// Binding a watch sn is not supported: 0: The watch SN is supported. 1: The watch SN is not supported
@property(nonatomic, assign) NSInteger notSupportSn;

/// 最大支持表盘内存大小（存储空间,单位KB）
/// Maximum supported dial memory size (storage space, unit KB)
@property(nonatomic, assign) NSInteger maxWatchSize;

/// LCD像素类型: 0: RGB565 1: GXGPU_RGB888
/// LCD pixel type: 0: RGB565 1: GXGPU_RGB888 2: ARGB8565(杰理) 
@property(nonatomic, assign) NSInteger lcdPixelType;


/// 支持闹钟数量：0:默认支持10个  n:支持n个
/// Number of alarms supported: 0: 10 alarms are supported by default. n: n alarms are supported
@property(nonatomic, assign) NSInteger numOfAlarmSupported;

/// 支持日程数量：0:默认支持10个  n:支持n个
/// Number of supported schedules: 0: 10 by default n: n supported
@property(nonatomic, assign) NSInteger numOfScheduleSupported;

/// apollo
@property(nonatomic,readonly) NSString *apbVerion;

/// res
@property(nonatomic,readonly) NSString *resVerion;

/// number version  -> x.x.x
@property(nonatomic,readonly) NSString *numberVersion;

@end

NS_ASSUME_NONNULL_END
