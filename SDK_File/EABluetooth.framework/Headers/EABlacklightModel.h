//
//  EABrightnessModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

/// The screen brightness of watch
/// 屏幕亮度
@interface EABlacklightModel : EABaseModel

/// brightness  0~100
/// 亮度 0~100
@property(nonatomic, assign) NSInteger level;


/// MARK: - 获取屏幕亮度相关信息
/// @param data 数据流
+ (EABlacklightModel *)getModelByData:(NSData *)data;






@end

NS_ASSUME_NONNULL_END
