//
//  EASportHrData.h
//  EABluetooth
//
//  Created by Aye on 2023/6/29.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// 心率数据
@interface EASportHrModel : EABigDataModel

/// heart rate
/// 心率值
@property(nonatomic, assign) NSInteger hrValue;

@end

@interface EASportHrData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EASportHrModel*> *sIndexArray;

+ (EASportHrData *)getBigData:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
