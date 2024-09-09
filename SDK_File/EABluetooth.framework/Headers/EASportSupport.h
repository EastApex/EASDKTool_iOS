//
//  EASportSupport.h
//  EABluetooth
//
//  Created by Aye on 2024/8/12.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EASportSupport : EABaseModel

@property(nonatomic, copy) NSData *mapSport;
@property(nonatomic, copy) NSData *launchScreenSport;

/// <#name#>
@property(nonatomic,copy) NSArray *mapSports;
@property(nonatomic,copy) NSArray *screenSports;

@end

NS_ASSUME_NONNULL_END
