//
//  Command.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/14.
//

import UIKit
import EABluetooth
import YYKit
class Command: NSObject {

    class func getData(dataInfoType:EADataInfoType) {
        
//        Get the relevant data of the watch
//        Parameter description: EADataInfoType is an enumeration of data types supported by the watch.
//        Eg: EADataInfoType.watch is watch information and returns EAWatchModel data type
        
        EABleSendManager.default().operationGetInfo(with: dataInfoType) { baseModel in
            
            print(baseModel.modelToJSONObject()!);
            print(baseModel.className())
        }
    }
    
    class func setData(model:EABaseModel) {
        
        EABleSendManager.default().operationChange(model) { respondModel in
            
            if respondModel.isKind(of: EARespondModel.self) {
                
                if respondModel.eErrorCode == .success {
                    
                    print("Succ")
                }else {
                    
                    print("Fail")
                }
            }
        }
    }
    
    class public func notSupportSetData() {
        
        print("⚠️⚠️⚠️ Not support set this data")
    }
    
    class public func notSupportGetData() {
        
        print("⚠️⚠️⚠️ Not support get this data")
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
    
    class func OTA() -> Bool{
        
        /* OTA
        add Notification:
        NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
        */
        let file1 =  EAFileModel.allocInit(withPath: "", otaType: .apollo, version: "AP0.1B1.1")
        let file2 =  EAFileModel.allocInit(withPath: "", otaType: .res, version: "R0.4")
        let file3 =  EAFileModel.allocInit(withPath: "", otaType: .res, version: "R0.5")

        return EABleSendManager.default().upgradeFiles([file1,file2,file3]);
    }
    
    class func onlineWatchFace(){
        
        /**
         Add notification to view progress 添加通知 查看进度
         NotificationCenter.default.addObserver(self, selector: #selector(finishOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataFinish), object: nil)
         NotificationCenter.default.addObserver(self, selector: #selector(ingOTA), name: NSNotification.Name(kNTF_EAOTAAGPSDataing), object: nil)
         */
        
        let path:String = Bundle.main.path(forResource:"001012_U6.1", ofType:"bin")! as String
        // set watch face id
        let fileModel = EAFileModel.eaInitWatchFaceFile(withPath: path, version: "1", watchFaceId: "123456789");
        
        EABleSendManager.default().upgradeWatchFaceFile(fileModel);
        
    }
    
    class func customPictureWatchFace() -> NSInteger {
        
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
        
        
        let eaWatchModel = EABleSendManager.default().getConnectWatchModel()
        var backgroundImage : UIImage = UIImage.init();
        switch eaWatchModel.width {
        case 240:
            switch eaWatchModel.height {
            case 240:
                backgroundImage = UIImage.init(named: "picture240*240")!;
                break;
            case 280:
                backgroundImage = UIImage.init(named: "picture240*280")!;
                break;
            default:
                break;
            }
            break
//        case 368:
//            switch eaWatchModel.height {
//            case 448:
//                backgroundImage = UIImage.init(named: "picture240*240")!;
//                break;
//            default:
//                break;
//            }
//            break
        default:
            break
        }
        
 
        
