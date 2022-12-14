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

@interface EAMakeWatchFaceManager : NSObject

/// The singleton
/// 单例
+ (instancetype)defaultManager;


/// Creating thumbnails 【创建表盘缩略图】
/// @param backgroundImage backgroundImage【图片】
/// @param colorType EACWFTimerColorType 【黑白色数字枚举】
/// @param styleType EACWFStyleType 【表盘风格类型】
/// @param size thumbnail size【缩略图size】
/// @param cornerRadius thumbnail radius【圆角】
/// @param screenType EAScreenType: 0: square screen 1: round screen【手表屏幕类型: 0:方屏 1:圆屏】
/// @return Thumbnail path 【缩略图路径】
- (NSString *)creatThumbnailWithBackgroundImage:(UIImage *)backgroundImage
                                      colorType:(EACWFTimerColorType )colorType
                                      styleType:(EACWFStyleType)styleType
                                  thumbnailSize:(CGSize )size
                                   cornerRadius:(NSInteger )cornerRadius
                                     screenType:(EAScreenType )screenType;


@end

NS_ASSUME_NONNULL_END
