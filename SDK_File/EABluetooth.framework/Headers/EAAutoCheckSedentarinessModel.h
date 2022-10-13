//
//  EAAutoCheckSedentarinessModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN

/// Sedentary monitoring
/// 久坐监测
@interface EAAutoCheckSedentarinessModel : EABaseModel

///  Interval: The unit is minute. 0 indicates that the monitoring function is disabled
/// 间隔时长：单位分钟，0为关闭监测功能
@property(nonatomic, assign) NSInteger  interval;

/** 周期：位对应从bit0~bit6对应周日~周六
    The same of EAAutoCheckSleepModel.weekCycleBit
 */
@property(nonatomic, assign) NSInteger  weekCycleBit;


@property(nonatomic, assign) NSInteger  beginHour;


@property(nonatomic, assign) NSInteger  beginMinute;


@property(nonatomic, assign) NSInteger  endHour;

@property(nonatomic, assign) NSInteger  endMinute;

/// Step threshold: Below this threshold indicates sedentary behavior
/// 步数阈值 ：低于此步数则提醒久坐
@property(nonatomic, assign) NSInteger  stepThreshold;


/// 久坐开关 (10:关闭，11:打开)（如果手机能读到10或11，代表设备已经支持了这个开关，就不用interval来控制关闭了）
@property(nonatomic, assign) NSInteger sw;



+ (EAAutoCheckSedentarinessModel *)getModelByData:(NSData *)data;




@end

NS_ASSUME_NONNULL_END
