//
//  EADataValue.h
//  EABluetooth
//
//  Created by Aye on 2021/3/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#define  eaConvertTenToHex(number) [EADataValue eaConvertTenToHex:number]
#define  eaConvertDataToHexStr(data) [EADataValue eaConvertDataToHexStr:data]
#define  eaConvertHexStrToData(string) [EADataValue eaConvertHexStrToData:string]



@interface EADataValue : NSObject



/// 16进制字符串转换具体多少个byte
/// @param hexString 16进制字符串
/// @param byteNumber 多少byte
/// @param back        加0的方式，前 or 后 back = 1 为后
+ (NSString *)eaConvertToHexByHex:(NSString *)hexString andByteNumber:(NSInteger)byteNumber  addZoreToBack:(BOOL)back ;




/// 10进制转16进制
/// @param tmpid 10进制
/// @param byteNumber 多少byte
/// @param isSmall 是否是小端 
+ (NSString *)eaConvertToHexByTen:(NSInteger)tmpid andByteNumber:(NSInteger)byteNumber small:(BOOL)isSmall ;


/// 10进制转16进制
/// @param tmpid 10进制
/// @param byteNumber 多少byte
/// @param isSmall 是否是小端
+ (NSString *)eaConvertToHexByTen:(NSInteger)tmpid andByteNumber:(NSInteger)byteNumber;


+ (NSString *)eaConvertToHexByString:(NSString *)text;


/// 10进制转16进制
/// @param tmpid 10进制
+ (NSString *)eaConvertToHexByTen:(NSInteger)tmpid;


/// 16进制转10进制
/// @param hexString 16进制
+ (NSString *)eaConvertToTenByHex:(NSString *)hexString;


/// 16进制转字符串
/// @param data 16进制
+ (NSString *)eaConvertToHexStringByData:(NSData *)data;


/// 字符串转16进制
/// @param str 字符串
+ (NSData *)eaConvertToDataByHexString:(NSString *)str;


/// 二进制转十进制
/// @param twoString 二进制字符串
+ (NSInteger )eaConvertToTenByTwo:(NSString *)twoString;


///  十进制转二进制字符串
/// @param ten 十进制
+ (NSString *)eaConvertToTwoByTen:(NSInteger )ten;


///  十进制转二进制字符串
/// @param ten 十进制
/// @param bitNumber 转化长度
+ (NSString *)eaConvertToTwoByTen:(NSInteger )ten andBitNumber:(NSInteger)bitNumber;


/// 二进制转16进制
/// @param binary 二进制字符串
+ (NSString *)eaConvertToHexStringByTwo:(NSString *)binary;


/// 16进制转二进制
/// @param HexString 16进制String
+ (NSString *)eaConvertToTwoByHexString:(NSString *)HexString;



/// 获取周期 int
/// @param bitString bitString
+ (NSInteger)getWeekCycleByWeekCycleBitString:(NSString *)bitString;

/// 获取 bitString
/// @param weekCycle int
+ (NSString *)getWeekCycleBitByWeekCycle:(NSInteger )weekCycle;


@end

NS_ASSUME_NONNULL_END
