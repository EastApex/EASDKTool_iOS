//
//  EABrightnessModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 7 : The screen brightness of watch
/// id = 7 : 屏幕亮度
@interface EABlacklightModel : EABaseModel

/// brightness  0~100
/// 亮度 0~100
@property(nonatomic, assign) NSInteger level;









@end

NS_ASSUME_NONNULL_END
