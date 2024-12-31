//
//  EAMuslimDirectionTime.h
//  EABluetooth
//
//  Created by Aye on 2024/11/13.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


@interface EAMuslimTimeItem : EABaseModel

@property(nonatomic, assign) NSInteger fajrTimestamp;

@property(nonatomic, assign) NSInteger sunRiseTimestamp;

@property(nonatomic, assign) NSInteger dhuhrTimestamp;

@property(nonatomic, assign) NSInteger asrTimestamp;

@property(nonatomic, assign) NSInteger maghribTimestamp;

@property(nonatomic, assign) NSInteger ishaTimestamp;


@end



@interface EAMuslimDirectionTime : EABaseModel

@property(nonatomic, strong) NSMutableArray<EAMuslimTimeItem*> *daydirArray;

@property(nonatomic, assign) NSInteger kneelerDir;

@end

NS_ASSUME_NONNULL_END
