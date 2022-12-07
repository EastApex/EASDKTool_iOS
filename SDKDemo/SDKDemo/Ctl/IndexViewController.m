//
//  IndexViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/6.
//

#import "IndexViewController.h"
#import "BluetoothFunc.h"


@interface IndexViewController () <UITableViewDelegate,UITableViewDataSource,EABleManagerDelegate>

/** tbView */
@property(nonatomic,weak) IBOutlet UITableView *tbView;
/** DataSource */
@property(nonatomic,strong) NSMutableArray *dataSource;

/** 未连接手表 */
@property(nonatomic,strong) IBOutlet UIView *noWatchHeadView;
/** 已连接手表 */
@property(nonatomic,strong) IBOutlet UIView *watchHeadView;



/** searchWatchsButton */
@property(nonatomic,weak) IBOutlet UIButton *searchWatchsButton;


@property(nonatomic,weak) IBOutlet UILabel *watchTypeLabel;
@property(nonatomic,weak) IBOutlet UILabel *watchSnLabel;
@property(nonatomic,weak) IBOutlet UILabel *watchFirmwareVersioLabel;
@property(nonatomic,weak) IBOutlet UILabel *watchUserIdLabel;
@property(nonatomic,weak) IBOutlet UILabel *watchAGPSLabel;
@property(nonatomic,weak) IBOutlet UILabel *watchBindingLabel;
@property(nonatomic,strong) IBOutlet UIButton *unbingButton;



@end



@implementation IndexViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"EASDK Demo";
    
    [_watchHeadView setFrame:CGRectMake(0, 0, kScreenWidth, 248)];
    [_noWatchHeadView setFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight)];
    _tbView.tableHeaderView = _noWatchHeadView;
    
    _tbView.delegate = self;
    _tbView.dataSource = self;
    
    [self addNotification];
    
    
}

#pragma mark - Notification
- (void)addNotification {
    
    /// 手表状态变更
    // 连接手表成功
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(connectSucc) name:kNTF_EAConnectStatusSucceed object:nil];
    // 连接手表失败
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(connectFailed) name:kNTF_EAConnectStatusFailed object:nil];
    // 手动断连手表
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(connectDisconnect) name:kNTF_EAConnectStatusDisconnect object:nil];

    /// 蓝牙状态变更
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(blePoweredOn) name:kNTF_EABlePoweredOn object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(blePoweredOff) name:kNTF_EABlePoweredOff object:nil];

}

