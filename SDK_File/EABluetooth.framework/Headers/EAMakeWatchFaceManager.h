//
//  EAMakeWatchFaceManager.h
//  EABluetooth
//
//  Created by Aye on 2023/2/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <EABluetooth/EAEnum.h>
#import "EACustomNumberWatchFaceModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface EAMakeWatchFaceManager : NSObject

/// Introduction to Custom watch face
/// I. There are three custom watch face styles
/// 1. 2 kinds of digital watch face (black and white numbers)
/// 2. 6 kinds of pointer watch face (black and white pointer * 3 kinds of scale [no scale, bar scale, digital bar scale])
/// 3. Completely customize the digital watch face (digital color, digital size, digital position)
///
/// II. Introduction to use:
/// 1. Each custom watch face provides a 'get thumbnail' and 'ota watch face' method respectively
/// 2. If ota watch face method is used, kNTF_EAOTAAGPSDataing and kNTF_EAOTAAGPSDataFinish notifications need to be added to monitor OTA progress and implemented.
///

/// 自定义表盘介绍
/// 一、目前有3种自定义表盘风格
/// 1.2种数字表盘（黑白色数字）
/// 2.6种指针表盘（黑白色指针 * 3种刻度【无刻度、线条刻度、数字线条刻度】）
/// 3.完全自定义数字表盘（数字颜色、数字大小、数字位置）
///
/// 二、使用介绍：
/// 1.每种自定义表盘 分别提供 获取缩略图方法 和 ota表盘方法
/// 2.使用 ota表盘 方法时，如果需要监听 OTA进度 需要添加 通知  kNTF_EAOTAAGPSDataing 和 kNTF_EAOTAAGPSDataFinish 并实现.
///





#pragma mark - thumbnails【缩略图】

/// Create thumbnails of digital watch face【创建数字表盘缩略图】
/// @return Thumbnail  【缩略图】
+ (UIImage *)eaGetNumberThumbnailWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType;

/// Create thumbnail of pointer watch face【创建指针表盘缩略图】
/// @return Thumbnail 【缩略图】
+ (UIImage *)eaGetPointerThumbnailWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType scaleStyle :(EACWFPointerScaleStyle)scaleStyle;

/// Create a fully custom digital watch face thumbnail 【创建完全自定义数字表盘缩略图】
/// @return Thumbnail  【缩略图】
+ (UIImage *)eaGetNumberThumbnailWithImage:(UIImage *)image list:(NSArray <EACustomNumberWatchFaceModel *>*)numberList;



#pragma mark - watch face ota 【表盘OTA】
/// Digital watch face with custom picture【自定义图片的数字表盘】
+ (NSInteger )eaOtaNumberWatchFaceWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType;

/// Pointer watch face with custom  picture【自定义图片的指针表盘】
+ (NSInteger )eaOtaPointerWatchFaceWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType scaleStyle :(EACWFPointerScaleStyle)scaleStyle;

/// Digital watch face with fully custom picture 【完全自定义图片的数字表盘】
+ (NSInteger )eaOtaNumberWatchFaceWithImage:(UIImage *)image list:(NSArray <EACustomNumberWatchFaceModel *>*)numberList;

@end

NS_ASSUME_NONNULL_END
