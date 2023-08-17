//
//  EASos.h
//  EABluetooth
//
//  Created by Aye on 2023/6/29.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// id = 58
/// 紧急联系人
/// Sos
@interface EASos : EABaseModel

/// 名称
/// name
@property(nonatomic, strong) NSString *name;

/// 号码
/// number
@property(nonatomic, strong) NSString *num;


@end

NS_ASSUME_NONNULL_END
