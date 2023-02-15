//
//  ViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2022/8/4.
//

import UIKit
import EABluetooth

class ViewController: UIViewController, EABleManagerDelegate, UITableViewDataSource, UITableViewDelegate {
    
    var alertView: UIAlertController!
    var ids: NSMutableArray!
    
    var listCtl : UINavigationController!
    
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
        
        self.present(alertView, animated: true, completion: nil)
    }
    
    
    func didDiscoverPeripheral(_ peripheralModel: EAPeripheralModel) {
        
        if ids.contains(peripheralModel.peripheral.identifier.uuidString) {
            
            return
        }
        
        ids.add(peripheralModel.peripheral.identifier.uuidString);
        
        print(peripheralModel.peripheral.name!)
        
        dataSource.add(peripheralModel)
        
        tbView.reloadData();
    }
    
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        alertView = UIAlertController.init(title: "Connecting", message: "Please Wait", preferredStyle: .alert)

        ids = NSMutableArray.init()
        
        EABleManager.default().delegate = self;
        
        tbView.dataSource = self
        tbView.delegate = self
        tbView.isHidden = true
        
        addNotification()
    }
    
    func loadWatchData(){
        
        setSyncTime()

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
        
        listCtl.dismiss(animated: true);
    }
    
    @objc func blePoweredOn(){
        
        print("blePoweredOn")
    }
    @objc func blePoweredOff(){
        
        print("blePoweredOff")
        listCtl.dismiss(animated: true);
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

        if operatingModel.intValue < 0 { // failing 失败
            
            if operatingModel.intValue == -1 {
                
                /// Failure to send OTA data: Reject OTA request => Other reasons
                /// 发送OTA数据失败：拒绝ota请求=>其他原因
            }
            
            if operatingModel.intValue == -2 {
                
                /// Failed to send OTA data: Reject OTA request => The device has updated the version
                /// 发送OTA数据失败：拒绝ota请求=>设备已经更新此版本
            }
            
            if operatingModel.intValue == -4 {
                
                /// Failed to send OTA data: transmission completed. CRC check error
                /// 发送OTA数据失败：传输完成，crc校验错误
                
            }
            
        }else {
            
            // The current progress 当前进度
            
        }
        
    }
    
    @IBAction func searchWatch(_ sender: Any) {
        
        EABleManager.default().scanPeripherals();

        tbView.isHidden = false


        EABleManager.default().unbindAndResetPeripheral()
                
    }
    
    func showView(){
        
        alertView.dismiss(animated: true)
        
        dataSource.removeAllObjects()
        tbView.reloadData()
        tbView.isHidden = true
        ids.removeAllObjects()
        
        bindingWatch("")
        
        let listViewController = ListViewController()
        listCtl = UINavigationController(rootViewController: listViewController)
        listCtl.modalPresentationStyle = .fullScreen
        self.present(listCtl, animated: true, completion: nil)
        

        
        /**
         
         1.Call this method to get information about form watch
         
         EABleSendManager.default().operationGetInfo(dataInfoType)
         
         dataInfoType see EAEnum.h ==> EADataInfoType
         
         2.Call this method to set information about on watch
         
         EABleSendManager.default().operationChange(）
         
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
        
       
    }
    
    
    func bindingWatch(_ userId:String){
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.watch) { baseModel in

            /**
             Judge bindingType == .unBound need set EABingingOps().ops = .end to complete the binding
             【判断bindingType == . unbound需要设置EABingingOps()。Ops = .end完成绑定】
             */
            if (baseModel as! EAWatchModel).bindingType == .unBound {

                let bindWatch = EABingingOps()
                bindWatch.ops = EABindingOpsType.end //  Set EABindingOpsType. End to complete the binding 【设置 EABindingOpsType.end 完成绑定】
                EABleSendManager.default().operationChange(bindWatch) { respondModel in

                    self.loadWatchData();
                }
            }else {
                
                self.loadWatchData();
            }
        }
        
    
         /*
         // 获取手表信息
         EABleSendManager.default().operationGetInfo(with: EADataInfoType.watch) { baseModel in

             // 判断手表是否被绑定了
             let watchModel = baseModel as! EAWatchModel
             if (watchModel.bindingType == .bound) { // 已绑定

                 // 判断此手表是否是用户自己的手表
                 if (watchModel.userId == userId) { // 用户自己的手表

                     // do 读取或者同步手表数据
                     self.loadWatchData()
                 }else {

                     // 不是用户自己的手表
                     EABleManager.default().cancelConnectingPeripheral();// 设备要断开连接
                 }

             }else {

                 // 未绑定
                 // 判断 设置是否支持 手表界面需要点击确认才能完成绑定
                 if (watchModel.isWaitForBinding == 1) {
                     // 需要手表操作确定绑定、
                     let bindWatch = EABingingOps()
                     bindWatch.ops = EABindingOpsType.normalBegin // 开始绑定
                     EABleSendManager.default().operationChange(bindWatch) { respondModel in

                         // 等待手表确认

                         if respondModel.eErrorCode == .success { // 用户点击确认

                             let bindWatch = EABingingOps()
                             bindWatch.ops = EABindingOpsType.end //  Set EABindingOpsType. End to complete the binding 【设置 EABindingOpsType.end 完成绑定】
                             bindWatch.userId = userId
                             EABleSendManager.default().operationChange(bindWatch) { respondModel in

                                 // 绑定结束
                                 // do 读取或者同步手表数据
                                 self.loadWatchData()
                             }
                         }else {

                             // 用户点击取消
                             // 绑定结束
                             EABleManager.default().cancelConnectingPeripheral();// 设备要断开连接
                         }

                     }


                 }else {

                     let bindWatch = EABingingOps()
                     bindWatch.ops = EABindingOpsType.end //  Set EABindingOpsType. End to complete the binding 【设置 EABindingOpsType.end 完成绑定】
                     bindWatch.userId = userId
                     EABleSendManager.default().operationChange(bindWatch) { respondModel in

                         // 绑定结束
                         // do 读取或者同步手表数据
                         self.loadWatchData()
                     }
                 }
             }
         }
         
         */
    }
    

    func setSyncTime() {
        
        let syncTimeModel = EASyncTime.getCurrent()
        EABleSendManager.default().operationChange(syncTimeModel) { respondModel in
            
        }
    }

}

