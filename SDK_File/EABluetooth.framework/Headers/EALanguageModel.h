//
//  EALanguageModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN


/// Watch language information
/// 设备语言
@interface EALanguageModel : EABaseModel


@property(nonatomic, assign) EALanguageType language;



+ (EALanguageModel *)getModelByData:(NSData *)data;





@end

NS_ASSUME_NONNULL_END
