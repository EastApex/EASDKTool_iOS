//
//  EAEnum.h
//  EAProductDemo
//
//  Created by Aye on 2021/3/18.
//

#ifndef EAEnumh
#define EAEnumh


/// 数据类型
/// Watch data type
typedef NS_ENUM(NSUInteger, EADataInfoType) {
    
    EADataInfoTypeRespond = 1,
    EADataInfoTypeRequest = 2,
    
    /// id = 3: Watch information
    /// id = 3: 手表
    ///EAWatchModel
    EADataInfoTypeWatch = 3,
    
    /// id = 4: User information
    /// id = 4: 用户
    ///EAUserModel
    EADataInfoTypeUser = 4,
    
    /// id = 5: Sync watch time
    /// id = 5: 同步时间
    ///EASyncTime
    EADataInfoTypeSyncTime = 5,
    
    /// id = 6: Binding
    /// Swift
    /// Get value of watch to judge bindingType == .unBound need set EABingingOps().ops = .end to complete the binding
    /// if (baseModel as! EAWatchModel).bindingType == .unBound {
    ///     let bindWatch = EABingingOps()
    ///      bindWatch.ops = EABindingOpsType.end // 设置 EABindingOpsType.end 完成绑定
    ///     EABleSendManager.default().operationChange(bindWatch) { respondModel in
    ///     }
    /// }
    ///
    /// 获取手表信息，EAWatchModel.bindingType == .unBound 需要设置 EABingingOps().ops = .end 来完成绑定
    /// EABingingOps
    EADataInfoTypeBinding = 6,
    
    /// id = 7:The screen brightness of watch
    /// id = 7:屏幕亮度
    /// EABlacklightModel
    EADataInfoTypeBlacklight = 7,
    
    /// id = 8:Time when the screen automatically dies
    /// id = 8:屏幕自动灭屏时间
    /// EABlacklightTimeoutModel
    EADataInfoTypeBlacklightTimeout = 8,
    
    /// id = 9: Watch power information
    /// id = 9: 手表电量信息
    /// EABatteryModel
    EADataInfoTypeBattery = 9,
    
    /// id = 10: Watch language information
    /// id = 10: 手表语言信息
    /// EALanguageModel
    EADataInfoTypeLanguage = 10,
    
    /// id = 11: watch unit
    /// id = 11: 统一手表单位
    ///  EAUnifiedUnitModel
    EADataInfoTypeUnifiedUnit = 11,
    
    /// id = 12: Operating the watch
    /// id = 12: 操作手表
    /// EADeviceOps
    EADataInfoTypeDeviceOps = 12,
    
    /// id = 13: Do not disturb Settings
    /// id = 13: 免打扰设置
    /// EANotDisturbModel
    EADataInfoTypeNotDisturb = 13,
    
    /// ignore
    /// id = 14: Home time zone setting
    /// id = 14: 家乡时区设置
    /// EAHomeTimeZoneItem
    EADataInfoTypeHomeTimeZone = 14,
    
    /// id = 15: Daily target value setting
    /// id = 15: 日常目标值设置
    /// EADailyGoalModel
    EADataInfoTypeDailyGoal = 15,
    
    /// id = 16: Automatic sleep monitoring
    /// id = 16: 自动睡眠监测
    /// EAAutoCheckSleepModel
    EADataInfoTypeAutoCheckSleep = 16,
    
    /// id = 17: Automatic heart rate monitoring
    /// id = 17: 自动心率监测
    /// EAAutoCheckHeartRateModel
    EADataInfoTypeAutoCheckHeartRate = 17,
    
    /// id = 18: Sedentary monitoring
    /// id = 18: 久坐监测
    /// EAAutoCheckSedentarinessModel
    EADataInfoTypeAutoCheckSedentariness = 18,
    
    /// id = 20: Weather
    /// id = 20: 天气
    /// EAWeatherModel and EADayWeatherModel
    EADataInfoTypeWeather = 20,
    
    /// id = 21: Social alert switch
    /// id = 21: 社交提醒开关
    /// EASocialSwitchModel
    EADataInfoTypeSocialSwitch = 21,
    
    /// id = 22: Reminder
    /// id = 22: 提醒
    /// EAReminderOps and EAReminderModel
    EADataInfoTypeReminder = 22,
    
    /// id = 23: 提醒回应
    /// 'EAReminderRespondModel' is deprecated, please adopt EARespondModel
    EADataInfoTypeReminderRespond = 23,
    
    /// ignore
    /// id = 24: Distance uint
    /// id = 24: 距离单位
    /// EADistanceUintModel
    EADataInfoTypeDistanceUnit = 24,
    
    /// ignore
    /// id = 25: Weight unit
    /// id = 25: 重量单位
    /// EAWeightUnitModel
    EADataInfoTypeWeightUnit = 25,
    
    /// id = 26: Heart rate alarm setting
    /// id = 26: 心率报警设置
    /// EAHeartRateWaringSettingModel
    EADataInfoTypeHeartRateWaringSetting = 26,
    
    /// id = 27: Base calorie switch
    /// id = 27: 基础卡路里开关
    /// EACaloriesSettingModel
    EADataInfoTypeCaloriesSetting = 27,
    
    /// id = 28: Raise the screen switch
    /// id = 28: 抬手亮屏开关
    /// EAGesturesSettingModel
    EADataInfoTypeGesturesSetting = 28,
    
    /// id = 29: Big data acquisition command
    /// id = 29: 大数据获取命令
    /// EAGetBigDataRequestModel
    EADataInfoTypeGetBigData = 29,
    
    /// id = 30: Basic Device Information
    /// id = 30: 设备基本信息
    /// EACombinationModel
    EADataInfoTypeCombination = 30,
    
    /// id = 31: Level 1 menu setting command
    /// id = 31: 一级菜单设置命令
    /// EAHomePageModel
    EADataInfoTypeHomePage = 31,
    
    /// id = 32: Period
    /// id = 32: 经期
    /// EAMenstruals
    EADataInfoTypeMenstrual = 32,
    
    /// id = 33: The watch face command
    /// id = 33: 表盘命令
    /// EADialPlateModel
    EADataInfoTypeDialPlate = 33,
    
    /// id = 34: Message push switch
    /// id = 34: 消息推送开关
    /// EAShowAppMessageModel
    EADataInfoTypeAppMessage = 34,
    
    /// ignore
    /// id = 36: 血压校准值 （老人表）*/
    EADataInfoTypeBloodPressure = 36,
    
    /// ignore
    /// id = 37: 自动监测 心率 血氧 血压 （老人表）
    EADataInfoTypeAutoMonitor = 37,
    
    /// id = 38: Habit tracker
    /// id = 38: 习惯追踪
    /// EAHabitTrackerModel
    EADataInfoTypeHabitTracker = 38,
    
    /// Habit tracker respond
    /// 习惯追踪回应
    /// 'EAHabitTrackerRespondModel' is deprecated, please adopt EARespondModel
    EADataInfoTypeHabitTrackerRespond = 39,
    
    /// id = 40: Value displayed on the motion screen of the current watch
    /// id = 40: 当前手表运动界面显示值
    /// EASportShowDataModel
    EADataInfoTypeSportShowData = 40,
    
    /// id = 41: Gets Bluetooth pairing status
    /// id = 41: 获取蓝牙配对状态
    /// EABlePairStateModel
    EADataInfoTypeBlePairState = 41,
    
    /// id = 42: Telephone book
    /// id = 42: 通讯录
    /// EATelephoneBookModel and EAContactModel
    EADataInfoTypeTelephoneBook = 42,
    
    /// id = 43: Read telephone book
    /// id = 43: 读取通讯录
    /// EAReadTelephoneBookModel and EAPhoneModel
    EADataInfoTypeReadTelephoneBook = 43,
    
    
    /// id = 44: 手表支持的功能（备注EAWatchModel.projSettings = 1 才支持此协议）
    /// id = 44: The watch supports Settings(note: EAWatchModel.projSettings = 1 to support this agreement)
    /// EAWatchSupportModel
    EADataInfoTypeWatchSupport = 44,
    
    /// id = 45: 提醒事件监测
    /// id = 45: Monitor reminder event
    /// EAMonitorReminder
    EADataInfoTypeMonitorReminder = 45,
    
    /// id = 46: App地图运动
    /// id = 46: App launch map sport
    /// EAAppLaunchMapSport
    EADataInfoTypeAppLaunchMapSport = 46,
    
    /// id = 47: App发送地图运动数据（定时发送单位秒）
    /// id = 47: App sends map motion data (timed transmission: unit of second)
    /// EAAppSendMapSportDetails
    EADataInfoTypeAppSendMapSportDetails = 47,
    
    /// id = 48: App操作手表（开始/停止【心率、血氧、压力、呼吸】）
    /// id = 48: App operation watch (start/stop [heart rate, blood oxygen, pressure, breathing])
    /// EAAppOps
    EADataInfoTypeAppOps = 48,
    
    /// id = 49: 单独获取大数据（如步数、如心率）
    /// id = 49: Get big data separately (e.g. steps, e.g. heart rate)
    /// EAOnlyGetBigData
    EADataInfoTypeOnlyGetBigData = 49,
    
    /// id = 50 自动睡眠血氧监测（夜间血氧监测）
    /// id = 50: Automatic sleep oxygen monitoring (night oxygen monitoring)
    /// EASleepBloodOxygenMonitor
    EADataInfoTypeSleepBloodOxygenMonitor = 50,
    
    /// id = 51 自动压力监测
    /// id = 51: Automatic pressure monitoring
    /// EAStressMonitor
    EADataInfoTypeStressMonitor = 51,
    
    /// id = 52 实时数据开关
    /// id = 52: real-time data switch
    /// EASendRealTimeDataOnOff
    EADataInfoTypeSendRealTimeDataOnOff = 52,
    
    /// id = 53 震动模式
    /// id = 53: vibrate mode
    /// EAVibrateIntensity
    EADataInfoTypeVibrateIntensity = 53,
    
    /// id = 54 APP启动手表运动（投屏运动）
    /// id = 54 APP starts watch motion (screen motion)
    /// EAAppLaunchScreenSport
    EADataInfoTypeAppLaunchScreenSport = 54,
    
    /// id = 55 经期提醒
    /// id = 55 Menstrual reminder
    /// EAMenstrualReminder
    EADataInfoTypeMenstrualReminder = 55,
    
    /// id = 56 删除表盘
    /// id = 56 Remove custom (online) watch faces
    /// EAWatchFaceDelete
    EADataInfoTypeWatchFaceDelete = 56,
    
    /// id = 57 运动心率报警
    /// id = 57 Exercise heart rate warning
    /// EASportHrWarning
    EADataInfoTypeSportHrWarning = 57,
    
    /// id = 58
    /// 紧急联系人
    /// Sos
    /// EASos
    EADataInfoTypeSos = 58,
    
    /// id = 59
    /// Classic Bluetooth BT Control
    /// EAOpsBt
    EADataInfoTypeOpsBt = 59,
    
    /// id = 60
    /// User-defined reply messages
    /// EAReplayUserMessage、EAReplayUserMessageData
    EADataInfoTypeReplayUserMessage = 60,
    
    
    /// id = 61
    /// Watch Log
    /// EAWatchLog
    EADataInfoTypeWatchLog = 61,
    
    /// Operating Phone Commands
    /// 操作手机命令
    /// EAPhoneOpsModel
    EADataInfoTypePhoneOps = 2001,
    
    /// Reply messages
    EADataInfoTypeReplayMessage = 2005,
    
    /// MTU
    EADataInfoTypeMTU = 2006,
    
    /// 实时数据（具体数据需要调用大数据方法获取）
    EADataInfoTypeRealTime = 2007,
    
    /// App运动实时数据
    EADataInfoTypeAppSportRealTime = 2008,
    
    /// 上报启动手表测量结果【id = 48 测量结果）】
    EADataInfoTypeAppOpsData = 2009,
    
    
    /// Daily steps
    /// 大数据步数
    /// EAStepModel
    EADataInfoTypeStepData = 3001,
    
    /// Sleep data
    /// 大数据睡眠
    /// EASleepDataModel
    EADataInfoTypeSleepData = 3002,
    
    /// Heart rate data
    /// 大数据心率
    /// EAHeartRateModel
    EADataInfoTypeHeartRateData = 3003,
    
    /// GPS data
    /// 大数据GPS
    /// EAGPSDataModel
    EADataInfoTypeGPSData = 3004,
    
    /// Sports data
    /// 大数据多运动
    /// EASportsDataModel
    EADataInfoTypeSportsData = 3005,
    
    /// Bloodoxygen data
    /// 大数据血氧
    /// EABloodOxygenDataModel
    EADataInfoTypeBloodOxygenData = 3006,
    
    /// Stress data
    /// 大数据压力
    /// EAStressDataModel
    EADataInfoTypeStressData = 3007,
    
    /// stride frequency data
    /// 大数据步频
    /// EAStepFreqDataModel
    EADataInfoTypeStepFreqData = 3008,
    
    /// speed data
    /// 大数据配速
    /// EAStepPaceDataModel
    EADataInfoTypeStepPaceData = 3009,
    
    /// Resting heart rate data
    /// 大数据静息心率
    /// EARestingHeartRateModel
    EADataInfoTypeRestingHeartRateData = 3010,
    
    /// Habit tracker data
    /// 习惯数据
    /// EAHabitTrackerDataModel
    EADataInfoTypeHabitTrackerData = 3011,
    
    /// 睡眠得分数据
    /// Sleep score data
    /// EASleepScoreData
    EADataInfoTypeSleepScoreData = 3012,
    
    
    /// 多运动心率数据
    /// Sport heart rate data
    /// EASportHrData
    EADataInfoTypeSportHrData = 3013,

    
    /// OTA命令
    EADataInfoTypeOTARequest = 9001,
    
    /// OTA命令回应
    EADataInfoTypeOTARespond = 9000,
};

