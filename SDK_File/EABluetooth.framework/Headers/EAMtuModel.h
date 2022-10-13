//
//  EAMtuModel.h
//  EABluetooth
//
//  Created by Aye on 2021/7/1.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAMtuModel : EABaseModel

/** 目前连接的mtu值 */
@property(nonatomic, readwrite) uint32_t mtuValue;


/// 获取手机和设备之间的mtu信息
/// @param data 数据流
+ (EAMtuModel *)getModelByData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
