//
//  EABaseModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/18.
//

#import <Foundation/Foundation.h>
#import <EABluetooth/EAEnum.h>
#import <YYKit/YYKit.h>
#import <EABluetooth/EADataValue.h>
#import <EABluetooth/EAModelCustomPropertyMapperConfig.h>
#import <EABluetooth/EADataInfoModel.h>

@class GPBMessage;
@class EABaseModel;
@class EARespondModel;
NS_ASSUME_NONNULL_BEGIN

typedef void(^ResultGetInfoBlock)(EABaseModel *baseModel);
typedef void(^RespondBlock)(EARespondModel *respondModel);


@interface EABaseModel : NSObject<NSCopying>


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

+ (instancetype )getModelByData:(NSData *)data;

- (void)eaSend:(void (^)(EARespondCodeType respondCodeType ))completion;
@end


@interface EABigDataModel : EABaseModel

/// The time stamp
/// 时间戳
@property(nonatomic, assign) NSInteger timeStamp;

@end

NS_ASSUME_NONNULL_END
