//
//  EAPhoneOpsModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/22.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN



@interface EAPhoneOpsModel : EABaseModel

@property(nonatomic, readwrite) EAPhoneOps eOps;

@property(nonatomic, readwrite) EAPhoneOpsStatus eOpsStatus;


+ (EAPhoneOpsModel *)getModelByData:(NSData *)data;






@end

NS_ASSUME_NONNULL_END
