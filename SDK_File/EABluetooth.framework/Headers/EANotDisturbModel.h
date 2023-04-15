//
//  EANotDisturbModel.h
//  EABluetooth
//
//  Created by Aye on 2021/3/19.
//

#import <EABluetooth/EABaseModel.h>
NS_ASSUME_NONNULL_BEGIN



/**
 目前的免打扰模式是这样的：有2种模式设置共同作用的结果
       1是 【手表免打扰】 ===》优先级高，它的任何操作都会 关闭 【App免打扰时间段】的开关。如果需要响应【App免打扰时间段】，那必须设置【App免打扰时间段】的开关为开启状态，同时关闭 手表免打扰。
       2是 【App免打扰时间段】 ===》优先级低，它的开启就是 在设置的时间段 内 免打扰

     关系：手表的免打扰状态是 由【手表免打扰】和【App免打扰时间段】 共同决定。手表的免打扰icon 是对 【手表免打扰】的开关的操作。
         例：1.假设【手表免打扰】设为 on，无论【App免打扰时间段】on 或者 off，都不会有消息提醒，这时候 手表的免打扰icon状态 是 开启状态，不会有消息提醒
            2.假设【手表免打扰】设为 off，【App免打扰时间段】on，并且在此时时间在【App免打扰时间段】设置的时间段内，手表的免打扰icon状态 是 关闭状态，不会有消息提醒
         如果这时候去点击 手表的免打扰icon，则 手表的免打扰状态 变为 关闭状态，同时 【App免打扰时间段】和 【手表免打扰】 也会变为off，会有消息提醒
            3.假设【手表免打扰】设为 off，【App免打扰时间段】off，无论此时时间是否在【App免打扰时间段】设置的时间段内，手表的免打扰icon状态 是 关闭状态，会有消息提醒。
         如果这时候去点击 手表的免打扰icon，则 手表的免打扰状态 变为 开启状态，【手表免打扰】会变为 on，【App免打扰时间段】会变为off，不会有消息提醒

       The current DND mode is this: There are 2  mode settings that work together
       1 is [Watch Do Not Disturb] ===" with high priority, any operation on it will turn off the switch of [App Do Not Disturb Time Period]. If you need to respond to the [App Do Not Disturb Time Period], you must set the [App Do Not Disturb Time Period] switch to on, and turn off the watch Do Not Disturb at the same time.
       2 is [App Do Not Disturb Time Period] === "low priority, its turn on is Do Not Disturb within the set time period

     Relationship: The Do Not Disturb status of the watch is determined by [Watch Do Not Disturb] and [App Do Not Disturb Time Period]. The Do Not Disturb icon of the watch is the operation of the switch of [Watch Do Not Disturb].
         Example: 1. Assuming that [Watch Do Not Disturb] is set to on, no matter if [App Do Not Disturb Time Period] is on or off, there will be no message reminders. At this time, the watch's Do Not Disturb icon status is on, and there will be no message reminders.
            2. Assuming that [Watch Do Not Disturb] is set to off, [App Do Not Disturb Time Period] is on, and the time is within the time period set by [App Do Not Disturb Time Period], the watch's Do Not Disturb icon state is off. There will be no message reminders
         If you click the Do Not Disturb icon of the watch at this time, the Do Not Disturb status of the watch will be turned off, and the [App Do Not Disturb Time Period] and [Watch Do Not Disturb] will also be turned off, and there will be a message reminder
            3. Assuming that [Watch Do Not Disturb] is set to off, and [App Do Not Disturb Time Period] is off, no matter whether the time is within the time period set by [App Do Not Disturb Time Period], the Do Not Disturb icon status of the watch is off. There will be a message reminder.
         If you click the Do Not Disturb icon of the watch at this time, the Do Not Disturb status of the watch will turn on, [Watch Do Not Disturb] will turn on, [App Do Not Disturb Time Period] will turn off, and there will be no message reminders
  */

/// id = 13: Do not disturb Settings
/// id = 13: 免打扰设置
@interface EANotDisturbModel : EABaseModel

/// App set DND time range switch: 0 off 1 On
/// App设置免打扰时间段开关： 0关闭 1打开
@property(nonatomic, assign) NSInteger sw;

/// begin hour
/// 开始时间 ：小时
@property(nonatomic, assign) NSInteger beginHour;

/// begin minute
/// 开始时间 ：分钟
@property(nonatomic, assign) NSInteger beginMinute;

/// end hour
/// 结束时间 ：小时
@property(nonatomic, assign) NSInteger endHour;

/// end minute
/// 结束时间 ：分钟
@property(nonatomic, assign) NSInteger endMinute;

/// 手表免打扰开关： 0关闭 1打开
/// Watch do not disturb switch: 0 off 1 On
@property(nonatomic, assign) NSInteger watchSw;




@end

NS_ASSUME_NONNULL_END
