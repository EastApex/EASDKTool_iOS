//
//  EABloodOxygenDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/23.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN


/// 血氧数据
@interface EABloodOxygenDataModel : EABigDataModel


/// blood Oxygen
/// 血氧
@property(nonatomic, assign) NSInteger bloodOxygenValue;

@end

@interface EABloodOxygenData : EABaseBigDataModel


@property(nonatomic, strong) NSMutableArray<EABloodOxygenDataModel*> *sIndexArray;

+ (EABloodOxygenData *)getBloodOxygenData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