- (void)removeNotification {
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
- (void)connectSucc {
    
    [self dismissAlert];
    
    _tbView.tableHeaderView = _watchHeadView;
    
    self.unbingButton.hidden = NO;
    [self.dataSource removeAllObjects];
    [self.tbView reloadData];
    
    WeakSelf
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeWatch) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAWatchModel *watchModel = (EAWatchModel *)baseModel;
        selfWeak.watchTypeLabel.text            = [@"手表类型：" stringByAppendingString:watchModel.type];
        selfWeak.watchSnLabel.text              = [@"SN：" stringByAppendingString:watchModel.id_p];
        selfWeak.watchFirmwareVersioLabel.text  = [@"手表版本号：" stringByAppendingString:watchModel.firmwareVersion];
        selfWeak.watchUserIdLabel.text          = [@"关联用户ID：" stringByAppendingString:watchModel.userId];
        selfWeak.watchAGPSLabel.text            = [@"AGPS更新时间：" stringByAppendingString:timestampToTimeString(watchModel.agpsUpdateTimestamp)];
        selfWeak.watchBindingLabel.text         = [@"绑定状态：" stringByAppendingString:(watchModel.bindingType == EABindingTypeBound? @"已绑定":@"未绑定")];
        // 判断手表是否被绑定了
        if (watchModel.bindingType == EABindingTypeBound) { // 已绑定
            
            // 判断此手表是否是用户自己的手表
            if ([watchModel.userId isEqualToString:@"xxxxx"]) { // 用户自己的手表
                
//             do 读取或者同步手表数据
                //读取本地json文件
                NSError *error;
                NSString *path = [[NSBundle mainBundle] pathForResource:@"DataInfoTypes" ofType:@"json"];
                NSData *data = [[NSData alloc] initWithContentsOfFile:path];
                NSArray *list = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
                [self.dataSource addObjectsFromArray:list];
                [self.tbView reloadData];
                    
            }else {
                // 不是用户自己的手表
                [[EABleManager defaultManager] cancelConnectingPeripheral];// 设备要断开连接
            }
            
        }else {
            // 进去绑定操作
            
            // 判断 设置是否支持 手表界面需要点击确认才能完成绑定
            if (watchModel.isWaitForBinding) {
                // 需要手表操作确定绑定、
                
                EABingingOps *opsModel = [[EABingingOps alloc] init];
                opsModel.ops = EABindingOpsTypeNormalBegin; // 开始绑定
                [[EABleSendManager defaultManager] operationChangeModel:opsModel respond:^(EARespondModel * _Nonnull respondModel) {
                   
                    // 等待手表确认
                    if (respondModel.eErrorCode == EARespondCodeTypeSuccess) {  // 用户点击确认
                        
                        EABingingOps *opsModel = [[EABingingOps alloc] init];
                        opsModel.ops = EABindingOpsTypeEnd; // 结束绑定
                        opsModel.userId = @""; // 可以输入用户的id
                        [[EABleSendManager defaultManager] operationChangeModel:opsModel respond:^(EARespondModel * _Nonnull respondModel) {
                           
                            // 绑定结束
//                            do 读取或者同步手表数据
                            //读取本地json文件
                            NSError *error;
                            NSString *path = [[NSBundle mainBundle] pathForResource:@"DataInfoTypes" ofType:@"json"];
                            NSData *data = [[NSData alloc] initWithContentsOfFile:path];
                            NSArray *list = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
                            [self.dataSource addObjectsFromArray:list];
                            [self.tbView reloadData];
                            
                        }];
                        
                    }else {
                        
                        // 用户点击取消
                        // 绑定结束
                        [[EABleManager defaultManager] cancelConnectingPeripheral];// 设备要断开连接
                    }
                    
                    
                }];
                
            }else {
                // 不需要手表操作确定绑定
                EABingingOps *opsModel = [[EABingingOps alloc] init];
                opsModel.ops = EABindingOpsTypeEnd; // 结束绑定
                opsModel.userId = @""; // 可以输入用户的id
                [[EABleSendManager defaultManager] operationChangeModel:opsModel respond:^(EARespondModel * _Nonnull respondModel) {
                   
                    // 绑定结束
//                    do 读取或者同步手表数据
                    //读取本地json文件
                    NSError *error;
                    NSString *path = [[NSBundle mainBundle] pathForResource:@"DataInfoTypes" ofType:@"json"];
                    NSData *data = [[NSData alloc] initWithContentsOfFile:path];
                    NSArray *list = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
                    [self.dataSource addObjectsFromArray:list];
                    [self.tbView reloadData];
                }];
            }
        }
    }];
}


- (void)connectFailed {
    
    
}

- (void)connectDisconnect {
    
    // 手表断链后，如果是自动断连，SDK会主动重连设备，手动断连则不会
    [self showAlertWithTitle:@"Watch disconnect"];
    self.unbingButton.hidden = YES;
}

- (void)blePoweredOn {
    
    if ([[EABleManager defaultManager] getPeripheralModel]) { // 有设备信息
        
        [[EABleManager defaultManager] reConnectToPeripheral]; // 重连设备
    }
}

- (void)blePoweredOff {
    
    [self showAlertWithTitle:@"Bluetooth off"];
 
    self.unbingButton.hidden = YES;
    
}



#pragma mark - Action
- (IBAction)searchWatchsAction:(id)sender {
    
        // 判断是否开启蓝牙权限
    if ([[EABleManager defaultManager] isBleOn]) {
        
        // 搜索设备
        [[EABleManager defaultManager] scanPeripherals];
        [EABleManager defaultManager].delegate = self;
        
        _tbView.tableHeaderView = nil;
    }else {
        
        // 未开启蓝牙
        [self showAlertWithTitle:@"Open bluetooth"];
    }
}

- (IBAction)unbingAction:(id)sender {
       
    BOOL unbind = NO;
    if (unbind) {
        
        /// 解绑设备（手表会重置,重启，清空手表所有数据）
        [[EABleManager defaultManager] unbindPeripheral];
    }else {
       
        /// 解绑设备（物理层的断开连接）
        [[EABleManager defaultManager] disconnectPeripheral];
    }
    
    _tbView.tableHeaderView = _noWatchHeadView;
    [self.dataSource removeAllObjects];
    [self.tbView reloadData];
}


