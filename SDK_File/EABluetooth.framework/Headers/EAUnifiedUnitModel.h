//
//  EALengthUnitModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN



/// id = 11 : 手表单位（公制、英制）
/// id = 11 : 手表单位（公制、英制）
@interface EAUnifiedUnitModel : EABaseModel


@property(nonatomic, assign) EAUnifiedUnit unit;






@end

NS_ASSUME_NONNULL_END
