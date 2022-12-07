//
//  EALoadBundleFile.h
//  EABluetooth
//
//  Created by Aye on 2022/9/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface EALoadBundleFile : NSObject

// 将EAWatchFace添加在工程里使用
+ (NSString *)loadBundleImagePathWithImageName:(NSString *)imageName;
+ (NSString *)loadBundleJsonPathWithJsonName:(NSString *)jsonName;

// 使用cocoapods将EAWatchFace添加在工程里使用
+ (UIImage *)loadBundleImageWithImageName:(NSString *)imageName;
+ (NSDictionary *)loadBundleJsonWithJsonName:(NSString *)jsonName;
@end

NS_ASSUME_NONNULL_END
