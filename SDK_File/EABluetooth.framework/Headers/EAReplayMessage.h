//
//  EAReplayMessage.h
//  EABluetooth
//
//  Created by Aye on 2023/7/24.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAReplayMessage : EABaseModel


@property(nonatomic, assign) NSInteger id_p;

@property(nonatomic, strong) NSString *content;

@property(nonatomic, strong) NSString *name;

@property(nonatomic, strong) NSString *num;
@end

NS_ASSUME_NONNULL_END
