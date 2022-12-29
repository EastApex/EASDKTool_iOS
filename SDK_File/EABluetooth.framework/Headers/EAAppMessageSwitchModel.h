//
//  EAAppMessageSwitchModel.h
//  EABluetooth
//
//  Created by Aye on 2021/9/18.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@class EAAppMessageSwitchData;




@interface EAShowAppMessageModel : EABaseModel

@property(nonatomic,assign) BOOL unknow;
@property(nonatomic,assign) BOOL wechat;
@property(nonatomic,assign) BOOL qq;
@property(nonatomic,assign) BOOL facebook;
@property(nonatomic,assign) BOOL twitter;
@property(nonatomic,assign) BOOL messenger;
@property(nonatomic,assign) BOOL hangouts;
@property(nonatomic,assign) BOOL gmail;
@property(nonatomic,assign) BOOL viber;
@property(nonatomic,assign) BOOL snapchat;
@property(nonatomic,assign) BOOL whatsApp;
@property(nonatomic,assign) BOOL instagram;
@property(nonatomic,assign) BOOL linkedin;
@property(nonatomic,assign) BOOL line;
@property(nonatomic,assign) BOOL skype;
@property(nonatomic,assign) BOOL booking;
@property(nonatomic,assign) BOOL airbnb;
@property(nonatomic,assign) BOOL flipboard;
@property(nonatomic,assign) BOOL spotify;
@property(nonatomic,assign) BOOL pandora;
@property(nonatomic,assign) BOOL telegram;
@property(nonatomic,assign) BOOL dropbox;
@property(nonatomic,assign) BOOL waze;
@property(nonatomic,assign) BOOL lift;
@property(nonatomic,assign) BOOL slack;
@property(nonatomic,assign) BOOL shazam;
@property(nonatomic,assign) BOOL deliveroo;
@property(nonatomic,assign) BOOL kakaotalk;
@property(nonatomic,assign) BOOL pinterest;
@property(nonatomic,assign) BOOL tumblr;
@property(nonatomic,assign) BOOL vk;
@property(nonatomic,assign) BOOL youtube;
@property(nonatomic,assign) BOOL amazon;
@property(nonatomic,assign) BOOL discord;
@property(nonatomic,assign) BOOL github;
@property(nonatomic,assign) BOOL googleMaps;
@property(nonatomic,assign) BOOL newsBreak;
@property(nonatomic,assign) BOOL rReddit;
@property(nonatomic,assign) BOOL teams;
@property(nonatomic,assign) BOOL tiktok;
@property(nonatomic,assign) BOOL twitch;
@property(nonatomic,assign) BOOL uberEats;
@property(nonatomic,assign) BOOL doordash;
@property(nonatomic,assign) BOOL grubhub;
@property(nonatomic,assign) BOOL instacart;
@property(nonatomic,assign) BOOL postmates;
@property(nonatomic,assign) BOOL zoom;
@property(nonatomic,assign) BOOL uber;
@property(nonatomic,assign) BOOL appleEmail;

// 获取App推送蓝牙传输对象数据
- (EAAppMessageSwitchData *)getEAAppMessageSwitchData;


+ (EAShowAppMessageModel *)eaAllocInitWithAppMessageSwitchData:(EAAppMessageSwitchData *)appMessageSwitchData;

/// 一键开启或者关闭
/// - Parameter onOff: 开启或者关闭
+ (EAShowAppMessageModel *)eaAllocInitWithAllOnOff:(BOOL)onOff;


@end




@interface EAAppMessageSwitchModel : EABaseModel
/**
 unknow=0;        //类型：其他社交类型
 wechat =1;
 qq=2;
 facebook=3;
 twitter = 4;
 messenger =5;
 hangouts =6;
 gmail = 7;
 viber=8;
 snapchat=9;
 whatsApp=10;
 instagram =11;
 linkedin =12;
 line =13;
 skype =14;
 booking =15;
 airbnb =16;
 flipboard =17;
 spotify =18;
 pandora =19;
 telegram =20;
 dropbox =21;
 waze =22;
 lift =23;
 slack =24;
 shazam =25;
 deliveroo =26;
 kakaotalk =27;
 pinterest =28;
 tumblr =29;
 vk =30;
 youtube=31;
 Amazon = 33,
 Discord = 34,
 Github = 35,
 GoogleMaps = 36,
 NewsBreak = 37,
 Reddit = 38,
 Teams = 39,
 Tiktok = 40,
 Twitch = 41,
 UberEats = 42,
 Doordash = 43,
 Grubhub = 44,
 Instacart = 45,
 Postmates = 46,
 Zoom = 47,
 Uber = 48,
 AppleEmail = 49,
 */
@property(nonatomic, assign) BOOL sw;

@end


@interface EAAppMessageSwitchData : EABaseModel

@property(nonatomic,strong) NSMutableArray<EAAppMessageSwitchModel*> *sAppSwArray;


+ (EAAppMessageSwitchData *)getModelByData:(NSData *)data;

- (NSData *)getModelData ;


@end

NS_ASSUME_NONNULL_END