- (void)getBlacklightModel {
    
    [EABleSendManager.defaultManager operationGetInfoWithType:(EADataInfoTypeBlacklight) result:^(EABaseModel * _Nonnull baseModel) {
       
        EABlacklightModel *model = (EABlacklightModel *)baseModel;
    }];
}

- (void)setBlacklightModel {
    
    EABlacklightModel *model = [[EABlacklightModel alloc] init];
    model.level = 80;
    [EABleSendManager.defaultManager operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void) getBlacklightTimeoutModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeBlacklightTimeout) result:^(EABaseModel * _Nonnull baseModel) {
       
        EABlacklightTimeoutModel *model = (EABlacklightTimeoutModel *)baseModel;
    }];
}

- (void) setBlacklightTimeoutModel {
    
    EABlacklightTimeoutModel *model = [[EABlacklightTimeoutModel alloc] init];
    model.timeOut = 5;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getEABatteryModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeBattery) result:^(EABaseModel * _Nonnull baseModel) {
       
        EABatteryModel *model = (EABatteryModel *)baseModel;
    }];
}

- (void)getLanguageModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeLanguage) result:^(EABaseModel * _Nonnull baseModel) {
       
        EABlacklightTimeoutModel *model = (EABlacklightTimeoutModel *)baseModel;
    }];
}

- (void)setLanguageModel {
    
    EALanguageModel *model = [[EALanguageModel alloc] init];
    model.language = EALanguageTypeEnglish;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getUnitModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeUnifiedUnit) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAUnifiedUnitModel *model = (EAUnifiedUnitModel *)baseModel;
    }];
}

- (void)setUnitModel {
    
    EAUnifiedUnitModel *model = [[EAUnifiedUnitModel alloc] init];
    model.unit = EALengthUnitBritish;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)operateWatch {
    
    EADeviceOps *model = [[EADeviceOps alloc] init];
    model.deviceOpsType = EADeviceOpsTypeStartSearchWatch;
    model.deviceOpsStatus = EADeviceOpsStatusExecute;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}


- (void)getNotDisturbModel {
    

    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeNotDisturb) result:^(EABaseModel * _Nonnull baseModel) {
       
        EANotDisturbModel *model = (EANotDisturbModel *)baseModel;
    }];
}

- (void)setNotDisturbModel {
    
    EANotDisturbModel *model = [[EANotDisturbModel alloc] init];
    model.sw = 1;
    model.beginHour = 22;
    model.beginMinute = 30;
    model.endHour = 7;
    model.endMinute = 0;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getHomeTimeZoneModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeHomeTimeZone) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAHomeTimeZoneModel *model = (EAHomeTimeZoneModel *)baseModel;
    }];
}

- (void)setHomeTimeZoneModel {
    
    EAHomeTimeZoneItem *item = [[EAHomeTimeZoneItem alloc] init];
    item.timeZone = EATimeZoneEast;
    item.timeZoneHour = 8;
    item.timeZoneMinute = 0;
    
    EAHomeTimeZoneModel *model = [[EAHomeTimeZoneModel alloc] init];
    model.sHomeArray = [NSMutableArray arrayWithArray:@[item]];
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getDailyGoalModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeDailyGoal) result:^(EABaseModel * _Nonnull baseModel) {
       
        EADailyGoalModel *model = (EADailyGoalModel *)baseModel;
    }];
}

- (void)setDailyGoalModel {
    
    EADailyGoalItem *step = [[EADailyGoalItem alloc] init];
    step.sw = 1;
    step.goal = 7000;
    
//    ... // 其他目标
    
    EADailyGoalModel *model = [[EADailyGoalModel alloc] init];
    model.sStep = step;
//    ... // 其他目标
    
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getAutoCheckSleepModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeAutoCheckSleep) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAAutoCheckSleepModel *model = (EAAutoCheckSleepModel *)baseModel;
    }];
}

