//
//  GetBigDataViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/16.
//

import UIKit
import EABluetooth
class GetBigDataViewController: UIViewController  , UITableViewDelegate, UITableViewDataSource {
    
    var tableView : UITableView!
    static let cellId = "cellIdl"
    var dataSource : NSMutableArray!
    override func viewWillDisappear(_ animated: Bool) {
        
        NotificationCenter.default.removeObserver(self)
    }
    override func viewDidLoad() {
        super.viewDidLoad()

        
        view.backgroundColor = UIColor.white
        
        tableView = UITableView.init(frame: view.bounds, style: .grouped)
        tableView.contentInsetAdjustmentBehavior = .never
        tableView.delegate = self
        tableView.dataSource = self
        view.addSubview(tableView)
        
        tableView.snp.makeConstraints { make in
            
            make.top.equalTo(view.safeAreaLayoutGuide.snp.top)
            make.left.equalTo(view)
            make.right.equalTo(view)
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom)
        }
        
        dataSource = NSMutableArray.init();
        
        let setList:NSArray = [
            "Check whether the agreement supports separate access to big data.(id:44 Cmd_WatchSupport.getData() ==> supportOnlyGetBigData)",
            "id:29 \nGet all the big data【获取所有大数据】",
            "id:49 \nGet big data separately by type【按类型单独获取大数据】"
        ]
        let setInfo = NSMutableDictionary.init()
        setInfo.setObject(setList, forKey: "list" as NSCopying)
        dataSource.add(setInfo)

