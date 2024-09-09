//
//  EATemplateBobyData.h
//  EABluetooth
//
//  Created by Aye on 2024/6/13.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


@interface EATemplateBobyDataItem : EABigDataModel

/** 体温 （单位摄氏度） */
@property(nonatomic, assign) NSInteger body;

/** 环境温度（单位摄氏度） */
@property(nonatomic, assign) NSInteger environment;

@end

@interface EATemplateBodyData : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EATemplateBobyDataItem*> *sIndexArray;

+ (EATemplateBodyData *)getBigData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
