//
//  ControlPhoneViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2023/3/8.
//

import UIKit
import EABluetooth
class ControlPhoneViewController: UIViewController , UITableViewDelegate, UITableViewDataSource {
    
    var tableView : UITableView!
    static let cellId = "cellIdl"
    var dataSource : NSMutableArray!
    var alertView : UIAlertController!
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        view.backgroundColor = UIColor.white
        
        alertView = UIAlertController.init(title: "Alert", message: "", preferredStyle: .alert)
        alertView.addAction(UIAlertAction.init(title: "OK", style: .default,handler: { action in
                
            Cmd_DeviceOps.stopSearchPhone()
        }))
        
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
            "Please operate the watch to send related commands"
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
        /// see enum EAPhoneOps
        switch operatingModel.eOps {
            
            /// find phone
            /// note: The App needs to respond by vibrating and playing sounds or other actions.
        case .searchPhone:
            
            print("Find phone: start");
            self.present(alertView, animated: true)
            
            break
        case .stopSearchPhone:
            print("Find phone: stop");
            alertView.dismiss(animated: true)
            break
            
            
            /// take photo
            /// note:
            /// 1.App needs to take a photo function,and enable the camera and album permissions.
            /// 2.When the watch clicks to take a picture, it will send ".connectthecamera ". After the App receives this command, it needs to open the App photo page.
            /// 3.After connecting the App camera successfully, click the watch to take a picture, and you will receive ".startTakingPictures ". At this time, the App needs to realize the function of taking pictures of the camera.
            /// 4.When the watch exits the photo page, the App will receive ".stopTakingPictures ", in which case the App needs to close the photo page.
            
        case .connectTheCamera:
            print("Camera: connect app camera ");
            break
        case .startTakingPictures:
            print("Camera: take a picture ");
            break
        case .stopTakingPictures:
            print("Camera: exit ");
            break
            /// The watch requests the App to send weather data
        case .requestTheLatestWeather:
            print("Weather: request weather data ");
            break
            
            /// The watch requests the App to send AGPS data -- Only watches that support GPS location.
        case .requestTheAgps:
            print("AGPS: request AGPS data ");
            break;
            /// The watch requests the App to send menstrual data
        case .requestTheMenstrualCycle:
            print("Menstrual: request menstrual data ");
            break
            
            /// find watch
            /// note：App use this function "Cmd_DeviceOps.findWatch()",watch close search page will send this command.
        case .stopSearchWatch:
            print("Find watch: stop");
            break
            
            /// sport status
        case .appSportPause:
            print("Sport status: pause");
            break
            
           
        case .appSportContinue:
            print("Sport status: continue");
            break
            
        case .appSportEnd:
            print("Sport status: end");
            break
            
            /// DND status
        case .notDisturbOpen:
            print("DND status: open");
            break
            
        case .notDisturbClose:
            print("DND status: close");
            break
            /// gestures status
        case .gesturesOpen:
            print("wake gesture : open");
            break
            
        case .gesturesClose:
            print("wake gesture : close");
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
        
    
    }
    
}

