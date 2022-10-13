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


/// Creating thumbnails 【创建缩略图】
/// @param backgroundImage backgroundImage
/// @param colorType EATimerColorType 黑白色数字枚举
/// @param size thumbnail size
/// @param cornerRadius thumbnail radius
/// @return Thumbnail path 【缩略图路径】
- (NSString *)creatThumbnailWithBackgroundImage:(UIImage *)backgroundImage colorType:(EATimerColorType )colorType thumbnailSize:(CGSize )size cornerRadius:(NSInteger )cornerRadius;


@end

NS_ASSUME_NONNULL_END