- (void)setAutoCheckSleepModel {
    
    EAAutoCheckSleepModel *model = [[EAAutoCheckSleepModel alloc] init];
    model.weekCycleBit = 49;
    model.beginHour = 18;
    model.beginMinute = 0;
    model.endHour = 9;
    model.endMinute = 0;

    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getAutoCheckHeartRateModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeAutoCheckHeartRate) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAAutoCheckHeartRateModel *model = (EAAutoCheckHeartRateModel *)baseModel;
    }];
}

- (void)setAutoCheckHeartRateModel {
    
    EAAutoCheckHeartRateModel *model = [[EAAutoCheckHeartRateModel alloc] init];
    model.interval = 30;// Heart rate detection every 30 minutes 【30分钟检测一次心率】

    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getAutoCheckSedentarinessModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeAutoCheckSedentariness) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAAutoCheckSedentarinessModel *model = (EAAutoCheckSedentarinessModel *)baseModel;
    }];
}

- (void)setAutoCheckSedentarinessModel {
    
    EAAutoCheckSedentarinessModel *model = EAAutoCheckSedentarinessModel.new;
    model.interval = 60;
    model.weekCycleBit = 127;
    model.beginHour = 9;
    model.beginMinute = 0;
    model.endHour = 18;
    model.endMinute = 0;
    model.stepThreshold = 10;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)setWeather{
    
    EADayWeatherModel *day1 = EADayWeatherModel.new;
    day1.eDayType = EAWeatherTypeClear;
    day1.eNightType = EAWeatherTypeCloudy;
    day1.eAir =  EAWeatherAirTypeGood;
//        ... 其他数据
    
    
    EAWeatherModel *model = EAWeatherModel.new;
    model.sDayArray = @[day1];
    model.place = @"guangzhou";
    model.currentTemperature = 25;
    model.eFormat =  EAWeatherUnitCentigrade;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getSocialSwitchModel{
    
    WeakSelf
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeSocialSwitch) result:^(EABaseModel * _Nonnull baseModel) {
       
        EASocialSwitchModel *model = (EASocialSwitchModel *)baseModel;
        
        model.sSms.sw = 1;
        model.sSms.remindActionType = EARemindActionTypeOneLongVibration;
        [selfWeak setSocialSwitchModel:model];
    }];

}

- (void)setSocialSwitchModel:(EASocialSwitchModel *)model{
    
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}



- (void)getReminder {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeReminder) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAReminderOps *model = (EAReminderOps *)baseModel;
   
    }];
}

- (void)addReminder {
    
    EAReminderModel *reminder1 = EAReminderModel.new;
    reminder1.remindActionType = EARemindActionTypeLongVibration;
    reminder1.reminderEventType = EAReminderEventTypeAlarm;
    reminder1.sw = 1;
    reminder1.secSw = 1;
    reminder1.hour = 7;
    reminder1.minute = 10;
    reminder1.year = 2022;
    reminder1.month = 8;
    reminder1.day = 16;
    
    
    EAReminderOps *model = EAReminderOps.new;
    model.sIndexArray = @[reminder1];
    model.eOps = EAReminderEventOpsAdd;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)editReminder {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeReminder) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAReminderOps *model = (EAReminderOps *)baseModel;
        
        EAReminderModel *reminder1 = [model.sIndexArray firstObject];
        reminder1.sw = 0;
        
        model.id_p = reminder1.id_p;
        model.eOps = EAReminderEventOpsEdit;
        [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
            
        }];
        
    }];
}

- (void)deleteReminder {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeReminder) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAReminderOps *model = (EAReminderOps *)baseModel;
        
        EAReminderModel *reminder1 = [model.sIndexArray firstObject];
        
        model.id_p = reminder1.id_p;
        model.eOps = EAReminderEventOpsDel;
        [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
            
        }];
    }];
}


- (void)getDistanceUintModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeDistanceUnit) result:^(EABaseModel * _Nonnull baseModel) {
       
        EADistanceUintModel *model = (EADistanceUintModel *)baseModel;
   
    }];
}

- (void)setDistanceUintModel{
    
    
    EADistanceUintModel *model = EADistanceUintModel.new;
    model.unit = EADistanceUnitKilometre;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getWeightUnitModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeWeightUnit) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAWeightUnitModel *model = (EAWeightUnitModel *)baseModel;
   
    }];
}

