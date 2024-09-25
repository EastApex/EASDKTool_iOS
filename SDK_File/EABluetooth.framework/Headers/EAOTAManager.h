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









typedef void(^CheckHisResCompleteBlock)(NSArray * _Nullable hisresFiles);
typedef void(^CheckHisResErrorBlock)(NSError * _Nullable error);
typedef void(^OTACompleteBlock)(BOOL succ, NSError * _Nullable error);

@interface EAOTAManager : NSObject

+ (instancetype)defaultManager;
- (BOOL)getOTAState;

/// OTA
/// - Parameter list: Files that need to be upgraded (multiple)【需要升级的文件(可多个)】
- (BOOL)eaUpgradeFiles:(NSArray<EAFileModel *> *)list progress:(void (^)(CGFloat progress))progress complete:(OTACompleteBlock)complete;


/// OTA Watch Face【OTA表盘】
/// - Parameter watchFaceFile: Watch Face File【表盘文件】
- (BOOL)eaUpgradeWatchFaceFile:(EAFileModel *)watchFaceFile progress:(void (^)(CGFloat progress))progress complete:(OTACompleteBlock)complete;


/// Check the HisRes.zip file【解压并获取需要OTA的文件】
/// - Parameters:
///   - hisResZipFile: HisRes.zip
///   - progress: progress【解压进度】
///   - complete: HisRes.bin file that needs to be upgraded【需要升级的HisRes.bin文件】
- (void)eaCheckHisRes:(EAFileModel *)hisResZipFile progress:(void (^)(CGFloat progress))progress complete:(CheckHisResCompleteBlock)complete fail:(CheckHisResErrorBlock)fail;



/// Decompress the Hisilicon Res file【解压海思Res文件】
/// - Parameters:
///   - hisResFilePath: Path of the hisilicon Res file【海思Res文件路径】
///   - progress: progress【进度】
- (void)eaUncompressHisResFilePath:(NSString *)hisResFilePath uncompressProgress:(void (^)(CGFloat progress))uncompressProgress complete:(void (^)(NSString *jsonPath,NSString *uncompressPath))complete uncompressRrror:(CheckHisResErrorBlock)uncompressRrror;


/// Analyze the json file to get the Hisilicon file that needs OTA【分析json文件获取需要OTA的海思文件】
/// - Parameters:
///   - jsonPath: jsonPath
///   - progress: progress
- (void)eaCheckHisJsonPath:(NSString *)jsonPath checkProgress:(void (^)(CGFloat progress))checkProgress complete:(CheckHisResCompleteBlock)complete fail:(CheckHisResErrorBlock)fail;


@end

NS_ASSUME_NONNULL_END
