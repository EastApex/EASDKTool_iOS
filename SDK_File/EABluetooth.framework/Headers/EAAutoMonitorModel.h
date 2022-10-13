//
//  EAAutoMonitorModel.h
//  EABluetooth
//
//  Created by Aye on 2021/9/26.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAAutoMonitorModel : EABaseModel

/** 心率自动监测 */
@property(nonatomic, assign) NSInteger heartCheckSw;

/** 血氧自动监测 */
@property(nonatomic, assign) NSInteger bloodOxyCheckSw;

/** 血压自动监测 */
@property(nonatomic, assign) NSInteger bloodPressureCheckSw;

/** 自动监测 间隔（分钟）*/
@property(nonatomic, assign) NSInteger checkTime;

+ (EAAutoMonitorModel *)getModelByData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
