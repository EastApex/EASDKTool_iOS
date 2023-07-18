//
//  EABleBigDataManager.h
//  EABluetooth
//
//  Created by Aye on 2023/7/17.
//

#import <Foundation/Foundation.h>
#import <EABluetooth/EAEnum.h>

NS_ASSUME_NONNULL_BEGIN


typedef void(^ResultBlock)(EARespondCodeType eaRespondCodeType);


@interface EABleBigDataManager : NSObject

+ (instancetype)defaultManager;

/// Initiate synchronous big data
/// Data will not be available until the watch sends the big data message[Listening notification kNTF_EAGetDeviceOpsPhoneMessage],Then call eaGetBigDataButNotDeleteWithBigDataType: access to relevant data details
/// 发起同步大数据
/// 需要等待手表发送完成大数据消息才会有数据【监听通知 kNTF_EAGetDeviceOpsPhoneMessage】,然后调用 eaGetBigDataButNotDeleteWithBigDataType: 获取相关大数据详细内容
- (void)eaSendSyncBigData:(ResultBlock )respond;


/// Get and delete big data by bigDataType 【Data will not be available until the watch sends the big data message：EAPhoneOpsBig8803DataUpdateFinish】
/// 获取大数据（并删除数据）【需要等待手表发送完成大数据消息才会有数据：EAPhoneOpsBig8803DataUpdateFinish】
- (NSArray *)eaGetBigDataWithBigDataType:(EADataInfoType)bigDataType;


/// Get big data without deleting it by bigDataType 【Data will not be available until the watch sends the big data message：EAPhoneOpsBig8803DataUpdateFinish】
/// 获取大数据但不删除数据【需要等待手表发送完成大数据消息才会有数据：EAPhoneOpsBig8803DataUpdateFinish】
- (NSArray *)eaGetBigDataButNotDeleteWithBigDataType:(EADataInfoType)bigDataType;

/// Delete big data by bigDataType
/// 删除大数据
- (void)eaDeleteBigDataWithBigDataType:(EADataInfoType)bigDataType;

/// Delete all big data by bigDataType
/// 删除所有大数据
- (void)eaDeleteAllBigData;



/// Obtaining and processing sleep data(Sleep combined interval: 60 minutes)
/// 获取并处理睡眠数据(睡眠合并间隔：60分钟)
- (NSArray *)eaGetProcessingSleepData:(NSInteger)mergeTime;



@end

NS_ASSUME_NONNULL_END
