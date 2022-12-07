//
//  EAMakeWatchFace.h
//  EABluetooth
//
//  Created by Aye on 2022/9/5.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <EABluetooth/EAEnum.h>
NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, EATimerType) {
    
    EATimerTypeNumber         = 0,   // 数字
    EATimerTypePoint          = 1,   // 指针
    EATimerTypeKeduNumber     = 2,   // 指针+刻度数字
    EATimerTypeKeduDot        = 3,   // 指针+刻度点
};

@interface EAPointPictureModel : NSObject

@property(nonatomic,strong) NSString *background;
@property(nonatomic,strong) NSString *hourHigh;
@property(nonatomic,strong) NSString *hourLow;
@property(nonatomic,strong) NSString *minuteHigh;
@property(nonatomic,strong) NSString *minuteLow;
@property(nonatomic,strong) NSString *maohao;
@property(nonatomic,strong) NSString *weekText;
@property(nonatomic,strong) NSString *dayText;

@property(nonatomic,strong) NSString *hour;
@property(nonatomic,strong) NSString *arcHour;
@property(nonatomic,strong) NSString *minute;
@property(nonatomic,strong) NSString *arcMinute;
@property(nonatomic,strong) NSString *second;
@property(nonatomic,strong) NSString *arcSecond;

+ (EAPointPictureModel *)getSizePictureModelWithDeviceSize:(NSString *)deviceSize withType:(NSInteger)type;

- (CGPoint)getPointWithKey:(NSString *)key;
@end


@interface EAMakeWatchFace : NSObject


/// 生成自定义表盘
+ (NSInteger )customWatchFaceBackgroundImage:(UIImage *)backgroundImage thumbnailImage:(UIImage *)thumbnailImage colorType:(EATimerColorType )colorType watchFaceWidth:(NSInteger)watchFaceWidth watchFaceHeight:(NSInteger)watchFaceHeight small:(BOOL)small  firstSN:(NSString *)firstSN;

@end

NS_ASSUME_NONNULL_END
