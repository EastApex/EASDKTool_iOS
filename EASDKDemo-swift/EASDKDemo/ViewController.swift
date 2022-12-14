//
//  ViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2022/8/4.
//

import UIKit

import EABluetooth

class ViewController: UIViewController, EABleManagerDelegate, UITableViewDataSource, UITableViewDelegate {
    
    @IBOutlet weak var tbView: UITableView!
    var dataSource:NSMutableArray = []
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return dataSource.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        
        let identifier = "reusedCell"
        var cell = tableView.dequeueReusableCell(withIdentifier: identifier)
        if cell == nil{
            cell = UITableViewCell(style: .default, reuseIdentifier: identifier)
        }
        
        let peripheralModel = (dataSource[indexPath.row] as! EAPeripheralModel);
        cell?.textLabel?.text = peripheralModel.peripheral.name! + "  " + peripheralModel.sn
        return cell!
        
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let peripheralModel = dataSource[indexPath.row] as! EAPeripheralModel
        
        EABleManager.default().stopScanPeripherals()
        EABleManager.default().connect(toPeripheral: peripheralModel);
        
    }
    
    
    func didDiscoverPeripheral(_ peripheralModel: EAPeripheralModel) {
        
        print(peripheralModel.peripheral.name!)
        
        dataSource.add(peripheralModel)
        
        tbView.reloadData();
    }
    
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        EABleManager.default().delegate = self;
        
        tbView.dataSource = self
        tbView.delegate = self
        tbView.isHidden = true
        
        addNotification()
    }
    
    func loadWatchData(){
        
        setSyncTime()
//        getWatchUserInfo();
//
//        // pair watch
//        opsWatch(EADeviceOpsType.showiPhonePairingAlert)
//
//
//        EABleSendManager.default().operationGetInfo(with: EADataInfoType.sportShowData) { baseModel in
//
//            print(baseModel.modelToJSONObject()!);
//        }
        
//        addReminder();
        
//        operateWatch()
//
//        getSocialSwitchModel ()
//
//        setAppPushModel()
//
//        getAppPushModel()
        
        
        
//        EABleSendManager.default().operationgGetBigData(EAGetBigDataRequestModel.init()) { respondModel in
//
//        };
        
        self.perform(#selector(customPictureWatchFace), with: nil, afterDelay: 3)

    }
    
    func addNotification(){
        
        NotificationCenter.default.addObserver(self, selector: #selector(connectSucc), name: NSNotification.Name(kNTF_EAConnectStatusSucceed), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(connectFailed), name: NSNotification.Name(kNTF_EAConnectStatusFailed), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(connectDisconnect), name: NSNotification.Name(kNTF_EAConnectStatusDisconnect), object: nil)
        
        NotificationCenter.default.addObserver(self, selector: #selector(blePoweredOn), name: NSNotification.Name(kNTF_EABlePoweredOn), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(blePoweredOff), name: NSNotification.Name(kNTF_EABlePoweredOff), object: nil)
        
        NotificationCenter.default.addObserver(self, selector: #selector(operatingPhone), name: NSNotification.Name(kNTF_EAGetDeviceOpsPhoneMessage), object: nil)
        
        NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
        
    }
    
    @objc func connectSucc(){
        
        print("connectSucc")
        
        showView()
        
 
    }
    
    @objc func connectFailed(){
        
        print("connectFailed")
    }
    
    @objc func connectDisconnect(){
        
        print("connectDisconnect")
    }
    
    @objc func blePoweredOn(){
        
        print("blePoweredOn")
    }
    @objc func blePoweredOff(){
        
        print("blePoweredOff")
    }
    
    @objc func operatingPhone(_ no:NSNotification){
        
        let operatingModel = no.object as! EAPhoneOpsModel
        
        // see enum EAPhoneOps
        
        switch operatingModel.eOps {
            
        case .searchPhone:
            
            print("search Phone")
            
            break
        case .stopSearchPhone:
            
            print("stop search Phone")
            break
            
        case .big8803DataUpdateFinish:
            
            print("Watch sending big data done")
            
            // daliy step data
            let stepData = EABleSendManager.default().getBigData(withBigDataType: .stepData);
            // heart rate data
            let heartRateData = EABleSendManager.default().getBigData(withBigDataType: .heartRateData);
            // sports data
            let sportsData = EABleSendManager.default().getBigData(withBigDataType: .sportsData);
            // stress data
            let stressData = EABleSendManager.default().getBigData(withBigDataType: .stressData);
            // Blood oxygen data
            let bloodOxygenData = EABleSendManager.default().getBigData(withBigDataType: .bloodOxygenData);
            // resting heart rate
            let restingHeartRateData = EABleSendManager.default().getBigData(withBigDataType: .restingHeartRateData);
            // GPS data
            let gpsData = EABleSendManager.default().getBigData(withBigDataType: .gpsData);
            // stride frequency
            let stepFreqData = EABleSendManager.default().getBigData(withBigDataType: .stepFreqData);
            // stride Pace
            let stepPaceData = EABleSendManager.default().getBigData(withBigDataType: .stepPaceData);
            // habit tracker data
            let habitTrackerData = EABleSendManager.default().getBigData(withBigDataType: .habitTrackerData);
            // sleep data
            let sleepData = EABleSendManager.default().getBigData(withBigDataType: .sleepData);
            
            break
        default:
            
            break
        }
        
    }
    
    @objc func finishOTA(){
        
        
    }
    @objc func ingOTA(_ no:NSNotification){
        
        let operatingModel = no.object as! NSNumber

        if operatingModel.intValue < 0 { // failing ??????
            
            if operatingModel.intValue == -1 {
                
                /// Failure to send OTA data: Reject OTA request => Other reasons
                /// ??????OTA?????????????????????ota??????=>????????????
            }
            
            if operatingModel.intValue == -2 {
                
                /// Failed to send OTA data: Reject OTA request => The device has updated the version
                /// ??????OTA?????????????????????ota??????=>???????????????????????????
            }
            
            if operatingModel.intValue == -4 {
                
                /// Failed to send OTA data: transmission completed. CRC check error
                /// ??????OTA??????????????????????????????crc????????????
                
            }
            
        }else {
            
            // The current progress ????????????
            
        }
        
    }
    
    @IBAction func searchWatch(_ sender: Any) {
        
        EABleManager.default().scanPeripherals();
        
        tbView.isHidden = false
        
        
        EABleManager.default().unbindAndResetPeripheral()
    }
    
    func showView(){
        
        dataSource.removeAllObjects()
        tbView.reloadData()
        
        bindingWatch("10086")
        
        
        

        
        /**
         
         1.Call this method to get information about form watch
         
         EABleSendManager.default().operationGetInfo(dataInfoType)
         
         dataInfoType see EAEnum.h ==> EADataInfoType
         
         2.Call this method to set information about on watch
         
         EABleSendManager.default().operationChange(???
         
         3. Get big data command
         
         EABleSendManager.default().operationgGetBigData(EAGetBigDataRequestModel.init()) { respondModel in
         
         }
         
         Wait for the watch to send the complete command before getting the big data details
         
         see func operatingPhone() ==> case:.big8803DataUpdateFinish
         
         
         4.Operating a watch
         
         see class EADeviceOps.h
         
         eg. pair watch
         
         let ops = EADeviceOps.init()
         ops.deviceOpsType = opsType
         ops.deviceOpsStatus = EADeviceOpsStatus.execute
         
         EABleSendManager.default().operationChange(ops) { respondModel in
         }
         
         5. Operating Phone
         
         add Notification:
         NotificationCenter.default.addObserver(self, selector: #selector(operatingPhone), name: NSNotification.Name(kNTF_EAGetDeviceOpsPhoneMessage), object: nil)
         
         see func operatingPhone()
         
         see enum EAPhoneOps
         
         6. OTA
         add Notification:
         NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
         NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
         
         
         */
        
        let file1 =  EAFileModel.allocInit(withPath: "", otaType: .apollo, version: "AP0.1B1.1")
        let file2 =  EAFileModel.allocInit(withPath: "", otaType: .res, version: "R0.4")
        let file3 =  EAFileModel.allocInit(withPath: "", otaType: .res, version: "R0.5")

        EABleSendManager.default().upgradeFiles([file1,file2,file3]);
    }
    
    
    func bindingWatch(_ userId:String){
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.watch) { baseModel in

            /**
             Judge bindingType == .unBound need set EABingingOps().ops = .end to complete the binding
             ?????????bindingType == . unbound????????????EABingingOps()???Ops = .end???????????????
             */
            if (baseModel as! EAWatchModel).bindingType == .unBound {

                let bindWatch = EABingingOps()
                bindWatch.ops = EABindingOpsType.end //  Set EABindingOpsType. End to complete the binding ????????? EABindingOpsType.end ???????????????
                EABleSendManager.default().operationChange(bindWatch) { respondModel in

                    self.loadWatchData();
                }
            }else {
                
                self.loadWatchData();
            }
        }
        
    
         /*
         // ??????????????????
         EABleSendManager.default().operationGetInfo(with: EADataInfoType.watch) { baseModel in

             // ??????????????????????????????
             let watchModel = baseModel as! EAWatchModel
             if (watchModel.bindingType == .bound) { // ?????????

                 // ?????????????????????????????????????????????
                 if (watchModel.userId == userId) { // ?????????????????????

                     // do ??????????????????????????????
                     self.loadWatchData()
                 }else {

                     // ???????????????????????????
                     EABleManager.default().cancelConnectingPeripheral();// ?????????????????????
                 }

             }else {

                 // ?????????
                 // ?????? ?????????????????? ????????????????????????????????????????????????
                 if (watchModel.isWaitForBinding == 1) {
                     // ?????????????????????????????????
                     let bindWatch = EABingingOps()
                     bindWatch.ops = EABindingOpsType.normalBegin // ????????????
                     EABleSendManager.default().operationChange(bindWatch) { respondModel in

                         // ??????????????????

                         if respondModel.eErrorCode == .success { // ??????????????????

                             let bindWatch = EABingingOps()
                             bindWatch.ops = EABindingOpsType.end //  Set EABindingOpsType. End to complete the binding ????????? EABindingOpsType.end ???????????????
                             bindWatch.userId = userId
                             EABleSendManager.default().operationChange(bindWatch) { respondModel in

                                 // ????????????
                                 // do ??????????????????????????????
                                 self.loadWatchData()
                             }
                         }else {

                             // ??????????????????
                             // ????????????
                             EABleManager.default().cancelConnectingPeripheral();// ?????????????????????
                         }

                     }


                 }else {

                     let bindWatch = EABingingOps()
                     bindWatch.ops = EABindingOpsType.end //  Set EABindingOpsType. End to complete the binding ????????? EABindingOpsType.end ???????????????
                     bindWatch.userId = userId
                     EABleSendManager.default().operationChange(bindWatch) { respondModel in

                         // ????????????
                         // do ??????????????????????????????
                         self.loadWatchData()
                     }
                 }
             }
         }
         
         */
    }
    
    
    
    
    /// Watch the information
    func getWatchInfo(){
        
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.watch) { baseModel in
            
            let userModel = baseModel as! EAWatchModel;
            print(userModel.modelToJSONObject()!);
        }
    }
    
    /// User the information
    func getWatchUserInfo(){
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.user) { baseModel in
            
            let userModel = baseModel as! EAUserModel;
            print(userModel.modelToJSONObject()!);
        }
    }
    
    func setWatchUserInfo() {
        
        let userModel = EAUserModel.init();
        userModel.height = 170;
//        ... // ????????????????????????
        EABleSendManager.default().operationChange(userModel) { respondModel in
            
            
        }
    }
    
    func getSyncTime() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.syncTime) { baseModel in
            
            let syncTime = baseModel as! EASyncTime;
            print(syncTime.modelToJSONObject()!);
        }
    }
    
    
    func setSyncTime() {
        
        let syncTimeModel = EASyncTime.getCurrent()
        syncTimeModel.timeHourType = .hour24;
        syncTimeModel.timeZoneHour = 5;
        syncTimeModel.timeZoneMinute = 30;
        syncTimeModel.timeZone = .east
        syncTimeModel.hour = 15;
        syncTimeModel.timeZoneMinute = 27;
        print(syncTimeModel.modelToJSONObject()!);

        
        EABleSendManager.default().operationChange(syncTimeModel) { respondModel in
            
        }
    }
    
    
    func opsWatch(_ opsType:EADeviceOpsType){
        
        let ops = EADeviceOps.init()
        ops.deviceOpsType = opsType
        ops.deviceOpsStatus = EADeviceOpsStatus.execute
        
        EABleSendManager.default().operationChange(ops) { respondModel in
            
            
        }
        
    }
    
    func changeUserInfo(){
        
        /**
         ???????????????baseModel ?????????????????????????????????
         Eg??? ??????????????????
         let userModel = EAUserModel.init();
         userModel.height = 170;
         .... // ??????????????????
         EABleSendManager.default().operationChange(userModel) { respondModel in
         
         }
         */
    }
    
    
    func getBlacklightModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.blacklight) { baseModel in
            
            let model = baseModel as! EABlacklightModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setBlacklightModel() {
        
        let model = EABlacklightModel.init();
        model.level = 80;
        EABleSendManager.default().operationChange(model) { respondModel in
            
            
        }
    }
    
    func getBlacklightTimeoutModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.blacklightTimeout) { baseModel in
            
            let model = baseModel as! EABlacklightTimeoutModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setBlacklightTimeoutModel() {
        
        let model = EABlacklightTimeoutModel.init();
        model.timeOut = 5;
        EABleSendManager.default().operationChange(model) { respondModel in
            
        }
    }
    
    func getEABatteryModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.battery) { baseModel in
            
            let model = baseModel as! EABatteryModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func getLanguageModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.language) { baseModel in
            
            let model = baseModel as! EALanguageModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setLanguageModel() {
        
        let model = EALanguageModel.init();
        model.language = .english;
        EABleSendManager.default().operationChange(model) { respondModel in
            
        }
    }
    
    
    func getUnitModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.language) { baseModel in
            
            let model = baseModel as! EAUnifiedUnitModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setUnitModel() {
        
        let model = EAUnifiedUnitModel.init();
        model.unit = .lengthUnitBritish;
        EABleSendManager.default().operationChange(model) { respondModel in
            
        }
    }
    
    func operateWatch() {
        
        let model = EADeviceOps.init()
        model.deviceOpsType = .showiPhonePairingAlert
        model.deviceOpsStatus = .execute
        EABleSendManager.default().operationChange(model) { respondModel in
            
        }
    }
    
    func getNotDisturbModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.notDisturb) { baseModel in
            
            let model = baseModel as! EANotDisturbModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setNotDisturbModel() {
        
        let model = EANotDisturbModel.init();
        model.sw = 1;
        model.beginHour = 22;
        model.beginMinute = 30;
        model.endHour = 7;
        model.endMinute = 0;
        EABleSendManager.default().operationChange(model) { respondModel in
            
        }
    }
    
    func getHomeTimeZoneModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.homeTimeZone) { baseModel in
            
            let model = baseModel as! EAHomeTimeZoneModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setHomeTimeZoneModel() {
        
        let item = EAHomeTimeZoneItem.init();
        item.timeZone = .east;
        item.timeZoneHour = 8;
        item.timeZoneMinute = 0;
        
        let model = EAHomeTimeZoneModel.init();
        model.sHomeArray = NSMutableArray.init(object: item);
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getDailyGoalModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.dailyGoal) { baseModel in
            
            let model = baseModel as! EADailyGoalModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setDailyGoalModel() {
        
        let step = EADailyGoalItem.init();
        step.sw = 1;
        step.goal = 7000
//        ... // ????????????
        
        let model = EADailyGoalModel.init();
        model.sStep = step
//        ... // ????????????
        
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getAutoCheckSleepModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.autoCheckSleep) { baseModel in
            
            let model = baseModel as! EAAutoCheckSleepModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setAutoCheckSleepModel() {
        
        let model = EAAutoCheckSleepModel.init();
        model.weekCycleBit = 49;
        model.beginHour = 18;
        model.beginMinute = 0;
        model.endHour = 9;
        model.endMinute = 0;
    
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getAutoCheckHeartRateModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.autoCheckHeartRate) { baseModel in
            
            let model = baseModel as! EAAutoCheckHeartRateModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setAutoCheckHeartRateModel() {
        
        let model = EAAutoCheckHeartRateModel.init();
        model.interval = 30; // Heart rate detection every 30 minutes ???30???????????????????????????
    
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getAutoCheckSedentarinessModel() {
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.autoCheckSedentariness) { baseModel in
            
            let model = baseModel as! EAAutoCheckSedentarinessModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setAutoCheckSedentarinessModel() {
        
        let model = EAAutoCheckSedentarinessModel.init();
        model.interval = 60;
        model.weekCycleBit = 127;
        model.beginHour = 9;
        model.beginMinute = 0;
        model.endHour = 18;
        model.endMinute = 0;
        model.stepThreshold = 10;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func setWeather(){
        
        let day1 = EADayWeatherModel.init();
        day1.eDayType = .clear;
        day1.eNightType = .cloudy;
        day1.eAir = .good;
//        ... ????????????
        
        
        let model = EAWeatherModel.init();
        model.sDayArray = NSMutableArray.init(object: day1);
        model.place = "guangzhou"
        model.currentTemperature = 25;
        model.eFormat = .centigrade;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    
    func getSocialSwitchModel (){
        
        EABleSendManager.default().operationGetInfo(with:.socialSwitch) { baseModel in
            
            let model = baseModel as! EASocialSwitchModel;
            print(model.modelToJSONObject()!);
            
            model.sEmail.sw = 1;
            model.sEmail.remindActionType = .longShortVibration;
            
            self.setSocialSwitchModel(model);
        }
        
    }
    
    func setSocialSwitchModel (_ model:EASocialSwitchModel){
        
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getReminder (){
        
        EABleSendManager.default().operationGetInfo(with:.reminder) { baseModel in
            
            let model = baseModel as! EAReminderOps;
            print(model.modelToJSONObject()!);
        }
    }
    
    func addReminder (){
        

        let reminder1 = EAReminderModel.init();
        reminder1.remindActionType = .longShortVibration;
        reminder1.reminderEventType = .alarm;
        reminder1.sw = 1;
        reminder1.secSw = 1;
        reminder1.hour = 7;
        reminder1.minute = 10;
        reminder1.year = 2022;
        reminder1.month = 8;
        reminder1.day = 16;
        
        
        let model = EAReminderOps.init();
        model.sIndexArray = NSMutableArray.init(object: reminder1);
        model.eOps = .add;
        EABleSendManager.default().operationChange(model) { respondModel in
            
            let dic = respondModel.modelToJSONObject()! as! NSDictionary;
            let reminderRespondModel = EAReminderRespondModel.model(withJSON: dic);

        }
    }
    
    func changeReminder(){
        
        EABleSendManager.default().operationGetInfo(with:.reminder) { baseModel in
            
            let model = baseModel as! EAReminderOps;
            print(model.modelToJSONObject()!);
            
            let reminder1 = model.sIndexArray.firstObject as! EAReminderModel;
            reminder1.sw = 0;
            
            model.id_p = reminder1.id_p;
            model.eOps = .edit;
            
            EABleSendManager.default().operationChange(model) { respondModel in

            }
        }
    }
    
    
    
    func deleteReminder(){
        
        EABleSendManager.default().operationGetInfo(with:.reminder) { baseModel in
            
            let model = baseModel as! EAReminderOps;
            print(model.modelToJSONObject()!);
            
            let reminder1 = model.sIndexArray.firstObject as! EAReminderModel;
            
            model.id_p = reminder1.id_p;
            model.eOps = .del;
            
            EABleSendManager.default().operationChange(model) { respondModel in

            }
        }
    }
    
    
    func getDistanceUintModel(){
        
        EABleSendManager.default().operationGetInfo(with:.distanceUnit) { baseModel in
            
            let model = baseModel as! EADistanceUintModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setDistanceUintModel(){
        
        
        let model = EADistanceUintModel.init();
        model.unit = .kilometre;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getWeightUnitModel(){
        
        EABleSendManager.default().operationGetInfo(with:.weightUnit) { baseModel in
            
            let model = baseModel as! EAWeightUnitModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setWeightUnitModel(){
        
        
        let model = EAWeightUnitModel.init();
        model.unit = .kilogram;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getHeartRateWaringSettingModel(){
        
        EABleSendManager.default().operationGetInfo(with:.heartRateWaringSetting) { baseModel in
            
            let model = baseModel as! EAHeartRateWaringSettingModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setHeartRateWaringSettingModel(){
        
        
        let model = EAHeartRateWaringSettingModel.init();
        model.sw = 1;
        model.maxHr = 180;
        model.minHr = 50;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    
    func getCaloriesSettingModel(){
        
        EABleSendManager.default().operationGetInfo(with:.caloriesSetting) { baseModel in
            
            let model = baseModel as! EACaloriesSettingModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setCaloriesSettingModel(){
        
        
        let model = EACaloriesSettingModel.init();
        model.sw = 1;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getGesturesSettingModel(){
        
        EABleSendManager.default().operationGetInfo(with:.gesturesSetting) { baseModel in
            
            let model = baseModel as! EAGesturesSettingModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setGesturesSettingModel(){
        
        
        let model = EAGesturesSettingModel.init();
        model.eBrightSrc = .allDay;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getAndSetCombinationModel(){
        
        EABleSendManager.default().operationGetInfo(with:.combination) { baseModel in
            
            let model = baseModel as! EACombinationModel;
            print(model.modelToJSONObject()!);
            
            model.setVibrateIntensity = 1;
            model.eVibrateIntensity = .strong;
            EABleSendManager.default().operationChange(model) { respondModel in

            }
        }
    }
    
    func getHomePageModel(){
        
        EABleSendManager.default().operationGetInfo(with:.homePage) { baseModel in
            
            let model = baseModel as! EAPageModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setHomePageModel(){
        
        let page1 = EAPageModel.init();
        page1.eType = .pageHeartRate;
        
        
        let model = EAHomePageModel.init();
        model.sPageArray = NSMutableArray.init(object: page1);
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
     
    
    func setPeriod(){
        
        let model = EAMenstruals.allocInit(withStartDate: "2022-08-16", keepDay: 7, cycleDay: 28);
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getWatchFace(){
        
        EABleSendManager.default().operationGetInfo(with:.dialPlate) { baseModel in
            
            let model = baseModel as! EADialPlateModel;
            print(model.modelToJSONObject()!);
        }
    }
    
    func setWatchFace(){
        
        // id_p userWfId ??????????????????
        let model = EADialPlateModel.init();
        model.id_p = 2; // ???????????????2???????????????
        // model.userWfId = "46641671517" // ???????????????46641671517??????????????????????????????
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func customWatchFace(){
        
        /**
         Add notification to view progress ???????????? ????????????
         NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
         NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
         */
        
        let path:NSString = Bundle.main.path(forResource:"001012_U6.1", ofType:"bin")! as NSString
        let fileModel = EAFileModel.allocInit(withPath: path as String, otaType: .userWf, version: "1");
        EABleSendManager.default().upgradeWatchFaceFile(fileModel);
        
    }
    
    @objc func customPictureWatchFace(){
        
        /**
         Add notification to view progress ???????????? ????????????
         NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
         NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
         */
        
        /**
         ?????????
         backgroundImage ????????? ??????????????????????????????
         class EAWatchModel ??? ????????????
         
         Note:
         The backgroundImage must be the same size as the watch.
         The class EAWatchModel is available in watch size
         */
        
        let backgroundImage = UIImage.init(named: "picture")!;
        EABleSendManager.default().customWatchFaceBackgroundImage(backgroundImage, colorType: .white ,styleType: .pictureNumber);
        
    }
    
    
    
    
    func getAppPushModel(){
        
        EABleSendManager.default().operationGetInfo(with:.appMessage) { baseModel in
            
            let model = baseModel as! EAAppMessageSwitchData;
            let appPushModel = EAShowAppMessageModel.eaAllocInit(with: model);
            print(appPushModel.modelToJSONObject()!);
        }
    }
    
    func setAppPushModel(){
        
        let appPushModel = EAShowAppMessageModel.init();
        appPushModel.gmail = true;
        
        let model = appPushModel.getEAAppMessageSwitchData();
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func getHabitTracker (){
        
        EABleSendManager.default().operationGetInfo(with:.habitTracker) { baseModel in
            
            let model = baseModel as! EAHabitTrackers;
            print(model.modelToJSONObject()!);
        }
    }
    
    func addHabitTracker (){
        
        let habit1 = EAHabitTrackerModel.init();
        habit1.eAction = .longShortVibration;
        habit1.eIconId = .study01;
        habit1.beginHour = 19;
        habit1.beginMinute = 0;
        habit1.endHour = 20;
        habit1.endMinute = 0;
        habit1.duration = 30;
        habit1.content = "Study English"
        
        let model = EAHabitTrackers.init();
        model.sIndexArray = NSMutableArray.init(object: habit1);
        model.eOps = .add;
        EABleSendManager.default().operationChange(model) { respondModel in

        }
    }
    
    func changeHabitTracker(){
        
        EABleSendManager.default().operationGetInfo(with:.habitTracker) { baseModel in
            
            let model = baseModel as! EAHabitTrackers;
            
            let habit1 = model.sIndexArray.firstObject as! EAHabitTrackerModel;
            habit1.content = "Study German";
            
            model.id_p = habit1.id_p;
            model.eOps = .edit;
            
            EABleSendManager.default().operationChange(model) { respondModel in

            }
        }
    }
    
    func deleteHabitTracker(){
        
        EABleSendManager.default().operationGetInfo(with:.reminder) { baseModel in
            
            let model = baseModel as! EAHabitTrackers;
            
            let habit1 = model.sIndexArray.firstObject as! EAHabitTrackerModel;
            
            model.id_p = habit1.id_p;
            model.eOps = .del;
            
            EABleSendManager.default().operationChange(model) { respondModel in

            }
        }
    }
    
    
    func getSportShowDataModel(){
        
        EABleSendManager.default().operationGetInfo(with:.sportShowData) { baseModel in
            
            let model = baseModel as! EASportShowDataModel;
        }
    }

    func getPairStateModel(){
        
        EABleSendManager.default().operationGetInfo(with:.blePairState) { baseModel in
            
            let model = baseModel as! EABlePairStateModel;
        }
    }
 
}

