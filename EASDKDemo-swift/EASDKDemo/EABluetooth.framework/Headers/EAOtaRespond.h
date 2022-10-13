//
//  EAOtaRespond.h
//  EABluetooth
//
//  Created by Aye on 2021/3/23.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAOtaRespond : EABaseModel

/** 协议请求的id号 */
@property(nonatomic, assign) NSInteger requestId;

/** 设备ota状态回应 */
@property(nonatomic, assign) EAOtaRespondStatus eStatus;

/** 当前类型设备已经收到多少字节的数据 */
@property(nonatomic, assign) NSInteger receiveBytes;


/// 获取回应数据
/// @param data 数据流
+ (EAOtaRespond *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
