### Native iOS SDK access document 【原生 iOS SDK 接入文档】
<p>https://www.showdoc.com.cn/2042713679210858/0
<p>Password:123456


### github:
https://github.com/EastApex/EASDKTool_iOS.git

### Release Notes:
<p>2023-02-22
      <br>Version：1.0.65.1
      <br>1.Add a pointer dial.
      <br>2.Fixed some bug.
<p>2023.02.14
     <br>1.Add part of the sample
     
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


