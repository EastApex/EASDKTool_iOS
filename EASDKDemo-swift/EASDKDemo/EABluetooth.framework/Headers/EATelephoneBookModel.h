//
//  EATelephoneBookModel.h
//  EABluetooth
//
//  Created by Aye on 2022/7/29.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAContactModel : EABaseModel

/** 名字 */
@property(nonatomic, strong) NSString *name;

/** 号码 */
@property(nonatomic, strong) NSString *num;

@end


@interface EATelephoneBookModel : EABaseModel

/** 标志 */
@property(nonatomic, assign) EAPhoneContactFlag eFlag;

/** 通信包 */
@property(nonatomic,strong) NSMutableArray<EAContactModel*> *sIndexArray;

@property(nonatomic, readonly) NSUInteger sIndexArray_Count;

+ (EATelephoneBookModel *)getModelByData:(NSData *)data;

@end



@interface EAPhoneModel : EABaseModel
/** 号码 */
@property(nonatomic, strong) NSString *num;

@end

@interface EAReadTelephoneBookModel : EABaseModel

/** 通信包 */
@property(nonatomic,strong) NSMutableArray<EAPhoneModel*> *sIndexArray;

@property(nonatomic, readonly) NSUInteger sIndexArray_Count;

+ (EATelephoneBookModel *)getModelByData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
