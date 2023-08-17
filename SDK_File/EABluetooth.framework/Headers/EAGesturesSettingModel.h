//
//  EAGesturesSettingModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 28: Raise the screen switch
/// id = 28: 抬手亮屏开关
@interface EAGesturesSettingModel : EABaseModel

/// Raised my hand against the bright screen type
@property(nonatomic, assign) EAGesturesBrightType eBrightSrc;

//@property(nonatomic, assign) NSInteger beginHour;
//
//@property(nonatomic, assign) NSInteger beginMinute;
//
//@property(nonatomic,  assign) NSInteger endHour;
//
//@property(nonatomic,  assign) NSInteger endMinute;


/// 【全天候开启】
+ (instancetype)eaInitAllDay;


/// 【关闭】
+ (instancetype)eaInitClose;

@end

NS_ASSUME_NONNULL_END
