//
//  CRVScalableFrame.h
//  Carrierwave
//
//  Created by Patryk Kaczmarek on 22.01.2015.
//  Copyright (c) 2015 Netguru Sp. z o.o. All rights reserved.
//

@import UIKit;

#import "CRVScalableBorder.h"

@protocol CRVScalableViewDelegate, CRVScalableViewHitTestDelegate;

@interface CRVScalableView : UIView

/**
 *  Initializes scalable view with another view used in hit test. When scalable view active flag is set to NO,
 *  hit test will be redirected to underneath view. Required when you want to move any view below scalable view in view hierarchy.
 *
 *  @param view Underneath view used to pass hit test if scalable view is not active.
 *
 *  @return Instance of scalable view.
 */
- (instancetype)initWithUnderneathView:(UIView *)view;

/**
 *  The receiver's delegate object.
 */
@property (weak, nonatomic) id <CRVScalableViewDelegate> delegate;

/**
 *  Defines whether scalable view is active or not.
 */
@property (assign, nonatomic, getter=isActive) BOOL active;

/**
 *  Border around scalable view. Also scalable.
 */
@property (strong, nonatomic, readonly) CRVScalableBorder *borderView;

/**
 *  Maximum size of scalable view. Default is 300 x 300 points.
 */
@property (assign, nonatomic) CGSize maxSize;

/**
 *  Minimum size of scalable view. Default is 50 x 50 points.
 */
@property (assign, nonatomic) CGSize minSize;

/**
 *  Indicates if scalable view should keep ratio or not. Default NO.
 *  Scalable view refers to ratio calculated on the basis of width/height in moment when ratioEnabled changed to YES.
 */
@property (assign, nonatomic, getter=isRatioEnabled) BOOL ratioEnabled;

/**
 *  Duration of animation. Default 1.0.
 */
@property (assign, nonatomic) NSTimeInterval animationDuration;

/**
 *  Animation curve. Default is UIViewAnimationOptionCurveEaseInOut.
 */
@property (assign, nonatomic) UIViewAnimationOptions animationCurve;

/**
 *  Initial spring velocity used in animation. Default 13.0f.
 */
@property (assign, nonatomic) CGFloat springVelocity;

/**
 *  Spring damping used in animation. Default 0.9f.
 */
@property (assign, nonatomic) CGFloat springDamping;

/**
 *  Animates scalable view to given frame. 
 *  CRVScalableView is smart enough to validate if that frame is located in the superview or not. If not origin (x or y) will be changed to valid ones.
 *  Takes animationDuration, animationCurve, springVelocity, springDamping under the hood as animation parameters.
 *
 *  @param frame      Frame after animation comlpetion.
 *  @param completion A block object to be executed when the animation sequence ends.
 */
- (void)animateToFrame:(CGRect)frame completion:(void (^)(BOOL finished))completion;

/**
 *  Animates scalable view to given size around center of scalable view.
 *  CRVScalableView is smart enough to validate if that frame is located in the superview or not. If not origin (x or y) will be changed to valid ones.
 *  Takes animationDuration, animationCurve, springVelocity, springDamping under the hood as animation parameters.
 *
 *  @param size       Size after animation comlpetion.
 *  @param completion A block object to be executed when the animation sequence ends.
 */
- (void)animateToSize:(CGSize)size completion:(void (^)(BOOL finished))completion;

/**
 *  Animates scalable view to given ratio around center of scalable view.
 *  Final dimensions are maximum possible values depending on superview bounds.
 *  Takes animationDuration, animationCurve, springVelocity, springDamping under the hood as animation parameters.
 *
 *  @param ratio      Final ratio to reach.
 *  @param completion A block object to be executed when the animation sequence ends.
 */
- (void)animateToRatio:(CGFloat)ratio completion:(void (^)(BOOL finished))completion;

/**
 *  Calculates and returns aspect ratio (width/height) of scalable view.
 *
 *  @return ratio in current state.
 */
- (CGFloat)currentRatio;

@end

/**
 * The receiver's delegate which inform about scaling and moving actions.
 */
@protocol CRVScalableViewDelegate <NSObject>

@optional

/**
 *  Called when user did begin to scale view.
 */
- (void)scalableViewDidBeginScaling:(CRVScalableView *)view;

/**
 *  Called when user did end to scale view.
 */
- (void)scalableViewDidEndScaling:(CRVScalableView *)view;

/**
 *  Called when user did begin to move view.
 */
- (void)scalableViewDidBeginMoving:(CRVScalableView *)view;

/**
 *  Called when user did end to move view.
 */
- (void)scalableViewDidEndMoving:(CRVScalableView *)view;

/**
 *  Called everytime when user did move view.
 *  Making cpu/memory consuming operations here may affect performance.
 */
- (void)scalableViewDidMove:(CRVScalableView *)view;

/**
 *  Called everytime when user did scale view. 
 *  Making cpu/memory consuming operations here may affect performance.
 */
- (void)scalableViewDidScale:(CRVScalableView *)view;

@end
