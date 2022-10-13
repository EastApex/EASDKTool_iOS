//
//  RadiusView.m
//  SDKDemo
//
//  Created by Aye on 2021/12/6.
//

#import "RadiusView.h"

@implementation RadiusView

- (instancetype)init{
    
    self = [super init];
    
    if (self) {
        
        [self initialization];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)coder {
    
    self = [super initWithCoder:coder];
    
    if (self) {
        
        [self initialization];
    }
    return self;
}

- (void)initialization{
    
    self.backgroundColor = [UIColor whiteColor];
    self.layer.masksToBounds = YES;
    self.layer.cornerRadius = 10;
}

@end