/// MARK: -  通道类型类型
typedef NS_ENUM(NSUInteger, EACharacteristicType) {
    
    /// 小数据通道，上位机*/
    EACharacteristicTypeSmall = 0, // 8801
    
    /// 小数据通道，固件*/
    EACharacteristicTypeSmall2,  // 8802
    
    /// 大数据通道
    EACharacteristicTypeBig,  // 8803
    
    /// OTA通道
    EACharacteristicTypeOTAMessage, // 9901
    
    /// OTA通道
    EACharacteristicTypeOTAData, // 9902
    
};


/// Watch connection status
/// MARK: - 手表连接状态
typedef NS_ENUM(NSUInteger,EAConnectStateType) {
    
    /// disconnect
    /// 断开连接
    EAConnectStateTypeUnconnected = 0,
    
    /// The connected
    /// 已连接
    EAConnectStateTypeConnected = 1,
    
    /// In the connection
    /// 连接中
    EAConnectStateTypeConnecting = 2,
};


/// Respond type
/// MARK: -  回应类型
typedef NS_ENUM(NSUInteger, EARespondCodeType) {
    
    /// Success
    /// 成功
    EARespondCodeTypeSuccess = 0,
    
    /// Fail
    /// 失败
    EARespondCodeTypeFail = 1,
    
    /// App发起运动回应状态（id=46）:手表正在运动，请结束后再开始
    /// App launch motion response status (id=46) : Watch is moving, please open it after the end
    EARespondCodeTypeWatchInMotion = 2,

    /// App发起运动回应状态（id=47）:APP运动已经结束
    /// App launch campaign response status (id=47) :APP campaign has ended.
    EARespondCodeTypeWatchEndMotion = 3,
    
    
    /// 经典蓝牙BT控制失败原因(id=59): 设备进入了勿扰模式
    /// Classic Bluetooth BT Control Failure Reason (id=59): Device is in Do Not Disturb Mode
    EARespondCodeTypeBtOnFailNotDisturb = 4,

    /// 经典蓝牙BT控制失败原因(id=59): 设备低电量
    /// Classic Bluetooth BT Control Failure Reason (id=59):Low Battery
    EARespondCodeTypeBtOnFailLowPower = 5,

    /// 经典蓝牙BT控制失败原因(id=59): 设备正在充电
    /// Classic Bluetooth BT Control Failure Reason (id=59):Charging.
    EARespondCodeTypeBtOnFailCharging = 6,
    
    /// The maximum number supported is exceeded
    /// 超过支持的最大数量
    EARespondCodeTypeMemFull = 902,
    
    /// Time to repeat
    /// 时间重复
    EARespondCodeTypeTimeConflict = 903,
    
    /// 超时
    /// Time Out
    EARespondCodeTypeTimeOut = 997,
    
    /// 不允许读取
    /// Not to read
    EARespondCodeTypeNotToRead = 998,
    
    
    /// 不允许写入
    ///Not to wirte
    EARespondCodeTypeNotToWirte = 999,
    
};

/// Binding type
/// MARK: -  绑定类型
typedef NS_ENUM(NSUInteger, EABindingType) {
    
    /// Bound
    /// 已绑定
    EABindingTypeBound = 0,
    
    /// UnBound
    /// 未绑定
    EABindingTypeUnBound,
};


/// Sex
/// MARK: -  性别类型
typedef NS_ENUM(NSUInteger, EASexType) {
    
    /// Male
    /// 男士
    EASexTypeMale = 0,
    
    /// Female
    /// 女士
    EASexTypeFemale,
};

/// MARK: -  穿戴方式
typedef NS_ENUM(NSUInteger, EAWearWayType) {
    
    /// Left hand
    /// 左手戴
    EAWearWayTypeLeftHand = 0,
    
    /// Right hand
    /// 右手戴
    EAWearWayTypeRightHand,
};

/// Color of skin
/// MARK: -  肤色
typedef NS_ENUM(NSUInteger, EASkinColorType) {
    
    /// White color of skin
    /// 白
    EASkinColorTypeWhite = 0,
    
    /// White-yellow color of skin
    /// 白偏黄
    EASkinColorTypeWhiteYellow = 1,
    
    /// Yellow color of skin
    /// 黄
    EASkinColorTypeYellow = 2,
    
    /// Yellow-black color of skin
    /// 黄偏黑
    EASkinColorTypeYellowBlack = 3,
    
    /// Black color of skin
    /// 黑
    EASkinColorTypeBalck = 4,
};

/// Time formats
/// MARK: -  时间制式
typedef NS_ENUM(NSUInteger, EATimeHourType) {
    
    /// 12-hour
    /// 12小时制
    EATimeHourTypeHour12 = 0,
    
    /// 24-hour
    /// 24小时制
    EATimeHourTypeHour24,
};

/// Time zone
/// MARK: -  时区
typedef NS_ENUM(NSUInteger, EATimeZone) {
    
    /// Time zone 0,
    /// 0时区
    EATimeZoneZero = 0,
    
    /// East Time zone,
    /// 东时区
    EATimeZoneEast,
    
    /// West time zone
    /// 西时区
    EATimeZoneWest,
};

/// MARK: - 同步模式
typedef NS_ENUM(NSUInteger, EASyncType) {
    
    /// 正常
    EASyncTypeNormal = 0,
    /// 同步至机芯
    EASyncTypeWatch,
};

/// MARK: - 绑定操作
typedef NS_ENUM(NSUInteger,EABindingOpsType) {
    
    /// Normal binding starts
    /// 正常绑定开始
    EABindingOpsTypeNormalBegin = 0,
    
    /// Start of two-dimensional code binding
    /// 二维码绑定开始
    EABindingOpsTypeQrCodeBegin = 1,
    
    /// End of the binding
    /// 绑定结束
    EABindingOpsTypeEnd = 2,
    
    /// Time out of the binding
    /// 绑定超时
    EABindingOpsTypeTimeOut = 3,
};


/// Battery status
/// MARK: - 电池状态
typedef NS_ENUM(NSUInteger,EABatteryStatus) {
    
    /// Normal
    /// 正常
    EABatteryStatusNormal = 0,
    
    /// In the charging
    /// 充电中
    EABatteryStatusInCharging = 1,
};


/// Language type
/// MARK: - 语言类型
typedef NS_ENUM(NSUInteger,EALanguageType) {
    
    /// Default English
    /// 默认
    EALanguageTypeDefault = 0,
    
    /// English
    /// 英文
    EALanguageTypeEnglish = 1,
    
    /// Chinese simplifid
    /// 中文简体
    EALanguageTypeChineseSimplifid = 2,
    
    /// Chinese traditional
    /// 中文繁体
    EALanguageTypeChineseTraditional = 3,
    
    /// Korean
    /// 韩文
    EALanguageTypeKorean = 4,
    
    /// Thai
    /// 泰文
    EALanguageTypeThai = 5,
    
    /// Japanese
    /// 日文
    EALanguageTypeJapanese = 6,
    
    /// Spanish
    /// 西班牙文
    EALanguageTypeSpanish = 7,
    
    /// Francais
    /// 法文
    EALanguageTypeFrancais = 8,
    
    /// Deutsch
    /// 德文
    EALanguageTypeDeutsch = 9,
    
    /// Italiano
    /// 意大利文
    EALanguageTypeItaliano = 10,
    
    /// Polski
    /// 波兰文
    EALanguageTypePolski = 11,
    
    /// Portuguese
    /// 葡萄牙文
    EALanguageTypePortuguese = 12,
    
    /// Russian
    /// 俄文
    EALanguageTypeRussian = 13,
    
    /// Dutch
    /// 荷兰文
    EALanguageTypeDutch = 14,
    
    /// Arabic
    /// 阿拉伯文
    EALanguageTypeArabic = 15,
    
    /// Greek
    /// 希腊文
    EALanguageTypeGreek = 16,
    
    /// Hebrew
    /// 希伯来文
    EALanguageTypeHebrew = 17,
    
    /// Swedish
    /// 瑞典文
    EALanguageTypeSwedish = 18,
    
    ///  土耳其文
    ///  Osmanli
    EALanguageTypeOsmanli = 19,

    ///  捷克语
    ///  Czech
    EALanguageTypeCzech = 20,

    ///  印度尼西亚文
    EALanguageTypeIndonesia = 21,

    ///  马来西亚语
    ///  Indonesia
    EALanguageTypeMelayu = 22,

    ///  波斯语
    ///  Farsi
    EALanguageTypeFarsi = 23,
    
    ///越南语
    ///Vietnamese
    EALanguageTypeVietnamese = 24,

    ///白俄罗斯语
    ///Belarusian
    EALanguageTypeBelarusian = 25,

    ///匈牙利语
    ///Hungarian
    EALanguageTypeHungarian = 26,
    
    /// 印地语
    /// Hindi
    EALanguageTypeHindi = 27,
};


