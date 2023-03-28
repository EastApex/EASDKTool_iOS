//
//  OTAViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/16.
//

import UIKit
import EABluetooth
class OTAViewController: UIViewController  , UITableViewDelegate, UITableViewDataSource {
    
    var alertView: UIAlertController!
    var tableView : UITableView!
    static let cellId = "cellIdl"
    var dataSource : NSMutableArray!
    
    override func viewWillDisappear(_ animated: Bool) {
        
        NotificationCenter.default.removeObserver(self)
    }
    override func viewDidLoad() {
        super.viewDidLoad()

        alertView = UIAlertController.init(title: "Under upgrade", message: "Please Wait", preferredStyle: .alert)
        
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
            "OTA",
            "Online Watch Face",
            "Custom Watch Face: Type 1 = number",
            "Custom Watch Face: Type 2 = pointer",
            "Custom Watch Face: Type 3 = number & color",
            "Custom Watch Face: Type 4 = number & color",
        ]
        let setInfo = NSMutableDictionary.init()
        setInfo.setObject(setList, forKey: "list" as NSCopying)
        dataSource.add(setInfo)

        addNotification()
    }
    
    func addNotification() {
        
        NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
    }
    
    @objc func finishOTA(){
        
        
    }
    @objc func ingOTA(_ no:NSNotification){
        
        let operatingModel = no.object as! NSNumber

        if operatingModel.intValue < 0 { // failing 失败
            
            alertView.dismiss(animated: true)
            
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
            
            if (operatingModel.floatValue  >= 0.99) {
                
                alertView.dismiss(animated: true)
            }
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
        
    
        self.present(alertView, animated: true, completion: nil)
        switch indexPath.row {
        case 0: do {
            
            var aa:Bool = Command.OTA()
            if !aa {
                
                alertView.dismiss(animated: true)
            }
            
        };break
        case 1: Command.onlineWatchFace();break
        case 2: do {
            let result:NSInteger = Command.customWatchFaceType1()
            if result < 1 {
                
                alertView.dismiss(animated: true)
            }
        };break
        case 3: do {
            let result:NSInteger = Command.customWatchFaceType2()
            if result < 1 {
                
                alertView.dismiss(animated: true)
            }
        };break
        case 4: do {
            let result:NSInteger = Command.customWatchFaceType3()
            if result < 1 {
                
                alertView.dismiss(animated: true)
            }
        };break
        case 5: do {
            let result:NSInteger = Command.customWatchFaceType4()
            if result < 1 {
                
                alertView.dismiss(animated: true)
            }
        };break
        default:break;
        }
    }

}
