//
//  EADistanceUintModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// Distance the unit
/// 距离单位
@interface EADistanceUintModel : EABaseModel

@property(nonatomic, assign) EADistanceUnit unit;


+ (EADistanceUintModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