/// Watch unit
/// MARK: - 统一单位
typedef NS_ENUM(NSUInteger,EAUnifiedUnit) {
    
    /// Metric
    /// 公制
    EALengthUnitMetric = 0,
    
    /// British
    /// 英制
    EALengthUnitBritish = 1,
};

/// Operating Device Type
/// MARK: - 操作手表类型
typedef NS_ENUM(NSUInteger,EADeviceOpsType) {
    
    /// factory data reset
    /// 恢复出厂设置
    EADeviceOpsTypeRestoreFactory = 0,
    
    /// Restart the watch
    /// 重启手表
    EADeviceOpsTypeReset = 1,
    
    /// Watch to turn it off
    /// 手表关机
    EADeviceOpsTypePowerOff = 2,
    
    /// Disconnect the bluetooth
    /// 断开蓝牙
    EADeviceOpsTypeDisconnectBle = 3,
    
    /// Go into flight mode
    /// 进入飞行模式
    EADeviceOpsTypeEnteringFlightMode = 4,
    
    /// Light up the screen
    /// 点亮屏幕
    EADeviceOpsTypeLightUpTheScreen = 5,
    
    /// Put out the screen
    /// 熄灭屏幕
    EADeviceOpsTypeTurnOffTheScreen = 6,
    
    /// Stop Looking for your phone
    /// 停止寻找手机(上位机需求)
    EADeviceOpsTypeStopSearchPhone = 7,
    
    /// 工厂模式专用进入工厂测试模式
    EADeviceOpsTypeEnterFactoryTestMode = 8,

    /// 工厂模式专用退出工厂测试模式
    EADeviceOpsTypeExitFactoryTestMode = 9,
    
    /// Looking for a watch
    /// 寻找手表
    EADeviceOpsTypeStartSearchWatch = 10,
    
    /// Stop Looking for a Watch
    /// 停止寻找手表
    EADeviceOpsTypeStopSearchWatch = 11,
    
    /// Exit the photo
    /// 退出拍照
    EADeviceOpsTypeStopCamera = 12,
    
    /// Enable Watch operation The pairing box is displayed on the IOS phone
    /// 使能手表操作IOS手机弹出配对框
    EADeviceOpsTypeShowiPhonePairingAlert = 13,
    
    /// 关闭bt信息回复功能
    /// Disable the bt message reply function
    EADeviceOpsTypeBtMsgOff = 14,

    /// 打开bt信息回复功能
    /// open the bt message reply function
    EADeviceOpsTypeBtMsgOn = 15,
};


/// Watch operating state
/// MARK: - 手表操作状态
typedef NS_ENUM(NSUInteger,EADeviceOpsStatus) {
    
    /// Execute
    /// 执行
    EADeviceOpsStatusExecute = 0,
    
    /// Execute successfully
    /// 执行成功
    EADeviceOpsStatusSuccess = 1,
    
    /// On failure
    /// 执行失败
    EADeviceOpsStatusFail = 2,
};


/// Temperature of the unit
/// MARK: - 温度单位
typedef NS_ENUM(NSUInteger,EAWeatherUnit) {
    
    /// Centigrade
    /// 摄氏度
    EAWeatherUnitCentigrade = 0,
    
    /// Fahrenheit
    /// 华氏度
    EAWeatherUnitFahrenheit = 1,
};

/// The weather types
/// MARK: - 天气类型
typedef NS_ENUM(NSUInteger,EAWeatherType) {
    
    /// Clear
    /// 晴 （100 102 150）
    EAWeatherTypeClear = 0,
    
    /// Cloudy
    /// 多云（101 103 153 502~515）
    EAWeatherTypeCloudy = 1,
    
    /// Gloomy
    /// 阴（104 154 500 501 999）
    EAWeatherTypeGloomy = 2,
    
    /// A shower or Drizzle
    /// 阵雨（小雨）（300 305 309 350）
    EAWeatherTypeDrizzle = 3,
    
    /// Strong rain shower or Moderate rain
    /// 强阵雨（301 306 314 399 351）
    EAWeatherTypeModerateRain = 4,
    
    /// Thunder shower or Thunderstorm
    /// 雷阵雨（302 303 304）
    EAWeatherTypeThunderstorm = 5,
    
    /// Heavy rain
    /// 大雨（307 308 310 311 312 315 316 317 318）
    EAWeatherTypeHeavyRain = 6,
    
    /// Sleet or Freezing rain
    /// 冻雨（雨夹雪）（313 404 405 406 456）
    EAWeatherTypeSleet = 7,
    
    /// Light snow
    /// 小雪（400 407 457）
    EAWeatherTypeLightSnow = 8,
    
    /// Moderate snow
    /// 中雪（401 408 499）
    EAWeatherTypeModerateSnow = 9,
    
    /// Heavy snow
    /// 大雪（402 403 409 410）
    EAWeatherTypeHeavySnow = 10,
    
    /// 台风
    /// Typhoon
    EAWeatherTypeTyphoon = 11,

    /// 灰尘
    /// Dust
    EAWeatherTypeDust = 12,

    /// 沙尘暴
    /// Sandstorm
    EAWeatherTypeSandstorm = 13,
    
    /// 雾
    EAWeatherTypeFog = 14,

    /// 霾
    EAWeatherTypeHaze = 15,
};

/// Air quality types
/// MARK: - 空气质量类型
typedef NS_ENUM(NSUInteger,EAWeatherAirType) {
    
    /// Excellent
    /// 优
    EAWeatherAirTypeExcellent = 0,
    
    /// Good
    /// 良
    EAWeatherAirTypeGood = 1,
    
    /// Bad
    /// 差
    EAWeatherAirTypeBad = 2,
};

/// Ultraviolet light intensity
/// MARK: - 紫外线强度
typedef NS_ENUM(NSUInteger,EAWeatherRaysType) {
    
    /// Weak
    /// 弱
    EAWeatherRaysTypeWeak = 0,
    
    /// Medium
    /// 中等
    EAWeatherRaysTypeMedium = 1,
    
    /// Strong
    /// 强
    EAWeatherRaysTypeStrong = 2,
    
    /// Very strong
    /// 很强
    EAWeatherRaysTypeVeryStrong = 3,
    
    /// Super strong
    /// 超级强
    EAWeatherRaysTypeSuperStrong = 4,
};

/// The moon type
/// MARK: - 月相类型
typedef NS_ENUM(NSUInteger,EAWeatherMoonType) {
    
    /// The new moon
    /// 新月
    EAWeatherMoonTypeNewMoon = 0,
    
    /// crescent moon
    /// 峨眉月
    EAWeatherMoonTypeWaxingCrescentMoon = 1,
    
    /// Quarter moon
    /// 上弦月
    EAWeatherMoonTypeQuarterMoon = 2,
    
    /// Half moon 1
    /// 盈半月
    EAWeatherMoonTypeHalfMoon1 = 3,
    
    /// Waxing gibbous moon
    /// 盈凸月
    EAWeatherMoonTypeWaxingGibbousMoon = 4,
    
    /// full moon
    /// 满月
    EAWeatherMoonTypeFullMoon = 5,
    
    /// Waning gibbous moon
    /// 亏凸月
    EAWeatherMoonTypeWaningGibbousMoon = 6,
    
    /// Half moon 2
    /// 亏半月
    EAWeatherMoonTypeHalfMoon2 = 7,
    
    /// Quarter moon
    /// 下弦月
    EAWeatherMoonTypeLastQuarterMoon = 8,
    
    /// Crescent moon
    /// 残月
    EAWeatherMoonTypeWaningCrescentMoon = 9,
};

/// Remind the way of vibration
/// MARK: - 提醒方式
typedef NS_ENUM(NSUInteger,EARemindActionType) {
    
    /// No action
    /// 不动作
    EARemindActionTypeNoAction = 0,
    
    /// Single long shock
    /// 单次长震
    EARemindActionTypeOneLongVibration = 1,
    
    /// A single short
    /// 单次短震
    EARemindActionTypeOneShortVibration = 2,
    
    /// Two long shock
    /// 两次长震
    EARemindActionTypeTwoLongVibration = 3,
    
    /// Two short shock
    /// 两次短震
    EARemindActionTypeTwoShortVibration = 4,
    
    /// Has been long shock
    /// 一直长震
    EARemindActionTypeLongVibration = 5,
    
    /// Long and short earthquake
    /// 一直长短震
    EARemindActionTypeLongShortVibration = 6,
    
    /// A single ring 【The watch does not support the speaker】
    /// 单次响铃
    EARemindActionTypeOneRing = 7,
    
    /// Ring the bell twice Ring the bell twice 【The watch does not support the speaker】
    /// 两次响铃
    EARemindActionTypeTwoRing = 8,
    
    /// Ring the bell 【The watch does not support the speaker】
    /// 一直响铃
    EARemindActionTypeRing = 9,
    
    /// A shock + a bell 【The watch does not support the speaker】
    /// 一次震动+响铃
    EARemindActionTypeOneVibrationRing = 10,
    
    /// Always vibrate + ring the bell  【The watch does not support the speaker】
    /// 一直震动+响铃
    EARemindActionTypeVibrationRing = 11,
};


/// Reminder Event Type
/// MARK: - 提醒事件类型
typedef NS_ENUM(NSUInteger,EAReminderEventType) {
    
    /// The alarm clock
    /// 闹钟
    EAReminderEventTypeAlarm = 0,
    
    /// Sleep 【Go to bed】
    /// 睡觉
    EAReminderEventTypeSleep = 1,
    
    /// Sport
    /// 运动
    EAReminderEventTypeSport = 2,
    
    /// Drink water
    /// 喝水
    EAReminderEventTypeDrink = 3,
    
    /// Take the medicine
    /// 吃药
    EAReminderEventTypeMedicine = 4,
    
    /// Meeting
    /// 会议
    EAReminderEventTypeMeeting = 5,
    
    /// User Customization
    /// 用户自定义
    EAReminderEventTypeUser = 6,
};


