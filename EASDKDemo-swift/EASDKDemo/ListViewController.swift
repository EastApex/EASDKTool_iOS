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
    
    public var type:NSInteger! = 0
    var tableView : UITableView!
    static let cellId = "cellIdl"
    var dataSource : NSMutableArray!
    
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
            "id:22 \nAlerts【提醒】",
            "id:26 \nHeart rate alarm threshold【手表心率报警门限】",
            "id:27 \nCalorie on-off【卡路里开关】",
            "id:28 \nRaise the screen switch【抬手亮屏开关】",
            "id:30 \nBasic Device Information【设备基本信息】",
            "id:31 \nLevel 1 menu setting【一级菜单设置】",
            "id:32 \nMenstrual【经期】",
            "id:33 \nwatch face 【表盘】",
            "id:34 \nMessage push switch【消息推送开关】",
            "id:38 \nHabit tracker【习惯追踪】",
            "id:40 \nMotion value displayed【当前手表运动界面显示值】",
            "id:41 \nBluetooth pairing status【蓝牙配对状态】",
            "id:42 \nTelephone book【通讯录】",
            "id:43 \nRead telephone book【读取通讯录】",
            "id:44 \nFunctions supported【支持的功能】",
            "id:45 \nMonitor reminder event【提醒事件监测】",
