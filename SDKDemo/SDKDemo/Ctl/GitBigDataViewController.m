//
//  GitBigDataViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/8.
//

#import "GitBigDataViewController.h"

@interface GitBigDataViewController ()

@end

@implementation GitBigDataViewController

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    [super viewDidLoad];

//    [self showAlertWithTitle:@"Get big data" message:@"Wait for a moment, please"];

    // 添加通知，监听传输完成
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(syncDataFinish:) name:kNTF_EAGetDeviceOpsPhoneMessage object:nil];
    
    // 发送请求大数据数据请求
    [self getBigData];
    
}

- (void)getBigData {
    
    EAGetBigDataRequestModel *model = [[EAGetBigDataRequestModel alloc] init];
    [[EABleSendManager defaultManager] operationgGetBigData:model respond:^(EARespondModel * _Nonnull respondModel) {
        
        
    }];
}


- (void)syncDataFinish:(NSNotification *)noti {
    
    EAPhoneOpsModel *phoneOpsModel = (EAPhoneOpsModel *)noti.object;
    if (phoneOpsModel.eOps == EAPhoneOpsBig8803DataUpdateFinish) { // 大数据接收完成
       
        // 日常步数
        NSArray *steps = [[EABleSendManager defaultManager] getBigDataWithBigDataType:(EADataInfoTypeStepData)];
        // 运动据
        NSArray *sports = [[EABleSendManager defaultManager] getBigDataWithBigDataType:(EADataInfoTypeSportsData)];
        // 心率
        NSArray *hrs = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeHeartRateData];
        // 睡眠
        NSArray *sleeps = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeSleepData];
        // 血氧
        NSArray *bloodOxygens = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeBloodOxygenData];
        // 压力
        NSArray *stress = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeStressData];
        // GPS
        NSArray *pgs = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeGPSData];
        // 步频
        NSArray *stepFreq = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeStepFreqData];
        // 配速
        NSArray *bigDatas = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeStepPaceData];
        // 静息心率
        NSArray *Restinghr = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeRestingHeartRateData];
        // 习惯
        NSArray *habitTrackers = [[EABleSendManager defaultManager] getBigDataWithBigDataType:EADataInfoTypeHabitTrackerData];
   }
}


- (IBAction)getBigDataAction:(UIButton *)sender {
    
    
    NSArray *list = [[EABleSendManager defaultManager] getBigDataWithBigDataType:sender.tag];
    if (list.count == 0) {
        
        [self showAlertWithTitle:@"Doing sport,please"];
    }else {
        
        /**
         
         your code
         
         */
    }
}




@end
