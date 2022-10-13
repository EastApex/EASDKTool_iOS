//
//  EARespondModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 回应数据
@interface EARespondModel : EABaseModel

/** 协议请求的id号 */
@property(nonatomic, assign) EADataInfoType requestId;

@property(nonatomic, assign) EARespondCodeType eErrorCode;


/// 获取回应数据
/// @param data 数据流
+ (EARespondModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
