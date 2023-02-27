//
//  EAAppOpsDataModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/2.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 2009 : 上报启动手表测量结果【主动上报 8801=>id = 48 测量结果）】
/// id = 2009: report the measurement result of start watch [Report the measurement result of 8801=>id = 48 voluntarily]
///
/// 监听通知【kNTF_EAAppOpsData】并实现通知方法获取EAAppOpsDataModel对象
/// Listen to the notification [kNTF_EAAppOpsData] and implement the notification method to obtain the EAAppOpsDataModel object
@interface EAAppOpsDataModel : EABaseModel

/// App操作手表类型
/// App operation watch type
@property(nonatomic, assign) EAAppOpsType eAppOpsType;

/// 结果
@property(nonatomic, assign) NSInteger value;

/// 状态：0失败 1成功 2开始测量
@property(nonatomic, assign) NSInteger status;

@end

NS_ASSUME_NONNULL_END
