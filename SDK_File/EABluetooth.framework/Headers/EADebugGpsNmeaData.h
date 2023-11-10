//
//  EADebugGpsNmeaData.h
//  EABluetooth
//
//  Created by Aye on 2023/10/31.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN



@interface EADebugGpsNmeaData : EABaseBigDataModel

/** 透传的log */
@property(nonatomic, strong) NSString *log;

+ (EADebugGpsNmeaData *)getBigData:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
