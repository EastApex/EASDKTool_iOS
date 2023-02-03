//
//  EAAppOps.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 48 ：启动手表测量（App主动开启）
/// id = 48: Start watch measurement (App actively starts)
///
/// 监听通知【kNTF_EAAppOpsData】并实现通知方法获取EAAppOpsDataModel对象
/// Listen to the notification [kNTF_EAAppOpsData] and implement the notification method to obtain the EAAppOpsDataModel object
@interface EAAppOps : EABaseModel


/// App操作手表类型
/// App operation watch type
@property(nonatomic, assign) EAAppOpsType eAppOpsType;


/// 0 stops, 1 starts
/// 0停止，1开启
@property(nonatomic, assign) BOOL sw;


/// Initialization method【初始化方法】
/// - Parameters:
///   - appOpsType: App operation watch type【App操作手表类型】
///   - sw: stop or start 【0停止，1开启】
+ (instancetype )eaInitWithAppOpsType:(EAAppOpsType )appOpsType sw:(BOOL)sw;

@end

NS_ASSUME_NONNULL_END
