//
//  EAAppSendSportDetails.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAAppSendSportDetails : EABaseModel

/// 当前总运动时长(单位:秒)
@property(nonatomic, assign) NSInteger duration;

/// 当前总距离（单位:厘米） 
@property(nonatomic, assign) NSInteger distance;

/// 当前配速（单位: S/KM）
@property(nonatomic, assign) NSInteger pace;


+ (instancetype )eaInitWithDuration:(NSInteger)duration distance:(NSInteger)distance pace:(NSInteger)pace;


@end

NS_ASSUME_NONNULL_END
