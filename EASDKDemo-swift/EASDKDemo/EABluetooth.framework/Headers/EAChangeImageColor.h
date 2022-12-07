//
//  EAChangeImageColor.h
//  EABluetooth
//
//  Created by Aye on 2022/9/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAChangeImageColor : NSObject

+ (NSMutableArray<UIColor*> *)getPixelColorsWithImage:(UIImage*)image;

+ (UIImage*)changePixelColorsWithImage:(UIImage*)image colors:(NSArray<UIColor*>*)colors toColor:(UIColor*)toColor;

@end

NS_ASSUME_NONNULL_END
