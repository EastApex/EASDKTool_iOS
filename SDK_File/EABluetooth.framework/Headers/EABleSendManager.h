//
//  EABleSendManager.h
//  EABluetooth
//
//  Created by Aye on 2021/3/26.
//

#import <Foundation/Foundation.h>
#import <EABluetooth/EAModelHeader.h>
#import <EABluetooth/EABleManager.h>
#import <EABluetooth/EAEnum.h>
#import <EABluetooth/EABleConfig.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN


typedef void(^ResultGetInfoBlock)(EABaseModel *baseModel);
typedef void(^RespondBlock)(EARespondModel *respondModel);


@interface EABleSendManager : NSObject


/// The singleton
/// 单例
+ (instancetype)defaultManager;

/// Get data [Queue Operation]获取数据【队列操作】
- (void)operationGetInfoWithType:(EADataInfoType)dataInfoType result:(ResultGetInfoBlock )result;
/// Set data 修改数据【队列操作】
- (void)operationChangeModel:(EABaseModel *)changeModel respond:(RespondBlock )respond;
/// Get big data 获取大数据【队列操作】
- (void)operationgGetBigData:(EAGetBigDataRequestModel *)model respond:(RespondBlock )respond;

/// upgrade [OTA]
- (BOOL)upgradeFiles:(NSArray<EAFileModel *> *)list;
/// Watch face [OTA]
- (BOOL)upgradeWatchFaceFile:(EAFileModel *)watchFaceFile;
/// AGPS OTA
- (BOOL)upgrade:(EAOTA *)ota;

/// Customize the background watch face
- (NSInteger )customWatchFaceBackgroundImage:(UIImage *)backgroundImage colorType:(EATimerColorType )colorType;



/// Get big data by bigDataType 【Data will not be available until the watch sends the big data message：8803 Big data transmission completed】
/// 获取大数据（bigDataType 只支持大数据类型 3000~3999）【需要等待手表发送完成大数据消息才会有数据：8803 Big data transmission completed】
- (NSArray *)getBigDataWithBigDataType:(EADataInfoType)bigDataType;
/// Retrieve audio data [Call this method to retrieve audio data only when notification 'recording completed' is received]
/// 获取音频数据【通知收到 ‘录音完成’ 才能调用此方法获取录音数据】
- (NSData *)getAudioDataData;


/** * You are not advised to use */
/** Need to operate in a single thread: make sure that the call does not respond until the last operation is complete. Try to use the queue operation method above */
/** 以下不建议使用 */
/** 需要在单线程操作:确保上次操作完成后，调用才会响应，尽量使用上面队列操作方法 */

/// Get data 获取数据【单线程操作】
- (void)getInfoByInfoType:(EADataInfoType)dataInfoType result:(ResultGetInfoBlock )result;
/// Set data 修改数据【单线程操作】
- (void)changeInfo:(EABaseModel *)baseModel respond:(RespondBlock )respond;
/// Get big data 获取大数据【单线程操作】
- (void)getBigDataRequestModel:(EAGetBigDataRequestModel *)model respond:(RespondBlock )respond;;


/** 以下 为测试使用 */

/// 分析大数据
- (void)analyzeBigDataString:(NSString *)dataString;
/// 分析大数据
- (NSArray *)analyzeBigDataString:(NSString *)pbDataString andIdNmuber:(NSInteger )idNumber;


/// ignore：
- (void)setNilBlock;
- (void)setchannelDataNil;
- (void)setBleQueueNil;
- (void)setIsConnected:(BOOL)isConnected;
@end

NS_ASSUME_NONNULL_END
