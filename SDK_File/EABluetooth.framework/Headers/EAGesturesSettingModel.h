//
//  EAGesturesSettingModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// Raise the screen switch
/// 抬手亮屏开关
@interface EAGesturesSettingModel : EABaseModel

/// Raised my hand against the bright screen type
@property(nonatomic, assign) EAGesturesBrightType eBrightSrc;


@property(nonatomic, assign) NSInteger beginHour;

@property(nonatomic, assign) NSInteger beginMinute;

@property(nonatomic,  assign) NSInteger endHour;

@property(nonatomic,  assign) NSInteger endMinute;


/// MARK: - 获取抬手亮屏开关设置相关信息
/// @param data 数据流
+ (EAGesturesSettingModel *)getModelByData:(NSData *)data;




@end

NS_ASSUME_NONNULL_END
