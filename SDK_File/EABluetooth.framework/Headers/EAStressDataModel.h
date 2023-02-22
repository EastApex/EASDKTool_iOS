//
//  EAStressDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN


/// 压力数据
@interface EAStressDataModel : EABigDataModel

/// stess
/// 压力 
@property(nonatomic, assign) NSInteger stessValue;

/// Stress data type
/// 压力类型
@property(nonatomic, assign) EAStressDataType eType;

@end

@interface EAStressData : EABaseBigDataModel


@property(nonatomic, strong) NSMutableArray<EAStressDataModel*> *sIndexArray;

+ (EAStressData *)getStressData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
