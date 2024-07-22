//
//  EAStocks.h
//  EABluetooth
//
//  Created by Aye on 2024/4/3.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// Watch unit
/// MARK: - 统一单位
typedef NS_ENUM(NSUInteger,EAStockColor) {
    
    EAStockColorUpRed = 0,
    EAStockColorUpGreen = 1,
};

@interface EAStock : EABaseModel

/// 股票代码      16字节
@property(nonatomic, strong) NSString *stockId;

/// 股票名称        32字节
@property(nonatomic, strong) NSString *stockName;

/// 股票涨跌颜色类型
@property(nonatomic, assign) EAStockColor eStockColor;

/// 当前价格        16字节
@property(nonatomic, strong) NSString *stockPrice;

/// 涨跌幅（%）    8字节
@property(nonatomic, strong) NSString *stockPriceLimit;

@end

@interface EAStocks : EABaseModel

/// max 10
@property(nonatomic, strong) NSMutableArray<EAStock *> *sStockArray;

/// 更新时间
@property(nonatomic, assign) NSInteger timestemp;

@end

NS_ASSUME_NONNULL_END
