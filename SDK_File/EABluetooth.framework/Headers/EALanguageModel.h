//
//  EALanguageModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN



@interface EALanguageItemModel : EABaseModel


@property(nonatomic, assign) EALanguageType languageName;

@end


/// id = 10 : Watch language information
/// id = 10 : 设备语言
@interface EALanguageModel : EABaseModel


@property(nonatomic, assign) EALanguageType language;

/// 支持的多语言
/// support language
@property(nonatomic, copy) NSArray<EALanguageItemModel*> *sLanguageArray;







@end

NS_ASSUME_NONNULL_END
