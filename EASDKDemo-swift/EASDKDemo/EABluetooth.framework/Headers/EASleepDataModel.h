//
//  EASleepDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 睡眠数据
@interface EASleepDataModel : EABaseModel

/// The time stamp
/// 时间戳
@property(nonatomic, assign) NSInteger timeStamp;

/// sleep status
/// 睡眠node
@property(nonatomic, assign) EASleepNode eSleepNode;

@end


@interface EAUpLoadSleepData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EASleepDataModel*> *sIndexArray;

+ (EAUpLoadSleepData *)getSleepData:(NSData *)data;

@end



NS_ASSUME_NONNULL_END
