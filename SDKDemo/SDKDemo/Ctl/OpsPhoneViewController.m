//
//  OpsPhoneViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/8.
//

#import "OpsPhoneViewController.h"

@interface OpsPhoneViewController ()

@end

@implementation OpsPhoneViewController

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    // 添加通知，监听传输完成
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(opsPhone:) name:kNTF_EAGetDeviceOpsPhoneMessage object:nil];
}

- (void)opsPhone:(NSNotification *)noti {
    
    EAPhoneOpsModel *phoneOpsModel = (EAPhoneOpsModel *)noti.object;
    
    
    switch (phoneOpsModel.eOps) {
        case EAPhoneOpsSearchPhone:
            
            break;
            
            // ....
            
        default:
            break;
    }
//    寻找手机
//    EAPhoneOpsSearchPhone = 0,
//
//     停止寻找手机(固件需求)
//    EAPhoneOpsStopSearchPhone = 1,
//
//    连接相机
//    EAPhoneOpsConnectTheCamera = 2,
//
//    开启拍照
//    EAPhoneOpsStartTakingPictures = 3,
//
//    停止拍照
//    EAPhoneOpsStopTakingPictures = 4,
//
//    请求最新天气信息
//    EAPhoneOpsRequestTheLatestWeather = 5,
//
//    请求最新agps星历数据
//    EAPhoneOpsRequestTheAgps = 6,
//
//    请求最新经期数据
//    EAPhoneOpsRequestTheMenstrualCycle = 7,
//
//    8803大数据传输完成
//    EAPhoneOpsBig8803DataUpdateFinish = 8,
    
}





@end
