//
//  EAFastGetSnNumber.h
//  EABluetooth
//
//  Created by Aye on 2022/9/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CBPeripheral;





@interface EAFastGetSnNumberManager : NSObject




+ (instancetype)defaultManager;


- (NSDictionary *)getSnNumbers;

- (NSArray *)getPairedWatches;

- (void)clear;

@end

NS_ASSUME_NONNULL_END