        /// Type 1 => number watch face and thumbnail
//        let thumbnail = EAMakeWatchFaceManager.eaGetNumberThumbnail(with: backgroundImage, colorType: .white);
//        let result = EAMakeWatchFaceManager.eaOtaNumberWatchFace(with: backgroundImage, colorType: .white)
        
        
        
//        / Type 2 => pointer watch face and thumbnail
//        let thumbnail = EAMakeWatchFaceManager.eaGetPointerThumbnail(with: backgroundImage, colorType: .white, scaleStyle: .bar);
        let result = EAMakeWatchFaceManager.eaOtaPointerWatchFace(with: backgroundImage, colorType: .white, scaleStyle: .none)
        
        
        // Type 3 => Digital watch face with color custom picture and thumbnail
//        let thumbnail = EAMakeWatchFaceManager.eaGetDefaultNumberThumbnail(with: backgroundImage, color: .red)
//        let result = EAMakeWatchFaceManager.eaOtaDefaultNumberWatchFace(with: backgroundImage, color: UIColor.red)
        
        
//        // Type 4 => Digital watch face with fully custom picture and thumbnail
//
//        let numberModel_hh = EACustomNumberWatchFaceModel.eaAllocInit(with: .highHour, font: UIFont.systemFont(ofSize: 60), color: UIColor.blue, point: CGPoint(x: 40, y: 50))
//        let numberModel_lh = EACustomNumberWatchFaceModel.eaAllocInit(with: .lowHour, font: UIFont.systemFont(ofSize: 60), color: UIColor.blue, point: CGPoint(x: 80, y: 50))
//        let numberModel_hm = EACustomNumberWatchFaceModel.eaAllocInit(with: .highMinute, font: UIFont.systemFont(ofSize: 60), color: UIColor.blue, point: CGPoint(x: 140, y: 50))
//        let numberModel_lm = EACustomNumberWatchFaceModel.eaAllocInit(with: .lowMinute, font: UIFont.systemFont(ofSize: 60), color: UIColor.blue, point: CGPoint(x: 180, y: 50))
//        let numberModel_date = EACustomNumberWatchFaceModel.eaAllocInit(with: .date, font: UIFont.systemFont(ofSize: 60), color: UIColor.blue, point: CGPoint(x: 120, y: 150))
//        let list = NSArray(objects: numberModel_hh,numberModel_lh,numberModel_hm,numberModel_lm,numberModel_date) as! [EACustomNumberWatchFaceModel]
//        let thumbnail = EAMakeWatchFaceManager.eaGetNumberThumbnail(with: backgroundImage, list: list)
//        let result = EAMakeWatchFaceManager.eaOtaNumberWatchFace(with: backgroundImage, list: list)
        
        
        /// Type 5 =>
        ///
//        let hModel = EACustomPointerWatchFaceModel.eaInit(withPoniterImage: UIImage.init(named: "h")!, pointerType: .hour, originalPoint: CGPoint(x: 180, y: 50), rotationPoint: CGPoint(x: 180, y: 50))
//        let mModel = EACustomPointerWatchFaceModel.eaInit(withPoniterImage: UIImage.init(named: "m")!, pointerType: .minute, originalPoint: CGPoint(x: 180, y: 50), rotationPoint: CGPoint(x: 180, y: 50))
//        let sModel = EACustomPointerWatchFaceModel.eaInit(withPoniterImage: UIImage.init(named: "s")!, pointerType: .second, originalPoint: CGPoint(x: 180, y: 50), rotationPoint: CGPoint(x: 180, y: 50))
//        let list = NSArray(objects: hModel,mModel,sModel) as! [EACustomPointerWatchFaceModel]
//
//        let thumbnail = EAMakeWatchFaceManager.eaGetPointerThumbnail(with: backgroundImage, list: list)
//        let result = EAMakeWatchFaceManager.eaOtaPointerThumbnail(with: backgroundImage, list: list)
    
        
        
        
        return result;

        
    }
    
    class func customWatchFaceType1() -> NSInteger {
        
        let backgroundImage = self.getBgImage()
        
//      let thumbnail = EAMakeWatchFaceManager.eaGetNumberThumbnail(with: backgroundImage, colorType: .white);
         let result = EAMakeWatchFaceManager.eaOtaNumberWatchFace(with: backgroundImage, colorType: .white)
        return result;
    }
    
    class func customWatchFaceType2() -> NSInteger {
        
        let backgroundImage = self.getBgImage()
//        let thumbnail = EAMakeWatchFaceManager.eaGetPointerThumbnail(with: backgroundImage, colorType: .white, scaleStyle: .bar);
        let result = EAMakeWatchFaceManager.eaOtaPointerWatchFace(with: backgroundImage, colorType: .white, scaleStyle: .none)
        return result;
    }
    
    class func customWatchFaceType3() -> NSInteger {
        
        let backgroundImage = self.getBgImage()
//        let thumbnail = EAMakeWatchFaceManager.eaGetDefaultNumberThumbnail(with: backgroundImage, color: .red)
        let result = EAMakeWatchFaceManager.eaOtaDefaultNumberWatchFace(with: backgroundImage, color: UIColor.white)
        return result;
    }
    
