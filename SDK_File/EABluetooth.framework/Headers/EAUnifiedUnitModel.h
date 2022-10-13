//
//  EALengthUnitModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN



@interface EAUnifiedUnitModel : EABaseModel


@property(nonatomic, assign) EAUnifiedUnit unit;


+ (EAUnifiedUnitModel *)getModelByData:(NSData *)data;



@end

NS_ASSUME_NONNULL_END
