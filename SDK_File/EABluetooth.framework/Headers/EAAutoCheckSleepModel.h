//
//  EAAutoCheckSleepModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN


/// Automatic sleep monitoring
/// 自动睡眠监测设置
@interface EAAutoCheckSleepModel : EABaseModel

/** Cycle: == "Sunday ~ Saturday,
 0: shut down
 1: open
 Eg1: Sunday to Monday to Tuesday to Wednesday to Thursday to Friday to Saturday
 0, 1, 1, 0, 0, 0, 1
 Switch 0110001 from binary to hexadecimal. That is, weekCycleBit is 49. Enable the Monday Tuesday check

 Eg2: Sunday to Monday to Tuesday to Wednesday to Thursday to Friday to Saturday
 0 0 0 0 0 1 1
 Change 0000010 binary to 10. WeekCycleBit is set to 3 to enable Friday and Saturday check

 When weekCycleBit is set to 0, the monitoring function is disabled
*/
 
/** 周期：==》周日~周六，
 0：关闭
 1：开启
 eg1：周日 ~ 周一 ~ 周二 ~ 周三 ~ 周四 ~ 周五 ~ 周六
      0     1      1     0     0     0      1
 将 0110001 二进制转为 10进制 即此时 weekCycleBit 为 49 开启 周一二六 检测
 
 eg2：周日 ~ 周一 ~ 周二 ~ 周三 ~ 周四 ~ 周五 ~ 周六
      0     0      0     0     0      1     1
 将 0000010 二进制转为 10进制 即此时 weekCycleBit 为 3 开启 周五六 检测
 
 weekCycleBit 为0 即 关闭监测功能
 */

/// cycle
@property(nonatomic, assign) NSInteger weekCycleBit;

@property(nonatomic, assign) NSInteger beginHour;

@property(nonatomic, assign) NSInteger beginMinute;

@property(nonatomic, assign) NSInteger endHour;

@property(nonatomic, assign) NSInteger endMinute;


+ (EAAutoCheckSleepModel *)getModelByData:(NSData *)data;




@end

NS_ASSUME_NONNULL_END