/// Reminder event operations
/// MARK: - 提醒事件操作
typedef NS_ENUM(NSUInteger,EAReminderEventOps) {
    
    /// add
    /// 操作新增
    EAReminderEventOpsAdd = 0,
    
    ///edit
    /// 操作编辑
    EAReminderEventOpsEdit = 1,
    
    /// delete this
    /// 操作删除此条
    EAReminderEventOpsDel = 2,
    
    /// delete all remind 【Except for the alarm clock】
    /// 操作删除全部提醒
    EAReminderEventOpsDelRemind = 3,
    
    /// delete all alarm
    /// 操作删除全部闹钟
    EAReminderEventOpsDelAlarm = 4,
    
    /// delete all alarm clock & remind
    ///  操作删除全部闹钟及提醒
    EAReminderEventOpsDelRemindAlarm = 5,
    
    /// 操作根据类型替换所有(需要id=44reminder_all_in_and_replace_type_setting为1才支持)
    /// replace all with type(This parameter is supported only when id=44: reminder_all_in_and_replace_type_setting is 1)
    EAReminderEventOpsReplaceType = 6,

    /// 操作替换所有(需要id=44reminder_all_in_and_replace_type_setting为1才支持)
    /// replace all(This parameter is supported only when id=44: reminder_all_in_and_replace_type_setting is 1)
    EAReminderEventOpsAllIn = 7,
};



/// Reminder respond type
/// MARK: -  提醒回应类型
typedef NS_ENUM(NSUInteger, EAReminderRespondCodeType) {
    
    /// Success
    /// 成功
    EAReminderRespondCodeTypeSuccess = 0,
    
    /// Fail
    /// 失败
    EAReminderRespondCodeTypeFail,
    
    /// The maximum number supported is exceeded
    /// 超过支持的最大数量
    EAReminderRespondCodeTypeMemFull,
    
    /// Time to repeat
    /// 时间重复
    EAReminderRespondCodeTypeTimeConflict,
};


/// The unit distance
/// MARK: - 距离单位类型
typedef NS_ENUM(NSUInteger,EADistanceUnit) {
    
    /// Kilometre
    /// 公里
    EADistanceUnitKilometre = 0,
    
    /// Mile
    /// 英里
    EADistanceUnitMile = 1,
};

/// The unit weight
/// MARK: - 体重单位类型
typedef NS_ENUM(NSUInteger,EAWeightUnit) {
    
    /// Kilogram
    /// 千克
    EAWeightUnitKilogram = 0,
    
    /// Pound
    /// 英镑
    EAWeightUnitPound = 1,
};

/// Watch operating type of mobile phone
/// MARK: - 操作手机类型
typedef NS_ENUM(NSUInteger,EAPhoneOps) {
    
    /// Looking for mobile phone
    /// 寻找手机
    EAPhoneOpsSearchPhone = 0,
    
    /// Stop Looking for your phone
    /// 停止寻找手机(固件需求)
    EAPhoneOpsStopSearchPhone = 1,
    
    /// Open the App camera
    /// 连接相机
    EAPhoneOpsConnectTheCamera = 2,
    
    /// Taking pictures
    /// 开启拍照
    EAPhoneOpsStartTakingPictures = 3,
    
    /// Stop taking pictures
    /// 停止拍照
    EAPhoneOpsStopTakingPictures = 4,
    
    /// Request the latest weather data
    /// 请求最新天气信息
    EAPhoneOpsRequestTheLatestWeather = 5,
    
    /// Request the latest AGPS data
    /// 请求最新agps星历数据
    EAPhoneOpsRequestTheAgps = 6,
    
    /// Request the latest period data
    /// 请求最新经期数据
    EAPhoneOpsRequestTheMenstrualCycle = 7,
    
    /// 8803 Big data transmission completed
    /// 8803大数据传输完成
    EAPhoneOpsBig8803DataUpdateFinish = 8,
    
    /// Recording Preparation
    /// mic录音准备
    EAPhoneOpsMicRecordReady = 9,
    
    /// Recording stop
    /// mic录音结束 lin
    EAPhoneOpsMicRecordStop = 10,
    
    /// Stop Looking for a Watch
    /// 停止寻找手表(固件需求)
    EAPhoneOpsStopSearchWatch = 11,
    
    /// 手表发起暂停app运动
    /// Watch launches pause app campaign
    EAPhoneOpsAppSportPause = 13,

    /// 手表发起继续app运动
    /// Watch launches continue app campaign
    EAPhoneOpsAppSportContinue = 14,

    /// 手表发起结束app运动
    /// Watch launches end app campaign
    EAPhoneOpsAppSportEnd = 15,
    
    ///  接听来电(android)
    EAPhoneOpsIncomingCallAccept = 16,

    ///  拒接来电(android)
    EAPhoneOpsIncomingCallReject = 17,

    ///  Do not disturb open
    EAPhoneOpsNotDisturbOpen = 18,

    ///  Do not disturb close
    EAPhoneOpsNotDisturbClose = 19,

    ///  抬手亮屏打开
    ///  Lift your hand to light up the screen and turn it on
    EAPhoneOpsGesturesOpen = 20,

    ///  抬手亮屏关闭
    ///  Lift your hand to light up the screen and turn it off
    EAPhoneOpsGesturesClose = 21,
    
    /// 经典蓝牙BT打开
    /// Classic Bluetooth BT Open
    EAPhoneOpsBtOn = 22,

    ///  经典蓝牙BT关闭
    ///  Classic Bluetooth BT Close
    EAPhoneOpsBtOff = 23,
    
    /// 经典蓝牙BT打开(已连接)
    /// Classic Bluetooth BT connected
    EAPhoneOpsBtConnected = 24,
};

/// Operating mobile phone status
/// MARK: - 操作手机状态
typedef NS_ENUM(NSUInteger,EAPhoneOpsStatus) {
    
    /// Execute
    /// 执行
    EAPhoneOpsStatusExecute = 0,
    
    /// Success
    /// 执行成功
    EAPhoneOpsStatusSuccess = 1,
    
    /// Fail
    /// 执行失败
    EAPhoneOpsStatusFail = 2,
};


/// MARK: - 上传状态
typedef NS_ENUM(NSUInteger,EAUploadRespondStatus) {
    
    /// 起始包
    EAUploadRespondStatusBegin = 0,
    
    /// 中间包
    EAUploadRespondStatusContinue = 1,
    
    /// 结束包
    EAUploadRespondStatusEnd = 2,
    
    /// 开始即结束包
    EAUploadRespondStatusBeginEnd = 3,
};


/// sleep status
/// MARK: - 睡眠状态
typedef NS_ENUM(NSUInteger,EASleepNode) {
    
    /// Activity
    /// 活动状态
    EASleepNodeActivity = 0,
    
    /// Enter sleep
    /// 进入睡眠 (!!!),同时 代表进入浅睡状态
    EASleepNodeEnter = 1,
    
    /// Wake
    /// 睡眠中途醒来
    EASleepNodeWake = 2,
    
    /// Rem
    /// 快速眼动
    EASleepNodeRem = 3,
    
    /// Light sleep
    /// 浅睡
    EASleepNodeLight = 4,
    
    /// Deep sleep
    /// 深睡
    EASleepNodeDeep = 5,
    
    /// Quit sleep
    /// 退出睡眠(!!!)
    EASleepNodeQuit = 6,
    
    /// Unknown
    /// 未知
    EASleepNodeUnknown = 7,
    
    /// Summary
    /// 睡眠摘要
    EASleepNodeSummary = 8,
};

