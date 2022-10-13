//
//  BaseViewController.h
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//

#import <UIKit/UIKit.h>
#import "BluetoothFunc.h"
#import <Masonry/Masonry.h>
NS_ASSUME_NONNULL_BEGIN

#define kScreenWidth    [UIScreen mainScreen].bounds.size.width
#define kScreenHeight   [UIScreen mainScreen].bounds.size.height

#define WeakObj(obj) __weak typeof(obj) obj##Weak = obj
#define WeakSelf WeakObj(self);

@interface BaseViewController : UIViewController

@property(nonatomic,strong)  UILabel *textLabel;
/** 弹窗 */
@property(nonatomic,strong) UIAlertController *alertVC;
- (void)loadWatchData;

- (void)showAlertWithTitle:(NSString *)title;
- (void)showAlertWithTitle:(NSString *)title message:(NSString *)message;
- (void)dismissAlert;

@end


CG_INLINE NSString* timestampToTimeString(NSInteger timestamp) {
    
    NSDate *detailDate = [NSDate dateWithTimeIntervalSince1970:timestamp];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyy.MM.dd HH:mm:ss"];
    NSString *timeString = [dateFormatter stringFromDate:detailDate];
    return timeString;
}


CG_INLINE NSInteger timeStringToTimestamp(NSString *timeString) {
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setLocale:[NSLocale currentLocale]];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];
    [dateFormatter setDateFormat:@"yyyy.MM.dd HH:mm:ss"];
    NSDate *date = [dateFormatter dateFromString:timeString];
    NSTimeInterval timestamp = [date timeIntervalSince1970]; // *1000 是精确到毫秒，不乘就是精确到秒
    return [[NSString stringWithFormat:@"%.0f", timestamp] integerValue];
}


NS_ASSUME_NONNULL_END
