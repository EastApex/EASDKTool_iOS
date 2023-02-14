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
    
    class public func notSupport() {
        
        print("⚠️⚠️⚠️ Not support set this data")
    }
    
    
    
}