/// Sport type
/// MARK: - 运动类型
typedef NS_ENUM(NSUInteger,EASportType) {
    
    /// Daily
    /// 日常运动
    EASportTypeDaily = 0,

    /// Outdoor Walk
    /// 户外步行
    EASportTypeOurdoorWalking = 1,

    /// Outdoor Run
    /// 户外跑步
    EASportTypeOurdoorRunning = 2,

    /// Hike
    /// 户外徒步、远足
    EASportTypeOurdoorOnFoot = 3,

    /// Mountaineer
    /// 户外登山、登山
    EASportTypeOurdoorOnMountaineering = 4,

    /// Trail Run
    /// 户外越野跑、越野跑
    EASportTypeOurdoorTrailRunning = 5,

    /// Cycling
    /// 户外单车、室外骑行、户外骑行
    EASportTypeOurdoorCycling = 6,

    /// Outdoor Swim
    /// 户外游泳、室外游泳
    EASportTypeOutdoorSwimming = 7,

    /// Stepper
    /// 室内步行、踏步机
    EASportTypeIndoorWalking = 8,

    /// Treadmill
    /// 室内跑步、 跑步机
    EASportTypeIndoorRunning = 9,

    /// Physical Training
    /// 室内锻炼、体能训练
    EASportTypeIndoorExercise = 10,

    /// Indoor Cycle
    /// 室内单车、室内骑行
    EASportTypeIndoorCycling = 11,

    /// Elliptical Trainer
    /// 椭圆机
    EASportTypeElliptical = 12,

    /// Yoga
    /// 瑜伽
    EASportTypeYoga = 13,

    /// Rowing
    /// Rowing Machine
    /// 划船机
    EASportTypeRowing = 14,

    /// Indoor Swim
    /// 室内游泳
    EASportTypeIndoorSwimming = 15,

    /// Rock Climb
    /// 攀岩
    EASportTypeOdRock = 16,

    /// Skateboard
    /// 滑板
    EASportTypeOdSkate = 17,

    /// Roller Skating
    /// 轮滑
    EASportTypeOdRoller = 18,

    /// Parkour
    /// 跑酷
    EASportTypeOdParkour = 19,

    /// Skydive
    /// 跳伞
    EASportTypeOdParachute = 20,

    /// HIIT
    EASportTypeTrainHit = 21,

    /// Weightlifting
    /// 举重
    EASportTypeTrainWeight = 22,

    /// Plank
    /// 平板支撑
    EASportTypeTrainPlank = 23,

    /// Jumping Jack
    /// 开合跳
    EASportTypeTrainJumping = 24,

    /// Stair Machine
    /// 爬楼机
    EASportTypeTrainStair = 25,

    /// Core Training
    /// 核心训练
    EASportTypeTrainCore = 26,

    /// Flexibility Training
    /// 柔韧训练
    EASportTypeTrainFlex = 27,

    /// Pilates
    /// 普拉提
    EASportTypeTrainPilates = 28,

    /// Stretch
    /// 拉伸
    EASportTypeTrainStretch = 29,

    /// Strength Training
    /// 力量训练
    EASportTypeTrainStrength = 30,

    /// Cross Training
    /// 交叉训练
    EASportTypeTrainCross = 31,

    /// Dumbbell Training
    /// 哑铃训练
    EASportTypeTrainDumbbell = 32,

    /// Deadlift
    /// 硬拉
    EASportTypeTrainDeadlift = 33,

    /// Sit Ups
    /// 仰卧起坐
    EASportTypeTrainSit = 34,

    /// Functional Training
    /// 功能性训练
    EASportTypeTrainFuncition = 35,

    /// Upper Body Training
    /// 上肢训练
    EASportTypeTrainUpper = 36,

    /// Lower Body Training
    /// 下肢训练
    EASportTypeTrainLower = 37,

    /// Abs Training
    /// 腹肌训练
    EASportTypeTrainAbs = 38,

    /// Back Training
    /// 背部训练
    EASportTypeTrainBack = 39,

    /// Sailboat
    /// 帆船、帆船运动
    EASportTypeWaterSailboat = 40,

    /// SUP
    /// 浆板
    EASportTypeWaterSup = 41,

    /// Water Polo
    /// 水球
    EASportTypeWaterPolo = 42,

    /// Thrash
    /// 划水
    EASportTypeWaterThrash = 43,

    /// Kayak
    /// 皮划艇、赛艇
    EASportTypeWaterKayak = 44,

    /// Drifting
    /// 漂流
    EASportTypeWaterDrifting = 45,

    /// Boating
    /// 划船
    EASportTypeWaterBoating = 46,

    /// Fin Swim
    /// 蹼泳
    EASportTypeWaterFin = 47,

    /// Diving
    /// 跳水
    EASportTypeWaterDiving = 48,

    /// Artistic Swim
    /// 花样游泳
    EASportTypeWaterArtistic = 49,

    /// Snorkel
    /// 潜水
    EASportTypeWaterSnorkel = 50,

    /// Kitesurfing
    /// 风筝冲浪、冲浪
    EASportTypeWaterKitesurfing = 51,

    /// ATV
    /// 沙滩车
    EASportTypeWaterAtv = 52,

    /// Beach Soccer
    /// 沙滩足球
    EASportTypeWaterBeach = 53,

    /// Dance
    /// 舞蹈
    EASportTypeDanceDance = 54,

    /// Belly dance
    /// 肚皮舞
    EASportTypeDanceDelly = 55,

    /// Gymnastics
    /// 体操
    EASportTypeDanceGymnastics = 56,

    /// Aerobics
    /// 健身操、室内健身
    EASportTypeDanceAerobics = 57,

    /// Hip-Hop
    /// 街舞
    EASportTypeDanceHipHop = 58,

    /// Boxing
    /// 拳击
    EASportTypeFightBoxing = 59,

    /// Wushu
    /// 武术
    EASportTypeFightWushu = 60,

    /// Wrestling
    /// 摔跤
    EASportTypeFightWrestling = 61,

    /// Tai-Chi
    /// 太极
    EASportTypeFightTaichi = 62,

    /// Muay Thai
    /// 泰拳
    EASportTypeFightMuayThai = 63,

    /// Judo
    /// 柔道
    EASportTypeFightJudo = 64,

    /// Taekwondo
    /// 跆拳道
    EASportTypeFightTaekwondo = 65,

    /// Karate
    /// 空手道
    EASportTypeFightKarate = 66,

    /// Free Sparring
    /// 自由搏击
    EASportTypeFightFreeSparring = 67,

    /// Soccer
    /// 足球
    EASportTypeBallSoccer = 68,

    /// Basketball
    /// 篮球
    EASportTypeBallBasketball = 69,

    /// Volleyball
    /// 排球
    EASportTypeBallVolleyball = 70,

    /// Badminton
    /// 羽毛球
    EASportTypeBallBadminton = 71,

    /// Pingpong
    /// 乒乓球
    EASportTypeBallPingpong = 72,

    /// Cricket
    /// 板球
    EASportTypeBallCricket = 73,

    /// Rugby 、Football
    /// 橄榄球
    EASportTypeBallRugby = 74,

    /// Racquetball
    /// 墙球
    EASportTypeBallRacquetball = 75,

    /// Handball
    /// 手球
    EASportTypeBallHandball = 76,

    /// Squash
    /// 壁球
    EASportTypeBallSquash = 77,

    /// Shuttlecock
    /// 毽球
    EASportTypeBallShuttlecock = 78,

    /// Raga
    /// 藤球
    EASportTypeBallRaga = 79,

    /// Snowboard
    /// 雪车
    EASportTypeSnowBoard = 80,

    /// Skis
    /// 双板滑雪、滑雪
    EASportTypeSnowSkis = 81,

    /// Puck
    /// 冰球
    EASportTypeSnowPuck = 82,

    /// Skate
    /// 滑冰
    EASportTypeSnowSkate = 83,

    /// Curling
    /// 冰壶
    EASportTypeSnowCurling = 84,

    /// Snowmobile
    /// 单板滑雪
    EASportTypeSnowMobile = 85,

    /// Sled
    /// 雪橇
    EASportTypeSnowSled = 86,

    /// Meditation
    /// 冥想
    EASportTypeLeisureMeditation = 87,

    /// Kendo
    /// 剑道
    EASportTypeLeisureKendo = 88,

    /// Fence
    /// 击剑
    EASportTypeLeisureFence = 89,

    /// Bowling
    /// 保龄球
    EASportTypeLeisureBowling = 90,

    /// Billiards
    /// 台球
    EASportTypeLeisureBilliards = 91,

    /// Archery
    /// 射箭
    EASportTypeLeisureArchery = 92,

    /// Darts
    /// 飞镖
    EASportTypeLeisureDarts = 93,

    /// Riding a horse
    /// 骑马
    EASportTypeLeisureHorse = 94,

    /// Hula Hoop
    /// 呼啦圈
    EASportTypeLeisureHula = 95,

    /// Flying a kite
    /// Kite
    /// 放风筝
    EASportTypeLeisureKite = 96,

    /// Fishing
    /// 钓鱼
    EASportTypeLeisureFishing = 97,

    /// Fribee
    /// 飞盘
    EASportTypeLeisureFribee = 98,

    /// Equestrianism
    /// 马术
    EASportTypeLeisureEquestrian = 99,

    /// Racing
    /// 赛车
    EASportTypeLeisureRacing = 100,

    /// Free Exercise
    /// 自由锻炼、自由训练
    EASportTypeOtherFree = 101,

    /// Rope
    /// 跳绳
    EASportTypeOtherRope = 102,

    /// Climb
    /// 上楼梯、爬楼梯
    EASportTypeOtherClimb = 103,

    /// Push Pull
    /// 拔河
    EASportTypeOtherPush = 104,

    /// Horizontal Bar
    /// 单杠
    EASportTypeOtherHorizontal = 105,

    /// Parallel Bars
    /// 双杠
    EASportTypeOtherParallel = 106,

    /// ignore this enum-type
    /// Tennis
    /// 网球
    EASportTypeTennis = 107,

    /// ignore this enum-type
    /// Baseball
    /// 棒球
    EASportTypeBaseball = 108,

    /// ignore this enum-type
    /// Hockey
    /// 曲棍球
    EASportTypeHockey = 109,

    /// ignore this enum-type
    /// CustomSport
    /// 自定义运动
    EASportTypeCustomSport = 110,

    /// ignore this enum-type
    /// MarkTime
    /// 踏步
    EASportTypeMarkTime = 111,

    /// ignore this enum-type
    /// Walking machine
    /// 漫步机
    EASportTypeWalkingMachine = 112,

    /// ignore this enum-type
    /// Athletics
    /// 田径
    EASportTypeAthletics = 113,

    /// ignore this enum-type
    /// Lumbar abdomen training
    /// 腰腹训练
    EASportTypeLumbarAbdomenTraining = 114,

    /// ignore this enum-type
    /// Latin dance
    /// 拉丁舞
    EASportTypeLatinDance = 115,

    /// ignore this enum-type
    /// Ballet
    /// 芭蕾
    EASportTypeBallet = 116,

    /// ignore this enum-type
    /// Golf
    /// 高尔夫
    EASportTypeGolf = 117,

    /// ignore this enum-type
    /// Folk dance
    /// 民族舞
    EASportTypeFolkDance = 118,

    /// ignore this enum-type
    /// Lacrosse
    /// 长曲棍球
    EASportTypeLacrosse = 119,

    /// ignore this enum-type
    /// Softball
    /// 垒球
    EASportTypeSoftball = 120,

    /// ignore this enum-type
    /// PeakBall
    /// 匹克球
    EASportTypePeakBall = 121,
    
    /// ignore this enum-type
    /// Trampoline
    /// 蹦床
    EASportTypeTrampoline = 122,

    /// ignore this enum-type
    /// Parkour
    /// 酷跑
    EASportTypeParkour = 123,

    /// ignore this enum-type
    /// Push-ups
    /// 俯卧撑
    EASportTypePushUp = 124,
    
    
    /// ignore this enum-type
    /// High jump
    /// 跳高
    EASportTypeHighJump = 125,

    /// ignore this enum-type
    /// Long jump
    /// 跳远
    EASportTypeLongJump = 126,

    
    
    /// Intelligent movement: Daily
    /// 智慧运动: 日常运动
    EASportTypeDailyEx = 32768,

    /// Intelligent movement:
    /// 智慧运动: 户外步行
    EASportTypeOurdoorWalkingEx = 32769,

    /// Intelligent movement:
    /// 智慧运动: 户外跑步
    EASportTypeOurdoorRunningEx = 32770,

    /// Intelligent movement:
    /// 智慧运动: 户外徒步
    EASportTypeOurdoorOnFootEx = 32771,

    /// Intelligent movement:
    /// 智慧运动: 户外登山
    EASportTypeOurdoorOnMountaineeringEx = 32772,

    /// Intelligent movement:
    /// 智慧运动: 户外越野跑
    EASportTypeOurdoorTrailRunningEx = 32773,

    /// Intelligent movement:
    /// 智慧运动: 户外单车
    EASportTypeOurdoorCyclingEx = 32774,

    /// Intelligent movement:
    /// 智慧运动: 户外游泳
    EASportTypeOutdoorSwimmingEx = 32775,

    /// Intelligent movement:
    /// 智慧运动: 室内步行
    EASportTypeIndoorWalkingEx = 32776,

    /// Intelligent movement:
    /// 智慧运动: 室内跑步
    EASportTypeIndoorRunningEx = 32777,

    /// Intelligent movement:
    /// 智慧运动: 室内锻炼
    EASportTypeIndoorExerciseEx = 32778,

    /// Intelligent movement:
    /// 智慧运动: 室内单车
    EASportTypeIndoorCyclingEx = 32779,

    /// Intelligent movement:
    /// 智慧运动: 椭圆机
    EASportTypeEllipticalEx = 32780,

    /// Intelligent movement:
    /// 智慧运动: 瑜伽
    EASportTypeYogaEx = 32781,

    /// Intelligent movement:
    /// 智慧运动: 划船机
    EASportTypeRowingEx = 32782,

    /// Intelligent movement:
    /// 智慧运动: 室内游泳
    EASportTypeIndoorSwimmingEx = 32783,
    
};

