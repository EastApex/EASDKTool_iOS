//
//  ListViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/14.
//

import UIKit
import SnapKit
import EABluetooth
class ListViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    

    var tableView : UITableView!
    static let cellId = "cellIdl"
    var dataSource : NSMutableArray!
    
    override func viewDidLoad() {
        super.viewDidLoad()


        
        self.title = "Command";
        
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
            "id: 3 \nWatch information【手表信息】",
            "id: 4 \nUser information【用户信息】",
            "id: 5 \nSync watch time【同步时间】",
            "id: 7 \nScreen brightness【屏幕亮度】",
            "id: 8 \nScreen rest time【息屏时间】",
            "id: 9 \nWatch power information【手表电量】",
            "id:10 \nLanguage【语言】",
            "id:11 \nUnit【单位】",
            "id:12 \nOperating watch【操作手表】",
            "id:13 \nDND【免打扰】",
            "id:15 \nDaily target【日常目标】",
            "id:16 \nSleep monitoring on-off【睡眠监测开关】",
            "id:17 \nHeart rate monitoring on-off【心率监测开关】",
            "id:18 \nSedentary monitoring【久坐监测】",
            "id:20 \nWeather【天气】",
            "id:21 \nSocial alert on-off(SMS、PhoneCall、Email Etc.)【社交提醒开关】",
//            "id:22 \nAlerts【提醒】",
//            "id:26 \nHeart rate alarm threshold【手表心率报警门限】",
//            "id:27 \nCalorie on-off【卡路里开关】",
//            "id:28 \nRaise the screen switch【抬手亮屏开关】",
//            "id:30 \nBasic Device Information【设备基本信息】",
//            "id:31 \nLevel 1 menu setting【一级菜单设置】",
//            "id:33 \nwatch face 【表盘】",
//            "id:34 \nMessage push switch【消息推送开关】",
//            "id:38 \nHabit tracker【习惯追踪】",
//            "id:40 \nMotion value displayed【当前手表运动界面显示值】",
//            "id:41 \nBluetooth pairing status【蓝牙配对状态】",
//            "id:43 \nRead telephone book【Read】",
//            "id:44 \nFunctions supported【支持的功能】",
//            "id:45 \nMonitor reminder event【提醒事件监测】",
//            "id:46 \nApp map motion【App地图运动】",
//            "id:47 \nApp sends map motion data【App发送地图运动数据】",
//            "id:48 \nApp operation watch measurement【App操作手表测量】",
//            "id:50 \nSleep oxygen monitoring【睡眠血氧监测（夜间血氧监测）】",
//            "id:51 \nPressure monitoring【压力监测】",
//            "id:52 \nReal-time data switch【实时数据开关】",
//            "id:53 \nVibrate mode【震动模式】",
        ]
        let setInfo = NSMutableDictionary.init()
        setInfo.setValue("Command【指令】", forKey: "title")
        setInfo.setObject(setList, forKey: "list" as NSCopying)
        dataSource.add(setInfo)
        
//        let getBigDataList:NSArray = [
//            "Get all the big data【获取所有大数据】 => id:29",
//            "Get big data separately by type【按类型单独获取大数据】 => id:49"
//        ]
//        let getBigDataInfo = NSMutableDictionary.init()
//        getBigDataInfo.setValue("Get big data【大数据】", forKey: "title")
//        getBigDataInfo.setObject(getBigDataList, forKey: "list" as NSCopying)
//        dataSource.add(getBigDataInfo)
        
        
        
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
        
        let info = dataSource.object(at: section) as! NSMutableDictionary
        
        let headerView = UIView.init(frame: CGRect.init(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 40))
        let lable = UILabel.init()
        lable.text = info.object(forKey: "title") as? String
        lable.font = UIFont.boldSystemFont(ofSize: 16)
        headerView.addSubview(lable)
        lable.snp.makeConstraints { make in
            make.left.equalTo(headerView).offset(15)
            make.top.equalTo(headerView)
        }
        return headerView
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let info = dataSource.object(at: indexPath.section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        let text = list.object(at: indexPath.row) as? String
        
        let dataInfoTypeString = String((text?.dropFirst(3).prefix(2) ?? "3")) as String
        let dateType = NSNumber.init(string: dataInfoTypeString)
        let dataInfoType = (dateType?.uintValue)!
        
        
        command(dataInfoType: EADataInfoType(rawValue: dataInfoType) ?? .watch)
    }
    
    func command(dataInfoType:EADataInfoType) {
        
        // get
        Command.getData(dataInfoType: dataInfoType);
        
        // set
        switch dataInfoType {
        case .watch:
            Command.notSupport();break
        case .user:
            Command.setData(model: Cmd_UserInfo.getModel());break
        case .syncTime:
            Command.setData(model: Cmd_SyncTime.getModel());break
        case .blacklight:
            Command.setData(model: Cmd_Blacklight.getModel());break
        case .blacklightTimeout:
            Command.setData(model: Cmd_BlacklightTimeout.getModel());break
        case .battery:
            Command.notSupport();break
        case .language:
            Command.setData(model: Cmd_Language.getModel());break
        case .unifiedUnit:
            Command.setData(model: Cmd_Unit.getModel());break
        case .deviceOps:
            Command.setData(model: Cmd_DeviceOps.getModel());break
        case .notDisturb:
            Command.setData(model: Cmd_DND.getModel());break
        case .dailyGoal:
            Command.setData(model: Cmd_DailyGoal.getModel());break
        case .autoCheckSleep:
            Command.setData(model: Cmd_CheckSleep.getModel());break
        case .autoCheckHeartRate:
            Command.setData(model: Cmd_CheckHeartRate.getModel());break
        case .autoCheckSedentariness:
            Command.setData(model: Cmd_CheckSedentariness.getModel());break
        case .weather:
            Command.setData(model: Cmd_Weather.getModel());break
        case .socialSwitch:
            Command.setData(model: Cmd_SocialSwitch.getModel());break
        default:break

        }
        
    }
    
    
}
