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
        
        // After paired，can use the ANCS service、App push 、Muisc control
        Cmd_DeviceOps.pairWatch()
    }
    
    func addNotification(){
        
        NotificationCenter.default.addObserver(self, selector: #selector(connectSucc), name: NSNotification.Name(kNTF_EAConnectStatusSucceed), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(connectFailed), name: NSNotification.Name(kNTF_EAConnectStatusFailed), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(connectDisconnect), name: NSNotification.Name(kNTF_EAConnectStatusDisconnect), object: nil)
        
        NotificationCenter.default.addObserver(self, selector: #selector(blePoweredOn), name: NSNotification.Name(kNTF_EABlePoweredOn), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(blePoweredOff), name: NSNotification.Name(kNTF_EABlePoweredOff), object: nil)

        
    }
    
    @objc func connectSucc(){
        
        print("connectSucc")
        
        bindingWatch("")
        showView()
        
 
    }
    
    @objc func connectFailed(){
        
        print("connectFailed")
    }
    
    @objc func connectDisconnect(){
        
        print("connectDisconnect")
        if ((listCtl) != nil) {
            listCtl.dismiss(animated: true);
        }
    }
    
    @objc func blePoweredOn(){
        
        print("blePoweredOn")
    }
    @objc func blePoweredOff(){
        
        print("blePoweredOff")
        listCtl.dismiss(animated: true);
    }
    
    
    
    
    
    @IBAction func searchWatch(_ sender: Any) {
        
        EABleManager.default().scanPeripherals();

        tbView.isHidden = false


        EABleManager.default().unbindAndResetPeripheral()
          
        EABleManager.default().getPeripheralModel();
    }
    
    func showView(){
        
        alertView.dismiss(animated: true)
        
        dataSource.removeAllObjects()
        tbView.reloadData()
        tbView.isHidden = true
        ids.removeAllObjects()
        
        
        
        let listViewController = WatchViewController()
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
        
        /**
         After the watch is successfully connected
         1. Get the watch information first
         2. Determine the binding status of watch information
         3. Unbound: Determine whether the watch information supports the user binding page
            3.1 Support: Call the binding method, set bindWatch.ops = .normalBegin, let the watch display the binding page, wait User click Feedback according to user click:
                3.1.1 Binding: Call the binding method again, set bindWatch.ops = .end to complete the binding, and then the watch data interaction can be carried out.
                3.1.2 Unbound: App disconnects the watch EABleManager.default().cancelConnectingPeripheral()
            3.2 Not supported: Call the binding method, set bindWatch.ops = .end to complete the binding, and then the watch data interaction can be carried out
         4. Bound: There is no need to call the binding method, and the watch data interaction can be carried out.
         */
        
        
        EABleSendManager.default().operationGetInfo(with: EADataInfoType.watch) { baseModel in
    
            // Determine whether the watch is bound: unbound -> execute the binding process
            if (baseModel as! EAWatchModel).bindingType == .unBound {

                // Determine whether the watch supports the user to determine the binding function:
                // Support -> Set < bindWatch.ops = .normalBegin > Let the watch display the binding page
                if ((baseModel as! EAWatchModel).isWaitForBinding == 1) {
                    
                    let bindWatch = EABingingOps()
                    bindWatch.ops = .normalBegin // To start the binding, the user needs to click on the watch to confirm it
                    EABleSendManager.default().operationChange(bindWatch) { respondModel in
                        
                        // Determine whether the user clicks the binding:
                        // YES: < Set bindWatch.ops = .end > binding completed
                        if ( respondModel.eErrorCode == .success) {
                            
                            let bindWatch = EABingingOps()
                            bindWatch.ops = .end //  Set EABindingOpsType. End to complete the binding
                            EABleSendManager.default().operationChange(bindWatch) { respondModel in
                                
                                // Interactive data with the watch
                                self.loadWatchData();
                            }
                        }
                        else
                        {
                            //NO: Refuse, disconnect from the watch
                            EABleManager.default().cancelConnectingPeripheral();
                        }
                    }
                }
                else
                {
                    //Not supported -> < Set bindWatch.ops = .end > binding completed
                    let bindWatch = EABingingOps()
                    bindWatch.ops = .end //  Set EABindingOpsType. End to complete the binding
                    EABleSendManager.default().operationChange(bindWatch) { respondModel in
                        
                        // Interactive data with the watch
                        self.loadWatchData();
                    }
                }
            }else {
                
                // Bound,interactive data with the watch
                self.loadWatchData();
            }
        }
    }
    

    func setSyncTime() {
        
        let syncTimeModel = EASyncTime.getCurrent()
        EABleSendManager.default().operationChange(syncTimeModel) { respondModel in
            
        }
    }

}

