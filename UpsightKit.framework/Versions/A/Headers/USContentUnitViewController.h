//
//  USContentUnitViewController.h
//  USBillboardManager
//
//  Created by Anton Fedorchenko on 9/30/14.
//  Copyright (c) 2014 - 2015 Upsight. All rights reserved.
//

#import <UIKit/UIKit.h>

/** Typedef for the completion block taken by <USContentUnitViewController's> methods.*/
typedef void (^USLoadContentUnitCompletionHandler)(BOOL inResult, NSError *inError);

@class USContentUnit;
@class USActionMap;

@protocol USContentUnitViewControllerDelegate;

/** View controller managing Upsight content unit presentation.*/
@interface USContentUnitViewController : UIViewController
/** Timeout used for content unit loading.*/
@property (nonatomic, assign, readonly) NSTimeInterval loadingTimeout;

/** Controller's initialization timestamp.*/
@property (nonatomic, assign, readonly) NSTimeInterval timestamp;

/** Content unit presented by the controller.*/
@property (nonatomic, strong, readonly) USContentUnit *contentUnit;

/** Action map containing content unit description that was passed to the receiver.*/
@property (nonatomic, strong, readonly) USActionMap *actionMap;

/** List of the associated scopes.

The view controller can be presented in a billboard with one of the scopes from the given
list.*/
@property (nonatomic, copy) NSArray *scopes;

/** Delegate of the receiver.*/
@property (weak) id<USContentUnitViewControllerDelegate> delegate;

/** Loads given content unit in the receiver.

This method can be called from any thread.

@param aContentUnit Content unit that is to be loaded and presented in the receiver.
@param aMap An action map that contains aContentUnit.
@param aBlock A completion block that is called when loading is finished.
*/
- (void)loadContentUnit:(USContentUnit *)aContentUnit actionMap:(USActionMap *)aMap completionBlock:(USLoadContentUnitCompletionHandler)aBlock;

/** Dismisses the receiver.

Must be called on the main thread.

@param aFlag Indicates with the receiver should be dismissed with an animation.
@param aCompletion A block that is called after the receiver is dismissed.
*/
- (void)dismissControllerAnimated:(BOOL)aFlag completion:(void (^)(void))aCompletion;

/** Provides access to content unit's data.

An example of data that can be accessed through this method is data submitted by a user to
opt-in data collection unit. To obtain data by key you should know the keys and associated
data. Refer to content unit templates source code for more information on exiting keys.

@param aKey Non-nil string tagging data from the content unit.
@return A dictionary representing data associated with aKey.
*/
- (NSDictionary *)viewDataForKey:(NSString *)aKey;

/** Requests to present a close button with the given delay.

Close button is presented in the top-right corner of the content unit. It won't be
presented until this method is called.

@param aDelay A delay with which the close button is presented.
*/
- (void)presentCloseButtonWithDelay:(NSTimeInterval)aDelay;
@end

/** Represents interface of <USContentUnitViewController>'s delegate. */
@protocol USContentUnitViewControllerDelegate <NSObject>
@optional
/** Delegate method called when a view controller is about to be dismissed.

@param aController A view controller that will be dismissed.
*/
- (void)contentUnitViewControllerWillDismiss:(USContentUnitViewController *)aController;

/** Delegate method called after a view controller is dismissed.

@param aController A view controller that has been dismissed.
*/
- (void)contentUnitViewControllerDidDismiss:(USContentUnitViewController *)aController;
@end
