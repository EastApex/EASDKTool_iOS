//
//  EAReplayUserMessage.h
//  EABluetooth
//
//  Created by Aye on 2023/7/24.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


@interface EAReplayUserMessage : EABaseModel

@property(nonatomic, strong) NSString *msg;

@end

@interface EAReplayUserMessageData : EABaseModel


@property(nonatomic, strong) NSMutableArray<EAReplayUserMessage *> *sIndexArray;


@end

NS_ASSUME_NONNULL_END
