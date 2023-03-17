//
//  EARespondModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 回应数据
@interface EARespondModel : EABaseModel

/** 协议请求的id号 */
@property(nonatomic, assign) EADataInfoType requestId;

@property(nonatomic, assign) EARespondCodeType eErrorCode;

/** 提醒id: 在write request的ops为新增 编辑回应中赋值，其他情况为0 */
@property(nonatomic, assign) NSInteger id_p;


+ (instancetype)eaInitSuccWithRequestId:(EADataInfoType)requestId;
+ (instancetype)eaInitErrorWithRequestId:(EADataInfoType)requestId;

+ (instancetype)eaInitMemFullWithRequestId:(EADataInfoType)requestId;
+ (instancetype)eaInitTimeConflictWithRequestId:(EADataInfoType)requestId;

+ (instancetype)eaInitNotReadWithRequestId:(EADataInfoType)requestId;
+ (instancetype)eaInitNotWriteWithRequestId:(EADataInfoType)requestId;

+ (instancetype)eaInitSuccWithRequestId:(EADataInfoType)requestId id_p:(NSInteger)id_p;
+ (instancetype)eaInitErrorWithRequestId:(EADataInfoType)requestId id_p:(NSInteger)id_p;

+ (instancetype)eaInitTimeOutWithRequestId:(EADataInfoType)requestId;

@end

NS_ASSUME_NONNULL_END
