//
//  EASportShowDataModel.h
//  EABluetooth
//
//  Created by Aye on 2022/5/30.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EASportShowDataModel : EABaseModel

@property(nonatomic, assign) NSInteger steps; // 单位：步

@property(nonatomic, assign) NSInteger calorie;// 单位：小卡

@property(nonatomic, assign) NSInteger distance;// 单位：厘米

@property(nonatomic, assign) NSInteger duration;// 单位:秒

+ (EASportShowDataModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