/// Sport type
/// MARK: - 运动类型
typedef NS_ENUM(NSUInteger,EAWatchSportType) {
    
    /// Daily
    /// 日常运动
    EAWatchSportDaily = 0,

    /// Outdoor Walk
    /// 户外步行
    EAWatchSportOurdoorWalk = 1,

    /// Outdoor Run
    /// 户外跑步
    EAWatchSportOurdoorRun = 2,

    /// Hike
    /// 远足
    EAWatchSportHike = 3,

    /// Mountaineer
    /// 登山
    EAWatchSportMountaineer = 4,

    /// Trail Run
    /// 越野跑
    EAWatchSportTrailRun = 5,

    /// Cycling
    /// 户外单车、室外骑行、户外骑行
    EAWatchSportCycling = 6,

    /// Outdoor Swim
    /// 户外游泳、室外游泳
    EAWatchSportOutdoorSwim = 7,

    /// Stepper
    /// 踏步机
    EAWatchSportStepper = 8,

    /// Treadmill
    /// 跑步机
    EAWatchSportTreadmill = 9,

    /// Physical Training
    /// 体能训练
    EAWatchSportPhysicalTraining = 10,

    /// Indoor Cycle
    /// 室内单车、室内骑行
    EAWatchSportIndoorCycle = 11,

    /// Elliptical Trainer
    /// 椭圆机
    EAWatchSportEllipticalTrainer = 12,

    /// Yoga
    /// 瑜伽
    EAWatchSportYoga = 13,

    /// Rowing
    /// Rowing Machine
    /// 划船机
    EAWatchSportRowing = 14,

    /// Indoor Swim
    /// 室内游泳
    EAWatchSportIndoorSwim = 15,

    /// Rock Climb
    /// 攀岩
    EAWatchSportOdRockClimb = 16,

    /// Skateboard
    /// 滑板
    EAWatchSportOdSkateboard = 17,

    /// Roller Skating
    /// 轮滑
    EAWatchSportOdRollerSkating = 18,

    /// Parkour
    /// 跑酷
    EAWatchSportOdParkour = 19,

    /// Skydive
    /// 跳伞
    EAWatchSportOdSkydive = 20,

    /// HIIT
    EAWatchSportTrainHIIT = 21,

    /// Weightlifting
    /// 举重
    EAWatchSportTrainWeightlifting = 22,

    /// Plank
    /// 平板支撑
    EAWatchSportTrainPlank = 23,

    /// Jumping Jack
    /// 开合跳
    EAWatchSportTrainumpingJack = 24,

    /// Stair Machine
    /// 爬楼机
    EAWatchSportTrainStairMachine = 25,

    /// Core Training
    /// 核心训练
    EAWatchSportTrainCoreTraining = 26,

    /// Flexibility Training
    /// 柔韧训练
    EAWatchSportTrainFlexibilityTraining = 27,

    /// Pilates
    /// 普拉提
    EAWatchSportTrainPilates = 28,

    /// Stretch
    /// 拉伸
    EAWatchSportTrainStretch = 29,

    /// Strength Training
    /// 力量训练
    EAWatchSportTrainStrengthTraining = 30,

    /// Cross Training
    /// 交叉训练
    EAWatchSportTrainCrossTraining = 31,

    /// Dumbbell Training
    /// 哑铃训练
    EAWatchSportTrainDumbbellTraining = 32,

    /// Deadlift
    /// 硬拉
    EAWatchSportTrainDeadlift = 33,

    /// Sit Ups
    /// 仰卧起坐
    EAWatchSportTrainSitUps = 34,

    /// Functional Training
    /// 功能性训练
    EAWatchSportTrainFunctionalTraining= 35,

    /// Upper Body Training
    /// 上肢训练
    EAWatchSportTrainUpperBodyTraining = 36,

    /// Lower Body Training
    /// 下肢训练
    EAWatchSportTrainLowerBodyTraining = 37,

    /// Abs Training
    /// 腹肌训练
    EAWatchSportTrainAbsTraining = 38,

    /// Back Training
    /// 背部训练
    EAWatchSportTrainBackTraining = 39,

    /// Sailboat
    /// 帆船、帆船运动
    EAWatchSportWaterSailboat = 40,

    /// SUP
    /// 浆板
    EAWatchSportWaterSUP = 41,

    /// Water Polo
    /// 水球
    EAWatchSportWaterPolo = 42,

    /// Thrash
    /// 划水
    EAWatchSportWaterThrash = 43,

    /// Kayak
    /// 皮划艇、赛艇
    EAWatchSportWaterKayak = 44,

    /// Drifting
    /// 漂流
    EAWatchSportWaterDrifting = 45,

    /// Boating
    /// 划船
    EAWatchSportWaterBoating = 46,

    /// Fin Swim
    /// 蹼泳
    EAWatchSportWaterFinSwim = 47,

    /// Diving
    /// 跳水
    EAWatchSportWaterDiving = 48,

    /// Artistic Swim
    /// 花样游泳
    EAWatchSportWaterArtisticSwim = 49,

    /// Snorkel
    /// 潜水
    EAWatchSportWaterSnorkel = 50,

    /// Kitesurfing
    /// 风筝冲浪、冲浪
    EAWatchSportWaterKitesurfing = 51,

    /// ATV
    /// 沙滩车
    EAWatchSportWaterAtv = 52,

    /// Beach Soccer
    /// 沙滩足球
    EAWatchSportWaterBeachSoccer = 53,

    /// Dance
    /// 舞蹈
    EAWatchSportDanceDance = 54,

    /// Belly dance
    /// 肚皮舞
    EAWatchSportDanceBellyDance = 55,

    /// Gymnastics
    /// 体操
    EAWatchSportDanceGymnastics = 56,

    /// Aerobics
    /// 健身操、室内健身
    EAWatchSportDanceAerobics = 57,

    /// Hip-Hop
    /// 街舞
    EAWatchSportDanceHipHop = 58,

    /// Boxing
    /// 拳击
    EAWatchSportFightBoxing = 59,

    /// Wushu
    /// 武术
    EAWatchSportFightWushu = 60,

    /// Wrestling
    /// 摔跤
    EAWatchSportFightWrestling = 61,

    /// Tai-Chi
    /// 太极
    EAWatchSportFightTaichi = 62,

    /// Muay Thai
    /// 泰拳
    EAWatchSportFightMuayThai = 63,

    /// Judo
    /// 柔道
    EAWatchSportFightJudo = 64,

    /// Taekwondo
    /// 跆拳道
    EAWatchSportFightTaekwondo = 65,

    /// Karate
    /// 空手道
    EAWatchSportFightKarate = 66,

    /// Free Sparring
    /// 自由搏击
    EAWatchSportFightFreeSparring = 67,

    /// Soccer
    /// 足球
    EAWatchSportBallSoccer = 68,

    /// Basketball
    /// 篮球
    EAWatchSportBallBasketball = 69,

    /// Volleyball
    /// 排球
    EAWatchSportBallVolleyball = 70,

    /// Badminton
    /// 羽毛球
    EAWatchSportBallBadminton = 71,

    /// Pingpong
    /// 乒乓球
    EAWatchSportBallPingpong = 72,

    /// Cricket
    /// 板球
    EAWatchSportBallCricket = 73,

    /// Rugby 、Football
    /// 橄榄球
    EAWatchSportBallFootball = 74,

    /// Racquetball
    /// 墙球
    EAWatchSportBallRacquetball = 75,

    /// Handball
    /// 手球
    EAWatchSportBallHandball = 76,

    /// Squash
    /// 壁球
    EAWatchSportBallSquash = 77,

    /// Shuttlecock
    /// 毽球
    EAWatchSportBallShuttlecock = 78,

    /// Raga
    /// 藤球
    EAWatchSportBallRaga = 79,

    /// Snowboard
    /// 雪车
    EAWatchSportSnowBoard = 80,

    /// Skis
    /// 双板滑雪、滑雪
    EAWatchSportSnowSkis = 81,

    /// Puck
    /// 冰球
    EAWatchSportSnowPuck = 82,

    /// Skate
    /// 滑冰
    EAWatchSportSnowSkate = 83,

    /// Curling
    /// 冰壶
    EAWatchSportSnowCurling = 84,

    /// Snowmobile
    /// 单板滑雪
    EAWatchSportSnowmobile = 85,

    /// Sled
    /// 雪橇
    EAWatchSportSnowSled = 86,

    /// Meditation
    /// 冥想
    EAWatchSportLeisureMeditation = 87,

    /// Kendo
    /// 剑道
    EAWatchSportLeisureKendo = 88,

    /// Fence
    /// 击剑
    EAWatchSportLeisureFence = 89,

    /// Bowling
    /// 保龄球
    EAWatchSportLeisureBowling = 90,

    /// Billiards
    /// 台球
    EAWatchSportLeisureBilliards = 91,

    /// Archery
    /// 射箭
    EAWatchSportLeisureArchery = 92,

    /// Darts
    /// 飞镖
    EAWatchSportLeisureDarts = 93,

    /// Riding a horse
    /// 骑马
    EAWatchSportRidingHorse = 94,

    /// Hula Hoop
    /// 呼啦圈
    EAWatchSportLeisureHulaHoop = 95,

    /// Flying a kite
    /// Kite
    /// 放风筝
    EAWatchSportLeisureFlyingKite= 96,

    /// Fishing
    /// 钓鱼
    EAWatchSportLeisureFishing = 97,

    /// Fribee
    /// 飞盘
    EAWatchSportLeisureFribee = 98,

    /// Equestrianism
    /// 马术
    EAWatchSportLeisureEquestrian = 99,

    /// Racing
    /// 赛车
    EAWatchSportLeisureRacing = 100,

    /// Free Exercise
    /// 自由锻炼、自由训练
    EAWatchSportOtherFreeExercise = 101,

    /// Rope
    /// 跳绳
    EAWatchSportOtherRope = 102,

    /// Climb
    /// 上楼梯、爬楼梯
    EAWatchSportOtherClimb = 103,

    /// Push Pull
    /// 拔河
    EAWatchSportOtherPush = 104,

    /// Horizontal Bar
    /// 单杠
    EAWatchSportOtherHorizontal = 105,

    /// Parallel Bars
    /// 双杠
    EAWatchSportOtherParallel = 106,

    /// ignore this enum-type
    /// Tennis
    /// 网球
    EAWatchSportTennis = 107,

    /// ignore this enum-type
    /// Baseball
    /// 棒球
    EAWatchSportBaseball = 108,

    /// ignore this enum-type
    /// Hockey
    /// 曲棍球
    EAWatchSportHockey = 109,

    /// ignore this enum-type
    /// CustomSport
    /// 自定义运动
    EAWatchSportCustomSport = 110,

    /// ignore this enum-type
    /// MarkTime
    /// 踏步
    EAWatchSportMarkTime = 111,

    /// ignore this enum-type
    /// Walking machine
    /// 漫步机
    EAWatchSportWalkingMachine = 112,

    /// ignore this enum-type
    /// Athletics
    /// 田径
    EAWatchSportAthletics = 113,

    /// ignore this enum-type
    /// Lumbar abdomen training
    /// 腰腹训练
    EAWatchSportLumbarAbdomenTraining = 114,

    /// ignore this enum-type
    /// Latin dance
    /// 拉丁舞
    EAWatchSportLatinDance = 115,

    /// ignore this enum-type
    /// Ballet
    /// 芭蕾
    EAWatchSportBallet = 116,

    /// ignore this enum-type
    /// Golf
    /// 高尔夫
    EAWatchSportGolf = 117,

    /// ignore this enum-type
    /// Folk dance
    /// 民族舞
    EAWatchSportFolkDance = 118,

    /// ignore this enum-type
    /// Lacrosse
    /// 长曲棍球
    EAWatchSportLacrosse = 119,

    /// ignore this enum-type
    /// Softball
    /// 垒球
    EAWatchSportSoftball = 120,

    /// ignore this enum-type
    /// PeakBall
    /// 匹克球
    EAWatchSportPeakBall = 121,
    
    /// ignore this enum-type
    /// Trampoline
    /// 蹦床
    EAWatchSportTrampoline = 122,

    /// ignore this enum-type
    /// Parkour
    /// 酷跑
    EAWatchSportParkour = 123,

    /// ignore this enum-type
    /// Push-ups
    /// 俯卧撑
    EAWatchSportPushUp = 124,
    
    /// ignore this enum-type
    /// High jump
    /// 跳高
    EAWatchSportHighJump = 125,

    /// ignore this enum-type
    /// Long jump
    /// 跳远
    EAWatchSportLongJump = 126,

    /// 室内跑步
    /// Indoor Running
    EAWatchSportIdRunning = 127,

    /// 户外健走
    /// Fast Walking
    EAWatchSportFastWalking = 128,

    /// 室内健走
    /// Indoor walking
    EAWatchSportIdWalking = 129,

    /// 小轮车
    /// BMX
    EAWatchSportBmx = 130,

    /// 有氧训练
    /// Aerobic Training
    EAWatchSportAerobicTraining = 131,

    /// 无氧训练
    /// Anaerobic Training
    EAWatchSportAnaerobicTraining = 132,

    /// 混合有氧
    /// Mix Aerobic
    EAWatchSportMixAerobic = 133,

    /// 打猎
    /// Hunting
    EAWatchSportHunting = 134,

    /// 遛狗
    /// Walk the Dog
    EAWatchSportWalkTheDog = 135,

    /// 蹦极跳
    /// Bungee Jumping
    EAWatchSportBungeeJumping = 136,

    /// 摩托艇
    /// MotorBoat
    EAWatchSportMotorBoat = 137,

    /// 户外溜冰
    /// Outdoor Ice Skating
    EAWatchSportOutdoorIceSkating = 138,

    /// 室内溜冰
    /// Indoor Ice Skating
    EAWatchSportIndoorIceSkating = 139,

    /// 冬季两项
    ///  Biathlon *
    EAWatchSportBiathlon = 140,

    /// 门球
    /// Croquet
    EAWatchSportCroquet = 141,

    /// 沙滩排球
    /// Volleyball
    EAWatchSportVolleyball = 142,

    /// 躲避球
    /// Dodge Ball
    EAWatchSportDodgeBall = 143,

    /// 美式足球
    /// Football
    EAWatchSportAmericanFootball = 144,

    /// 交谊舞
    /// Social Dancing
    EAWatchSportSocialDancing = 145,

    /// 尊巴
    /// Zumba
    EAWatchSportZumba = 146,

    /// 迪斯科
    /// Disco
    EAWatchSportDisco = 147,

    /// 华尔兹
    /// Waltz
    EAWatchSportWaltz = 148,

    /// 爵士舞
    /// Jazz Dance
    EAWatchSportJazzDance = 159,

    /// 探戈
    /// Tango
    EAWatchSportTango = 150,

    /// 踢踏舞
    /// Tap Dance
    EAWatchSportTapDance = 151,

    /// 障碍赛
    /// Show Jumper
    EAWatchSportShowJumper = 152,
    
    /// 攀爬 :
    /// climbing
    EAWatchSportClimbing = 153,

    /// 冲浪 :
    /// Surfing
    EAWatchSportWaterSurfing = 154,

    /// 广场舞 :
    /// Square Dancing
    EAWatchSportSquareDancing = 155,

    /// 高山滑雪 :
    /// Alpine Skiing
    EAWatchSportDownhillskiing = 156,
    
    
    
    /// Intelligent movement: Daily
    /// 智慧运动: 日常运动
    EAWatchSportDailyEx = 32768,

    /// Intelligent movement:
    /// 智慧运动: 户外步行
    EAWatchSportOurdoorWalkingEx = 32769,

    /// Intelligent movement:
    /// 智慧运动: 户外跑步
    EAWatchSportOurdoorRunningEx = 32770,

    /// Intelligent movement:
    /// 智慧运动: 户外徒步
    EAWatchSportOurdoorOnFootEx = 32771,

    /// Intelligent movement:
    /// 智慧运动: 户外登山
    EAWatchSportOurdoorOnMountaineeringEx = 32772,

    /// Intelligent movement:
    /// 智慧运动: 户外越野跑
    EAWatchSportOurdoorTrailRunningEx = 32773,

    /// Intelligent movement:
    /// 智慧运动: 户外单车
    EAWatchSportOurdoorCyclingEx = 32774,

    /// Intelligent movement:
    /// 智慧运动: 户外游泳
    EAWatchSportOutdoorSwimmingEx = 32775,

    /// Intelligent movement:
    /// 智慧运动: 室内步行
    EAWatchSportIndoorWalkingEx = 32776,

    /// Intelligent movement:
    /// 智慧运动: 室内跑步
    EAWatchSportIndoorRunningEx = 32777,

    /// Intelligent movement:
    /// 智慧运动: 室内锻炼
    EAWatchSportIndoorExerciseEx = 32778,

    /// Intelligent movement:
    /// 智慧运动: 室内单车
    EAWatchSportIndoorCyclingEx = 32779,

    /// Intelligent movement:
    /// 智慧运动: 椭圆机
    EAWatchSportEllipticalEx = 32780,

    /// Intelligent movement:
    /// 智慧运动: 瑜伽
    EAWatchSportYogaEx = 32781,

    /// Intelligent movement:
    /// 智慧运动: 划船机
    EAWatchSportRowingEx = 32782,

    /// Intelligent movement:
    /// 智慧运动: 室内游泳
    EAWatchSportIndoorSwimmingEx = 32783,
    
};