- (void)setWeightUnitModel{
    
    
    EAWeightUnitModel *model = EAWeightUnitModel.new;
    model.unit = EAWeightUnitKilogram;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getHeartRateWaringSettingModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeHeartRateWaringSetting) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAHeartRateWaringSettingModel *model = (EAHeartRateWaringSettingModel *)baseModel;
   
    }];
}

- (void)setHeartRateWaringSettingModel{
    
    EAHeartRateWaringSettingModel *model = EAHeartRateWaringSettingModel.new;
    model.sw = 1;
    model.maxHr = 180;
    model.minHr = 50;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getCaloriesSettingModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeCaloriesSetting) result:^(EABaseModel * _Nonnull baseModel) {
       
        EACaloriesSettingModel *model = (EACaloriesSettingModel *)baseModel;
   
    }];
}

- (void)setCaloriesSettingModel{
    
    EACaloriesSettingModel *model = EACaloriesSettingModel.new;
    model.sw = 1;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getGesturesSettingModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeGesturesSetting) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAGesturesSettingModel *model = (EAGesturesSettingModel *)baseModel;
   
    }];
}

- (void)setGesturesSettingModel{
    
    EAGesturesSettingModel *model = EAGesturesSettingModel.new;
    model.eBrightSrc = 1;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getAndSetCombinationModel {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeCombination) result:^(EABaseModel * _Nonnull baseModel) {
       
        EACombinationModel *model = (EACombinationModel *)baseModel;
   
        model.setVibrateIntensity = YES;
        model.eVibrateIntensity = EAVibrateIntensityTypeStrong;
        
        [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
            
        }];
    }];
}


- (void)getHomePageModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeHomePage) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAHomePageModel *model = (EAHomePageModel *)baseModel;
    }];
}

- (void)setHomePageModel{
    
    EAPageModel *page1 = [[EAPageModel alloc] init];
    page1.eType = EAFirstLeverTypePageHeartRate;
    
    
    EAHomePageModel *model = EAHomePageModel.new;
    model.sPageArray = [NSMutableArray arrayWithObject:page1];
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)setPeriod {
    
    EAMenstruals *model = [EAMenstruals allocInitWithStartDate:@"2022-08-16" keepDay:7 cycleDay:28];
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)getWatchFace{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeDailyGoal) result:^(EABaseModel * _Nonnull baseModel) {
       
        EADialPlateModel *model = (EADialPlateModel *)baseModel;
    }];
}

- (void)setWatchFace{
    
    // id_p userWfId 不可同时设置
    EADialPlateModel *model = EADialPlateModel.new;
    model.id_p = 2; // 设置序号为2的内置表盘
    // model.userWfId = "46641671517" // 设置序号为46641671517的已安装的自定义表盘
    
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)customWatchFace {
    
    /**
     添加通知 查看进度
     [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(syncDataFinish) name:kNTF_EAOTAAGPSDataFinish object:nil];
     [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(showProgress:) name:kNTF_EAOTAAGPSDataing object:nil];
     */
    
    EAFileModel *fileModel = [EAFileModel allocInitWithPath:@"" otaType:(EAOtaRequestTypeUserWf) version:@"1"];
    [[EABleSendManager defaultManager] upgradeWatchFaceFile:fileModel];
    
}

- (void)getAppPushModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeAppMessage) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAAppMessageSwitchData *model = (EAAppMessageSwitchData *)baseModel;
        EAShowAppMessageModel *appPushModel = [EAShowAppMessageModel allocInitWithAppMessageSwitchData:model];
    }];
}

- (void)setAppPushModel{
    
    EAShowAppMessageModel *appPushModel = [[EAShowAppMessageModel alloc] init];
    appPushModel.skype = YES;
    EAAppMessageSwitchData *model = [appPushModel getEAAppMessageSwitchData];
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}


- (void)getHabitTracker{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeHabitTracker) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAHabitTrackers *model = (EAHabitTrackers *)baseModel;
   
    }];
}

- (void)addHabitTracker {
    
    EAHabitTrackerModel *habit1 = EAHabitTrackerModel.new;
    habit1.eAction = EARemindActionTypeOneLongVibration;
    habit1.eIconId = EAHabitTrackerIconTypeStudy01;
    habit1.beginHour = 19;
    habit1.beginMinute = 0;
    habit1.endHour = 20;
    habit1.endMinute = 0;
    habit1.duration = 30;
    habit1.content = @"Study English";
    
    EAHabitTrackers *model = EAHabitTrackers.new;
    model.sIndexArray = @[habit1];
    model.eOps = EAHabitTrackerOpsAdd;
    [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
        
    }];
}

