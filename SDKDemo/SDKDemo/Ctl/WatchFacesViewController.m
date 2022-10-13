//
//  WatchFacesViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/8.
//

#import "WatchFacesViewController.h"

@interface WatchFacesViewController ()

@end

@implementation WatchFacesViewController


- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    // 添加通知，监听传输完成
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(syncDataFinish) name:kNTF_EAOTAAGPSDataFinish object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(showProgress:) name:kNTF_EAOTAAGPSDataing object:nil];

}
- (void)syncDataFinish {
    
    [self dismissAlert];
    [self showAlertWithTitle:@"Success"];
}

- (void)showProgress:(NSNotification *)no {
    
    if ([no.object floatValue] < 0) {
        
        [self dismissAlert];
        [self showAlertWithTitle:@"Fail"];
        return;
    }

    NSLog(@">>>>> Progress:%0.2f%%",[no.object floatValue]);
}

- (IBAction)setWatchFacesAction:(UIButton *)sender {
    
    
    EADialPlateModel *dpModel = [[EADialPlateModel alloc] init];
    dpModel.id_p = [sender.titleLabel.text integerValue];
    
    WeakSelf
    [BluetoothFunc changeWatchFaces:dpModel completion:^(BOOL succ) {
        
        [selfWeak showAlertWithTitle:@"Set success"];
    }];
}

- (IBAction)setCustomWatchFacesAction:(UIButton *)sender {
    
    //读取本地Bin文件
    NSString *filePath = @"";  //
    EAFileModel *fileModel = [EAFileModel allocInitWithPath:filePath otaType:(EAOtaRequestTypeUserWf) version:@"1"];
    BOOL succ = [[EABleSendManager defaultManager] upgradeWatchFaceFile:fileModel];
    
    if (succ) {
        
        [self showAlertWithTitle:@"Sync" message:@"Wait for a moment, please"];
        [[UIApplication sharedApplication] setIdleTimerDisabled:YES];
        
    }else {
        
        /**失败原因
         1.正在同步中
         2.同步的文件是空的
         */
        [self showAlertWithTitle:@"Fail"];
    }
    
    
}

@end
