//
//  EAMakeWatchFaceManager.h
//  EABluetooth
//
//  Created by Aye on 2022/9/7.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <EABluetooth/EAEnum.h>
#import "EACustomNumberWatchFaceModel.h"
NS_ASSUME_NONNULL_BEGIN


NS_CLASS_DEPRECATED_IOS(9_0, 9_0, "No longer supported; please adopt EAMakeWatchFaceManager") __TVOS_PROHIBITED
@interface EACreatThumbnail : NSObject




/// Creating thumbnails 【创建表盘缩略图】
/// @param backgroundImage backgroundImage【图片】
/// @param colorType EACWFTimerColorType 【黑白色数字枚举】
/// @param styleType EACWFStyleType 【表盘风格类型】
/// @return Thumbnail path 【缩略图路径】
+ (NSString *)creatThumbnailWithBackgroundImage:(UIImage *)backgroundImage
                                      colorType:(EACWFTimerColorType )colorType
                                      styleType:(EACWFStyleType)styleType;


/// Creating thumbnails 【创建表盘缩略图】
/// @param backgroundImage backgroundImage【图片】
/// @param colorType EACWFTimerColorType 【黑白色数字枚举】
/// @param styleType EACWFStyleType 【表盘风格类型】
/// @param thumbnailSize thumbnail size【缩略图size】
/// @param cornerRadius thumbnail radius【圆角】
/// @param screenType EAScreenType: 0: square screen 1: round screen【手表屏幕类型: 0:方屏 1:圆屏】
/// @return Thumbnail path 【缩略图路径】
+ (NSString *)creatThumbnailWithBackgroundImage:(UIImage *)backgroundImage
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
+ (NSString *)creatNumberThumbnailWithBackgroundImage:(UIImage *)backgroundImage
                                                 list:(NSArray <EACustomNumberWatchFaceModel *>*)numberList
                                        thumbnailSize:(CGSize )thumbnailSize
                                         cornerRadius:(NSInteger )cornerRadius;




@end

NS_ASSUME_NONNULL_END
