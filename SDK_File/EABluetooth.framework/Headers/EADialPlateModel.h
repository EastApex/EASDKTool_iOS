//
//  EADialPlateModel.h
//  EABluetooth
//
//  Created by Aye on 2021/6/21.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 32: 表盘信息
/// id = 32: Dial information（Watch Face information）
@interface EADialPlateModel : EABaseModel

/// watch face id, (0代表在线自定义表盘，1~n，内置表盘编号)
/// 表盘id, (0代表在线自定义表盘，1~n，内置表盘编号)
@property(nonatomic, assign) NSInteger id_p;

/// Id of the currently set custom watch face. If set, it has a value
/// 当前设置的自定义表盘id,如果设置了就有值
@property(nonatomic, copy) NSString *userWfId;

/// Id of a custom watch face
/// 自定义表盘id0
@property(nonatomic, copy) NSString * userWfId0;

/// Id of a custom watch face
/// 自定义表盘id1
@property(nonatomic, copy) NSString * userWfId1;

/// Id of a custom watch face
/// 自定义表盘id2
@property(nonatomic, copy) NSString * userWfId2;

/// Id of a custom watch face
/// 已存在线自定义表盘id3
@property(nonatomic, copy) NSString * userWfId3;

/// 已存在线自定义表盘id4
/// Id of a custom watch face
@property(nonatomic, copy) NSString *userWfId4;

/// 已存在线自定义表盘id5
/// Id of a custom watch face
@property(nonatomic, copy) NSString *userWfId5;

/// 已存在线自定义表盘id6
/// Id of a custom watch face
@property(nonatomic, copy) NSString *userWfId6;

/// 已存在线自定义表盘id7
/// Id of a custom watch face
@property(nonatomic, copy) NSString *userWfId7;

/// 已存在线自定义表盘id8
/// Id of a custom watch face
@property(nonatomic, copy) NSString *userWfId8;

/// 已存在线自定义表盘id9
/// Id of a custom watch face
@property(nonatomic, copy) NSString *userWfId9;


/// show the built-in watch face
+ (instancetype)eaInitBuiltInWatchFaceWithID:(NSInteger )id_p;

/// show the custom watch face
+ (instancetype)eaInitCustomWatchFaceWithID:(NSString *)userWfId;


@end

NS_ASSUME_NONNULL_END
