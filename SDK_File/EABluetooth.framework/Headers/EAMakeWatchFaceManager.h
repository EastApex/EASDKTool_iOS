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

/// I. There are currently 5 custom watch face styles
/// 1.(deprecated) Two types of digital dial (black and white numbers) ==> Type1
/// 2.2 Pointer dial (black and white pointer) ==> Type2
/// 3. Default custom digital dial (color needs to be set) ==> Type3
/// 4. Customize the digital dial (need to set the color, size and position of the number) ==> Type4
/// 5. Customize pointer dial (need to set picture, position, rotation point) ==> Type5
///
/// II. Introduction to use:
/// 1. Each custom watch face provides a 'get thumbnail' and 'ota watch face' method respectively
/// 2. If ota watch face method is used, kNTF_EAOTAAGPSDataing and kNTF_EAOTAAGPSDataFinish notifications need to be added to monitor OTA progress and implemented.
///
/// III.Advanced custom watch face
/// 1.Type 4 and type 5 is an advanced custom watch face, which needs to be planned by the product manager and designed by a UI designer. If your app doesn't require this, just use type 2 or type 3.
/// 2.If the watch digital watch face does not want the built-in digital watch face style of sdk, then you need to use type4 to set the font, color and position to meet your needs.
/// 3.It may take you 1 to 2 days to complete this.
///

/// 自定义表盘介绍
/// 一、目前有5种自定义表盘风格
/// 1.(弃用)2种数字表盘（黑白色数字） ==> Type1
/// 2.2种指针表盘（黑白色指针） ==> Type2
/// 3.默认自定义数字表盘（需要设置颜色） ==> Type3
/// 4.自定义数字表盘（需要设置数字颜色、数字大小、数字位置）  ==> Type4
/// 5.自定义指针表盘（需要设置图片、位置、旋转点） ==> Type5
///
/// 二、使用介绍：
/// 1.每种自定义表盘 分别提供 获取缩略图方法 和 ota表盘方法
/// 2.使用 ota表盘 方法时，如果需要监听 OTA进度 需要添加 通知  kNTF_EAOTAAGPSDataing 和 kNTF_EAOTAAGPSDataFinish 并实现.
///
///
/// 三、高级自定义表盘
/// 1.Type 4和Type 5是高级自定义表盘，需要产品经理来规划并且需要UI设计师来设计。如果你的应用程序不需要这个，只需使用Type2 ~ 3。
/// 2.如果手表的数字表盘不想要sdk内置的数字表盘样式，那么你需要使用type4来设置字体、颜色和位置来满足你的需求。
/// 3.你可能需要花费1~2天来完成这个事情。


#pragma mark - thumbnails【缩略图】

/// Type2：Create thumbnail of pointer watch face【创建指针表盘缩略图】
/// @return Thumbnail
+ (UIImage *)eaGetPointerThumbnailWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType scaleStyle :(EACWFPointerScaleStyle)scaleStyle;

/// Type3： Create thumbnail of default style digital watch face
/// @return Thumbnail
+ (UIImage *)eaGetDefaultNumberThumbnailWithImage:(UIImage *)image color:(UIColor *)color;

/// Type4：Create a fully custom digital watch face thumbnail 【创建完全自定义数字表盘缩略图】
/// @return Thumbnail
+ (UIImage *)eaGetNumberThumbnailWithImage:(UIImage *)image list:(NSArray <EACustomNumberWatchFaceModel *>*)numberList;

/// Type5：Create a fully custom pointer watch face thumbnail 【创建完全自定义指针表盘缩略图】
/// @return Thumbnail
+ (UIImage *)eaGetPointerThumbnailWithImage:(UIImage *)image list:(NSArray <EACustomPointerWatchFaceModel *>*)pointerList ;


/// Type1：Create thumbnails of digital watch face【创建数字表盘缩略图】
/// @return Thumbnail
+ (UIImage *)eaGetNumberThumbnailWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType DEPRECATED_MSG_ATTRIBUTE("Please use \"eaGetDefaultNumberThumbnailWithImage: color:\"");

/**

 0: Unconnected watch
 -1: The resolution of the picture is inconsistent with the watch
 -2: If the numberList data is insufficient, it must contain high, low, high and low.
 -3: numberList contains duplicate time type data
 -4: Font does not exist, please set it again
 

 0:未连接手表
 -1:图片与手表分辨率不一致
 -2:numberList数据不足，必须含有时高位、时低位、分高位、分低位
 -3:numberList含有重复时间类型数据
 -4:字体不存在，请重新设置
 */

#pragma mark - watch face ota 【表盘OTA】

/// Type2：Pointer watch face with custom  picture【自定义图片的指针表盘】
+ (NSInteger )eaOtaPointerWatchFaceWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType scaleStyle :(EACWFPointerScaleStyle)scaleStyle;

/// Type3：Default style digital watch face【默认数字表盘】
+ (NSInteger )eaOtaDefaultNumberWatchFaceWithImage:(UIImage *)image color:(UIColor *)color ;

/// Type4：Advanced custom digital watch face【高级自定义数字表盘】
+ (NSInteger )eaOtaNumberWatchFaceWithImage:(UIImage *)image list:(NSArray <EACustomNumberWatchFaceModel *>*)numberList;

/// Type5：Advanced custom pointer watch face【高级自定义指针表盘】
+ (NSInteger )eaOtaPointerWatchFaceWithImage:(UIImage *)image list:(NSArray <EACustomPointerWatchFaceModel *>*)pointerList;



/// Type2：Pointer watch face with custom  picture【自定义图片的指针表盘】
+ (NSInteger )eaOtaPointerWatchFaceWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType scaleStyle :(EACWFPointerScaleStyle)scaleStyle watchFaceId:(NSString *)watchFaceId;
 
/// Type3：Default style digital watch face【默认数字表盘】
+ (NSInteger )eaOtaDefaultNumberWatchFaceWithImage:(UIImage *)image color:(UIColor *)color watchFaceId:(NSString *)watchFaceId;

/// Type4：Advanced custom digital watch face【高级自定义数字表盘】
+ (NSInteger )eaOtaNumberWatchFaceWithImage:(UIImage *)image list:(NSArray <EACustomNumberWatchFaceModel *>*)numberList watchFaceId:(NSString *)watchFaceId;

/// Type5：Advanced custom pointer watch face【高级自定义指针表盘】
+ (NSInteger )eaOtaPointerWatchFaceWithImage:(UIImage *)image list:(NSArray <EACustomPointerWatchFaceModel *>*)pointerList watchFaceId:(NSString *)watchFaceId;







/// Type1：Digital watch face with custom picture【自定义图片的数字表盘】
+ (NSInteger )eaOtaNumberWatchFaceWithImage:(UIImage *)image colorType:(EACWFTimerColorType )colorType DEPRECATED_MSG_ATTRIBUTE("Please use \"eaOtaDefaultNumberWatchFaceWithImage: color:\"");




@end

NS_ASSUME_NONNULL_END
