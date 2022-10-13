//
//  EAModelCustomPropertyMapperConfig.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

#define EAMCPMC [EAModelCustomPropertyMapperConfig defaultCofig]

@interface EAModelCustomPropertyMapperConfig : NSObject

/// 单例
+ (instancetype)defaultCofig;

#pragma mark - yymodel 属性替换

- (NSDictionary *)watchModelMapper;

- (NSDictionary *)userModelMapper;

- (NSDictionary *)syncTimeMapper;

- (NSDictionary *)bingingOpsMapper;

- (NSDictionary *)blacklightTimeoutMapper;

- (NSDictionary *)batteryModelMapper;

- (NSDictionary *)languageModelMapper;

- (NSDictionary *)lengthUnitModelMapper;

- (NSDictionary *)deviceOpsMapper;

- (NSDictionary *)homeTimeZoneItemMapper;

- (NSDictionary *)socialOpsMapper;

- (NSDictionary *)weatherMapper;

- (NSDictionary *)reminderMapper;

- (NSDictionary *)distanceUintMapper;

@end

NS_ASSUME_NONNULL_END