    class func customWatchFaceType4() -> NSInteger {
        
        let backgroundImage = self.getBgImage()

        let eaWatchModel = EABleSendManager.default().getConnectWatchModel()
        let number = "4"  //  4 occupies the largest width in the number
        let colon = ":"
        let font = UIFont.boldSystemFont(ofSize: 60)
        let top = 30.0
        let space = 2.0
        let sizeToFit = number.size(for: font, size: CGSize(width: CGFLOAT_MAX, height: 1000), mode: .byWordWrapping)
        let colonSizeToFit = colon.size(for: font, size: CGSize(width: CGFLOAT_MAX, height: 1000), mode: .byWordWrapping)

        
        let colonPoint  = CGPointMake(CGFloat(eaWatchModel.width)/2.0 - sizeToFit.width/2.0, top);
        let hmPoint     = CGPointMake(CGFloat(eaWatchModel.width)/2.0 + colonSizeToFit.width/2.0, top);
        let lmPoint     = CGPointMake(hmPoint.x + sizeToFit.width + space, top);
        let lhPoint     = CGPointMake(CGFloat(eaWatchModel.width)/2.0 - sizeToFit.width - colonSizeToFit.width/2.0 - space, top);
        let hhPoint     = CGPointMake(lhPoint.x - sizeToFit.width - space, top);

        let numberModel_hh = EACustomNumberWatchFaceModel.eaAllocInit(with: .highHour, font: font, color: UIColor.blue, point: hhPoint)
        let numberModel_lh = EACustomNumberWatchFaceModel.eaAllocInit(with: .lowHour, font: font, color: UIColor.blue, point: lhPoint)
        let numberModel_hm = EACustomNumberWatchFaceModel.eaAllocInit(with: .highMinute, font: font, color: UIColor.blue, point: hmPoint)
        let numberModel_lm = EACustomNumberWatchFaceModel.eaAllocInit(with: .lowMinute, font: font, color: UIColor.blue, point: lmPoint)
        let numberModel_colon = EACustomNumberWatchFaceModel.eaAllocInit(with: .colon, font: font, color: UIColor.blue, point:colonPoint)
        let list = NSArray(objects: numberModel_hh,numberModel_lh,numberModel_hm,numberModel_lm,numberModel_colon) as! [EACustomNumberWatchFaceModel]
        
//        let thumbnail = EAMakeWatchFaceManager.eaGetNumberThumbnail(with: backgroundImage, list: list)
        let result = EAMakeWatchFaceManager.eaOtaNumberWatchFace(with: backgroundImage, list: list)
        
        return result
    }
    
    class func getBgImage() -> UIImage {
        
        let eaWatchModel = EABleSendManager.default().getConnectWatchModel()
        var backgroundImage : UIImage = UIImage.init();
        switch eaWatchModel.width {
        case 240:
            switch eaWatchModel.height {
            case 240:
                backgroundImage = UIImage.init(named: "picture240*240")!;
                break;
            case 280:
                backgroundImage = UIImage.init(named: "picture240*280")!;
                break;
            default:
                break;
            }
            break
        case 368:
            switch eaWatchModel.height {
            case 448:
                backgroundImage = UIImage.init(named: "picture368*448")!;
                break;
            default:
                break;
            }
            break
        case 466:
            switch eaWatchModel.height {
            case 466:
                backgroundImage = UIImage.init(named: "picture466*466")!;
                break;
            default:
                break;
            }
            break
        default:
            break
        }
        
        return backgroundImage
    }
    

    class func unbind(){
        
        //Disconnect from watch, restart after killing App, will not automatically connect after initializing EAsdk.
        EABleManager.default().unbindPeripheral();
    }
    class func disconnect(){
        // Disconnect from the watch, restart after killing the App, and connect automatically after initializing EAsdk.
        EABleManager.default().disconnectPeripheral();
    }
    
    class func unbindAndReset(){
        // Disconnect from the watch and reset and clear the watch data.
        EABleManager.default().unbindAndResetPeripheral();
    }
}
