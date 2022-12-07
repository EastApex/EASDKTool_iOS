//
//  EAPBDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/9/24.
//

#import <Realm/Realm.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAPBDataModel : RLMObject

/// id
@property NSInteger modelId;

/// 数据类型
@property NSInteger pbType;

/// pbData
@property NSString *pbDataString;

/// 添加时间
@property NSString *timeString;

/// 时间戳
@property NSInteger dayTimestamp;

/// 初始化
- (instancetype)initModel;


/// 保存数据
- (void)saveModel;


/// 删除数据
- (void)deleteModel;


/// 检测是否有重复记录
- (BOOL)checkExitPbDataString;

@end

NS_ASSUME_NONNULL_END
