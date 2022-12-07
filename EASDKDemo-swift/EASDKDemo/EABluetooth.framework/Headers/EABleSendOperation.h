//
//  EABleSendOperation.h
//  EABluetooth
//
//  Created by Aye on 2021/8/26.
//

#import <Foundation/Foundation.h>
#import <EABluetooth/EABluetooth.h>
#import <EABluetooth/EAModelHeader.h>
NS_ASSUME_NONNULL_BEGIN


typedef void(^ResultGetInfoOperationBlock)(EABaseModel *baseModel);
typedef void(^RespondOperationBlock)(EARespondModel *respondModel);

/// MARK: -  操作类型
typedef NS_ENUM(NSUInteger, EAOperationType) {
    
    EAOperationTypeGet,
    EAOperationTypeChange,
    EAOperationTypeGetBigData,
};
@interface EABleSendOperation : NSOperation
{
    BOOL executing;
    BOOL finished;

}
/** <#name#> */
@property(nonatomic,assign) EAOperationType  operationType;


/** 获取数据 */
@property(nonatomic,assign) EADataInfoType dataInfoType;
@property(nonatomic,copy) ResultGetInfoOperationBlock resultGetInfoBlock;

@property(nonatomic,strong) EARequestModel *requestModel;

/** 修改数据 */
@property(nonatomic,copy) RespondOperationBlock respondBlock;
@property(nonatomic,strong) EABaseModel *changeModel;


@property(nonatomic,strong) EAGetBigDataRequestModel *bigDataModel;




/// 获取手表数据操作
/// @param dataInfoType 数据类型
/// @param resultGetInfoBlock 手表数据
+ (instancetype)addOperationForGetWithDataInfoType:(EADataInfoType )dataInfoType
                                     completeBlock:(ResultGetInfoOperationBlock)resultGetInfoBlock;


/// 获取手表数据操作
/// @param requestModel 数据模型
/// @param resultGetInfoBlock 手表数据
+ (instancetype)addOperationForGetWithRequestModel:(EARequestModel *)requestModel
                                     completeBlock:(ResultGetInfoOperationBlock)resultGetInfoBlock;


/// 修改手表数据操作
/// @param baseModel 修改的数据
/// @param respondBlock 修改结果
+ (instancetype)addOperationForChangeWithModel:(EABaseModel *)baseModel
                                 completeBlock:(RespondOperationBlock)respondBlock;


/// 获取手表大数据
+ (instancetype)addOperationForGetBigDataWithModel:(EAGetBigDataRequestModel *)baseModel
                                     completeBlock:(RespondOperationBlock)respondBlock;


/// 超时响应
+ (void)checkOTATimeOut;
@end

NS_ASSUME_NONNULL_END
