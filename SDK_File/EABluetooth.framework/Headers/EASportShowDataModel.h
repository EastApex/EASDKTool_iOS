//
//  EASportShowDataModel.h
//  EABluetooth
//
//  Created by Aye on 2022/5/30.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 40: 手表日常界面数据
/// id = 40: daily interface data of the watch
@interface EASportShowDataModel : EABaseModel

@property(nonatomic, assign) NSInteger steps; // 单位：步

@property(nonatomic, assign) NSInteger calorie;// 单位：小卡

@property(nonatomic, assign) NSInteger distance;// 单位：厘米

@property(nonatomic, assign) NSInteger duration;// 单位:秒



@end

NS_ASSUME_NONNULL_END
