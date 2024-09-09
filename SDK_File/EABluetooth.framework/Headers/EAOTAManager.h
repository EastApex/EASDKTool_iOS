//
//  EAOTAManager.h
//  EABluetooth
//
//  Created by Aye on 2024/8/2.
//

#import <Foundation/Foundation.h>
#import "EABleConfig.h"
#import "EAOTAModel.h"
NS_ASSUME_NONNULL_BEGIN


typedef void(^CheckHisResCompleteBlock)(BOOL succ,NSArray * _Nullable hisresFiles);
typedef void(^OTACompleteBlock)(BOOL succ, NSError * _Nullable error);

@interface EAOTAManager : NSObject


+ (instancetype)defaultManager;


/// 检查HisRes.zip文件
/// - Parameters:
///   - hisResZipFile: HisRes.zip文件
///   - progress: 解压进度
///   - complete: 需要升级的HisRes.bin文件
- (void)eaCheckHisRes:(EAFileModel *)hisResZipFile progress:(void (^)(CGFloat progress))progress complete:(CheckHisResCompleteBlock)complete;


/// OTA升级
/// - Parameter list: 需要升级的文件(可多个)
- (BOOL)eaUpgradeFiles:(NSArray<EAFileModel *> *)list progress:(void (^)(CGFloat progress))progress complete:(OTACompleteBlock)complete;


/// OTA表盘
/// - Parameter watchFaceFile: 表盘文件
- (BOOL)eaUpgradeWatchFaceFile:(EAFileModel *)watchFaceFile progress:(void (^)(CGFloat progress))progress complete:(OTACompleteBlock)complete;
@end

NS_ASSUME_NONNULL_END
