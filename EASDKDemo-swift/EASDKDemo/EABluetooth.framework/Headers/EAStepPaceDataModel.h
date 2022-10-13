//
//  EAStepPaceDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN

///配速数据
@interface EAStepPaceDataModel : EABaseModel

/// The time stamp
/// 时间戳
@property(nonatomic, assign) NSInteger timeStamp;

/// Pace value
/// 配速值
@property(nonatomic, assign) NSInteger stepPaceValue;

@end

@interface EAStepPaceData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EAStepPaceDataModel*> *sIndexArray;

+ (EAStepPaceData *)getStepPaceData:(NSData *)data;


@end
NS_ASSUME_NONNULL_END