//            "id:46 \nApp map motion【App地图运动】",
//            "id:47 \nApp sends map motion data【App发送地图运动数据】",
//            "id:48 \nApp operation watch measurement【App操作手表测量】",
//            "id:50 \nSleep oxygen monitoring【睡眠血氧监测（夜间血氧监测）】",
            "id:51 \nPressure monitoring【压力监测】",
            "id:52 \nReal-time data switch【实时数据开关】",
            "id:53 \nVibrate mode【震动模式】",
        ]
        let setInfo = NSMutableDictionary.init()
        setInfo.setValue("Command【指令】", forKey: "title")
        setInfo.setObject(setList, forKey: "list" as NSCopying)
        dataSource.add(setInfo)

        
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
        
        if indexPath.section == 0 {
            
            let text = list.object(at: indexPath.row) as? String
            
            let dataInfoTypeString = String((text?.dropFirst(3).prefix(2) ?? "3")) as String
            let dateType = NSNumber.init(string: dataInfoTypeString)
            let dataInfoType = (dateType?.uintValue)!
            
            if type==0 {
                
                getCommand(dataInfoType: EADataInfoType(rawValue: dataInfoType) ?? .watch)
                
            }else {
                
                setCommand(dataInfoType: EADataInfoType(rawValue: dataInfoType) ?? .watch)
            }
        }
    }
    
    func getCommand(dataInfoType:EADataInfoType) {
        
//        Command.getData(dataInfoType: dataInfoType);
        
        switch dataInfoType {
        case .watch: // id: 3
            Cmd_WatchInfo.getData();break
        case .user: // id: 4
            Cmd_UserInfo.getData();break
        case .syncTime:// id: 5
            Cmd_SyncTime.getData();break
        case .blacklight:// id: 7
            Cmd_Blacklight.getData();break
        case .blacklightTimeout:// id: 8
            Cmd_BlacklightTimeout.getData();break
        case .battery:// id: 9
            Cmd_Battery.getData();break
        case .language:// id: 10
            Cmd_Language.getData();break
        case .unifiedUnit:// id: 11
            Cmd_Unit.getData();break
        case .deviceOps:// id: 12
            Cmd_DeviceOps.getData();break
        case .notDisturb:// id: 13
            Cmd_DND.getData();break
        case .dailyGoal:// id: 15
            Cmd_DailyGoal.getData();break
        case .autoCheckSleep:// id: 16
            Cmd_CheckSleep.getData();break
        case .autoCheckHeartRate:// id: 17
            Cmd_CheckHeartRate.getData();break
        case .autoCheckSedentariness:// id: 19
            Cmd_CheckSedentariness.getData();break
        case .weather:// id: 20
            Cmd_Weather.getData();break
        case .socialSwitch:// id: 21
            Cmd_SocialSwitch.getData();break
        case .reminder:// id: 22
            do {
                let rCtl = RemiderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
        case .heartRateWaringSetting:// id: 26
            Cmd_HeartRateWaringSetting.getData();break
        case .caloriesSetting:// id: 27
            Cmd_CaloriesSetting.getData();break
        case .gesturesSetting:// id: 28
            Cmd_GesturesSetting.getData();break
        case .combination:// id: 30
            Cmd_Combination.getData();break
        case .homePage:// id: 31
            Cmd_HomePage.getData();break
        case .menstrual:// id: 32
            Cmd_Menstrual.getData();break
        case .dialPlate:// id: 33
            Cmd_WatchFace.getData();break
        case .appMessage:// id: 34
            Cmd_AppMessage.getData();break
        case .habitTracker:// id: 38
            Cmd_HabitTracker.getData();break
        case .sportShowData:// id: 40
            Cmd_SportShowData.getData();break
        case .blePairState:// id: 41
            Cmd_BlePairState.getData();break
        case .telephoneBook:// id: 42
            Command.notSupportGetData();break
        case .readTelephoneBook:// id: 43
            Cmd_TelephoneBook.getData();break
        case .watchSupport:// id: 44
            Cmd_WatchSupport.getData();break
        case .monitorReminder:// id: 45
            do{
                let rCtl = MonitorReminderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
//        case .appLaunchMapSport:// id: 46
//            Command.notSupportSetData();break
        case .stressMonitor:// id: 51
            Cmd_StressMonitor.getData();break
        case .sendRealTimeDataOnOff:// id: 52
            Cmd_SendRealTimeDataOnOff.getData();break
        case .vibrateIntensity:// id: 53
            Cmd_VibrateIntensity.getData();break
        default:break

        }
    }
    
    func setCommand(dataInfoType:EADataInfoType) {

        switch dataInfoType {
        case .watch: // id: 3
            Command.notSupportSetData();break
        case .user: // id: 4
            Cmd_UserInfo.setData();break
        case .syncTime:// id: 5
            Cmd_SyncTime.setData();break
        case .blacklight:// id: 7
            Cmd_Blacklight.setData();break
        case .blacklightTimeout:// id: 8
            Cmd_BlacklightTimeout.setData();break
        case .battery:// id: 9
            Command.notSupportSetData();break
        case .language:// id: 10
            Cmd_Language.setData();break
        case .unifiedUnit:// id: 11
            Cmd_Unit.setData();break
        case .deviceOps:// id: 12
            Cmd_DeviceOps.setData();break
        case .notDisturb:// id: 13
            Cmd_DND.setData();break
        case .dailyGoal:// id: 15
            Cmd_DailyGoal.setData();break
        case .autoCheckSleep:// id: 16
            Cmd_CheckSleep.setData();break
        case .autoCheckHeartRate:// id: 17
            Cmd_CheckHeartRate.setData();break
        case .autoCheckSedentariness:// id: 19
            Cmd_CheckSedentariness.setData();break
        case .weather:// id: 20
            Cmd_Weather.setData();break
        case .socialSwitch:// id: 21
            Cmd_SocialSwitch.setData();break
        case .reminder:// id: 22
            do {
                let rCtl = RemiderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
        case .heartRateWaringSetting:// id: 26
            Cmd_HeartRateWaringSetting.setData();break
        case .caloriesSetting:// id: 27
            Cmd_CaloriesSetting.setData();break
        case .gesturesSetting:// id: 28
            Cmd_GesturesSetting.setData();break
        case .combination:// id: 30
            Command.notSupportSetData();break
        case .homePage:// id: 31
            Cmd_HomePage.setData();break
        case .menstrual:// id: 32
            Cmd_Menstrual.setData();break
        case .dialPlate:// id: 33
            Cmd_WatchFace.setData();break
        case .appMessage:// id: 34
            Cmd_AppMessage.setData();break
        case .habitTracker:// id: 38
            Cmd_HabitTracker.setData();break
        case .sportShowData:// id: 40
            Command.notSupportSetData();break
        case .blePairState:// id: 41
            Command.notSupportSetData();break
        case .telephoneBook:// id: 42
            Cmd_TelephoneBook.setData();break
        case .readTelephoneBook:// id: 43
            Command.notSupportSetData();break
        case .watchSupport:// id: 44
            Command.notSupportSetData();break
        case .monitorReminder:// id: 45
            do{
                let rCtl = MonitorReminderViewController()
                self.navigationController?.pushViewController(rCtl, animated: true)
            };break
//        case .appLaunchMapSport:// id: 46
//            Command.notSupportSetData();break
        case .stressMonitor:// id: 51
            Cmd_StressMonitor.setData();break
        case .sendRealTimeDataOnOff:// id: 52
            Cmd_SendRealTimeDataOnOff.setData();break
        case .vibrateIntensity:// id: 53
            Cmd_VibrateIntensity.setData();break
        default:break

        }
        
    }
    
    
}
