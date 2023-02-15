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


/// id = 31: 手表一级菜单设置
/// id = 31: Level 1 menu Settings
@interface EAHomePageModel : EABaseModel


/// 设置新的菜单类型
/// Set a new menu type
@property(nonatomic, strong) NSMutableArray<EAPageModel*> *sPageArray;


/// Menu types supported for setting
/// 支持设置的菜单类型
@property(nonatomic, strong) NSMutableArray<EAPageModel*> *supportPageArray;







@end

NS_ASSUME_NONNULL_END
