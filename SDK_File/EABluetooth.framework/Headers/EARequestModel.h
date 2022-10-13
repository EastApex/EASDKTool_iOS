//
//  EARequestModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/23.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// 请求数据
@interface EARequestModel : EABaseModel

/** 协议请求的id号 */
@property(nonatomic, assign) NSInteger requestId;


+ (NSData *)getModelDataByRequestId:(NSInteger )requestId;

/// 获取回应数据
/// @param data 数据流
+ (EARequestModel *)getModelByData:(NSData *)data;
@end







NS_ASSUME_NONNULL_END
