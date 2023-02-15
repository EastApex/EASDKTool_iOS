//
//  EABloodPressureModel.h
//  EABluetooth
//
//  Created by Aye on 2021/9/26.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

// disuse
// 弃用
/// id = 35: 血压值校准
@interface EABloodPressureModel : EABaseModel


/** 高血压值校准值 */
@property(nonatomic, assign) NSInteger highBloodVal;

/** 低血压值校准值 */
@property(nonatomic, assign) NSInteger lowBloodVal;



@end

NS_ASSUME_NONNULL_END
