//
//  EADataInfoModel.h
//  EABluetooth
//
//  Created by Aye on 2021/4/1.
//

#import <Foundation/Foundation.h>
#import <EABluetooth/EAEnum.h>

NS_ASSUME_NONNULL_BEGIN


/// 数据模型
@interface EADataInfoModel : NSObject

/** 请求id */
@property(nonatomic,assign) EADataInfoType requestId;

/** 通道 */
@property(nonatomic,assign) EACharacteristicType channel;

/** 是否可写 */
@property(nonatomic,assign) BOOL canWrite;

/** 是否可读 */
@property(nonatomic,assign) BOOL canRead;


@end

NS_ASSUME_NONNULL_END
