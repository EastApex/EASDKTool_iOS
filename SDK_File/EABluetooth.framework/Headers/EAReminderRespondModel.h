//
//  EAReminderRespondModel.h
//  EABluetooth
//
//  Created by Aye on 2021/4/7.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAReminderRespondModel : EABaseModel

/** 操作状态 */
@property(nonatomic, assign) EARespondCodeType eOpsStatus;

/** 提醒id: 在write request的ops为新增 编辑回应中赋值，其他情况为0 */
@property(nonatomic, assign) NSInteger id_p;


+ (EAReminderRespondModel *)getModelByData:(NSData *)data;


@end

NS_ASSUME_NONNULL_END
