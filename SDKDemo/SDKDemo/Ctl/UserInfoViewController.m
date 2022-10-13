//
//  UserInfoViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//

#import "UserInfoViewController.h"


@interface UserInfoViewController ()

/** EAUserModel */
@property(nonatomic,strong) EAUserModel *userModel;



@end

@implementation UserInfoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)loadWatchData {
    
    

    WeakSelf
    [BluetoothFunc getUserInfo:^(EAUserModel * _Nonnull userModel) {
       
        selfWeak.userModel = userModel;
        NSArray *list = @[@"白皮肤",@"白偏黄皮肤",@"黄皮肤",@"黄偏黑皮肤",@"黑皮肤"];
        selfWeak.textLabel.text = [NSString stringWithFormat:@"年龄：%ld \n穿戴方式：%@ \n性别：%@ \n肤色：%@ \n身高：%ldcm \n体重：%0.2fKg",userModel.age,(userModel.wearWayType == EAWearWayTypeRightHand ? @"右手":@"左手"),(userModel.sexType == EASexTypeMale ? @"男性":@"女性"),list[userModel.eSkinColor],userModel.height,userModel.weight/1000.00];
    }];
    

    
}



- (IBAction)sexAction:(UIButton *)sender {
    
    /// 修改性别 0男性，1女性
    self.userModel.sexType = sender.tag - 100;
    WeakSelf
    [BluetoothFunc changeUserInfo:self.userModel completion:^(BOOL succ) {
       
        [selfWeak loadWatchData];
    }];
    
}









@end
