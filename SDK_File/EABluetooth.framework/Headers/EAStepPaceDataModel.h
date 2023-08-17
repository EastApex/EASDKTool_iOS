//
//  EAStepPaceDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN

///配速数据
@interface EAStepPaceDataModel : EABigDataModel

/// Pace value
/// 配速值
@property(nonatomic, assign) NSInteger stepPaceValue;

///  Whether it is mile pace; 0: kilometer pace 1:mile pace
/// 是否为英里配速;  0: 公里配速 1:英里配速
@property(nonatomic, assign) NSInteger isMile;
@end

@interface EAStepPaceData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EAStepPaceDataModel*> *sIndexArray;

+ (EAStepPaceData *)getStepPaceData:(NSData *)data;


@end
NS_ASSUME_NONNULL_END