- (void)editHabitTracker{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeReminder) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAHabitTrackers *model = (EAHabitTrackers *)baseModel;

        EAHabitTrackerModel *habit1 = [model.sIndexArray firstObject];
        habit1.content = @"Study German";

        model.id_p = habit1.id_p;
        model.eOps = EAHabitTrackerOpsEdit;
        [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
            
        }];
        
    }];
}

- (void)deleteHabitTrackerr {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeReminder) result:^(EABaseModel * _Nonnull baseModel) {
       
        EAHabitTrackers *model = (EAHabitTrackers *)baseModel;

        EAHabitTrackerModel *habit1 = [model.sIndexArray firstObject];

        model.id_p = habit1.id_p;
        model.eOps = EAHabitTrackerOpsDel;
        [[EABleSendManager defaultManager] operationChangeModel:model respond:^(EARespondModel * _Nonnull respondModel) {
            
        }];
    }];
}

- (void)getSportShowDataModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeSportShowData) result:^(EABaseModel * _Nonnull baseModel) {
       
        EASportShowDataModel *model = (EASportShowDataModel *)baseModel;
    }];
}

- (void)getBlePairStateModel{
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeBlePairState) result:^(EABaseModel * _Nonnull baseModel) {
       
        EABlePairStateModel *model = (EABlePairStateModel *)baseModel;
    }];
}

#pragma mark - EABleManagerDelegate
/// 发现设备
- (void)didDiscoverPeripheral:(EAPeripheralModel *)peripheralModel {
    
    for (EAPeripheralModel *_peripheralModel in self.dataSource) {
        
        if ([_peripheralModel.SN isEqualToString:peripheralModel.SN]) {
            
            return;
        }
    }
    [self.dataSource addObject:peripheralModel];
    [self.tbView reloadData];
}

#pragma mark - UITableViewDelegate,UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    id model = [self.dataSource objectAtIndex:indexPath.row];

    if ([model isKindOfClass:[EAPeripheralModel class]]) {
        
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"UITableViewCellStyleSubtitle"];
        if (!cell) {
            
            cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"UITableViewCellStyleSubtitle"];
        }
       
        EAPeripheralModel *peripheralModel = (EAPeripheralModel *)model;
        cell.textLabel.text = peripheralModel.peripheral.name;
        cell.detailTextLabel.text = [@"sn:" stringByAppendingString:peripheralModel.SN];
        return cell;
    }else {
        
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"UITableViewCellStyleValue1"];
        if (!cell) {
            
            cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@"UITableViewCellStyleValue1"];
        }
       
        NSDictionary *item = (NSDictionary *)model;
        cell.textLabel.text = item[@"title"];
        return cell;
    }
    
    
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    return 60;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    id model = [self.dataSource objectAtIndex:indexPath.row];
    
    if ([model isKindOfClass:[EAPeripheralModel class]]) {
        
        /// 连接手表
        [[EABleManager defaultManager] connectToPeripheral:[self.dataSource objectAtIndex:indexPath.row]];
        
        /// 弹窗
        [self showAlertWithTitle:@"Connecting" message:@"Wait for a moment, please"];
        
        /// 等待通知 kNTF_EAConnectStatusSucceed
        ///
        /// 
    }else {
        
        if ([EABleManager defaultManager].isConnected) {
            
            NSDictionary *item = [self.dataSource objectAtIndex:indexPath.row];
            NSString *ctl = [item objectForKey:@"ctl"];
            Class class = NSClassFromString(ctl);
            UIViewController *viewController = [[class alloc] init];
            viewController.title = [item objectForKey:@"title"];
            [self.navigationController pushViewController:viewController animated:YES];
            
        }else {
            
            [self showAlertWithTitle:@"Watch disconnect"];
        }
    }
}


#pragma mark - lasy
- (NSMutableArray *)dataSource {
    
    if (!_dataSource) {
        
        _dataSource = [[NSMutableArray alloc] init];
    }
    return _dataSource;
}



@end
