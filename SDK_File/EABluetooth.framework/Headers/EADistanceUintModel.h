//
//  EADistanceUintModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

// disuse
// 弃用
/// id = 24: Distance the unit
/// id = 24: 距离单位
@interface EADistanceUintModel : EABaseModel

@property(nonatomic, assign) EADistanceUnit unit;



@end

NS_ASSUME_NONNULL_END
