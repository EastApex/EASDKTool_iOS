//
//  EAHabitTrackerDataModel.h
//  EABluetooth
//
//  Created by Aye on 2022/5/13.
//

#import <EABluetooth/EABluetooth.h>
NS_ASSUME_NONNULL_BEGIN



@interface EAHistoryHabitTrackerModel : EABigDataModel



@property(nonatomic, readwrite) EAHabitTrackerIconType eIconId;

@property(nonatomic, assign) NSInteger beginHour;

@property(nonatomic, assign) NSInteger beginMinute;

@property(nonatomic, assign) NSInteger endHour;

@property(nonatomic, assign) NSInteger endMinute;

@property(nonatomic, assign) NSInteger r;

@property(nonatomic, assign) NSInteger g;

@property(nonatomic, assign) NSInteger b;

@property(nonatomic, assign) EAHabitTrackerFlag eFlag;

/// Customized content: supports UTF8 of up to 64 bytes
/// 自定义内容：最多支持64字节的utf8，字符串
@property(nonatomic, strong) NSString *content;

@end


/// 习惯大数据
@interface EAHabitTrackerDataModel : EABaseBigDataModel

@property(nonatomic, strong) NSMutableArray<EAHistoryHabitTrackerModel*> *sIndexArray;

+ (EAHabitTrackerDataModel *)getHabitTrackerData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
