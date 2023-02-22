//
//  EAMtuModel.h
//  EABluetooth
//
//  Created by Aye on 2021/7/1.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAMtuModel : EABaseModel

/** 目前连接的mtu值 */
@property(nonatomic, assign) NSInteger mtuValue;




@end

NS_ASSUME_NONNULL_END
