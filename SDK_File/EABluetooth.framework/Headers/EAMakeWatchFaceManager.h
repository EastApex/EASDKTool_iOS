//
//  EAMakeWatchFaceManager.h
//  EABluetooth
//
//  Created by Aye on 2022/9/7.
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


@end



@interface EAMakeWatchFaceManager : NSObject

/// The singleton
/// 单例
+ (instancetype)defaultManager;


/// Creating thumbnails 【创建表盘缩略图】
/// @param backgroundImage backgroundImage【图片】
/// @param colorType EACWFTimerColorType 【黑白色数字枚举】
/// @param styleType EACWFStyleType 【表盘风格类型】
/// @param thumbnailSize thumbnail size【缩略图size】
/// @param cornerRadius thumbnail radius【圆角】
/// @param screenType EAScreenType: 0: square screen 1: round screen【手表屏幕类型: 0:方屏 1:圆屏】
/// @return Thumbnail path 【缩略图路径】
- (NSString *)creatThumbnailWithBackgroundImage:(UIImage *)backgroundImage
                                      colorType:(EACWFTimerColorType )colorType
                                      styleType:(EACWFStyleType)styleType
                                  thumbnailSize:(CGSize )thumbnailSize
                                   cornerRadius:(NSInteger )cornerRadius
                                     screenType:(EAScreenType )screenType;


/// Creating custom number thumbnails 【创建自定义数字表盘缩略图】
/// @param backgroundImage backgroundImage【图片】
/// @param numberList Array of time numeric models【时间数字模型数组】
/// @param thumbnailSize thumbnail size【缩略图size】
/// @param cornerRadius thumbnail radius【圆角】
/// @param screenType EAScreenType: 0: square screen 1: round screen【手表屏幕类型: 0:方屏 1:圆屏】
- (NSString *)creatNumberThumbnailWithBackgroundImage:(UIImage *)backgroundImage
                                                 list:(NSArray <EACustomNumberWatchFaceModel *>*)numberList
                                        thumbnailSize:(CGSize )thumbnailSize
                                         cornerRadius:(NSInteger )cornerRadius
                                           screenType:(EAScreenType )screenType;

@end

NS_ASSUME_NONNULL_END
