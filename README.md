### Native iOS SDK access document 【原生 iOS SDK 接入文档】
<p>https://www.showdoc.com.cn/2042713679210858/0
<p>Password:123456


### github:
https://github.com/EastApex/EASDKTool_iOS.git

### Release Notes:
<p>2023.02.08
     <br>1.Fixed the watch face bule bug;
     <br>2.Class EAMenstruals add new method and abandon method; Detail to see class 'EAMenstruals';
     <br>3.Modify setting the callback of EAReminderModel and EAHabitTrackerModel to EARespondModel. Deprecated EAReminderRespondModel and EAHabitTrackerRespondModel;
<p>2023-02-03:
    <br>1. New enumeration values:
    <br>&nbsp; &nbsp; id = 10: Language (Turkish, Czech, Indonesian, Bahasa Malaysia, German, Farsi)
    <br>&nbsp; &nbsp; id = 19: Social network Dingding, Alipay
    <br>&nbsp; &nbsp; id = 22: Reminder Replaces all and all by type
    <br>&nbsp; &nbsp; id = 34: Message push switch Dingding, Alipay
    <br>
    <br>2. Add attributes
    <br>&nbsp; &nbsp; id = 22: EAReminderOps alert type (eType);
    <br>&nbsp; &nbsp; id = 30: EACombinationModel Sleep Oxygen monitor switch (sleepBloodOxygenSw), stressSw,
    <br>&nbsp; &nbsp; id = 44: EAWatchSupportModel supports the pressure monitoring switch protocol (id = 51), real-time data switch protocol (id = 52), all write operations of alert protocols, all replace operations of alert protocols by type (id = 22), and shock mode setting protocol (id = 53) Support App startup motion protocol (screen motion) (id = 54)
    <br>
    <br>3. New protocol:
    <br>&nbsp; &nbsp; Sleep a blood oxygen monitor blood oxygen monitoring (night) EASleepBloodOxygenMonitor id = 50
    <br>&nbsp; &nbsp; Pressure Monitor EAStressMonitor id = 51
    <br>&nbsp; &nbsp; Real-time data switch EASendRealTimeDataOnOff id = 52
    <br>&nbsp; &nbsp; EAVibrateIntensity Mode id = 53
    <br>&nbsp; &nbsp; APP start watch motion (screen motion) EAAppLaunchScreenSport id = 54
    <br>
    <br>4. Change the class name
    <br>&nbsp; &nbsp; APP map sport "EAAppLaunchSport" = "EAAppLaunchMapSport" id = 46
    <br>&nbsp; &nbsp; APP map sports data EAAppSendSportDetails = and EAAppSendMapSportDetails id = 47
    <br>&nbsp; &nbsp; Dial thumbnail EAMakeWatchFaceManager = EACreatThumbnail
    <br>
    <br>5. Change the attribute name
    <br>&nbsp; &nbsp; Watch Function EAWatchSupportModel supportAppSport = supportAppMapSport
    <br>
    <br>6. Add a custom digital dial (Font, color, origin position)
    <br>&nbsp; &nbsp; Time digital model "EACustomNumberWatchFaceModel custom font, color, the origin position
    <br>&nbsp; &nbsp; Method to generate a thumbnail view EACreatThumbnail + (nsstrings *) creatNumberThumbnailWithBackgroundImage:...
    <br>&nbsp; &nbsp; Method to check the oat dial EABleSendManager - (NSInteger) creatPictureNumberThumbnailWithBackgroundImage:...
    <br>
<p>2023-01-30:
    <br>fixed ios connect camera bug
<p>2022-12-29:
    <br>1.BT one-click connection.
    <br>2. Add App sports.
    <br>3. Add real-time data
    <br>4. Newly added App Open heart rate, pressure and blood oxygen detection
    <br>5. Modify the custom dial
<p>2022-12-08:
     <br>1. Change the yymodel to yykit.
     <br>2. Add ANCS status change notification.
<p>2022-10-19:
     <br>1. Added a new periodic reminder protocol, and added a new acquisition of periodic reminders.【class EAMonitorReminder】
     <br>2. Add object query data.
     <br>3. Added quick query of paired watch SN number.【class EAFastGetSnNumberManager】
     <br>4. Fix some bugs.
<p>2022-10-13: Modify the bug that the custom watch face file cannot be listed on the App Store.
<p>2022-09-22: Adapt to new models of watches, and add methods related to custom dials.
<p>2022-09-08: Fix some bugs.
<p>2022-09-02: First release.

