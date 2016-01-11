//
//  USBillboardManager.h
//  USBillboardManager
//
//  Created by Anton Fedorchenko on 9/24/14.
//  Copyright (c) 2014 - 2015 Upsight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "USBillboardManager.h"

@protocol UpsightDataStoreInterface;
@protocol USActionMapManagerInterface;
@protocol USActionHandlerRegistry;

/** Concrete implementation of <USBillboardManager> managing <USContentUnitBillboard> instances.*/
@interface USContentUnitBillboardManager : NSObject <USBillboardManager>
/** Designated initializer of the class.

@param aDataStore A data store where action maps from Upsight server get stored. If this
parameter is nil, the manager uses the default data store returned by <[UpsightDataStore defaultStore]>.
@param aManager An action map manager that the receiver uses to register its action handlers.
@return Initialized instance of USContentUnitBillboardManager class.
*/
- (nonnull instancetype)initWithDataStore:(nullable id<UpsightDataStoreInterface>)aDataStore actionMapManager:(nonnull id<USActionMapManagerInterface>)aManager;

/** Data store that was passed to the DI.*/
@property (nonatomic, strong, readonly, nonnull) id<UpsightDataStoreInterface> dataStore;
@end
