//
//  EABloodPressureModel.h
//  EABluetooth
//
//  Created by Aye on 2021/9/26.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EABloodPressureModel : EABaseModel


/** 高血压值校准值 */
@property(nonatomic, assign) NSInteger highBloodVal;

/** 低血压值校准值 */
@property(nonatomic, assign) NSInteger lowBloodVal;


+ (EABloodPressureModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
