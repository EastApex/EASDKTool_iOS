//
//  EACustomNumberWatchFaceModel.h
//  EABluetooth
//
//  Created by Aye on 2023/2/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <EABluetooth/EAEnum.h>

NS_ASSUME_NONNULL_BEGIN

/// time numeric models
/// 时间数字模型
@interface EACustomNumberWatchFaceModel : NSObject


/// Time type
/// 时间类型
@property(nonatomic,assign) EATimeType eaTimeType;

/// 字体
/// Font
@property(nonatomic,strong) UIFont *font;

/// 颜色
/// Color
@property(nonatomic,strong) UIColor *color;

/// 原点位置
/// Origin position
@property(nonatomic,assign) CGPoint point;


///  Initialization method【初始化方法】
/// - Parameters:
///   - eaTimeType: Time type【时间类型】
///   - font: Font【字体】
///   - color: Color【颜色】
///   - point: Origin position【原点位置】
+ (instancetype)eaAllocInitWithTimeType:(EATimeType )eaTimeType font:(UIFont *)font color:(UIColor *)color point:(CGPoint )point;

- (NSArray *)getRGB;

@end



/// Pointer model
/// 时针模型
@interface EACustomPointerWatchFaceModel : NSObject

/// image
@property(nonatomic,strong) UIImage *poniterImage;

/// Pointer type
@property(nonatomic,assign) EAPointerType eaPointerType;

/// original point
/// 原点
@property(nonatomic,assign) CGPoint originalPoint;

/// Point of rotation
/// 旋转点：时针的旋转点
@property(nonatomic,assign) CGPoint rotationPoint;


+ (instancetype)eaInitWithPoniterImage:(UIImage *)poniterImage pointerType:(EAPointerType)eaPointerType originalPoint:(CGPoint)originalPoint rotationPoint:(CGPoint)rotationPoint;

@end




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

@property(nonatomic,assign) NSInteger weekTextWidth;
@property(nonatomic,assign) NSInteger weekTextAlign;
@property(nonatomic,assign) NSInteger weekTextFont;
@property(nonatomic,assign) NSInteger dayTextWidth;
@property(nonatomic,assign) NSInteger dayTextAlign;
@property(nonatomic,assign) NSInteger dayTextFont;

@property(nonatomic,strong) NSString *hour;
@property(nonatomic,strong) NSString *arcHour;
@property(nonatomic,strong) NSString *minute;
@property(nonatomic,strong) NSString *arcMinute;
@property(nonatomic,strong) NSString *second;
@property(nonatomic,strong) NSString *arcSecond;

+ (EAPointPictureModel *)getSizePictureModelWithDeviceSize:(NSString *)deviceSize withType:(NSInteger)type screenType:(EAScreenType )screenType;

- (CGPoint)getPointWithKey:(NSString *)key;
@end

NS_ASSUME_NONNULL_END
