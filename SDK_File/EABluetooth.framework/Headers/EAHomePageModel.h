//
//  EAHomePageModel.h
//  EABluetooth
//
//  Created by Aye on 2021/5/8.
//

#import <EABluetooth/EABaseModel.h>

NS_ASSUME_NONNULL_BEGIN


@interface EAPageModel : EABaseModel

@property(nonatomic, assign) EAFirstLeverType eType;

@end

@interface EAHomePageModel : EABaseModel


@property(nonatomic, strong) NSMutableArray<EAPageModel*> *sPageArray;

@property(nonatomic, strong) NSMutableArray<EAPageModel*> *supportPageArray;


+ (EAHomePageModel *)getModelByData:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
