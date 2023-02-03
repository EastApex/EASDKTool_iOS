//
//  EAStressMonitor.h
//  EABluetooth
//
//  Created by Aye on 2023/2/3.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 51 ：自动压力监测
/// id = 51: Automatic pressure monitoring
@interface EAStressMonitor : EABaseModel

/// 0关，1开
/// Zero off, one on
@property(nonatomic, assign) BOOL sw;

/// init【初始化】
/// - Parameters:
///   - sw: on-off Zero off, one on[0关，1开]
+ (instancetype )eaInitWithOnOff:(BOOL)sw;


+ (instancetype )getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
