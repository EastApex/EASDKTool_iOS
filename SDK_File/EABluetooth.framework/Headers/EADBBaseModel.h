//
//  EADBBaseModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/6.
//

#import <Realm/Realm.h>

NS_ASSUME_NONNULL_BEGIN

@interface EADBBaseModel : RLMObject

/// id
@property NSInteger modelId;

/// 用户id
@property NSString *userId;

/// 日期时间戳 （eg：2021-05-17 就是保存 1621180800）
@property NSInteger dayTimeStamp;

/// 手表型号id
@property NSString *watchId;

/// 手表标志【SN号、Mac地址】
@property NSString *watchSign;

/// 手表型号
@property NSString *watchName;


- (instancetype)initModel;

- (void)saveModel;

- (void)deleteModel;

/// FIXME: - 获取当天数据
/// - Parameters:
///   - watchSign: watchSign
///   - dayTimeStamp: 当前时间戳（天）
+ (instancetype )eaGetDbModelWithWatchSign:(NSString *)watchSign dayTimeStamp:(NSInteger)dayTimeStamp;


/// FIXME: - 获取范围时间数据（天）
/// - Parameters:
///   - watchSign: watchSign
///   - startDayTimeStamp: 开始时间戳（天）
///   - endDayTimeStamp: 结束时间戳（天）
+ (NSArray *)eaGetDbDataWithWatchSign:(NSString *)watchSign startDayTimeStamp:(NSInteger)startDayTimeStamp endDayTimeStamp:(NSInteger)endDayTimeStamp;


/// FIXME: - 删除所有watchSign数据
/// - Parameter watchSign: watchSign
+ (void)eaDelectWithWatchSign:(NSString *)watchSign;


/// FIXME: - 删除当天的本地数据
/// - Parameter :
///   - watchSign: watchSign
///   - dayTimeStamp: 当天时间戳
+ (void)eaDelectWithWatchSign:(NSString *)watchSign dayTimeStamp:(NSInteger)dayTimeStamp;


/// FIXME: - 删除时间范围的本地数据
/// - Parameter :
///   - watchSign: watchSign
///   - dayTimeStamp: 开始时间戳（天）
///   - endDayTimeStamp: 结束时间戳（天）
+ (void)eaDelectWithWatchSign:(NSString *)watchSign startDayTimeStamp:(NSInteger)startDayTimeStamp endDayTimeStamp:(NSInteger)endDayTimeStamp;


/// FIXME: - 清空数据库所有数据
+ (void)eaClearDatabase;

@end

NS_ASSUME_NONNULL_END
