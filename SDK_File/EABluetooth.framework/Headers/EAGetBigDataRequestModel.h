//
//  EAGetBigDataRequestModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 29: Big data acquisition command
/// id = 29: 获取大数据请求
@interface EAGetBigDataRequestModel : EABaseModel

/// Set the following properties to return first
/// 设置以下属性为 优先 返回


@property(nonatomic, assign) NSInteger sportDataReq;

@property(nonatomic, assign) NSInteger sleepDataReq;

@property(nonatomic, assign) NSInteger hrDataReq;

@property(nonatomic, assign) NSInteger gpsDataReq;

@property(nonatomic, assign) NSInteger multiSportsDataReq;

@property(nonatomic, assign) NSInteger bloodOxygenDataDataReq;

@property(nonatomic, assign) NSInteger stressDataReq;

@property(nonatomic, assign) NSInteger stepFreqDataReq;

@property(nonatomic, assign) NSInteger stepPaceDataReq;

@property(nonatomic, assign) NSInteger restingHrDataReq;


+ (instancetype)eaInit;


@end

NS_ASSUME_NONNULL_END
