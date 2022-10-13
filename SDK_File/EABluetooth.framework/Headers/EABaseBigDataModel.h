//
//  EABaseBigDataModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/31.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface EABaseBigDataModel : EABaseModel

/** 标志 */
@property(nonatomic, assign) EAUploadRespondStatus eCommonFlag;

//@property(nonatomic, readonly) NSUInteger sIndexArray_Count;
@end

NS_ASSUME_NONNULL_END
