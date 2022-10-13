//
//  EAWeightUnitModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

/// Weight unit
@interface EAWeightUnitModel : EABaseModel

@property(nonatomic, assign) EAWeightUnit unit;

+ (EAWeightUnitModel *)getModelByData:(NSData *)data;



@end

NS_ASSUME_NONNULL_END
