//
//  EAPwd.h
//  EABluetooth
//
//  Created by Aye on 2024/4/3.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAPwd : EABaseModel

@property(nonatomic, assign) NSInteger sw;

//@property(nonatomic, assign) NSInteger pwdLen;

@property(nonatomic, strong) NSString *pwd;
@end

NS_ASSUME_NONNULL_END
