//
//  EAWeightUnitModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

// disuse
// 弃用
/// id = 25: Weight unit
/// id = 25: 重量单位
@interface EAWeightUnitModel : EABaseModel

@property(nonatomic, assign) EAWeightUnit unit;





@end

NS_ASSUME_NONNULL_END
