//
//  Command.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/14.
//

import UIKit
import EABluetooth

class Command: NSObject {

    class func getData(dataInfoType:EADataInfoType) {
        
        EABleSendManager.default().operationGetInfo(with: dataInfoType) { baseModel in
            
            print(baseModel.modelToJSONObject()!);
        }
    }
    
    class func setData(model:EABaseModel) {
        
        EABleSendManager.default().operationChange(model) { respondModel in
            
            if respondModel.eErrorCode == .success {
                
                print("Succ")
            }else {
                
                print("Fail")
            }
        }
    }
    
    class public func notSupportSetData() {
        
        print("⚠️⚠️⚠️ Not support set this data")
    }
    
    class func getAllBigData(){
        
        /* Get big data command
         
         Wait for the watch to send the complete command before getting the big data details
         see func operatingPhone() ==> case:.big8803DataUpdateFinish
         
         */
        
        let model = EAGetBigDataRequestModel.eaInit()
        Command.setData(model: model)
    }
    
    class func getBigData(_ bigDataType:EADataInfoType){
        
        /* Get big data command
         
         Wait for the watch to send the complete command before getting the big data details
         see func operatingPhone() ==> case:.big8803DataUpdateFinish
         
         */
        
        let model = EAOnlyGetBigData.eaInit(withBigDataType: bigDataType)
        Command.setData(model: model)
    }
    
    class func OTA(){
        
        /* OTA
        add Notification:
        NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
        */
        let file1 =  EAFileModel.allocInit(withPath: "", otaType: .apollo, version: "AP0.1B1.1")
        let file2 =  EAFileModel.allocInit(withPath: "", otaType: .res, version: "R0.4")
        let file3 =  EAFileModel.allocInit(withPath: "", otaType: .res, version: "R0.5")

        EABleSendManager.default().upgradeFiles([file1,file2,file3]);
    }
    
    class func onlineWatchFace(){
        
        /**
         Add notification to view progress 添加通知 查看进度
         NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
         NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
         */
        
        let path:NSString = Bundle.main.path(forResource:"001012_U6.1", ofType:"bin")! as NSString
        let fileModel = EAFileModel.allocInit(withPath: path as String, otaType: .userWf, version: "1");
        EABleSendManager.default().upgradeWatchFaceFile(fileModel);
        
    }
    
    class func customPictureWatchFace(){
        
        /**
         Add notification to view progress 添加通知 查看进度
         NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
         NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
         */
        
        /**
         备注：
         backgroundImage 必须要 要和手表的尺寸一样。
         class EAWatchModel 有 手表尺寸
         
         Note:
         The backgroundImage must be the same size as the watch.
         The class EAWatchModel is available in watch size
         */
        
        let backgroundImage = UIImage.init(named: "picture")!;
        EABleSendManager.default().customWatchFaceBackgroundImage(backgroundImage, colorType: .white ,styleType: .pictureNumber);
        
        
        // thumbnail path
        let thumbnailPath = EACreatThumbnail.creatThumbnail(withBackgroundImage: backgroundImage, colorType: .white, styleType: .pictureNumber)
        let image = UIImage.init(contentsOfFile: thumbnailPath)
        
    }

    class func unbind(){
        
        EABleManager.default().unbindPeripheral();
    }
    
    class func unbindAndReset(){
        
        EABleManager.default().unbindAndResetPeripheral();
    }
    
    class func disconnect(){
        
        EABleManager.default().disconnectPeripheral();
    }
}