/// OTA respond status
/// MARK: - OTA 响应类型
typedef NS_ENUM(NSUInteger,EAOtaRespondStatus) {
    
    /// Accept
    /// 接受ota请求
    EAOtaRespondStatusAccept = 0,
    
    /// Reject:unkown
    /// 拒绝ota请求 : 其他原因
    EAOtaRespondStatusReject = 1,
    
    ///Reject:The watch has been updated with this version
    /// 拒绝ota请求 : 手表已经更新此版本
    EAOtaRespondStatusRejectVersionError = 2,
    
    /// Reject
    /// 请继续发送数据包
    EAOtaRespondStatusProceed = 3,
    
    /// Crc error
    /// 传输完成，crc校验错误
    EAOtaRespondStatusCrcError = 4,
    
    /// Complete
    /// 传输完成
    EAOtaRespondStatusComplete = 5,
};

/// MARK: - OTA 请求类型
typedef NS_ENUM(NSUInteger,EAOtaRequestType) {
    
    /// Apollo
    /// 阿波罗
    EAOtaRequestTypeApollo = 0,
    
    /// stm
    EAOtaRequestTypeStm32 = 1,
    
    /// Font & Picture
    /// res
    EAOtaRequestTypeRes = 2,
    
    /// The screen
    /// tp
    EAOtaRequestTypeTp = 3,
    
    /// Heart rate
    /// 心率
    EAOtaRequestTypeHr = 4,
    
    /// gps
    EAOtaRequestTypeGps = 5,
    
    /// agps
    EAOtaRequestTypeAgps = 6,
    
    /// Watch face
    /// 自定义表盘
    EAOtaRequestTypeUserWf = 7,
};


/// MARK: - OTA 图片类型
typedef NS_ENUM(NSUInteger,EAUIType) {
    
    /// 未知的归类
    EAUITypeUnknow = 0,
    
    /// 背景
    EAUITypeBackground = 1,
    
    /// 数字字体，打包0~9,固定宽高，在bin中按0~9排序
    EAUITypeNumberFont = 2,
    
    /// 年
    EAUITypeYear = 3,
    
    /// 月
    EAUITypeMonth = 4,
    
    /// 日
    EAUITypeDay = 5,
    
    /// 时
    EAUITypeHour = 6,
    
    /// 分
    EAUITypeMinute = 7,
    
    /// 秒
    EAUITypeSecond = 8,
    
    /// 时针
    EAUITypeHourHand = 9,
    
    /// 分针
    EAUITypeMinuteHand = 10,
    
    /// 秒针
    EAUITypeSecondHand = 11,
    
    /// 家乡时区时针
    EAUITypeHomeHourHand = 12,
    
    /// 家乡时区分针
    EAUITypeHomeMinuteHand = 13,
    
    /// 家乡时区秒针
    EAUITypeHomeSecondHand = 14,
    
    /// 步数图标
    EAUITypeSteps = 15,
    
    /// 步数字体
    EAUITypeStepsNumberFont = 16,
    
    /// 卡路里
    EAUITypeCalorie = 17,
    
    /// 卡路里字体
    EAUITypeCalorieNumberFont = 18,
    
    /// 距离
    EAUITypeDistance = 19,
    
    /// 距离 字体
    EAUITypeDistanceNumberFont = 20,
    
    /// 运动时长
    EAUITypeDuration = 21,
    
    /// 运动时长字体
    EAUITypeDurationNumberFont = 22,
    
    /// 心率
    EAUITypeHeartRate = 23,
    
    /// 心率字体
    EAUITypeHeartRateNumberFont = 24,
    
    /// 天气
    EAUITypeWeather = 25,
    
    /// 电池
    EAUITypeBattery = 26,
};

/// Stress data type
/// MARK: - 压力数据类型
typedef NS_ENUM(NSUInteger,EAStressDataType) {
    
    /// Unkown
    EAStressDataTypeStressUnkown = 0,
    
    /// Relax
    /// 放松
    EAStressDataTypeStressRelax = 1,
    
    /// Normal
    /// 正常
    EAStressDataTypeStressNormal = 2,
    
    /// Middle
    /// 中等
    EAStressDataTypeStressMiddle = 3,
    
    /// High
    /// 高
    EAStressDataTypeStressHigh = 4,
};

