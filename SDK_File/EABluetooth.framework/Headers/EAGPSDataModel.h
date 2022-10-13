//
//  EAGPSDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/23.
//

#import <EABluetooth/EABaseBigDataModel.h>

NS_ASSUME_NONNULL_BEGIN


/// GPS 数据
@interface EAGPSDataModel : EABaseModel

/// The time stamp
/// 时间戳
@property(nonatomic, assign) NSInteger timeStamp;

/// latitude
///  纬度
@property(nonatomic, assign) float latitude;

/// longitude
/// 经度
@property(nonatomic, assign) float longitude;

@end


@interface EAUploadGPSData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EAGPSDataModel*> *sIndexArray;

+ (EAUploadGPSData *)getGPSData:(NSData *)data;

@end


NS_ASSUME_NONNULL_END
