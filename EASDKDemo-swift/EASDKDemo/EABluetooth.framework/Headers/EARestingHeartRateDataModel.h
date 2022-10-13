//
//  EARestingHeartRateDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/7/21.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN


@interface EARestingHeartRateModel : EABaseModel

/// The time stamp
/// 时间戳
@property(nonatomic, assign) NSInteger  timeStamp;

/// heart rate
/// 心率值
@property(nonatomic, assign) NSInteger  hrValue;

@end


@interface EARestingHeartRateDataModel : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EARestingHeartRateModel*> *sIndexArray;

+ (EARestingHeartRateDataModel *)getRestingHeartRateData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