/// MARK: - 震动类型
/// Vibration type
typedef NS_ENUM(NSUInteger,EAVibrateIntensityType) {
    
    /// Light
    /// 弱
    EAVibrateIntensityTypeLight = 0,
    
    /// Normal
    /// 正常
    EAVibrateIntensityTypeMedium = 1,
    
    /// Strong
    /// 强
    EAVibrateIntensityTypeStrong = 2,
    
    /// Not Vibrate
    /// 不震动
    EAVibrateIntensityTypeNotVibrate = 3,
};

/// MARK: - 一级菜单样式
typedef NS_ENUM(NSUInteger,EAFirstLeverType) {
    
    /// Null
    /// 无
    EAFirstLeverTypePageNull = 0,
    
    /// HeartRate
    /// 心率
    EAFirstLeverTypePageHeartRate = 1,
    
    /// Stress or Pressure
    /// 压力
    EAFirstLeverTypePagePressure = 2,
    
    /// Weather
    /// 天气
    EAFirstLeverTypePageWeather = 3,
    
    /// Music
    /// 音乐
    EAFirstLeverTypePageMusic = 4,
    
    /// Breath
    /// 呼吸
    EAFirstLeverTypePageBreath = 5,
    
    /// Sleep
    /// 睡眠
    EAFirstLeverTypePageSleep = 6,
    
    /// Menstrual cycle
    /// 生理周期
    EAFirstLeverTypePageMenstrualCycle = 7,
    
    /// 拍照
    /// Camera
    EAFirstLeverTypePageCamera = 8,

    /// 多运动
    /// Workout
    EAFirstLeverTypePageWorkout = 9,
    
};

/// MARK: - 经期类型
typedef NS_ENUM(NSUInteger, EAMenstruationType) {
    
    /// First safe period
    /// 第一次安全期
    EAMenstruationTypeFirstSafePeriod        = 0,
    
    /// Second safe period,
    /// 第2次安全期
    EAMenstruationTypeSecondSafePeriod = 1,
    
    /// SecondSafePeriod,
    /// 经期
    EAMenstruationTypePeriod = 2,
    
    /// Easy pregnancy
    /// 易孕期
    EAMenstruationTypeEasyPregnancy = 3,
    
    /// Ovulation day
    /// 排卵日
    EAMenstruationTypeOvulationDay = 4,
    
    /// Un setting
    /// 未设置时间
    EAMenstruationTypeUnSetting,
    
};

/// Raised my hand against the bright screen type
/// MARK: - 抬手亮屏
typedef NS_ENUM(NSUInteger, EAGesturesBrightType) {
    
    /// Close
    /// 关闭
    EAGesturesBrightTypeClose = 0,
    
    /// All day open
    /// 全天开启
    EAGesturesBrightTypeAllDay = 1,
    
    /// Select time
    /// 选择时间段开启
    EAGesturesBrightTypeSelectTime = 2,
};


/// Habit tracker operation
/// MARK: - 习惯事件操作
typedef NS_ENUM(NSUInteger,EAHabitTrackerOps) {
    
    /// add
    /// 操作新增
    EAHabitTrackerOpsAdd = 0,
    
    /// edit
    /// 操作编辑
    EAHabitTrackerOpsEdit = 1,
    
    /// delete this
    /// 操作删除此条
    EAHabitTrackerOpsDel = 2,
    
    /// delete all
    /// 操作删除全部
    EAHabitTrackerOpsDelAll = 3,
    
    /// delete more
    /// 操作删除多天
    EAHabitTrackerOpsDelMore = 4,
};

/// Habit tracker icon type
/// MARK: - 习惯图标类型
typedef NS_ENUM(NSUInteger,EAHabitTrackerIconType) {
    
    EAHabitTrackerIconTypeStudy01 = 0,
    EAHabitTrackerIconTypeSleep02 = 1,
    EAHabitTrackerIconTypeStudy03 = 2,
    EAHabitTrackerIconTypeChores04 = 3,
    EAHabitTrackerIconTypeHavefun05 = 4,
    EAHabitTrackerIconTypeDrink06 = 5,
    EAHabitTrackerIconTypeSun07 = 6,
    EAHabitTrackerIconTypeTeeth08 = 7,
    EAHabitTrackerIconTypeCalendar09 = 8,
    EAHabitTrackerIconTypePiano10 = 9,
    EAHabitTrackerIconTypeFruit11 = 10,
    EAHabitTrackerIconTypeMedicine12 = 11,
    EAHabitTrackerIconTypeDraw13 = 12,
    EAHabitTrackerIconTypeTarget14 = 13,
    EAHabitTrackerIconTypeDog15 = 14,
    EAHabitTrackerIconTypeExercise16 = 15,
    EAHabitTrackerIconTypeBed17 = 16,
    EAHabitTrackerIconTypeTidyup18 = 17,
    EAHabitTrackerIconTypeEatFood = 18,
    EAHabitTrackerIconTypePackYourBag = 19,
};



/// Add habit tracker respond
/// MARK: - 习惯追踪回应状态
typedef NS_ENUM(NSUInteger,EAHabitTrackerRespondType) {
    
    /// Success
    /// 执行成功
    EAHabitTrackerRespondTypeSuccess = 0,
    
    /// Fail
    /// 执行失败
    EAHabitTrackerRespondTypeFail = 1,
    
    ///  The maximum number supported is exceeded
    /// 超过支持的最大数量
    EAHabitTrackerRespondTypeMemFull = 2,
    
    /// Time to repeat
    /// 时间重复
    EAHabitTrackerRespondTypeTimeConflict = 3,
};


#pragma mark - 习惯追踪flag
typedef NS_ENUM(NSUInteger,EAHabitTrackerFlag) {
    
    /// Initial
    /// 初始态
    EAHabitTrackerFlagInitial = 0,
    
    /// Progress
    /// 进行中
    EAHabitTrackerFlagInProgress = 1,
    
    /// Completed
    /// 已完成
    EAHabitTrackerFlagCompleted = 2,
    
    /// Cancel
    /// 已取消
    EAHabitTrackerFlagCancel = 3,
};


#pragma mark - 通讯录flag
typedef NS_ENUM(NSUInteger,EAPhoneContactFlag) {
    
    /// 标志: 起始包
    EAPhoneContactFlagBegin = 0,

    /// 标志: 非起始包
    EAPhoneContactFlagProceed = 1,
};

#pragma mark - 自定义表盘时间颜色
typedef NS_ENUM(NSUInteger, EACWFTimerColorType) {
    
    EACWFTimerColorTypeBlack         = 0,
    EACWFTimerColorTypeWhite         = 1,

};

#pragma mark - 自定义表盘风格类型
typedef NS_ENUM(NSUInteger, EACWFStyleType) {
    
    EACWFStyleTypePictureNumber         = 1,    // Picture digital dial【图片数字表盘】
    EACWFStyleTypePointer               = 2,    // Pointer dial【指针表盘】
};

#pragma mark - 自定义表盘指针刻度类型类型
typedef NS_ENUM(NSUInteger, EACWFPointerScaleStyle) {
    
    EACWFPointerScaleStyleNone          = 0,    // None【无刻度】
//    EACWFPointerScaleStyleBar           = 1,    // Bar scale【条形刻度】
//    EACWFPointerScaleStyleDigitalBar    = 2,    // Digital bar scale【数字条形刻度】
//    EACWFPointerScaleStyleRoman         = 3,    // Roman number【罗马数字】
//    EACWFPointerScaleStyleDiamond       = 4,    // Diamond【钻石】
};

#pragma mark - 手表形状
typedef NS_ENUM(NSUInteger, EAScreenType) {
    
    EAScreenTypeSquare          = 0, // 0: square screen
    EAScreenTypeCircle          = 1, // 1: round screen
};

#pragma mark - 时间类型
typedef NS_ENUM(NSUInteger, EATimeType) {
    
    EATimeTypeLowHour           = 0,        // 0: Low high【时低位】==》“0~9”
    EATimeTypeLowMinute         = 1,        // 1: Low minute【分低位】==》“0~9”

    EATimeTypeHighMinute        = 10,       // 10: Hour minute【分高位】==》“0~5”
    EATimeTypeHighHour          = 11,       // 11: Hour high【时高位】==》“0~2”
    
    EATimeTypeColon             = 100,      // 100:Colon【冒号】==> “:”
    
    EATimeTypeDate              = 1000,      // 101:Date【几号】
    EATimeTypeWeek              = 1001,      // 101:Week【星期几】
    
    EATimeTypeAmPmNull          = 1100,      // 1100:
};

typedef NS_ENUM(NSUInteger, EAPointerType) {
    
    EAPointerTypeHour   = 1,
    EAPointerTypeMinute = 10,
    EAPointerTypeSecond = 100,
};

#pragma mark - Monitor alert type【监测提醒类型】
typedef NS_ENUM(NSUInteger, EAMonitorReminderType) {
    
    /// Drink【喝水】
    EAMonitorReminderTypeDrink = 0,

    /// wash hands【洗手】
    EAMonitorReminderTypeWashHands = 1,

    /// take medicine【吃药】
    EAMonitorReminderTypeTakeMedicine = 2,
};

#pragma mark - Sport status【运动状态】
typedef NS_ENUM(NSUInteger, EAAppLaunchSportStatus) {
    
    EAAppLaunchSportStatusClose = 0,
    EAAppLaunchSportStatusStart = 1,
    EAAppLaunchSportStatusPause = 2,
};

#pragma mark - App operation watch type【App操作手表类型】
typedef NS_ENUM(NSUInteger, EAAppOpsType) {
    
    EAAppOpsTypeHr = 1, // 心率
    EAAppOpsTypeStress = 2,// 压力
    EAAppOpsTypeBloodOxygen = 3,// 血氧
    EAAppOpsTypeBreathe = 4,// 呼吸
};

#pragma mark - 大数据类型（获取）
typedef NS_ENUM(NSUInteger, EABigDataType) {
    
    EABigDataTypeSteps = 1,         // 步数
    EABigDataTypeSleep = 2,         // 睡眠
    EABigDataTypeHr = 3,            // 心率
    EABigDataTypeGps = 4,           // GPS
    EABigDataTypeMultiSports= 5,    // 多运动
    EABigDataTypeBloodOxygen = 6,   // 血氧
    EABigDataTypeStress = 7,        // 压力
    EABigDataTypeStepFreq = 8,      // 步频
    EABigDataTypeStepPace = 9,      // 配速
    EABigDataTypeRestingHr = 10,    // 静态心率
    EABigDataTypeHabitTracker = 11, // 习惯
};

/// 蓝牙状态
/// MARK: - Bluetooth status
typedef NS_ENUM(NSUInteger,EABleState) {
    
    EABleStateUnknown = 0,
    EABleStateResetting,
    EABleStateUnsupported,
    EABleStateUnauthorized,
    EABleStatePoweredOff,
    EABleStatePoweredOn,
};


/// BT
/// MARK: - BT
typedef NS_ENUM(NSUInteger,EABtType) {
    
    EABtTypeOff = 0,
    EABtTypeOn = 1,
    EABtTypeConnected = 2,
};

#endif /* EAEnumh */