        addNotification()
    }
    
    func addNotification() {
        
        NotificationCenter.default.addObserver(self, selector: #selector(operatingPhone), name: NSNotification.Name(kNTF_EAGetDeviceOpsPhoneMessage), object: nil)
    }
    @objc func operatingPhone(_ no:NSNotification){
        
        let operatingModel = no.object as! EAPhoneOpsModel
        
        // see enum EAPhoneOps
        switch operatingModel.eOps {
            
        case .big8803DataUpdateFinish:
            
            print("Watch sending big data done")
            
            /**
             
             When the watch sends this notification type [.big8803DataUpdateFinish], it means that the watch big data has been sent. At this time, you can call the SDK method to obtain different types of big data [EABleSendManager.default().getBigData()].
             
             */
            
            
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
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        var cell = tableView.dequeueReusableCell(withIdentifier: ListViewController.cellId)
        if cell == nil {
            cell = UITableViewCell.init(style: .default, reuseIdentifier: ListViewController.cellId)
        }
        let info = dataSource.object(at: indexPath.section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        cell?.textLabel?.text = list.object(at: indexPath.row) as? String
        cell?.textLabel?.numberOfLines = 0
        return cell!
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        let info = dataSource.object(at: section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        return list.count
    }
    func numberOfSections(in tableView: UITableView) -> Int {
        return dataSource.count
    }
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        
        let headerView = UIView.init(frame: CGRect.init(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 0))
        return headerView
    }
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        switch indexPath.row {
        case 1: Command.getAllBigData();break
        case 2: Command.getBigData(.stepData);break
        default:break;
        }
    }
    
    
    
    func eg_sleepData(_ sleepData : NSArray){
        
        // 如何处理睡眠数据
        // 1.调用这个方法获取sleepData “ let sleepData = EABleSendManager.default().getBigData(withBigDataType: .sleepData); ”
        // 2.遍历sleepData，根据时间戳从小到大排序。获得新的 new_sleepData 数组数据。
        // 3.遍历new_sleepData，找出所有 EASleepDataModel.eSleepNode == EASleepNode.enter && EASleepDataModel.eSleepNode == EASleepNode.quit 为一次睡眠数据，此时得到 allOnceSleepData。
        // 4.遍历allOnceSleepData,统计每次睡眠的总时长，浅睡、深睡、Res等时长。
        
    
        // How to process the sleep data
        // 1. call this method to get sleepData " let sleepData = EABleSendManager.default().getBigData(withBigDataType: .sleepData); "
        // 2. Iterate through sleepData, sorting from smallest to largest based on timestamp. Get the new new_sleepData array data.
        // 3. Iterate through new_sleepData to find all EASleepDataModel.eSleepNode == EASleepNode.enter && EASleepDataModel.eSleepNode == EASleepNode.quit as once sleep data, then get allOnceSleepData.
        // 4. Iterate through allOnceSleepData, counting the total duration of each sleep, light sleep, deep sleep, Res, etc.
        
    }
    
    
    func eg_sportData() {
        
        
                // How to adapt heart rate, GPS, pace, and speed data to a sports log.
                // 1. First call the method Command.getAllBigData() and wait for the notification kNTF_EAGetDeviceOpsPhoneMessage.
                // 2. Process and save heart rate data, GPS data, pace data, speed data.
                // 3. process the motion data, match the heart rate data, GPS data, step frequency data, pace data within the motion time range [from the saved heart rate data, GPS data, step frequency data, pace data, according to the motion start time and end time].
                // 4. Save the exercise data after matching.
                
                /* eg.
                 
                 hr data :
                  {
                  hrValue = 107;
                  timeStamp = 1689066010;
                  },
                  {
                  hrValue = 99;
                  timeStamp = 1689066011;
                  },
                  {
                  hrValue = 100;
                  timeStamp = 1689066012;
                  },
                  {
                  hrValue = 108;
                  timeStamp = 1689066013;
                  },
                  {
                  hrValue = 120;
                  timeStamp = 1689066014;
                  },
                  {
                  hrValue = 111;
                  timeStamp = 1689066015;
                  },
                  
                  sport data :
                  {
                      averageAltitude = 0;
                      averageHeartRate = 127;
                      averageHeartRateMax = 150;
                      averageHeartRateMin = 107;
                      averagePace = 954;
                      averageSpeed = 377;
                      averageStepFreq = 75;
                      averageStride = 83;
                      averageTemperature = 0;
                      beginTimeStamp = 1689066011;
                      calorie = 11753;
                      count = 0;
                      distance = 9965;
                      duration = 5;
                      eType = 2;
                      endTimeStamp = 1689066014;
                      steps = 120;
                      timeStamp = 0;
                      trainingEffectAerobic = 37;
                      trainingEffectAnaerobic = 16;
                      trainingEffectFatconsumption = 11;
                      trainingEffectLimit = 0;
                      trainingEffectNormal = 0;
                      trainingEffectWarmUp = 3;
                  }
                  
                 
                 We know that the start time of the exercise is [beginTimeStamp = 1689066011] and the end time is [endTimeStamp = 1689066014].
                 Then we can get the heart rate data from 1689066011~1689066014 from the heart rate data
                 We get.
                 {
                 hrValue = 99;
                 timeStamp = 1689066011;
                 },
                 {
                 hrValue = 100;
                 timeStamp = 1689066012;
                 },
                 {
                 hrValue = 108;
                 timeStamp = 1689066013;
                 },
                 {
                 hrValue = 120;
                 timeStamp = 1689066014;
                 },
                 
                 Then this heart rate data is the heart rate data for the exercise.
                 */
        
        
        // 如何给运动记录 适配其心率数据、GPS数据、步频数据、配速数据
        // 1.首先调用方法 Command.getAllBigData()，等待 通知 kNTF_EAGetDeviceOpsPhoneMessage
        // 2.处理并保存 心率数据、GPS数据、步频数据、配速数据
        // 3.处理 运动数据，匹配运动时间范围内的 心率数据、GPS数据、步频数据、配速数据【从保存的心率数据、GPS数据、步频数据、配速数据获取，根据运动开始时间和结束时间】
        // 4.匹配完成后 保存运动数据。
        
        /* eg:
         
        hr data :
         {
         hrValue = 107;
         timeStamp = 1689066010;
         },
         {
         hrValue = 99;
         timeStamp = 1689066011;
         },
         {
         hrValue = 100;
         timeStamp = 1689066012;
         },
         {
         hrValue = 108;
         timeStamp = 1689066013;
         },
         {
         hrValue = 120;
         timeStamp = 1689066014;
         },
         {
         hrValue = 111;
         timeStamp = 1689066015;
         },
         
         sport data :
         {
             averageAltitude = 0;
             averageHeartRate = 127;
             averageHeartRateMax = 150;
             averageHeartRateMin = 107;
             averagePace = 954;
             averageSpeed = 377;
             averageStepFreq = 75;
             averageStride = 83;
             averageTemperature = 0;
             beginTimeStamp = 1689066011;
             calorie = 11753;
             count = 0;
             distance = 9965;
             duration = 95;
             eType = 2;
             endTimeStamp = 1689066014;
             steps = 120;
             timeStamp = 0;
             trainingEffectAerobic = 37;
             trainingEffectAnaerobic = 16;
             trainingEffectFatconsumption = 11;
             trainingEffectLimit = 0;
             trainingEffectNormal = 0;
             trainingEffectWarmUp = 3;
         }
         
         我们知道 运动的开始时间为 【beginTimeStamp = 1689066011】 ，结束时间为 【endTimeStamp = 1689066014】
         那么 我们就可以从心率数据里 获取 1689066011~1689066014的心率数据
         得到
         {
         hrValue = 99;
         timeStamp = 1689066011;
         },
         {
         hrValue = 100;
         timeStamp = 1689066012;
         },
         {
         hrValue = 108;
         timeStamp = 1689066013;
         },
         {
         hrValue = 120;
         timeStamp = 1689066014;
         },
         
         那么这段心率数据就是运动的心率数据了。
         */
        
        
        
        
    }

}
