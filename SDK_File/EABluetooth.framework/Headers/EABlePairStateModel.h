//
//  EABlePairStateModel.h
//  EABluetooth
//
//  Created by Aye on 2022/6/24.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 41 : 手表配对情况
/// id = 41 : Watch matching condition
@interface EABlePairStateModel : EABaseModel
/** 0: 没有配对 1: 已经配对 */
@property(nonatomic, assign) BOOL secState;


@end

NS_ASSUME_NONNULL_END
