//
//  BaseViewController.m
//  SDKDemo
//
//  Created by Aye on 2021/12/7.
//

#import "BaseViewController.h"

@interface BaseViewController ()

@end

@implementation BaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
  
    _textLabel = [[UILabel alloc] init];
    _textLabel.numberOfLines = 0;
    [self.view addSubview:_textLabel];
    [_textLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.top.equalTo(self.mas_topLayoutGuide).offset(15);
        make.left.equalTo(self.view).offset(12);
        make.right.equalTo(self.view).offset(-12);

    }];
    
    
    [self loadWatchData];
}

- (void)loadWatchData {
    
}


#pragma mark - func
- (void)showAlertWithTitle:(NSString *)title {
    
    if (self.alertVC) {
        [self dismissAlert];
    }
    self.alertVC = [UIAlertController alertControllerWithTitle:title message:nil preferredStyle:(UIAlertControllerStyleAlert)];
    [self presentViewController:self.alertVC animated:YES completion:nil];
    
    [self performSelector:@selector(dismissAlert) withObject:nil afterDelay:1.25];
}
- (void)showAlertWithTitle:(NSString *)title message:(NSString *)message {
    if (self.alertVC) {
        [self dismissAlert];
    }
    self.alertVC = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:(UIAlertControllerStyleAlert)];
    [self presentViewController:self.alertVC animated:YES completion:nil];
}
- (void)dismissAlert {
    
    [self.alertVC dismissViewControllerAnimated:YES completion:nil];
}

@end
