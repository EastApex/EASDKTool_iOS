//
//  EABaseModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/18.
//

#import <Foundation/Foundation.h>
#import <EABluetooth/EAEnum.h>
#import <YYModel/YYModel.h>
#import <EABluetooth/EADataValue.h>
#import <EABluetooth/EAModelCustomPropertyMapperConfig.h>
#import <EABluetooth/EADataInfoModel.h>
@class GPBMessage;
NS_ASSUME_NONNULL_BEGIN

@interface EABaseModel : NSObject





/// MARK: - 通用转换方法
/// @param data 数据流
/// @param aClass 数据流转换后的类型
+ (instancetype)getClassValueByData:(NSData *)data fromClass:(Class )aClass;



/// 获取数据流
/// @param aClass 数据流转换后的类型
- (NSData *)getModelDataByClass:(Class )aClass;



/// MARK: - 子类必须要重写的方法
/// 获取数据流
- (NSData *)getModelData;


/// 获取数据类型 -- 子类必须要重写此方法
- (EADataInfoModel *)getDataInfoModel;




@end

NS_ASSUME_NONNULL_END
