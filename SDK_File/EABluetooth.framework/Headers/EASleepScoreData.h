//
//  EASleepScoreData.h
//  EABluetooth
//
//  Created by Aye on 2023/6/29.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EASleepScoreModel : EABigDataModel

/// 睡眠得分
/// sleep score
@property(nonatomic, assign) NSInteger sleepScore;

/// 睡眠起始时间戳
/// begin timeStamp
@property(nonatomic, assign) NSInteger beginTimeStamp;

/// 睡眠停止时间戳
/// end timeStamp
@property(nonatomic, assign) NSInteger endTimeStamp;

@end

@interface EASleepScoreData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EASleepScoreModel*> *sIndexArray;

+ (EASleepScoreData *)getBigData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
