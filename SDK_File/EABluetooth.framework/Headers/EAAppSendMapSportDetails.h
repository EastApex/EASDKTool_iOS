//
//  EAAppSendSportDetails.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 47 ：发送APP记录运动信息[运动暂停后，需要停止发送此命令，如果需要恢复运动，继续发此命名给手表即可]
/// id = 47: send APP to record the motion information [after the motion is suspended, you need to stop sending this command, if you need to resume the motion, you can continue to send this name to the watch]
@interface EAAppSendMapSportDetails : EABaseModel

/// 当前总运动时长(单位:秒)
/// Current total exercise duration (unit: second)
@property(nonatomic, assign) NSInteger duration;

/// 当前总距离（单位:厘米）
/// Current total distance (unit: cm)
@property(nonatomic, assign) NSInteger distance;

/// 当前配速（单位: S/KM）
/// Current pace (unit: S/KM)
@property(nonatomic, assign) NSInteger pace;

/** 断连后需要回传卡路里 */
@property(nonatomic, assign) NSInteger calorie;

/** 断连后需要回传步数 */
@property(nonatomic, assign) NSInteger step;

/** 断连后需要回传总次数（跳绳当前跳了多少下） */
@property(nonatomic, assign) NSInteger count;

/** 当前速度（单位: M/H） */
@property(nonatomic, assign) NSInteger speed;

+ (instancetype )eaInitWithDuration:(NSInteger)duration distance:(NSInteger)distance pace:(NSInteger)pace;

+ (instancetype )eaInitWithDuration:(NSInteger)duration distance:(NSInteger)distance pace:(NSInteger)pace calorie:(NSInteger)calorie step:(NSInteger)step count:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
