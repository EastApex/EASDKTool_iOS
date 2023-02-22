//
//  EAHeartRateModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN


/// 心率数据
@interface EAHeartRateModel : EABigDataModel


/// heart rate
/// 心率值
@property(nonatomic, assign) NSInteger hrValue;

@end

@interface EAUploadHeartRateData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EAHeartRateModel*> *sIndexArray;

+ (EAUploadHeartRateData *)getHeartRatetData:(NSData *)data;

@end



NS_ASSUME_NONNULL_END
