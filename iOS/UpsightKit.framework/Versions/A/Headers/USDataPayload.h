//
//  USDataPayload.h
//  USBillboards
//
//  Created by Kash Shamim on 1/09/17.
//  Copyright (c) 2017 Upsight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface USDataImage : NSObject

@property (nonnull, strong) NSString * imagePath;
@property (readonly) NSInteger width;
@property (readonly) NSInteger height;

@end


/** Object representing the data payload included with a content unit.*/
@interface USDataPayload : NSObject

/** Returns a string value for a given key in the data payload.

@param aKey The key corresponding to a string value in the data payload.  
 
@returns A string value for the given key. 
 Please note that the same key can have unique values for any of the types (string, bool, int, float, color and image).
*/
- (nullable NSString *)stringValueForKey:(nonnull NSString *)aKey;

/** Returns a boolean value for a given key in the data payload.
 
@param aKey The key corresponding to a boolean value in the data payload.
 
@returns An NSNumber representing the boolean value for the given key.
 Please note that the same key can have unique values for any of the types (string, bool, int, float, color and image).
*/
- (nullable NSNumber *)booleanValueForKey:(nonnull NSString *)aKey;

/** Returns an integer value for a given key in the data payload.
 
 @param aKey The key corresponding to a integer value in the data payload.
 
 @returns An NSNumber representing the integer value for the given key.
 Please note that the same key can have unique values for any of the types (string, bool, int, float, color and image).
*/
- (nullable NSNumber *)intValueForKey:(nonnull NSString *)aKey;

/** Returns a float value for a given key in the data payload.
 
 @param aKey The key corresponding to a float value in the data payload.
 
 @returns An NSNumber representing the float value for the given key.
 Please note that the same key can have unique values for any of the types (string, bool, int, float, color and image).
*/
- (nullable NSNumber *)floatValueForKey:(nonnull NSString *)aKey;

/** Returns a UIColor for the given key in the data payload.
 
 @param aKey The key corresponding to a color value in the data payload.
 
 @returns A UIColor representing the color value for the given key.
 Please note that the same key can have unique values for any of the types (string, bool, int, float, color and image).
*/
- (nullable UIColor *)colorValueForKey:(nonnull NSString *)aKey;

/** Returns the local file path to an image for the given key in the data payload.
 
 @param aKey The key corresponding to the image path in the data payload.
 
 @returns A string representing the image path for the given key.
 Please note that the same key can have unique values for any of the types (string, bool, int, float, color and image).
 */
- (nullable USDataImage *)imageForKey:(nonnull NSString *)aKey;

/** Tracks an impression.  Should be called if content is displayed to the user. 
 */
- (void)recordImpressionEvent;

/** Sends a click event. */
- (void)recordClickEvent;

/** Tracks when displayed content has been dismissed. */
- (void)recordDismissedEvent;

/** Destroy closes the data payload and cleans up any associated objects. */
- (void)destroy;

/** Emits an event associated with the USDataPayload.
  It has no effect after billboardDidDismiss is called for the billboard
 @returns a bool with a values of YES if the event exists as a part of the data payload.
*/
- (BOOL)record:(nonnull const NSString *)aEvent;

/** Used only for campaigns using the ‘Raw’ data input format.
 @returns Returns an NSDictionary representation of a data payload for Native Messaging campaigns created using the ‘Raw’ input format. If a Native Messaging campaign was created using the ‘Basic’ data input format, this method will return nil.
*/
- (nullable NSDictionary *)getRawData;
@end
