//
//  SyncTimeViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//

#import "SyncTimeViewController.h"

@interface SyncTimeViewController ()

/** EASyncTime */
@property(nonatomic,strong) EASyncTime *syncTime;
@end

@implementation SyncTimeViewController

- (void)viewDidLoad {
    [super viewDidLoad];


}


- (void)loadWatchData {
    
    
    
    
    
    
    WeakSelf
    [BluetoothFunc getWatchTime:^(EASyncTime * _Nonnull syncTime) {
       
        selfWeak.syncTime = syncTime;
        
        NSArray *timeZones = @[@"0时区",@"东时区",@"西时区"];
        
        selfWeak.textLabel.text = [NSString stringWithFormat:@"时间制式：%@\n时间：%ld.%02ld.%02ld %02ld:%02ld:%02ld\n当前时区：%@\n与0时区相差：%ld\n",(syncTime.timeHourType == EATimeHourTypeHour24 ? @"24小时制":@"12小时制"),syncTime.year,syncTime.month,syncTime.day,syncTime.hour,syncTime.minute,syncTime.second,timeZones[syncTime.timeZone],syncTime.timeZoneHour];
        
    }];
    
}


- (IBAction)setTimeAction {
    
    EASyncTime *syncTime = [EASyncTime getCurrentTime];
    
    ///修改syncTime的属性值。
//    syncTime.hour = 1;
    
    WeakSelf
    [BluetoothFunc changeSyncTime:syncTime completion:^(BOOL succ) {
       
        [selfWeak loadWatchData];
    }];
}





@end
