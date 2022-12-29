//
//  EAOnlyGetBigData.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAOnlyGetBigData : EABaseModel

/// 大数据类型
@property(nonatomic, assign) EADataInfoType eBigDataType;


+ (instancetype )eaInitWithBigDataType:(EADataInfoType)bigDataType;

@end

NS_ASSUME_NONNULL_END
