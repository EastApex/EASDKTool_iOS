//
//  EAReminderRespondModel.h
//  EABluetooth
//
//  Created by Aye on 2021/4/7.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_DEPRECATED_IOS(9_0, 9_0, "No longer supported; please adopt EARespondModel") __TVOS_PROHIBITED
@interface EAReminderRespondModel : EABaseModel

/** 操作状态 */
@property(nonatomic, assign) EAReminderRespondCodeType eOpsStatus;

/** 提醒id: 在write request的ops为新增 编辑回应中赋值，其他情况为0 */
@property(nonatomic, assign) NSInteger id_p;





@end

NS_ASSUME_NONNULL_END
