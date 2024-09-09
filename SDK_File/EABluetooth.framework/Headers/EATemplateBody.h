//
//  EATemplateBody.h
//  EABluetooth
//
//  Created by Aye on 2024/6/13.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EATemplateBody : EABaseModel

/** 0关，1开 */
@property(nonatomic, assign) BOOL sw;

/** 间隔时间，单位：分钟(最低不少于60分钟) */
@property(nonatomic, assign) NSInteger interval;

@end

NS_ASSUME_NONNULL_END
