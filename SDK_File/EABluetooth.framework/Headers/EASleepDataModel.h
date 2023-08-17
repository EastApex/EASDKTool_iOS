//
//  EASleepDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 睡眠数据
@interface EASleepDataModel : EABigDataModel

/// sleep status
/// 睡眠node
@property(nonatomic, assign) EASleepNode eSleepNode;

@end


@interface EAUpLoadSleepData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EASleepDataModel*> *sIndexArray;

+ (EAUpLoadSleepData *)getSleepData:(NSData *)data;

@end


@interface EAItemSleepModel : NSObject

@property(nonatomic, assign) EASleepNode eSleepNode;
@property(nonatomic, assign) NSInteger beginTimestamp;
@property(nonatomic, assign) NSInteger endTimestamp;
@property(nonatomic, assign) NSInteger duration;

+ (instancetype)eaInitWithSleepNode:(EASleepNode)eSleepNode beginTimestamp:(NSInteger)beginTimestamp endTimestamp:(NSInteger)endTimestamp duration:(NSInteger)duration;
@end


@interface EAOneSleepModel : NSObject

@property(nonatomic, assign) NSInteger dayTimestamp;

@property(nonatomic, assign) NSInteger beginTimestamp;
@property(nonatomic, assign) NSInteger endTimestamp;

@property(nonatomic, assign) NSInteger lightSleepMinutes;
@property(nonatomic, assign) NSInteger deepSleepMinutes;
@property(nonatomic, assign) NSInteger awakeSleepMinutes;
@property(nonatomic, assign) NSInteger remSleepMinutes;
@property(nonatomic, assign) NSInteger awakeCount;
@property(nonatomic, assign) NSInteger totalMinutes;

@property(nonatomic, assign) NSString *timestamps;
@property(nonatomic, assign) NSString *sleepNodes;
@property(nonatomic,strong) NSArray<EAItemSleepModel *> *itemSleepArray;
@end


@interface EADaySleepModel : NSObject

@property(nonatomic,strong) NSArray<EAOneSleepModel *> *oneSleepArray;
@property(nonatomic, assign) NSInteger dayTimestamp;

@end




NS_ASSUME_NONNULL_END
