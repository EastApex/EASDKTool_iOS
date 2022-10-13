//
//  EASocialSwitchModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN



/// 社交提醒设置
@interface EASocialOps : EABaseModel

/// on-off
/// 开关
@property(nonatomic, assign) NSInteger sw;

/// Remind the way
/// 提醒方式
@property(nonatomic, assign) EARemindActionType remindActionType;

@end


/// Social alert switch
/// 社交提醒开关
@interface EASocialSwitchModel : EABaseModel

/// incoming call
/// 来电
@property(nonatomic, strong) EASocialOps *sIncomingcall;

/// Missed vall
/// 未知来电
@property(nonatomic, strong) EASocialOps *sMissedcall;

/// Sms
/// 短信
@property(nonatomic, strong) EASocialOps *sSms;

/// Social
/// 社交
@property(nonatomic, strong) EASocialOps *sSocial;


/// 邮件
@property(nonatomic, strong) EASocialOps *sEmail;


/// Schedule
/// 日程
@property(nonatomic, strong) EASocialOps *sSchedule;



+ (EASocialSwitchModel *)getModelByData:(NSData *)data ;


- (NSData *)getModelData ;


@end



NS_ASSUME_NONNULL_END
