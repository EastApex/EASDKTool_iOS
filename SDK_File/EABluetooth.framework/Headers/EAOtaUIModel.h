//
//  EAOtaUIModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/23.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

//ota自定义表盘需求



@interface EAOtaUIModel : EABaseModel

/// 图片类型 */
@property(nonatomic, readwrite) EAUIType eType;

/// 字体编号 */
@property(nonatomic, assign) NSInteger fontId;

/// 内置编号，如果图片是手表内置，则输入1及以上的编号，0代表不内置 */
@property(nonatomic, assign) NSInteger builtInId;

/// 图片起始的位置：x坐标 */
@property(nonatomic, assign) NSInteger x;

/// 图片起始的位置：y坐标 */
@property(nonatomic, assign) NSInteger y;

/// 图片宽度，内置图片可以设置0 */
@property(nonatomic, assign) NSInteger w;

/// 图片高度，内置图片可以设置0 */
@property(nonatomic, assign) NSInteger h;

/// 图片在bin中的偏移地址 */
@property(nonatomic, assign) NSInteger offsetAddress;

/// 图片所占字节大小 */
@property(nonatomic, assign) NSInteger size;

/// 图片单元(如0~9的0)所占字节大小，没有单元则为0 */
@property(nonatomic, assign) NSInteger unitSize;

/// 图片颜色 */
@property(nonatomic, assign) NSInteger colour;

@end


@interface EAOtaUIRequest : EABaseModel

/// （大小详见对应OPTIONS文件） */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<EAOtaUIModel*> *sIndexArray;

/// The number of items in @c sIndexArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger sIndexArray_Count;

/// 当前类型ota数据的字节大小 */
@property(nonatomic, assign) NSInteger currentSize;

/// 当前类型ota数据的16bit的crc码 */
@property(nonatomic, assign) NSInteger crc;

/// 多少字节数据后等待设备数据包回应（影响ota速度: 根据手机性能调整，最高1024字节） */
@property(nonatomic, assign) NSInteger waitBytes;


@end

NS_ASSUME_NONNULL_END
