//
//  OTAViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/8.
//

#import "OTAViewController.h"

@interface OTAViewController ()

@end

@implementation OTAViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
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



- (IBAction)otaAction:(UIButton *)sender {
    
    
    /**OTA注意事项
     1.必须要比当前版本大才能升级成功，
     2.version 必须按照 一定的格式来 (以下 xx 代表为数值)
       阿波罗  Apollo: APxxBxx
       字库    Res: Rxx
       屏幕    Tp: Txx
       心率    Hr: Hxx
     */
    
    
    //读取本地Bin文件
    NSString *filePath1 = @"";
    NSString *filePath2 = @"";
    NSString *filePath3 = @"";
    
    NSMutableArray *models = [NSMutableArray new];
    [models addObject:[EAFileModel allocInitWithPath:filePath1 otaType:EAOtaRequestTypeRes version:@"R0.3"]];
    [models addObject:[EAFileModel allocInitWithPath:filePath2 otaType:EAOtaRequestTypeRes version:@"R0.4"]];
    [models addObject:[EAFileModel allocInitWithPath:filePath3 otaType:EAOtaRequestTypeApollo version:@"AP0.1B4.2"]];
    
    BOOL succ = [[EABleSendManager defaultManager] upgradeFiles:models];
    
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
