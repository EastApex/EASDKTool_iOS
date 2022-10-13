//
//  BluetoothFunc.m
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//

#import "BluetoothFunc.h"
@implementation BluetoothFunc

/// 绑定操作
+ (void)bingdingWatch:(EABingingOps *)bingdingOps completion:(void (^)(BOOL succ))completion {
    
    [[EABleSendManager defaultManager] operationChangeModel:bingdingOps respond:^(EARespondModel * _Nonnull respondModel) {
       
        completion((respondModel.eErrorCode == EARespondCodeTypeSuccess));
    }];
    
  
}


/// 获取手表信息
+ (void)getWatchInfo:(void (^)(EAWatchModel *watchModel))completion {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeWatch) result:^(EABaseModel * _Nonnull baseModel) {
       
        if ([baseModel isKindOfClass:[EAWatchModel class]]) {
            
            EAWatchModel *watchModel = (EAWatchModel *)baseModel;
            completion(watchModel);
        }
    }];
}

#pragma mark - 用户信息
/// 获取用户相关信息
+ (void)getUserInfo:(void (^)(EAUserModel *userModel))completion {
    
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:EADataInfoTypeUser result:^(EABaseModel * _Nonnull baseModel) {
       
        if ([baseModel isKindOfClass:[EAUserModel class]]) {
            
            EAUserModel *userModel = (EAUserModel *)baseModel;
            completion(userModel);
        }
    }];
}

+ (void)changeUserInfo:(EAUserModel *)userModel completion:(void (^)(BOOL succ))completion{
  
    [[EABleSendManager defaultManager] operationChangeModel:userModel respond:^(EARespondModel * _Nonnull respondModel) {
        
        completion((respondModel.eErrorCode == EARespondCodeTypeSuccess));
    }];
}

#pragma mark - 同步时间
/// 获取手表的时间
+ (void)getWatchTime:(void (^)(EASyncTime *syncTime))completion {
    
    [[EABleSendManager defaultManager] operationGetInfoWithType:(EADataInfoTypeSyncTime) result:^(EABaseModel * _Nonnull baseModel) {
       
        if ([baseModel isKindOfClass:[EASyncTime class]]) {
            
            EASyncTime *syncTime = (EASyncTime *)baseModel;
            completion(syncTime);
        }
    }];
}
/// 同步手机时间到手表
+ (void)changeSyncTime:(EASyncTime *)syncTime completion:(void (^)(BOOL succ))completion {
    
    [[EABleSendManager defaultManager] operationChangeModel:syncTime respond:^(EARespondModel * _Nonnull respondModel) {
       
        completion((respondModel.eErrorCode == EARespondCodeTypeSuccess));
    }];
}


#pragma mark - 天气
/// 同步天气
+ (void)changeWeather:(EAWeatherModel *)weatherModel completion:(void (^)(BOOL succ))completion {
    
    [[EABleSendManager defaultManager] changeInfo:weatherModel respond:^(EARespondModel * _Nonnull respondModel) {
       
        completion((respondModel.eErrorCode == EARespondCodeTypeSuccess));
    }];
}

#pragma mark - 经期
/// 同步经期数据
+ (void)changeMenstrual:(EAMenstruals *)menstruals completion:(void (^)(BOOL succ))completion {
    
    [[EABleSendManager defaultManager] changeInfo:menstruals respond:^(EARespondModel * _Nonnull respondModel) {
       
        completion((respondModel.eErrorCode == EARespondCodeTypeSuccess));
    }];
}

#pragma mark - 系统表盘
/// 系统表盘
+ (void)changeWatchFaces:(EADialPlateModel *)dialPlateModel completion:(void (^)(BOOL succ))completion {
    
    [[EABleSendManager defaultManager] changeInfo:dialPlateModel respond:^(EARespondModel * _Nonnull respondModel) {
        
        completion((respondModel.eErrorCode == EARespondCodeTypeSuccess));
    }];
}




@end
