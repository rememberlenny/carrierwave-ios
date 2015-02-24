//
//  CRVInfoView.m
//  Carrierwave
//
//  Created by Patryk Kaczmarek on 24.02.2015.
//  Copyright (c) 2015 Netguru Sp. z o.o. All rights reserved.
//

#import "CRVInfoView.h"

@implementation CRVInfoView

- (instancetype)init {
    self = [super init];
    if (self) {
        self.backgroundColor = [UIColor lightGrayColor];
        self.text = NSLocalizedString(@"Tap twice anywhere to freeze crop rectangle", nil);
        self.textColor = [UIColor whiteColor];
        self.textAlignment = NSTextAlignmentCenter;
        self.font = [UIFont systemFontOfSize:14.f];
    }
    return self;
}

@end
