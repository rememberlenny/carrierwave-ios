//
//  CRVImageEditView.h
//  Carrierwave
//
//  Created by Patryk Kaczmarek on 24.02.2015.
//  Copyright (c) 2015 Netguru Sp. z o.o. All rights reserved.
//

@import UIKit;

@interface CRVImageEditView : UIView

/**
 *  A header view layouted at the top of superview.
 */
@property (strong, nonatomic) UIView *headerView;

/**
 *  A footer view layouted at the bottom of superview.
 */
@property (strong, nonatomic) UIView *footerView;

/**
 *  Defines height designed for header view.
 */
@property (assign, nonatomic) CGFloat headerHeight;

/**
 *  Defines height designed for footer view.
 */
@property (assign, nonatomic) CGFloat footerHeight;

/**
 *  Calculates and returns rect designed for container view.
 */
- (CGRect)rectForContainerView;

@end
