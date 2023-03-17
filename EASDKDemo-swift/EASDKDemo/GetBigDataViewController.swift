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

}
