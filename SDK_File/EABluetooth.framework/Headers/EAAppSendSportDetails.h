//
//  EAAppSendSportDetails.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// 发送APP记录运动信息
/// 运动暂停后，需要停止发送此命令，如果需要恢复运动，继续发此命名给手表即可
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
