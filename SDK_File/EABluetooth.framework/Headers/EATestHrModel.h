//
//  EATestHrModel.h
//  EABluetooth
//
//  Created by Aye on 2021/8/21.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface EATestHrModel : EABaseBigDataModel

@property(nonatomic, assign) NSInteger hrValue;

+ (EATestHrModel *)getTestHeartRateData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