### 更新说明：
<p> 2023.02.08
    <br> 1.修复蓝色表盘bug;
    <br> 2.类EAMenstruals增加了新方法和放弃方法;详细信息见类'EAMenstruals';
    <br> 3.修改EAReminderModel和EAHabitTrackerModel的回调设置为EARespondModel。弃用EAReminderRespondModel和EAHabitTrackerRespondModel;
<p>2023-02-03:
    <br>1.新增枚举值：
    <br>&nbsp;&nbsp;id = 10：语言  》（土耳其文、捷克语、印度尼西亚文、马来西亚语、德语、波斯语）
    <br>&nbsp;&nbsp;id = 19：社交  》 钉钉、支付宝
    <br>&nbsp;&nbsp;id = 22：提醒  》 根据类型替换所有、替换所有 
    <br>&nbsp;&nbsp;id = 34：消息推送开关   》 钉钉、支付宝
    <br>
    <br>2.新增属性
    <br>&nbsp;&nbsp;id = 22：《EAReminderOps》 提醒类型（eType）;
    <br>&nbsp;&nbsp;id = 30：《EACombinationModel》 睡眠血氧监测开关（sleepBloodOxygenSw）、压力监测开关（stressSw）、
    <br>&nbsp;&nbsp;id = 44：《EAWatchSupportModel》 支持压力监测开关协议（id = 51）、支持实时数据开关协议（id = 52）、支持提醒协议全部写入操作、支持提醒协议根据类型全部替换操作（id = 22）、支持震动模式设置协议（id = 53）、支持App启动运动协议（投屏运动）（id = 54）
    <br>
    <br>3.新增协议：
    <br>&nbsp;&nbsp;睡眠血氧监测（夜间血氧监测）《EASleepBloodOxygenMonitor》id = 50
    <br>&nbsp;&nbsp;压力监测《EAStressMonitor》id = 51
    <br>&nbsp;&nbsp;实时数据开关《EASendRealTimeDataOnOff》id = 52
    <br>&nbsp;&nbsp;震动模式《EAVibrateIntensity》id = 53
    <br>&nbsp;&nbsp;APP启动手表运动（投屏运动）《EAAppLaunchScreenSport》id = 54
    <br>
    <br>4.修改类名
    <br>&nbsp;&nbsp;APP地图运动 《EAAppLaunchSport》 =》 《EAAppLaunchMapSport》id = 46
    <br>&nbsp;&nbsp;APP地图运动数据 《EAAppSendSportDetails》 =》 《EAAppSendMapSportDetails》id = 47
    <br>&nbsp;&nbsp;表盘缩略图   《EAMakeWatchFaceManager》 =》《EACreatThumbnail》
    <br>
    <br>5.修改属性名
    <br>&nbsp;&nbsp;手表功能《EAWatchSupportModel》  supportAppSport =》supportAppMapSport
    <br>
    <br>6.新增自定义数字表盘（字体、颜色、原点位置）
    <br>&nbsp;&nbsp;时间数字模型《EACustomNumberWatchFaceModel》自定义数字的字体、颜色、原点位置
    <br>&nbsp;&nbsp;缩略图生成方法 查看《EACreatThumbnail》+ (NSString *)creatNumberThumbnailWithBackgroundImage:.....
    <br>&nbsp;&nbsp;oat表盘方法 查看《EABleSendManager》- (NSInteger )customNumberWatchFaceBackgroundImage:.....
    <br>
  

<p>2023-01-30:
    <br>修复连接相机的bug
<p>2022-12-29:
    <br>1.BT一键连接。
    <br>2.新增App运动。
    <br>3.新增实时数据
    <br>4.新增App开启心率、压力、血氧检测
    <br>5.修改自定义表盘
<p>2022-12-08:
    <br>1.修改 yymodel为yykit。
    <br>2.新增ANCS状态变更通知。
<p>2022-10-19:
    <br>1.新增周期性提醒协议，新增获取周期性提醒。【class EAMonitorReminder】
    <br>2.新增对象查询数据。
    <br>3.新增快速查询已配对的手表SN号。【class EAFastGetSnNumberManager】
    <br>4.修复一些bug。
<p>2022-10-13:修改自定义表盘文件不能上架App Store的bug。
<p>2022-09-22:适配新型号手表，新增自定义表盘相关方法。
<p>2022-09-08:修复一些bug。
<p>2022-09-02:第一个版本。


