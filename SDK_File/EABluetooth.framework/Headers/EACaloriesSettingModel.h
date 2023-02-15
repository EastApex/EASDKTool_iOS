//
//  EACaloriesSettingModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 27: Base calorie switch
/// id = 27: 基础卡路里开关
@interface EACaloriesSettingModel : EABaseModel

/// Switch: 0 Off 1 on
/// 开关： 0关闭 1打开
@property(nonatomic, assign) NSInteger sw;



+ (instancetype)eaInitWithSwitch:(NSInteger)sw;


@end

NS_ASSUME_NONNULL_END
