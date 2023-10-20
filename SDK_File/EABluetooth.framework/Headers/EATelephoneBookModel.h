//
//  EATelephoneBookModel.h
//  EABluetooth
//
//  Created by Aye on 2022/7/29.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// Contact data model
///【联系人数据模型】
@interface EAContactModel : EABaseModel

/// Contact name
///【名字】
@property(nonatomic, strong) NSString *name;

/// Telephone number
///【电话号码】
@property(nonatomic, strong) NSString *num;


/// Initialization method【初始化方法】
/// - Parameters:
///   - name: Contact name【名字】
///   - num: Telephone number【电话号码】
+ (instancetype)eaAllocInitWithName:(NSString *)name telephoneNumber:(NSString *)num;

@end

/// id = 42: Mobile phone directory[Transfers the contact data model to the watch]
/// id = 42: 手机通信录【向手表传输联系人数据模型】
@interface EATelephoneBookModel : EABaseModel

/// ignore
@property(nonatomic, assign) EAPhoneContactFlag eFlag;

/// The contact that needs to be passed into the watch
/// 【需要传入手表的联系人】
@property(nonatomic,strong) NSMutableArray<EAContactModel*> *sIndexArray;

@property(nonatomic, readonly) NSUInteger sIndexArray_Count;


/// Initialization method【初始化方法】
/// - Parameter list: Contact number group【联系人数组】
+ (instancetype)eaAllocInitWithList:(NSArray <EAContactModel *>*)list;

+ (instancetype)eaAllocInitReverseWithList:(NSArray <EAContactModel *>*)list;

@end



/// A model of the mobile phone number already stored in the watch
/// 【手表已存的手机号码模型】
@interface EAPhoneModel : EABaseModel

/// Telephone number
///【电话号码】
@property(nonatomic, strong) NSString *num;

@end

/// Watch has saved contact model
///【手表已保存的联系人模型】
@interface EAReadTelephoneBookModel : EABaseModel

/// Cell phone number array
///【手机号码数组】
@property(nonatomic,strong) NSMutableArray<EAPhoneModel*> *sIndexArray;

/// ignore
@property(nonatomic, readonly) NSUInteger sIndexArray_Count;



@end

NS_ASSUME_NONNULL_END
