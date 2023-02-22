//
//  EAStepFreqDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 步频数据
@interface EAStepFreqDataModel : EABigDataModel


/// stride frequency
/// 步频值
@property(nonatomic, assign) NSInteger stepFreqValue;

@end

@interface EAStepFreqData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EAStepFreqDataModel*> *sIndexArray;

+ (EAStepFreqData *)getStepFreqData:(NSData *)data;


@end
NS_ASSUME_NONNULL_END
