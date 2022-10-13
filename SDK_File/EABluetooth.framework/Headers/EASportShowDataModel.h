//
//  EASportShowDataModel.h
//  EABluetooth
//
//  Created by Aye on 2022/5/30.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EASportShowDataModel : EABaseModel

@property(nonatomic, assign) NSInteger steps;

@property(nonatomic, assign) NSInteger calorie;

@property(nonatomic, assign) NSInteger distance;

@property(nonatomic, assign) NSInteger duration;

+ (EASportShowDataModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
