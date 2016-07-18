//
//  USAttributionEvent.h
//  UpsightAnalytics
//
//  Created by Kash 2016.
//  Copyright (c) 2014 - 2016 Upsight. All rights reserved.
//

#import "USEvent.h"

/** Type identifying storable objects of <USAttributionEvent> class. It is the same type as returned
by <[USAttributionEvent type]> property. The primary use of the constant is to pass it as a type
to methods declared in <UpsightDataStoreInterface> protocol to add/remove an observer for
specific type of storable objects.*/
FOUNDATION_EXTERN NSString *const USAttributionEventDataType;

@class USEventParameters;

/** An event that notifies the backend of the attribution source for a new install.*/
@interface USAttributionEvent : USEvent

/** Convenience method for creating an attribution event. Events should be created using <USEventFactory> class.

@param aParameters Parameters of the event.
@param aCampaign Advertising campaign associated with the install.
@param aCreative Advertising creative associated with the install.
@param aSource Advertising source associated with the install.
*/
+ (instancetype)attributionEventWithParameters:(USEventParameters *)aParameters campaign:(NSString *)aCampaign creative:(NSString *)aCreative source:(NSString *)aSource;

/** Accessors to the attribution parameters passed at event creation time.*/
@property (nonatomic, readonly) NSString *campaign;
@property (nonatomic, readonly) NSString *creative;
@property (nonatomic, readonly) NSString *source;
@end
